# ec535_FinalProject
## How to read accelerometer readings
1) Connect accelerometer's power, scl, sdl, and ground pins to the baord.
2) Open file "dev/i2c-0x"
3) Communicate with device with an ioctl() request with appropriate ic2 device address (you can accomplish using i2cdetect -r x)
4) Write into the file the control registers using appropriate addresses (from this step and onwards use accelerometer data sheet)
5) Write into file addresses of the registers of accelerometer readings you wish to read from
6) Store bits into a char array and convert char array into integer to represent the measurements (measurements in 0.0001 g)

## How to detect steps
1) Given accelerometer z readings, establish the four thresholds: bottom, low, high, top
2) Do z transform applying low-pass filter 
3) Detect if Z transform has passed low threshold, high threshold and if passed through bottom or top threshold, adjust min and max accordingly.
4) If it is such that z value is detected to have passed high, passing, and low threshold then a step has been made and step counter is incremented
5) write the result into a text file 
