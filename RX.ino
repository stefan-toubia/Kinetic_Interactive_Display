//Serial reading variables
//uint8_t incoming_serial[3][3][4]; // row x column x RGBD
uint16_t incoming_serial[NUM_COLUMNS][NUM_ROWS];  //just depth array
int x_in = 0;
int y_in = 0;
//int RGBD_in = 0;  // R, G, B, D
//int index = 0;

#if defined TESTING
  int frame = 1;  
  int last_frame;
  unsigned long last_frame_time = 0;
  unsigned long current_time_millis = 0;
#endif

#ifndef TESTING
  void get_serial(){
    
    if( Serial.available() > 0){
      //incoming_serial[x_in][y_in][RGBD_in] = Serial.read();
      incoming_serial[x_in][y_in] = Serial.read();
      roll_over_index();
    }
  }
  
  void roll_over_index(){
    x_in++;
    if(x_in>NUM_COLUMNS){
      x_in = 0;
      y_in++;
    }
    if(y_in>NUM_ROWS){
      y_in = 0;
      //RGBD_in++;
      copy_data();
    }
  //  if(RGBD_in>RGBD_MAX){
  //    RGBD_in = 0;
  //
  //  } 
    
    
  }

void copy_data(){
    for(int x = 0; x < NUM_COLUMNS; x++){
         for(int y = 0; y < NUM_ROWS; y++){
           next_position[x][y] = incoming_serial[x][y];
         }
       }
}
#else

  void next_frame(){
    last_frame = frame;
    current_time_millis= millis();
    if(current_time_millis > last_frame_time + SAMPLE_DELAY) {
      last_frame_time = current_time_millis;
      frame++;  // for test arrays only
      if(frame==10){
        frame = 0;
      }
      //print_current_frame();
      //print_next_position();
    }
    if(last_frame!=frame){
      #if defined SINEWAVE
        generate_sine_frame();
      #else
         for(int x = 0; x < NUM_COLUMNS; x++){
           for(int y = 0; y < NUM_ROWS; y++){
             next_position[x][y] = test_input[frame][x][y];
           }
         }
       #endif
      // print_next_position();
    }
  }

#endif
