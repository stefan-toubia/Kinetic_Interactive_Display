
#if defined SINEWAVE
  uint16_t sine_position = 0;
  uint8_t sine_values[SINE_SAMPLES];
  uint8_t sine_matrix[NUM_COLUMNS][NUM_ROWS];
  uint8_t increment;
  //, skew;
  uint16_t temp;
 // skew = 8;
  
  void generate_sine(){
      for(int i = 0; i<SINE_SAMPLES; i++){
        sine_values[i] = (int)(( sin(((float)i/(float)SINE_SAMPLES)*2*PI - PI/2) + 1) * (float)125/(float)2);
        //sine_values[i] = i*SINE_SAMPLES;
      }
      
      
  }
  
  void generate_sine_frame(){
    increment = 0;
    for(int y = 0; y < NUM_ROWS; y++){
      for(int x = 0; x < NUM_COLUMNS;x++){
        temp = sine_position + increment;
        //if(temp >= SINE_SAMPLES) temp = temp - SINE_SAMPLES;
        temp = temp%SINE_SAMPLES;
        increment= increment + 8;
        next_position[x][y] = sine_values[temp];
      } 
//      Serial.print(temp);
//      Serial.print(" - ");
//      Serial.print(sine_values[temp]);
//      Serial.print("    ");
      
      increment = increment + sine_increment;
      sine_position = sine_position%SINE_SAMPLES;
    }
//    Serial.println(" ");
    sine_position = sine_position + sine_speed;
    if(sine_position > SINE_SAMPLES) sine_position = sine_position - SINE_SAMPLES;
  }
  
#endif
