

#include "def.h"
#include "pins.h"
#include "TestValues.h"
#include <math.h>

//initial state
boolean start_up;  

uint32_t start_millis = 0;

void setup(){
  pinMode(SER1_PIN, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  //reset all register pins
  clearRegisters();
  writeRegisters();
  
  Serial.begin(19200);
  Serial.println("Ready");
  
  #if defined SINEWAVE
    generate_sine();
    print_sine();
  #endif
}               

void loop(){
  //if (start_up == 0) homing();  //will home only once upon startup
  #ifndef TESTING
    get_serial();
  #else
    next_frame();
  #endif
  
  calculate_delays();
  
  start_millis = millis();
  
  //decides whether or not enough time has passed to step a motor again in a certain direction
  if(millis() < SAMPLE_DELAY + start_millis){
    time_steps();  
  }
  
}

