// Read Acceleration and gyroscope data from Polulu's IMU01B

#ifndef IMU01B_H
#define IMU01B_H

#include "IMU01b_registers.h"
#include "mbed.h"

class IMU{
    
    I2C i2c;
        
    public:
    
    IMU(PinName sda, PinName scl):i2c(sda,scl){
    }
    
    void initIMU(int freq = 100000);
    
    float getXAcceleration() ;
    float getYAcceleration() ;
    float getZAcceleration() ;
    
    float getOmegaX() ;
    float getOmegaY() ;
    float getOmegaZ() ;
    
    private:
    
    char getAccData(char cmd) ;   
    char getGyrData(char cmd) ;
};

// Set the I2C frequency and turn ON the accelerometer and the Gyroscope
void IMU::initIMU(int freq){
    i2c.frequency(freq);
    char turn_gyro_on[2] = {CTRL_REG1, 0x0F};
    char turn_acc_on[2] = {CTRL_REG1_A, 0x77};

    i2c.write(GYRO_ADDR_WT,turn_gyro_on, 2);
    i2c.write(ACC_ADDR, turn_acc_on,2);
}

// Get the Raw acceleration data with respect to the x axis
float IMU::getXAcceleration(){
    char axH, axL;
    float aX;
    axL = getAccData(OUT_X_L_A);
    axH = getAccData(OUT_X_H_A);
    aX = ((int16_t)((axH << 8)|axL) >> 6);
    
    return aX;
}

// Get the Raw acceleration data with respect to the y axis
float IMU::getYAcceleration(){
    char ayH, ayL;
    float aY;
    ayL = getAccData(OUT_Y_L_A);
    ayH = getAccData(OUT_Y_H_A);
    aY = ((int16_t)((ayH << 8)|ayL) >> 6);
    
    return aY;
}

// Get the Raw acceleration data with respect to the z axis
float IMU::getZAcceleration(){
    char azH, azL;
    float aZ;
    azL = getAccData(OUT_Z_L_A);
    azH = getAccData(OUT_Z_H_A);
    aZ = ((int16_t)((azH << 8)|azL) >> 6);
    
    return aZ;
}    

// Get the Angular velocity about the x-axis
float IMU::getOmegaX() {
    char xL, xH;
    float wX;
    xL = getGyrData(OUT_X_L);
    xH = getGyrData(OUT_X_H);
    
    wX = (int16_t)((xH << 8) | xL);
    wX = wX*0.00875;
    return wX;
}

// Get the angular velocity about the y-axis
float IMU::getOmegaY() {
    char yL, yH;
    float wY;
    yL = getGyrData(OUT_Y_L);
    yH = getGyrData(OUT_Y_H);
    
    wY = (int16_t)((yH << 8) | yL);
    wY = wY*0.00875;
    return wY;
}

// Get the angular velocity about the z-axis
float IMU::getOmegaZ() {
    char zL, zH;
    float wZ;
    zL = getGyrData(OUT_Z_L);
    zH = getGyrData(OUT_Z_H);
    
    wZ = (int16_t)((zH << 8) | zL);
    wZ = wZ*0.00875;
    return wZ;
}

//Actual reading of the Accelerometer registers
char IMU::getAccData(char cmd) {
    char res;
    
    i2c.write(ACC_ADDR,&cmd,1);
    i2c.read(ACC_ADDR, &res,1);
    return res;
}

// Actual reading of the Gyroscopr registers
char IMU::getGyrData(char cmd) {
    char res;
    i2c.write(GYRO_ADDR_WT,&cmd,1);
    i2c.read(GYRO_ADDR_WT, &res,1);
    return res;
}

#endif 