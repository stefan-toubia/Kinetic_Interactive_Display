//This sketch processes the incoming serial data into delay values 
//for each pixel to control the step speed in each frame

uint32_t delay_table[126];

uint32_t calculate_start_time = 0;

//incoming sample from serial input
void set_delays(){
  //calculate_start_time = micros();
  for(int x = 0; x < NUM_COLUMNS; x++){
    for(int y = 0; y < NUM_ROWS; y++){
      //if(state = '3'){
        //steps[x][y] = pos[x][y];
      //}else 
      steps[x][y] = next_position[x][y] - pos[x][y];
      
      step_delay[x][y] = delay_table[abs(steps[x][y])]; 
    }
  }
  //Serial.println(micros()-calculate_start_time);
}


void time_steps(){
  //Serial.println("TIME_STEPS()");
  for(int x = 0; x < NUM_COLUMNS; x++){
    for(int y = 0; y < NUM_ROWS; y++){
      current_time_micros[x][y] = micros();

      
      #ifndef SLEEP_MODE_EN
      if(current_time_micros[x][y] - last_step_time[x][y] > step_delay[x][y] && step_delay[x][y] != 0 && next_position[x][y] != pos[x][y] ){ //
//      Serial.print("Stepping @ Current micros [");
//      Serial.print(x);
//      Serial.print("][");
//      Serial.print(y);
//      Serial.print("]: ");
//      Serial.println(current_time_micros[x][y]);
        if(steps[x][y] > 0){
          #ifdef SERIAL_DEBUG 
          Serial.println("STEPp+");
          #endif
          current_step[x][y]++;
          if(current_step[x][y] == 4) current_step[x][y] = 0;
          pos[x][y]++;
        }else{
          #ifdef SERIAL_DEBUG 
          Serial.println("STEPp-");
          #endif
          current_step[x][y]--;
          if(current_step[x][y] < 0) current_step[x][y] = 3;
          pos[x][y]--;
        }
        last_step_time[x][y] = current_time_micros[x][y];
      }
      #else
      if(current_time_micros[x][y] - last_step_time[x][y] > step_delay[x][y] && step_delay[x][y] != 0  && next_position[x][y] != pos[x][y]){
        if(steps[x][y] > 0){
          #ifdef SERIAL_DEBUG 
          
          #endif
          if(current_step[x][y] != 4){  //if not sleeping
            current_step[x][y]++;
            if(current_step[x][y] == 4) current_step[x][y] = 0;
            pos[x][y]++;
//            Serial.print(x);
//            Serial.print(y);
//            Serial.print("STEP+");
//            Serial.println(pos[x][y]);
          }else wake(x, y);
        }else{
          if(current_step[x][y] != 4){
            #ifdef SERIAL_DEBUG 

            #endif
            current_step[x][y]--;
            if(current_step[x][y] < 0) current_step[x][y] = 3;
            pos[x][y]--;
//            Serial.print(x);
//            Serial.print(y);
//            Serial.print("STEP-");
//            Serial.println(pos[x][y]);
          }else wake(x, y);
        }
        last_step_time[x][y] = current_time_micros[x][y];
      }
      //if motor has been idle longer than SLEEP_TIME, motor will be shut off
      if(current_time_micros[x][y] - last_step_time[x][y] > SLEEP_TIME) sleep(x, y);
      #endif
    }
  }
  create_shift_pattern();  
}

#if defined SLEEP_MODE_EN
//reactive the motor after it has been put to sleep.  Dedicated function required becuase motor needs to perform two step sequences
//after sleep in order to move one step.  First step re-arms the motor but does not move it forward a step.  
void wake(int x, int y){
  current_step[x][y] = 0;  //restarts motor step sequence at the top (arbitrary, starting step sequence doesn't matter)
  last_step_time[x][y] = current_time_micros[x][y] - step_delay[x][y];  //makes the second step sequencehappen as soon as possible upon next iteration of time_steps() 
}

//will set all motor pins to HIGH in order to turn off the current and allow motor to cool down while inactive
void sleep(int x, int y){
  current_step[x][y] = 4;
}
#endif

void generate_delay_table(){
    delay_table[0] = 0;
  for(int i = 1; i<126; i++){
    delay_table[i]=MICROS_PER_SECOND/(i*SAMPLE_RATE);
    if(delay_table[i] < MIN_DELAY) delay_table[i] = MIN_DELAY;
    
    //#if defined TESTING
    Serial.print(i-1);
    Serial.print(":  ");
    Serial.println(delay_table[i-1]);
    //#endif
  }
  
}
