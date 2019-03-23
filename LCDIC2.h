#ifndef LCDIC2_H
#define LCDIC2_H

#include "Arduino.h"
#include "Wire.h"

#define LCDIC2_MODE         0b100
#define LCDIC2_DISPLAY      0b1000
#define LCDIC2_MOVE         0b10000
#define LCDIC2_FUNCTION     0b100000
#define LCDIC2_CGRAM        0b1000000
#define LCDIC2_DDRAM        0b10000000

#define LCDIC2_BITS_4       0b0
#define LCDIC2_BITS_8       0b10000

#define LCDIC2_LINES_1      0b0
#define LCDIC2_LINES_2      0b1000

#define LCDIC2_DOTS_8       0b0
#define LCDIC2_DOTS_10      0b100

#define LCDIC2_CURSOR       0b0000
#define LCDIC2_SHIFT        0b1000

#define LCDIC2_LEFT         0b000
#define LCDIC2_RIGHT        0b100

#define LCDIC2_DEC          0b00
#define LCDIC2_INC          0b10

class LCDIC2 {
  private:
    bool _blink = true, _cursor = true, _display = true, _shift = false;
    uint8_t _address, _height, _width;

  public:
    LCDIC2(uint8_t address, uint8_t width, uint8_t height);
    void begin();
    void backlight(bool state);
    void blink(bool state);
    void busy();
    void clear();
    void cursor(bool state);
    void cursor(uint8_t x, uint8_t y);
    void display(bool state);
    void home();
    void leftToRight();
    void rightToLeft();
    void moveLeft();
    void moveRight();
    size_t print(int32_t number);
    size_t print(String string);
    void reset();
    uint8_t transmit(uint8_t data, bool mode = false);
};

#endif
