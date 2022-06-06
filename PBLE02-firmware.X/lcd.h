/* 
 * File:   lcd.h
 * Author: valter
 *
 * Created on May 15, 2022, 7:26 PM
 */

#ifndef _LCD_H
#define _LCD_H

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

#endif	// _LCD_H