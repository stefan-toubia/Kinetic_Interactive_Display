#include "def.h"
#include "pins.h"
#include "test_values.h"
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
  
  Serial.begin(115200);
  Serial.println("Ready");
  generate_delay_table();
  #if defined SINEWAVE
    generate_sine();
    
    //print_sine();
  #endif
}               

void loop(){
  //if (start_up == 0) homing();  //will home only once upon startup
  
  
  #ifndef TESTING
  if( Serial.available() > 0){
    
      #if defined SERIAL_DEBUG
      Serial.print(micros());
      Serial.println(": Getting Serial Data");
      #endif
      
      get_serial();
      set_delays();

    //start_millis = millis();
  }
    #else
      next_frame();
      set_delays();
    #endif
    



  //decides whether or not enough time has passed to step a motor again in a certain direction
  
    time_steps();  
  
  
}

