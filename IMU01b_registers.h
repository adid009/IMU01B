#ifndef IMU01B_REG_H
#define IMU01B_REG_H

#define GYRO_ADDR_WT 0xD6
#define GYRO_ADDR_RD 0xD7

#define ACC_ADDR 0x32

#define WHO_AM_I 0x0F
#define CTRL_REG1 0x20
#define CTRL_REG2 0x21
#define CTRL_REG3 0x22
#define CTRL_REG4 0X23
#define CTRL_REG5 0x24
#define INT_REF 0x25              
#define OUT_TEMP 0x26             
#define STATUS_REG 0x27

#define OUT_X_L 0x28
#define OUT_X_H 0x29
#define OUT_Y_L 0x2A
#define OUT_Y_H 0x2B
#define OUT_Z_L 0x2C
#define OUT_Z_H 0x2D

#define FIFO_CTRL_REG 0x2E
#define FIFO_SRC_REG 0x2F
#define INT1_CFG 0x30
#define INT1_SRC 0x31 

#define INT1_THS_XH 0x32
#define INT1_THS_XL 0x33
#define INT1_THS_YH 0x34
#define INT_THS_YL 0x35
#define INT1_THS_ZH 0X36
#define INT1_THS_ZL 0x37
#define INT1_DURATION 0x38


// Accelerometer registers
#define CTRL_REG1_A 0x20
#define CTRL_REG2_A 0x21
#define CTRL_REG3_A 0x22
#define CTRL_REG4_A 0x23
#define CTRL_REG5_A 0x24
#define CTRL_REG6_A 0x25

#define DATACAPTURE 0X26
#define STATUS_REG_A 0x27
#define OUT_X_L_A 0x28
#define OUT_X_H_A 0x29
#define OUT_Y_L_A 0x2A
#define OUT_Y_H_A 0x2B
#define OUT_Z_L_A 0x2C
#define OUT_Z_H_A 0x2D

#define FIFO_CTRL_REG_A 0x2E
#define FIFO_SRC_REG_A 0x2F
#define INT1_CFG_A 0x30
#define INT1_SRC_A 0x31
#define INT1_THS_A 0x32
#define INT1_DURATION_A 0x33

#define INT2_CFG_A 0x34
#define INT2_SRC_A 0x35
#define INT2_THS_A 0x36
#define INT2_DURATION_A 0x37

#define CLICK_CFG_A 0x38
#define CLICK_SRC_A 0x39
#define CLICK_THS_A 0x3A

#define TIME_LIMIT_A 0x3B
#define TIME_LATENCY_A 0x3C
#define TIME_WINDOW_A 0x3D

#endif