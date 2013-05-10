
boolean shift_pattern[45];  //output bit pattern for shift registers

int pos[NUM_COLUMNS][NUM_ROWS] = { {0,0,0}, {0,0,0}, {0,0,0} };     //position of each pixel

int current_step[NUM_COLUMNS][NUM_ROWS] = { {0,0,0}, {0,0,0}, {0,0,0} };    //sequence in step pattern value 1-4
uint16_t temp_delay;

//incoming sample from serial input
int next_position[NUM_COLUMNS][NUM_ROWS];    

//number of steps required in a given sample period  (negative or posative depending on direction)
int steps[NUM_COLUMNS][NUM_ROWS];      

int step_delay[NUM_COLUMNS][NUM_ROWS];
unsigned long current_time_millis2[NUM_COLUMNS][NUM_ROWS] = { {0,0,0}, {0,0,0}, {0,0,0} };
unsigned long last_step_time[NUM_COLUMNS][NUM_ROWS] = { {0,0,0}, {0,0,0}, {0,0,0} };
unsigned long last_step_times = 0;    // time stamp in us of the last step taken


void calculate_delays(){
  
  for(int x = 0; x < NUM_COLUMNS; x++){
    for(int y = 0; y < NUM_ROWS; y++){
      steps[x][y] = next_position[x][y] - pos[x][y];
      if(steps[x][y] != 0){
        temp_delay = 1000/((abs(steps[x][y])*SAMPLE_RATE));
        if(temp_delay<MIN_DELAY){
          step_delay[x][y] = MIN_DELAY;
        }else{
          step_delay[x][y] = temp_delay;
        }
                //Serial.print("Calculating step delay    ");
        //Serial.println(step_delay[x][y]);
      }else{
        step_delay[x][y] = 0;
      }
    }
  }

}



void time_steps(){
  for(int x = 0; x < NUM_COLUMNS; x++){
    for(int y = 0; y < NUM_ROWS; y++){
      current_time_millis2[x][y] = millis();

      if(current_time_millis2[x][y] - last_step_time[x][y] > step_delay[x][y] && step_delay[x][y] != 0){

        if(steps[x][y] > 0){
          current_step[x][y]++;
          if(current_step[x][y] == 4) current_step[x][y] = 0;
          pos[x][y]++;

        }else{
          current_step[x][y]--;
          if(current_step[x][y] < 0) current_step[x][y] = 3;
          pos[x][y]--;

        }

        last_step_time[x][y] = current_time_millis2[x][y];
        
      }
    }
  }
  create_shift_pattern();
  
  
}

void homing(){
  for(int x = 0; x < NUM_COLUMNS; x++){
    for(int y = 0; x < NUM_ROWS; y++){
      //step_delay[x][y] = 
    }
  }
  
  //STEP BACKWARDS 125 TIMES HERE ?!?!?!?!?!?!?!?!?
  Serial.println("Home");
  for(int x = 0; x < NUM_COLUMNS; x++){
    for(int y = 0; x < NUM_ROWS; y++){
      pos[x][y] = 0;
    }
  }
  
  start_up = 1;

}
