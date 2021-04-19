#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

/*register addresses of I2C devices */
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

int convert_data (int msb, int lsb){
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
            printf("Gyro Error : Input/output Erorr. Bytes read %d written %d \n", bytes_r, bytes_w);
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
            printf("Gyro Error : Input/output Erorr. Bytes read %d written %d \n", bytes_r, bytes_w);
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
            printf("Gyro Error : Input/output Erorr. Bytes read %d written %d \n", bytes_r, bytes_w);
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
    int i = 0;
    while(i < 600){
        Readings measurements = retrieve_measurements();
        printf("%d %d %d %d\n", i, measurements.accel_x,  measurements.accel_y, measurements.accel_z);
        sleep(1);
        i++;
    }

    return 0;
}
