#include "WS2801_Soft2.h"


/*****************************************************************************
Example sketch for driving WS2801 pixels
*****************************************************************************/

// Choose which 2 pins you will use for output.
// Can be any valid output pins.
// The colors of the wires may be totally different so
// BE SURE TO CHECK YOUR PIXELS TO SEE WHICH WIRES TO USE!
int dataPin0 = 37;
int dataPin1 = 36;
int dataPin2 = 35;
int clockPin = 39;
// Don't forget to connect the ground wire to Arduino ground,
// and the +5V wire to a +5V supply


// Set the first variable to the NUMBER of pixels. 25 = 25 pixels in a row
WS2801_Soft2 strip = WS2801_Soft2(dataPin0, dataPin1, dataPin2, clockPin);

// Optional: leave off pin numbers to use hardware SPI
// (pinout is then specific to each board and can't be changed)
//WS2801 strip = WS2801(25);

void setup() {
    
  strip.begin();

  // Update LED contents, to start they are all 'off'
  strip.show();
}


void loop() {
  // Some example procedures showing how to display to the pixels
 /* strip.setPixelColor(0, 255, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(0, 0, 255, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(0, 0, 0, 255);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(0, 0, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(1, 255, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(1, 0, 255, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(1, 0, 0, 255);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(1, 0, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(2, 255, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(2, 0, 255, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(2, 0, 0, 255);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(2, 0, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(3, 255, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(3, 0, 255, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(3, 0, 0, 255);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(3, 0, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(4, 255, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(4, 0, 255, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(4, 0, 0, 255);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(4, 0, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(5, 255, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(5, 0, 255, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(5, 0, 0, 255);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(5, 0, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(6, 255, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(6, 0, 255, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(6, 0, 0, 255);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(6, 0, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
    strip.setPixelColor(7, 255, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(7, 0, 255, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(7, 0, 0, 255);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(7, 0, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(8, 255, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(8, 0, 255, 0);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(8, 0, 0, 255);
  strip.show();   // write all the pixels out
  delay(1000);
  strip.setPixelColor(8, 0, 0, 0);
  strip.show();   // write all the pixels out
  delay(1000);
 
 
 
 
 
 
 
 
 
 */
 
 
 
 
 
 
 
 
  //colorWipe(Color(255, 0, 0), 1000);
  //colorWipe(Color(0, 255, 0), 1000);
  //colorWipe(Color(0, 0, 255), 1000);
  rainbow(50);
  //delay(2000);
  rainbowCycle(1);
  //delay(2000);
  rainbowCycle(10);
  //delay(3000);
}

void rainbow(uint8_t wait) {
  int i, j;
   
  for (j=0; j < 256; j++) {     // 3 cycles of all 256 colors in the wheel
    for (i=0; i < 9; i++) {
      strip.setPixelColor(i, 0, Wheel( (i + j) % 255));
      strip.setPixelColor(i, 1, Wheel( (i + j) % 255));
      strip.setPixelColor(i, 2, Wheel( (i + j) % 255));
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

// Slightly different, this one makes the rainbow wheel equally distributed 
// along the chain
void rainbowCycle(uint8_t wait) {
  int i, j;
  
  for (j=0; j < 256 * 5; j++) {     // 5 cycles of all 25 colors in the wheel
    for (i=0; i < 9; i++) {
      // tricky math! we use each pixel as a fraction of the full 96-color wheel
      // (thats the i / strip.numPixels() part)
      // Then add in j which makes the colors go around per pixel
      // the % 96 is to make the wheel cycle around
      strip.setPixelColor(i, 0, Wheel( ((i * 256 / 9) + j) % 256) );
      strip.setPixelColor(i, 1, Wheel( ((i * 256 / 9) + j) % 256) );
      strip.setPixelColor(i, 2, Wheel( ((i * 256 / 9) + j) % 256) );
    }  
    strip.show();   // write all the pixels out
    delay(wait);
  }
}

// fill the dots one after the other with said color
// good for testing purposes
void colorWipe(uint32_t c, uint8_t wait) {
  int i;
  
  for (i=0; i < 9; i++) {
      strip.setPixelColor(i, 0, c);
      strip.setPixelColor(i, 1, c);
      strip.setPixelColor(i, 2, c);
      
      strip.show();
      delay(wait);
  }
}

/* Helper functions */

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85) {
   return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
