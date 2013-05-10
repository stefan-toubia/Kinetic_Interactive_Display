boolean registers[numOfRegisterPins];


//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }
} 


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void writeRegisters(){

  digitalWrite(RCLK_Pin, LOW);

  for(int i = numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(SRCLK_Pin, LOW);

    int val_1 = registers[i];
    //int val_2 = registers[i+numOfRegisterPins];
    digitalWrite(SER1_PIN, val_1);
    delayMicroseconds (4); 
    digitalWrite(SRCLK_Pin, HIGH);
    delayMicroseconds (4); 
    
  }
  digitalWrite(RCLK_Pin, HIGH);
 
}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
}



        
void create_shift_pattern(){
int i=0; 
  for(int x = 0; x < 3; x++){
      for(int y = 0; y < 3; y++){
        switch (current_step[x][y]) {
          case 0:    // 1010
              setRegisterPin(5*(i), LOW);
              setRegisterPin(5*(i)+1, HIGH);
              setRegisterPin(5*(i)+2, LOW);
              setRegisterPin(5*(i)+3, HIGH);
              setRegisterPin(5*(i)+4, HIGH);
          break;
          case 1:    // 0110
              setRegisterPin(5*(i), HIGH);
              setRegisterPin(5*(i)+1, LOW);
              setRegisterPin(5*(i)+2, LOW);
              setRegisterPin(5*(i)+3, HIGH);
              setRegisterPin(5*(i)+4, HIGH);
          break;
          case 2:    //0101
              setRegisterPin(5*(i), HIGH);
              setRegisterPin(5*(i)+1, LOW);
              setRegisterPin(5*(i)+2, HIGH);
              setRegisterPin(5*(i)+3, LOW);
              setRegisterPin(5*(i)+4, HIGH);
          break;
          case 3:    //1001
              setRegisterPin(5*(i), LOW);
              setRegisterPin(5*(i)+1, HIGH);
              setRegisterPin(5*(i)+2, HIGH);
              setRegisterPin(5*(i)+3, LOW);
              setRegisterPin(5*(i)+4, HIGH);
          break;
        }
        i++;
      }
  }
  writeRegisters();
      
}

