#ifndef _LCD_H
#define _LCD_H

#include "mcc_generated_files/system.h"

    void pulseEnablePin();
    void pushNibble(int value, int rs);
    void pushByte(int value, int rs);
    void lcdChar(int value);
    void lcdCommand(int value);
    void lcdCommand4bits(int nibble);
    void lcdInit();
    void lcdString(char msg[]);
    void lcdData(unsigned char value);
    void lcdInt(int val);
    void lcd2Dig(int val);
    void lcdUInt32(uint32_t val);
    void lcdUInt16(uint16_t val);
    void lcdUInt8(uint8_t val);
#endif	// _LCD_H