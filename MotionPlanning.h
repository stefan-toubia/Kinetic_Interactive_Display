int steps[NUM_COLUMNS][NUM_ROWS];      //number of steps required in a given sample period  (negative or posative depending on direction)
int pos[NUM_COLUMNS][NUM_ROWS];
//= { {0,0,0}, {0,0,0}, {0,0,0} };     //position of each pixel
int current_step[NUM_COLUMNS][NUM_ROWS] = { {0,0,0}, {0,0,0}, {0,0,0} };    //sequence in step pattern value (0-3) and (4) sleep
int next_position[NUM_COLUMNS][NUM_ROWS];    
unsigned int step_delay[NUM_COLUMNS][NUM_ROWS];
unsigned long last_step_time[NUM_COLUMNS][NUM_ROWS] = { {0,0,0}, {0,0,0}, {0,0,0} };
unsigned long current_time_micros[NUM_COLUMNS][NUM_ROWS] = { {0,0,0}, {0,0,0}, {0,0,0} };
