#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

/*register addresses of I2C devices 6b and 1d*/
#define I2C_ADDR_GYRO 0x6B 
#define I2C_ADDR_ACCELMAG 0X1D

/*register addresses of CONTROL reg */
#define CTRL_REG_1 0X20
#define CTRL_REG_2 0X21
#define CTRL_REG_3 0X22
#define CTRL_REG_4 0X23
#define CTRL_REG_5 0X24 
#define CTRL_REG_5 0X24 
#define CTRL_REG_6 0X25
#define CTRL_REG_7 0X26

#define ENABLE_XYZ_95 0x0F
#define ENABLE_XYZ_100 0x67
#define ENABLE_CONT_UPDATE 0X30 
#define ENABLE_SCALE_A16 0x20
#define ENABLE_HIGH_MRES 0x70
#define ENABLE_SCALE_M12 0x60
#define ENABLE_CONT_NORM 0x00

/*register addresses of GYRO reg  */
#define GYRO_LSB_X 0x28
#define GYRO_MSB_X 0x29
#define GYRO_LSB_Y 0x2A
#define GYRO_MSB_Y 0x2B
#define GYRO_LSB_Z 0x2C
#define GYRO_MSB_Z 0x2D

/*register address of ACCEL reg */
#define ACCEL_LSB_X 0x28
#define ACCEL_MSB_X 0x29
#define ACCEL_LSB_Y 0x2A
#define ACCEL_MSB_Y 0x2B
#define ACCEL_LSB_Z 0x2C
#define ACCEL_MSB_Z 0x2D

/*register address of MAGN reg */
#define MAGN_LSB_X 0x08
#define MAGN_MSB_X 0x09
#define MAGN_LSB_Y 0x0A
#define MAGN_MSB_Y 0x0B
#define MAGN_LSB_Z 0x0C
#define MAGN_MSB_Z 0x0D

/*number of steps*/
static int steps = 0;

static double last_reading = -9999; 
static long last_time = 0; 

static int high_state = 1; 
static int low_state = 1; 
static int passing_state = 0; 
 
static double high_threshold = 0; 
static double high_threshold_Alpha = 1.0;
static double top_threshold = 1;
static double top_threshold_Min = 0.50; 
static double top_threshold_Max = 1.5; 
static double top_threshold_Alpha = 0.0005; 

static double low_threshold = 0; 
static double low_threshold_Alpha = -1.0;
static double bottom_threshold = -1; 
static double bottom_threshold_Max = -0.50; 
static double bottom_threshold_Min = -1.5; 
static double bottom_threshold_Alpha = 0.0005; 

static double filter_alpha = 0.9;  

/*stores all the data bits for x y z data */ 
typedef struct Readings{
    int gyro_x;
    int gyro_y;
    int gyro_z;
    int accel_x;
    int accel_y;
    int accel_z;
    int magn_x;
    int magn_y;
    int magn_z;
}Readings;

/*  does step detection by detecting if readings cross: bottom, low, high, top boundary */
/* step must accomplish a lifting, transient, and stepping phase */
/* lifting phase: negative acceleration when passing low treshold */
/* passing phase: between lifting phase and stepping phase. must already be on lifting stage, passed low threshold*/
/* stepping phase: positive acceleration when passing high threshold, must already be on passing phase*/
int step_detection(int accel_z_measurement) {
    struct timespec current;
    clock_gettime(CLOCK_REALTIME, &current);
    
    long current_time = current.tv_nsec/1000000;
    long gapTime1 = (current_time - last_time);

    //if first time, assign last reading as current reading
    if (last_reading == -9999){
        last_reading = (accel_z_measurement-1300);
    }

    //adjust high threshold and boundary for detection
    if (high_state && (top_threshold > top_threshold_Min)) {
        top_threshold = top_threshold - top_threshold_Alpha;
        high_threshold = top_threshold * high_threshold_Alpha;
    }

    //adjust low threshold and boundary for detection
    if (low_state && (bottom_threshold < bottom_threshold_Max)) {
        bottom_threshold = bottom_threshold + bottom_threshold_Alpha;
        low_threshold = bottom_threshold * low_threshold_Alpha;
    }

    //perform a low pass filter for sensor reading
    double transformed_Z = (filter_alpha * last_reading) + (1 - filter_alpha) * (accel_z_measurement-1300);

    //set high state off after 100 ms if already in high state and within high threshold
    if (high_state && gapTime1 > 100 && (transformed_Z > high_threshold)){
        high_state = 0;
    }

    //set low state off if already in passing state and low state and within low threshold
    if (low_state && (transformed_Z < low_threshold) && passing_state) {
        low_state = 0;
    }

    //check if we have reached high state
    if ((high_state == 0)) {
        //adjust thresholds if Z already above top
        if (transformed_Z > top_threshold) {
            top_threshold = transformed_Z;
            high_threshold = top_threshold * high_threshold_Alpha;

            //adjust max
            if (top_threshold > top_threshold_Max) {
                top_threshold = top_threshold_Max;
                high_threshold = top_threshold * high_threshold_Alpha;
            }
        } else {
            //otherwise set high state on and passing state on 
            if (high_threshold > transformed_Z) {
                high_state = 1;
                passing_state = 1;
            }
        }
    }

    //check if we have reached low state
    if ((low_state == 0) && passing_state) {

        //adjust thresholds if Z already below bottom
        if (transformed_Z < bottom_threshold) {
            bottom_threshold = transformed_Z;
            low_threshold = bottom_threshold * low_threshold_Alpha;
            
             //adjust min
            if (bottom_threshold < bottom_threshold_Min) {
                bottom_threshold = bottom_threshold_Min;
                low_threshold = bottom_threshold * low_threshold_Alpha;
            }
        } else {

            //otherwise set low state and set passing state off 
            if (low_threshold < transformed_Z) {
                low_state = 1;
                passing_state = 0;
                
                //increment steps
                steps++;
                
                last_time = current_time;
            }
        }
    }  

    last_reading = transformed_Z;

    return 1;
}

int convert_data (char msb, char lsb){
    int measurement = 0;
    measurement = msb * 256 + lsb;
    if (measurement > 32767){
        measurement -= 65536;
    }
    return measurement;
}

Readings retrieve_measurements(){
    /* Connecting board to accelerometer device */
	int file;
	char * bus = "/dev/i2c-2";

    //initialize address structures
    char gyro_address [6] = {GYRO_LSB_X, GYRO_MSB_X, GYRO_LSB_Y, GYRO_MSB_Y, GYRO_LSB_Z, GYRO_MSB_Z};
    char accel_address [6] = {ACCEL_LSB_X, ACCEL_MSB_X, ACCEL_LSB_Y, ACCEL_MSB_Y, ACCEL_LSB_Z, ACCEL_MSB_Z};
    char magn_address [6] = {MAGN_LSB_X, MAGN_MSB_X, MAGN_LSB_Y, MAGN_MSB_Y, MAGN_LSB_Z, MAGN_MSB_Z};
    
    //initialize data structures 
    char bits_array [6] = {0}; //{int lsb_x, int msb_x, int lsb_y, int msb_y, int lsb_z, int msb_z;}
    Readings measurement_array = {0};

    // config values
    char config_0 [2] = {CTRL_REG_1, ENABLE_XYZ_95};
    char config_1 [2] = {CTRL_REG_4, ENABLE_CONT_UPDATE};

    char config_2 [2] = {CTRL_REG_1, ENABLE_XYZ_100};
    char config_3 [2] = {CTRL_REG_2, ENABLE_SCALE_A16};
    char config_4 [2] = {CTRL_REG_5, ENABLE_HIGH_MRES};
    char config_5 [2] = {CTRL_REG_6, ENABLE_SCALE_M12};
    char config_6 [2] = {CTRL_REG_7, ENABLE_CONT_NORM};

    // open device
    if((file = open(bus, O_RDWR)) <0){
        printf("Failed to open");
        exit(1);
    }

    // Communicate with I2C device
    if(ioctl(file, I2C_SLAVE, I2C_ADDR_GYRO)<0){	
        printf("Failed to communicate \n");
        exit(2);
   
   };
    
    // enable xyz axis, power on, 95 hz data rate
    write(file, config_0, 2);
    
    // enable continous update 95 dps or degrees/sec
    write(file, config_1, 2);  
    
    /* Begin reading gyrometer values */
    for (int i = 0; i < 6; i++){
        int bytes_w = write(file, &gyro_address[i], 1);
        int bytes_r = read (file, &bits_array[i], 1);
        if(bytes_w != 1 || bytes_r != 1)
        {
            printf("Gyro Error : Input/output Error. Bytes read %d written %d \n", bytes_r, bytes_w);
            exit(1);
        }
    }	
    
    measurement_array.gyro_x = convert_data(bits_array[1], bits_array[0]);
    measurement_array.gyro_y = convert_data(bits_array[3], bits_array[2]);
    measurement_array.gyro_z = convert_data(bits_array[5], bits_array[4]);
    /* Communicate with I2C devices */
    ioctl(file, I2C_SLAVE, 0x1d);
    
    //enable xyz for 100 hz data rate 
    write(file, config_2, 2);
    
    //enable full scale +/- 16g accel
    write(file, config_3, 2);
    
    //enable magnetic high res 50hz
    write(file, config_4, 2);
    
    //enable magnetic full scale +/- 12 gauss
    write(file, config_5, 2);
    
    //enable magnetic continous mode
    write(file, config_6, 2);   

    /* Begin reading gyrometer values */
    for (int i = 0; i < 6; i++){
        int bytes_w = write(file, &accel_address[i], 1);
        int bytes_r = read (file, &bits_array[i], 1);
        if(bytes_w != 1 || bytes_r != 1)
        {
            printf("Gyro Error : Input/output Error. Bytes read %d written %d \n", bytes_r, bytes_w);
            exit(1);
        }
    }	
    
    measurement_array.accel_x = convert_data(bits_array[1], bits_array[0]);
    measurement_array.accel_y = convert_data(bits_array[3], bits_array[2]);
    measurement_array.accel_z = convert_data(bits_array[5], bits_array[4]);
    
     /* Begin reading magnometer values */

    for (int i = 0; i < 6; i++){
        int bytes_w = write(file, &magn_address[i], 1);
        int bytes_r = read (file, &bits_array[i], 1);
        if(bytes_w != 1 || bytes_r != 1)
        {
            printf("Gyro Error : Input/output Error. Bytes read %d written %d \n", bytes_r, bytes_w);
            exit(1);
        }
    }	
    
    measurement_array.magn_x = convert_data(bits_array[1], bits_array[0]);
    measurement_array.magn_y = convert_data(bits_array[3], bits_array[2]);
    measurement_array.magn_z = convert_data(bits_array[5], bits_array[4]);

    // /*print statements*/
    // printf("Rotation in X-axis : %d \n", measurement_array.gyro_x);
    // printf("Rotation in Y-axis : %d \n", measurement_array.gyro_y);
    // printf("Rotation in Z-axis : %d \n", measurement_array.gyro_z);
    // printf("Acceleration in X-axis : %d \n", measurement_array.accel_x);
    // printf("Acceleration in Y-axis : %d \n", measurement_array.accel_y);
    // printf("Acceleration in Z-axis : %d \n", measurement_array.accel_z);
    // printf("Magnetic field in X-axis : %d \n", measurement_array.magn_x);
    // printf("Magnetic field in Y-axis : %d \n", measurement_array.magn_y);
    // printf("Magnetic field in Z-axis : %d \n", measurement_array.magn_z);
	return measurement_array;
}

int main(){
    //int i = 0;
    int file_io;
    FILE *fptr;

	char * input_text = "input.txt";
    char * line = malloc(32);
    memset(line, 0 , 32);

    while(1){
        Readings measurements = retrieve_measurements();
        //printf("%d %d %d %d\n", i, measurements.accel_x,  measurements.accel_y, measurements.accel_z);
        //step_detection(measurements.accel_x,  measurements.accel_y, measurements.accel_z);
        step_detection(measurements.accel_z);
        //printf("step: %d z_accel: %d \n", steps, measurements.accel_z);


        /*
        if((file_io = open(input_text, O_TRUNC)) < 0){
            printf("Failed to open input text");
            exit(1);
        }

        //steps++;

        sprintf(line, "%d", steps);

        if(write(file_io, line, strlen(line)) <= 0){
            printf("Failed to write input text");
            exit(1);
        }

        close (file_io);
        memset(line, 0 , 32); */
        fptr = fopen(input_text, "w");
        if(fptr == NULL){
            printf("ERROR writing to input file \n");
            exit(1);
        }

        fprintf(fptr, "%d", steps);
        fclose(fptr);

        usleep(100000);
    }

    return 0;
}
