/////////////////////////////////////////////////////////////////
//TESTING

//comment out to enter testing mode (uses test array from TestValues.h)
#define TESTING    //no serial

#if defined TESTING
  #define SINEWAVE
  #define SINE_INCREMENT 8
  #define SINE_SPEED 32
  #define SINE_SAMPLES 256
#endif

//////////////////////////////////////////////////////////////
//SHIFT REGISTER 
//How many of the shift registers - change this
#define number_of_74hc595s 6 

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8
  
//////////////////////////////////////////////////////////////
//MOTION PLANNING DEFS
#define max_steps  125      // total number of steps this motor can take 
#define MAX_SPEED  250  //steps per second
#define MIN_DELAY 1000/MAX_SPEED



/////////////////////////////////////////////////////////////////
//CONFIGURATION DEFS
#define NUM_COLUMNS 3
#define NUM_ROWS 3
#define RGBD_MAX 4


/////////////////////////////////////////////////////////////////
//SERIAL DEFS
#define SAMPLE_RATE  10  //samples per second
#define SAMPLE_DELAY 1000/SAMPLE_RATE //ms


///////////////////////////////////////////////////////////////
