#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

#include "WS2801_Soft.h"
#include "Stepper_Shift.h"

#include "def.h"
#include "pins.h"
#include "RX.h"
#include "test_values.h"
#include "MotionPlanning.h"
#include <math.h>

WS2801_Soft rgb = WS2801_Soft(RGB_PIN0, RGB_PIN1, RGB_PIN2, RGB_CLK);

Stepper_Shift shift_out = Stepper_Shift(SER0_PIN, SER1_PIN, SER2_PIN, RCLK_PIN, SRCLK_PIN);

//initial state
boolean start_up = 1;  
uint16_t current_millis = 0;
uint16_t start_millis = 0;
uint16_t last_start_millis = 0;
char state = '0';
int sine_speed = 8;
int sine_increment = 16;
boolean buffer_full;
boolean homing_state;

void setup(){

  rgb.begin();
  rgb.show(); //initially clears rgb output
  
  shift_out.begin();
  shift_out.writeRegisters();
  
  data_packet.index = 0;
  buffer_full = false;
  //reset all register pins
  
  Serial.begin(19200);
  Serial.println("Ready");
  
  homing_state = true;
  generate_delay_table();
  delay(10);
  #if defined SINEWAVE
    generate_sine();
    print_sine();
  #endif
  
  for(int x = 0; x < NUM_COLUMNS; x++){
    for(int y = 0; y < NUM_ROWS; y++){
      pos[x][y] = MAX_STEPS;
      next_position[x][y] = 0;
      step_delay[x][y] = 10000;
//      Serial.print("pixel [");
//      Serial.print(x);
//      Serial.print("][");
//      Serial.print(y);
//      Serial.print("] position : ");
//      Serial.println(pos[x][y]);
    }
  }
  #ifdef SERIAL_DEBUG
  Serial.print("Buffer size: ");
  Serial.println(RX_BUFFER_SIZE);
  Serial.print("Index: ");
  Serial.println(data_packet.index);
  #endif
  
  
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
 //main loop
void loop(){
  #ifdef HOMING_EN
  if(homing_state && pos[0][0] == pos[NUM_COLUMNS-1][NUM_ROWS-1] && pos[0][0] == 0){
    Serial.println("Home");
    homing_state = false;
  }
  #endif
  
  #ifndef TESTING
  if( Serial.available() > 0 && !homing_state){
    #ifdef SERIAL_DEBUG 
    Serial.print(Serial.available());
    Serial.println("Getting Serial");
    #endif
    get_serial();
  }
  
  if(buffer_full == true){
    #ifdef SERIAL_DEBUG 
    Serial.println("Buffer Full Loop");
    #endif
    //Serial.write('T');
    handle_data();
    #ifdef SERIAL_DEBUG 
    Serial.println("data handles");
    print_current_position();
    print_next_position();
    #endif
    
    
    set_delays();
    #ifdef SERIAL_DEBUG 
    Serial.println("delays set");
    print_delays();
    #endif
    
    data_packet.index = 0;
    #ifdef SERIAL_DEBUG 
    Serial.println("buffer emptied (re-indexed)");
    #endif
    buffer_full = false;
  }


   
  
  #else
  /*
  if ( Serial.available()&& state != '1' && state != '2') {
    //Serial.println(micros());
    state = Serial.read();
    //Serial.println(state);
    //Serial.println(micros()); 
    //Serial.print("State: ");
   // Serial.println(state);
    //Serial.println("1 - sine speed, 2 - sine increment 3 - stop");
  } 
 
  if(state == '1'){
    if ( Serial.available()) {
    int temp = Serial.read();
    sine_speed = (int)temp;
    //Serial.print("sine speed: ");
    //Serial.println(sine_speed);
    state = '0';
    } 
  }else if(state == '2'){
    if ( Serial.available()) {
    int temp = Serial.read();
    sine_increment = (int)temp;
    //Serial.print("sine increment: ");
    //Serial.println(sine_increment);
    state = 0;
    } 
  }
  
  */
  current_millis = millis();
  if(current_millis > start_millis + 100){
    start_millis = millis();
    next_frame();  //sets next_position[] based on defined test input 
    set_delays();
    Color();
    rgb.show();
    last_start_millis = start_millis;
    //print_delays();
  }
 #endif
//  //Serial.println("Time steps");
  time_steps();  //always running when not doing anything else.
  

}  

