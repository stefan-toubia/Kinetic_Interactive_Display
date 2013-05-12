//This sketch processes the incoming serial data into delay values for each pixel to control
//the step speed in each frame

int steps[NUM_COLUMNS][NUM_ROWS];      //number of steps required in a given sample period  (negative or posative depending on direction)
int pos[NUM_COLUMNS][NUM_ROWS] = { {0,0,0}, {0,0,0}, {0,0,0} };     //position of each pixel
int current_step[NUM_COLUMNS][NUM_ROWS] = { {0,0,0}, {0,0,0}, {0,0,0} };    //sequence in step pattern value (1-4)
int next_position[NUM_COLUMNS][NUM_ROWS];    
int step_delay[NUM_COLUMNS][NUM_ROWS];

uint32_t last_step_time[NUM_COLUMNS][NUM_ROWS] = { {0,0,0}, {0,0,0}, {0,0,0} };
uint32_t current_time_micros[NUM_COLUMNS][NUM_ROWS] = { {0,0,0}, {0,0,0}, {0,0,0} };

boolean shift_pattern[45];  //output bit pattern for shift registers
uint16_t delay_table[126];

uint32_t calculate_start_time = 0;

//incoming sample from serial input
void set_delays(){
  //calculate_start_time = micros();
  for(int x = 0; x < NUM_COLUMNS; x++){
    for(int y = 0; y < NUM_ROWS; y++){
      steps[x][y] = next_position[x][y] - pos[x][y];
      
      step_delay[x][y] = delay_table[abs(steps[x][y])]; 
    }
  }
  //Serial.println(micros()-calculate_start_time);
}

void time_steps(){
  for(int x = 0; x < NUM_COLUMNS; x++){
    for(int y = 0; y < NUM_ROWS; y++){
      current_time_micros[x][y] = micros();
      if(current_time_micros[x][y] - last_step_time[x][y] > step_delay[x][y] && step_delay[x][y] != 0){
        if(steps[x][y] > 0){
          current_step[x][y]++;
          if(current_step[x][y] == 4) current_step[x][y] = 0;
          pos[x][y]++;
        }else{
          current_step[x][y]--;
          if(current_step[x][y] < 0) current_step[x][y] = 3;
          pos[x][y]--;
        }
        last_step_time[x][y] = current_time_micros[x][y];
      }
      //if motor has been idle longer than SLEEP_TIME, motor will be shut off
      if(current_time_micros[x][y] - last_step_time[x][y] > SLEEP_TIME) sleep(x, y);
    }
  }
  create_shift_pattern();  
}
.
void sleep(int x, int y){
  
}

void homing(){  //homing is not working right now
  for(int x = 0; x < NUM_COLUMNS; x++){
    for(int y = 0; x < NUM_ROWS; y++){
      
    }
  }
  //STEP BACKWARDS 125 TIMES HERE ?!?!?!?!?!?!?!?!?

  for(int x = 0; x < NUM_COLUMNS; x++){
    for(int y = 0; x < NUM_ROWS; y++){
      pos[x][y] = 0;
    }
  }
  
  start_up = 1;

}

void generate_delay_table(){
    delay_table[0] = 0;
  for(int i = 1; i<126; i++){
    delay_table[i]=MICROS_PER_SECOND/(i*SAMPLE_RATE);
    if(delay_table[i] < MIN_DELAY) delay_table[i] = MIN_DELAY;
    
    #if defined TESTING
    Serial.print(i);
    Serial.print(":  ");
    Serial.println(delay_table[i]);
    #endif
  }
  
}
