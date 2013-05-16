
#include "WS2801_Soft2.h"

// Example to control WS2801-based RGB LED Modules in a strand or strip
// Written by Adafruit - MIT license
// Modified by Stefan Toubia:
// Removed Hardware SPI and modified Soft SPI to run 9 separate data pins

/*****************************************************************************/

// Constructor for use with arbitrary clock/data pins:
// n is number of WS2801 per data pin?
//Constructor for 3 boards
WS2801_Soft2::WS2801_Soft2(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t cpin) {
  numBoards = 3;
  alloc(9);
  updatePins(dpin0, dpin1, dpin2, cpin);
}

//constructor for 6 boards
WS2801_Soft2::WS2801_Soft2(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t dpin3, uint8_t dpin4, uint8_t dpin5, uint8_t cpin) {
  numBoards = 6;
  alloc(9);
  updatePins(dpin0, dpin1, dpin2, dpin3, dpin4, dpin5, cpin);
}

//constructor for 9 boards
WS2801_Soft2::WS2801_Soft2


(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t dpin3, uint8_t dpin4, uint8_t dpin5, uint8_t dpin6, uint8_t dpin7, uint8_t dpin8, uint8_t cpin) {
  alloc(9);
  updatePins(dpin0, dpin1, dpin2, dpin3, dpin4, dpin5, dpin6, dpin7, dpin8, cpin);
  numBoards = 9;
}

// Allocate 3 bytes per pixel, init to RGB 'off' state:
void WS2801_Soft2::alloc(uint16_t n) {
  numLEDs = 9;
  if(numBoards == 3) {
    pixels0  = (uint8_t *)calloc(n, 3);
    pixels1  = (uint8_t *)calloc(n, 3);
    pixels2  = (uint8_t *)calloc(n, 3);
  }else if(numBoards == 6){
    pixels0  = (uint8_t *)calloc(n, 3);
    pixels1  = (uint8_t *)calloc(n, 3);
    pixels2  = (uint8_t *)calloc(n, 3);
    pixels3  = (uint8_t *)calloc(n, 3);
    pixels4  = (uint8_t *)calloc(n, 3);
    pixels5  = (uint8_t *)calloc(n, 3);
  }else if(numBoards == 9){
    pixels0  = (uint8_t *)calloc(n, 3);
    pixels1  = (uint8_t *)calloc(n, 3);
    pixels2  = (uint8_t *)calloc(n, 3);
    pixels3  = (uint8_t *)calloc(n, 3);
    pixels4  = (uint8_t *)calloc(n, 3);
    pixels5  = (uint8_t *)calloc(n, 3);
    pixels6  = (uint8_t *)calloc(n, 3);
    pixels7  = (uint8_t *)calloc(n, 3);
    pixels8  = (uint8_t *)calloc(n, 3);
  }
}

// Activate hard/soft SPI as appropriate:
void WS2801_Soft2::begin(void) {
  if(numBoards >= 3){
    pinMode(datapin0, OUTPUT);
    pinMode(datapin1, OUTPUT);
    pinMode(datapin2, OUTPUT);
  }
  if(numBoards >= 6){
    pinMode(datapin3, OUTPUT);
    pinMode(datapin4, OUTPUT);
    pinMode(datapin5, OUTPUT);
  }
  if(numBoards == 9){
    pinMode(datapin6, OUTPUT);
    pinMode(datapin7, OUTPUT);
    pinMode(datapin8, OUTPUT);
  }

  pinMode(clkpin , OUTPUT);

}


// Change pin assignments post-constructor, using arbitrary pins:
void WS2801_Soft2::updatePins(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t cpin) {

  datapin0     = dpin0;
  datapin1     = dpin1;
  datapin2     = dpin2;
  
  clkpin      = cpin;
  clkport     = portOutputRegister(digitalPinToPort(cpin));
  clkpinmask  = digitalPinToBitMask(cpin);
  
  dataport0    = portOutputRegister(digitalPinToPort(dpin0));
  datapinmask0 = digitalPinToBitMask(dpin0);
  
  dataport1    = portOutputRegister(digitalPinToPort(dpin1));
  datapinmask1 = digitalPinToBitMask(dpin1);
  
  dataport2    = portOutputRegister(digitalPinToPort(dpin2));
  datapinmask2 = digitalPinToBitMask(dpin2);
  
}

void WS2801_Soft2::updatePins(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t dpin3, uint8_t dpin4, uint8_t dpin5, uint8_t cpin) {

  datapin0     = dpin0;
  datapin1     = dpin1;
  datapin2     = dpin2;
  datapin3     = dpin3;
  datapin4     = dpin4;
  datapin5     = dpin5;

  
  clkpin      = cpin;
  clkport     = portOutputRegister(digitalPinToPort(cpin));
  clkpinmask  = digitalPinToBitMask(cpin);
  
  dataport0    = portOutputRegister(digitalPinToPort(dpin0));
  datapinmask0 = digitalPinToBitMask(dpin0);
  
  dataport1    = portOutputRegister(digitalPinToPort(dpin1));
  datapinmask1 = digitalPinToBitMask(dpin1);
  
  dataport2    = portOutputRegister(digitalPinToPort(dpin2));
  datapinmask2 = digitalPinToBitMask(dpin2);
  
  dataport3    = portOutputRegister(digitalPinToPort(dpin3));
  datapinmask3 = digitalPinToBitMask(dpin3);
  
  dataport4    = portOutputRegister(digitalPinToPort(dpin4));
  datapinmask4 = digitalPinToBitMask(dpin4);
  
  dataport5    = portOutputRegister(digitalPinToPort(dpin5));
  datapinmask5 = digitalPinToBitMask(dpin5);
  

}

void WS2801_Soft2::updatePins(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t dpin3, uint8_t dpin4, uint8_t dpin5, uint8_t dpin6, uint8_t dpin7, uint8_t dpin8, uint8_t cpin) {

  datapin0     = dpin0;
  datapin1     = dpin1;
  datapin2     = dpin2;
  datapin3     = dpin3;
  datapin4     = dpin4;
  datapin5     = dpin5;
  datapin6     = dpin6;
  datapin7     = dpin7;
  datapin8     = dpin8;
  
  clkpin      = cpin;
  clkport     = portOutputRegister(digitalPinToPort(cpin));
  clkpinmask  = digitalPinToBitMask(cpin);
  
  dataport0    = portOutputRegister(digitalPinToPort(dpin0));
  datapinmask0 = digitalPinToBitMask(dpin0);
  
  dataport1    = portOutputRegister(digitalPinToPort(dpin1));
  datapinmask1 = digitalPinToBitMask(dpin1);
  
  dataport2    = portOutputRegister(digitalPinToPort(dpin2));
  datapinmask2 = digitalPinToBitMask(dpin2);
  
  dataport3    = portOutputRegister(digitalPinToPort(dpin3));
  datapinmask3 = digitalPinToBitMask(dpin3);
  
  dataport4    = portOutputRegister(digitalPinToPort(dpin4));
  datapinmask4 = digitalPinToBitMask(dpin4);
  
  dataport5    = portOutputRegister(digitalPinToPort(dpin5));
  datapinmask5 = digitalPinToBitMask(dpin5);
  
  dataport6    = portOutputRegister(digitalPinToPort(dpin6));
  datapinmask6 = digitalPinToBitMask(dpin6);
  
  dataport7    = portOutputRegister(digitalPinToPort(dpin7));
  datapinmask7 = digitalPinToBitMask(dpin7);
  
  dataport8    = portOutputRegister(digitalPinToPort(dpin8));
  datapinmask8 = digitalPinToBitMask(dpin8);
}

void WS2801_Soft2::show(void) {
  uint16_t i, nl3 = numLEDs * 3; // 3 bytes per LED
  uint8_t  bit;

  // Write 24 bits per pixel:

    for(i=0; i<nl3; i++ ) {
      for(bit=0x80; bit; bit >>= 1) {
        if(numBoards >= 3){
          if(pixels0[i] & bit) *dataport0 |=  datapinmask0;
          else                *dataport0 &= ~datapinmask0;
          
          if(pixels1[i] & bit) *dataport1 |=  datapinmask1;
          else                *dataport1 &= ~datapinmask1;
          
          if(pixels2[i] & bit) *dataport2 |=  datapinmask2;
          else                *dataport2 &= ~datapinmask2;
        }
        if(numBoards >= 6){
          if(pixels3[i] & bit) *dataport3 |=  datapinmask3;
          else                *dataport3 &= ~datapinmask3;
          
          if(pixels4[i] & bit) *dataport4 |=  datapinmask4;
          else                *dataport4 &= ~datapinmask4;
          
          if(pixels5[i] & bit) *dataport5 |=  datapinmask5;
          else                *dataport5 &= ~datapinmask5;
        }
        if(numBoards == 9){
          if(pixels6[i] & bit) *dataport6 |=  datapinmask6;
          else                *dataport6 &= ~datapinmask6;
          
          if(pixels7[i] & bit) *dataport7 |=  datapinmask7;
          else                *dataport7 &= ~datapinmask7;
          
          if(pixels8[i] & bit) *dataport8 |=  datapinmask8;
          else                *dataport8 &= ~datapinmask8;
        }
        
        *clkport |=  clkpinmask;
        *clkport &= ~clkpinmask;
      }
    }

  delay(1); // Data is latched by holding clock pin low for 1 millisecond
}

// Set pixel color from separate 8-bit R, G, B components:
void WS2801_Soft2::setPixelColor(uint16_t index, uint16_t board, uint8_t r, uint8_t g, uint8_t b) {
  if(index < numLEDs) { // Arrays are 0-indexed, thus NOT '<='
    switch(board){
      case 0:
      {
        uint8_t *p = &pixels0[index * 3];
        *p++ = r;
        *p++ = g;
        *p++ = b;
        break;
      }
      case 1:
      {
        uint8_t *p = &pixels1[index * 3];
        *p++ = r;
        *p++ = g;
        *p++ = b;
        break;
      }
      case 2:
      {
        uint8_t *p = &pixels2[index * 3];
        *p++ = r;
        *p++ = g;
        *p++ = b;
        break;
      }
      case 3:
      {
        uint8_t *p = &pixels3[index * 3];
        *p++ = r;
        *p++ = g;
        *p++ = b;
        break;
      }
      case 4:
      {
        uint8_t *p = &pixels4[index * 3];
        *p++ = r;
        *p++ = g;
        *p++ = b;
        break;
      }
      case 5:
      {
        uint8_t *p = &pixels5[index * 3];
        *p++ = r;
        *p++ = g;
        *p++ = b;
        break;
      }
      case 6:
      {
        uint8_t *p = &pixels6[index * 3];
        *p++ = r;
        *p++ = g;
        *p++ = b;
        break;
      }
      case 7:
      {
        uint8_t *p = &pixels7[index * 3];
        *p++ = r;
        *p++ = g;
        *p++ = b;
        break;
      }
      case 8:
      {
        uint8_t *p = &pixels8[index * 3];
        *p++ = r;
        *p++ = g;
        *p++ = b;
        break;
      }
    }

  }
}

// Set pixel color from 'packed' 32-bit RGB value:
void WS2801_Soft2::setPixelColor(uint16_t index, uint16_t board, uint32_t c) {
  if(index < numLEDs) { // Arrays are 0-indexed, thus NOT '<='
    // To keep the show() loop as simple & fast as possible, the
    // internal color representation is native to different pixel
    // types.  For compatibility with existing code, 'packed' RGB
    // values passed in or out are always 0xRRGGBB order.
    switch(board){
      case 0:
      {
        uint8_t *p = &pixels0[index * 3];
        *p++ = c >> 16; // Red
        *p++ = c >>  8; // Green
        *p++ = c;         // Blue
        break;
      }
      case 1:
      {
        uint8_t *p = &pixels1[index * 3];
        *p++ = c >> 16; // Red
        *p++ = c >>  8; // Green
        *p++ = c;         // Blue
        break;
      }
      case 2:
      {
        uint8_t *p = &pixels2[index * 3];
        *p++ = c >> 16; // Red
        *p++ = c >>  8; // Green
        *p++ = c;         // Blue
        break;
      }
      case 3:
      {
        uint8_t *p = &pixels3[index * 3];
        *p++ = c >> 16; // Red
        *p++ = c >>  8; // Green
        *p++ = c;         // Blue
        break;
      }
      case 4:
      {
        uint8_t *p = &pixels4[index * 3];
        *p++ = c >> 16; // Red
        *p++ = c >>  8; // Green
        *p++ = c;         // Blue
        break;
      }
      case 5:
      {
        uint8_t *p = &pixels5[index * 3];
        *p++ = c >> 16; // Red
        *p++ = c >>  8; // Green
        *p++ = c;         // Blue
        break;
      }
      case 6:
      {
        uint8_t *p = &pixels6[index * 3];
        *p++ = c >> 16; // Red
        *p++ = c >>  8; // Green
        *p++ = c;         // Blue
        break;
      }
      case 7:
      {
        uint8_t *p = &pixels7[index * 3];
        *p++ = c >> 16; // Red
        *p++ = c >>  8; // Green
        *p++ = c;         // Blue
        break;
      }
      case 8:
      {
        uint8_t *p = &pixels8[index * 3];
        *p++ = c >> 16; // Red
        *p++ = c >>  8; // Green
        *p++ = c;         // Blue
        break;
      }
    }
  }
}



