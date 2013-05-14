#ifdef RGB

#include "WS2801.h"

#define PIXELS 9
#define BYTES_PER_PIXEL 3
#define SAMPLE_RATE 1 //samples per .1sec
#define SAMPLE_TIME 1 //sec

const int sampleSize = PIXELS*BYTES_PER_PIXEL*SAMPLE_RATE*SAMPLE_TIME; //36
uint16_t RXbuffer; //buffer array

int led_pcb0 = 37; //assign pin 37 on mega to LED serial data
int clockPin = 39; //assign pin 37 on mega to LED clock data

//individual pixel arrrays for leds in first 3x3 only!

//int i=0;
//leds elements of pcb0---WS2801(number of pixels, serial output pin, clock pin)
WS2801 strip0 = WS2801(9, led_pcb0, clockPin);

/*
void group_led_data (void) { //assigns R, G, B Bytes in buffer to pixel array
      uint32_t led_pixel_0[24] = {RXbuffer[0], RXbuffer[9], RXbuffer[19]};
      uint32_t led_pixel_1[24] = {RXbuffer[1], RXbuffer[10], RXbuffer[20]};
      uint32_t led_pixel_2[24] = {RXbuffer[2], RXbuffer[11], RXbuffer[21]};
      uint32_t led_pixel_3[24] = {RXbuffer[3], RXbuffer[12], RXbuffer[22]};
      uint32_t led_pixel_4[24] = {RXbuffer[4], RXbuffer[13], RXbuffer[23]};
      uint32_t led_pixel_5[24] = {RXbuffer[5], RXbuffer[14], RXbuffer[24]};
      uint32_t led_pixel_6[24] = {RXbuffer[6], RXbuffer[15], RXbuffer[25]};
      uint32_t led_pixel_7[24] = {RXbuffer[7], RXbuffer[16], RXbuffer[26]};
      uint32_t led_pixel_8[24] = {RXbuffer[8], RXbuffer[17], RXbuffer[27]};
      
    }
  
void send_led_data (void) { //sets each pixel individually then shows simultaneously
      
      strip0.setPixelColor(1, led_pixel_1[24]);
      strip0.setPixelColor(2, led_pixel_2[24]);
      strip0.setPixelColor(3, led_pixel_3[24]);
      strip0.setPixelColor(4, led_pixel_4[24]);
      strip0.setPixelColor(5, led_pixel_5[24]);
      strip0.setPixelColor(6, led_pixel_6[24]);
      strip0.setPixelColor(7, led_pixel_7[24]);
      strip0.setPixelColor(8, led_pixel_8[24]);
   
      strip0.show();
    }*/










#endif
