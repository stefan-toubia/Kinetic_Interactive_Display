/////////////////////////////////////////////////////////////////
//TESTING

//comment out to enter testing mode (uses test array from TestValues.h)
#define TESTING    //no serial
#define SERIAL_DEBUG

#if defined TESTING
  #define SINEWAVE
//  #define SINE_INCREMENT 4
//  #define SINE_SPEED 4
  #define SINE_SAMPLES 256
#endif
/////////////////////////////////////////////////////////////////
//RGB DEFS
//#define RGB
//////////////////////////////////////////////////////////////
//SHIFT REGISTER 
//How many of the shift registers - change this
#define number_of_74hc595s 6 

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8
  
//////////////////////////////////////////////////////////////
//MOTION PLANNING DEFS
#define SLEEP_MODE_EN
#define HOMING_EN

#define MAX_STEPS  125      // total number of steps this motor can take 
#define MAX_SPEED  200  //steps per second
#define HOMING_SPEED 50
#define MIN_DELAY MICROS_PER_SECOND/MAX_SPEED
#define HOMING_DELAY = MICROS_PER_SECOND/HOMING_SPEED

#if defined SLEEP_MODE_EN
#define SLEEP_TIME 1*MICROS_PER_SECOND
#endif


/////////////////////////////////////////////////////////////////
//CONFIGURATION DEFS
#define NUM_COLUMNS 3
#define NUM_ROWS 3
#define RGBD_MAX 4


/////////////////////////////////////////////////////////////////
//SERIAL DEFS
#define RX_BUFFER_SIZE 9
#define SERIAL_TIMEOUT 500 //ms
#define SAMPLE_RATE  10  //samples per second
#define SAMPLE_DELAY MILLIS_PER_SECOND/SAMPLE_RATE //ms
#define HEADER_SIZE 4
#define DEPTH_HEADER "\xAA\xDA"


///////////////////////////////////////////////////////////////
#define MICROS_PER_SECOND 1000000
#define MILLIS_PER_SECOND 1000
