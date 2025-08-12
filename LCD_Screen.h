#ifndef _LCD_Screen_H
#define _LCD_Screen_H


#define LCD_RS LATAbits.LATA11
#define LCD_EN LATAbits.LATA10
#define LCD_D4 LATAbits.LATA2
#define LCD_D5 LATAbits.LATA3
#define LCD_D6 LATAbits.LATA4
#define LCD_D7 LATAbits.LATA5

void LCD_Init(void);
void LCD_Command(uint8_t cmd);
void LCD_Char(uint8_t data);
void LCD_String(const char *str);
void LCD_CreateChar(uint8_t location, uint8_t *charmap);
void DelayMs(uint16_t ms);


const uint8_t heart[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000
};

const uint8_t smiley[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b10001,
    0b01110,
    0b00000
};

const uint8_t frownie[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b00000,
    0b01110,
    0b10001
};

const uint8_t armsDown[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b01010
};

const uint8_t armsUp[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b10101,
    0b01110,
    0b00100,
    0b00100,
    0b01010
};


#endif