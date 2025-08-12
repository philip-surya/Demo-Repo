#include <xc.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "I2C.h"
#include "io.h"
#include "PWM.h"
#include "UART.h"
#include "LCD_Screen.h"
#define PRESCALE     1
#define INCRPERSEC   836/PRESCALE

// Fuck you 

void main(void){
    double kp, ki, kd, P, I, D;
    double setpoint, current, error, lastError, output;
    unsigned char ByteLow, ByteHigh;
    int accelx, i;
    char str[7];
    IO_init();
    I2C_init();
    UART_init();
    PWM_init();
    LCD_Init();
    
    
    setpoint = 0;
    current = 0;
    error = 0;
    lastError = 0;
    output = 0;
    
    kp = 0.5;
    ki = 0.02;
    kd = 1;
    
    SensorWrite(CTRL_REG6_X, 0xC0);
    
    while(1){
        SensorRead(ACCEL_X_L, &ByteLow);
        SensorRead(ACCEL_X_H, &ByteHigh);
        accelx = (ByteHigh << 8) | (ByteLow);
        if (accelx > 32767) accelx -= 65536;
        
        error = setpoint - accelx;
        
        P = kp * error;
        I += ki * lastError;
        D = kd * (error - lastError);
        
        if(I > 2000) I = 2000;
        if(I < -2000) I = -2000;
        
        output = P + I + D;
        lastError = error;
        
        if(output > 1000) return 1000;
        if(output < 5) return 5;
        
        PWM_duty(output);
        
        sprintf(str, "%7.1f%7.1f%7.1f%7.1f%7.1f\n\r", error, P, I, D, output);
        sendString(str);
        
        for(i = 0; i < INCRPERSEC / 1000; i++){}
    
    }
}