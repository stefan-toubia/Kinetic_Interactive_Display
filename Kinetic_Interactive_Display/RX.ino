//Some inspiration was taken from Erik Zalm's Marlin RepRap firmware


//Serial reading variables
//uint8_t incoming_serial[3][3][4]; // row x column x RGBD

uint16_t incoming_serial[NUM_COLUMNS][NUM_ROWS];  //just depth array
char header[HEADER_SIZE];
char incoming_depth[9];
int x_in = 0;
int y_in = 0;

#if defined TESTING
  int frame = 1;  
  int last_frame = 0;
  unsigned long last_frame_time = 0;
  unsigned long current_time_millis = 0;
#endif

#ifndef TESTING

void get_serial(){
 // if((last_received_time + SERIAL_TIMEOUT) < millis()){
 //   data_packet.index = 0;
  //  buffer_full = false;
  //}
  //last_received_time = millis();
  #ifdef SERIAL_DEBUG 
  Serial.println("Get Serial Function");
  #endif
  data_packet.buffer[data_packet.index] = Serial.read();
  #ifdef SERIAL_DEBUG 
  Serial.print("Received: ");
  Serial.println(data_packet.buffer[data_packet.index]);
  Serial.print("Index: ");
  Serial.println(data_packet.index);
  #endif
  //Serial.write(data_packet.buffer[data_packet.index]);
  data_packet.index++;
  #ifdef SERIAL_DEBUG 
  Serial.print("Index after ++: ");
  Serial.println(data_packet.index);
  #endif
  if(data_packet.index == RX_BUFFER_SIZE){
    #ifdef SERIAL_DEBUG 
    Serial.println("Buffer Full");
    #endif
     buffer_full = true;
  }
}

void handle_data(){
  #ifdef SERIAL_DEBUG 
  Serial.println("Handle data function");
  #endif
  /*switch(data_packet.buffer[HEADER_LOC]){
    case DEPTH:*/
      save_next_position();
    /*  break;
    default:
      buffer_full = false;
      data_packet.index = 0;
      //Serial.println("ERROR");
  }*/
  //buffer_full = false;
  //data_packet.index = 0;
}

void save_next_position(){
  #ifdef SERIAL_DEBUG 
  Serial.println("save next position function");
  Serial.println("data packet buffer:");
  #endif
  int i=0;
    for(int y = 0; y < NUM_ROWS; y++){
     for(int x = 0; x < NUM_COLUMNS; x++){
       #ifdef SERIAL_DEBUG 
       Serial.print(data_packet.buffer[i]);
       Serial.print(" ");
       #endif
       //Serial.write(data_packet.buffer[i]);
       next_position[x][y] = data_packet.buffer[i];
       i++;
     }
    #ifdef SERIAL_DEBUG  
    Serial.println(" ");
    #endif
   }
   
}

#else

  void next_frame(){
    last_frame = frame;
    frame++;  // for test arrays only
    if(frame==10){
      frame = 0;
    }
      //print_current_frame();
      //print_next_position();
  
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

#endif
