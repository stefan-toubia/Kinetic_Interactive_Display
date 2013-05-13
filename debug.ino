//void print_current_frame(){
//  for(int y = 0; y < 3; y++){
//    for(int x = 0; x < 3; x++){
//      Serial.print(test_input[frame][x][y]);
//      Serial.print("  ");
//    }
//    Serial.print("\n");
//  }
//  Serial.print("\n");
//}

void print_current_step(){
  for(int y = 0; y < 3; y++){
    for(int x = 0; x < 3; x++){
      Serial.print(current_step[x][y]);
      Serial.print("  ");
    }
    Serial.print("\n");
  }
  Serial.print("\n");
}

#if defined SINEWAVE
  void print_sine(){
    int i = 0;
    for(int y = 0; y < SINE_SAMPLES/8; y++){
      for(int x = 0; x < 8; x++){
        Serial.print(sine_values[i]);
        i++;
        Serial.print("  ");
      }
      Serial.print("\n");
    }
    Serial.print("\n");
  }
#endif

void print_next_position(){
  Serial.println("Next Positions");
  for(int y = 0; y < 3; y++){
    for(int x = 0; x < 3; x++){
      Serial.print(next_position[x][y]);
      Serial.print("  ");
    }
    Serial.print("\n");
  }
  Serial.print("\n");
}

void print_current_position(){
  Serial.println("Current Positions");
  for(int y = 0; y < 3; y++){
    for(int x = 0; x < 3; x++){
      Serial.print(pos[x][y]);
      Serial.print("  ");
    }
    Serial.print("\n");
  }
  Serial.print("\n");
}

void print_delays(){
  Serial.println("Delays");
  for(int y = 0; y < 3; y++){
    for(int x = 0; x < 3; x++){
      Serial.print(step_delay[x][y]);
      Serial.print("  ");
    }
    Serial.print("\n");
  }
  Serial.print("\n");
}
