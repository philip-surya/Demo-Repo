#include <xc.h>
#include "LCD_Screen.h"

void main(void) {
    // Configure LCD pins
    TRISB = 0x0000; // Set PORTB as output for LCD control
    TRISD = 0x0000; // Set PORTD as output for LCD data
    
    // Initialize LCD
    LCD_Init();
    
    // Create custom characters
    LCD_CreateChar(0, (uint8_t *)heart);
    LCD_CreateChar(1, (uint8_t *)smiley);
    LCD_CreateChar(2, (uint8_t *)frownie);
    LCD_CreateChar(3, (uint8_t *)armsDown);
    LCD_CreateChar(4, (uint8_t *)armsUp);

    // Print a message to the LCD
    LCD_Command(0x80); // Set cursor to first line
    LCD_Char(0); // Display custom heart character
    LCD_String(" PIC32MM! ");
    LCD_Char(1); // Display custom smiley character

    while (1) {
        // Simulate reading an analog value
        uint16_t sensorReading = ADC1BUF0; // Replace with actual ADC read
        uint16_t delayTime = (sensorReading * (1000 - 200)) / 1023 + 200;
        
        // Display custom characters with delay
        LCD_Command(0xC0); // Set cursor to second line
        LCD_Char(3); // Display custom arms down character
        DelayMs(delayTime);
        
        LCD_Command(0xC0); // Set cursor to second line
        LCD_Char(4); // Display custom arms up character
        DelayMs(delayTime);
    }
}

void LCD_Init(void) {
    DelayMs(15); // Wait for LCD to power up
    LCD_Command(0x30); // Function set
    DelayMs(5);
    LCD_Command(0x30); // Function set
    DelayMs(1);
    LCD_Command(0x30); // Function set
    LCD_Command(0x38); // 8-bit mode, 2 lines, 5x8 dots
    LCD_Command(0x0C); // Display ON, cursor OFF
    LCD_Command(0x06); // Entry mode set
    LCD_Command(0x01); // Clear display
    DelayMs(2);
}

void LCD_Command(uint8_t cmd) {
    LCD_RS = 0;
    LATD = cmd; // Send command to data port
    LCD_EN = 1;
    DelayMs(1);
    LCD_EN = 0;
    DelayMs(2);
}

void LCD_Char(uint8_t data) {
    LCD_RS = 1;
    LATD = data; // Send data to data port
    LCD_EN = 1;
    DelayMs(1);
    LCD_EN = 0;
    DelayMs(2);
}

void LCD_String(const char *str) {
    while (*str) {
        LCD_Char(*str++);
    }
}

void LCD_CreateChar(uint8_t location, uint8_t *charmap) {
    location &= 0x07; // Maximum 8 custom characters
    LCD_Command(0x40 | (location << 3)); // Set CGRAM address
    for (int i = 0; i < 8; i++) {
        LCD_Char(charmap[i]);
    }
}

void DelayMs(uint16_t ms) {
    while (ms--) {
        DelayMs(20000); // Adjust for your clock speed
    }
}





