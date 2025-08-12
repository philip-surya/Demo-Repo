#ifndef _I2C_H
#define _I2C_H

#define I2CSPEED    400000
#define PBCLK       8000000
#define ADDREAD     0xD5
#define ADDWRITE    0xD4
#define WHO_AM_I    0x0f
#define CTRL_REG6_X 0x20
#define ACCEL_X_L   0x28
#define ACCEL_X_H   0x29
#define ACCEL_Y_L   0x2A
#define ACCEL_Y_H   0x2B
#define ACCEL_Z_L   0x2C
#define ACCEL_Z_H   0x2D

void I2C_init();
void I2C_wait(void);
void I2C_start(void);
void I2C_stop(void);
void I2C_restart(void);
void ack(void);
void nack(void);
void I2C_wirte(unsigned char, char);
void I2C_read(unsigned char*, char);
void SensorWrite(unsigned char, unsigned char);
void SensorRead(unsigned char, unsigned char*);

#endif