#include <xc.h>
#include <math.h>
#include "PWM.h"

void PWM_init(void){
    //set MCCP operating mode
    CCP1CON1bits.ON = 0;
    CCP1CON1bits.CCSEL = 0;
    CCP1CON1bits.MOD = 0b0110;
    
    //configure  MCCP Timebase
    CCP1CON1bits.T32 = 0;
    CCP1CON1bits.TMRSYNC = 0;
    CCP1CON1bits.CLKSEL = 0b000;
    CCP1CON1bits.TMRPS = 0b10;
    CCP1CON1bits.TRIGEN = 0;
    CCP1CON1bits.SYNC = 0b00000;
    
    //configure MCCP output for
     CCP1CON2bits.OCBEN = 1;
     CCP1CON3bits.OUTM = 0b000;
     CCP1CON3bits.POLACE = 0;
     CCP1TMRbits.TMRL = 0x0000;
     CCP1PRbits.PRL = 0x2710;
     CCP1RA = 0x03E8;
     CCP1RB = 0x1388;
     CCP1CON1bits.ON = 1;
}

void PWM_duty(int duty){
    CCP1RA = duty;
}