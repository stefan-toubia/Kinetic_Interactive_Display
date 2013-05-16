#include "Output.h"
#include <Arduino.h>

void create_shift_pattern(){
  int i=0; 
  for(int x = 0; x < 3; x++){
      for(int y = 0; y < 3; y++){
        switch (current_step[x][y]) {
          case 0:    
            //setMotorPinsXY(x, y, 0x0B);
            shift_out.setMotorPins(i, 0, B01011);//0x0B
            //shift_out.setMotorPins(i, 1, B01011);//0x0B
          break;
          case 1:
            //setMotorPinsXY(x, y, 0x13);    
            shift_out.setMotorPins(i, 0, B10011);//0x0
            //shift_out.setMotorPins(i, 1, B10011);//0x0D
          break;
          case 2:    
            //setMotorPinsXY(x, y, 0x15);
            shift_out.setMotorPins(i, 0, B10101);//0x15
            //shift_out.setMotorPins(i, 1, B10101);//0x15

          break;
          case 3:   
            //setMotorPinsXY(x, y, 0x0D);
            shift_out.setMotorPins(i, 0, B01101);
            //shift_out.setMotorPins(i, 1, B01101);
          break;
          #if defined SLEEP_MODE_EN
          case 4: //1111 - SLEEP mode
            //setMotorPinsXY(x, y, 0x1F);
            shift_out.setMotorPins(i, 0, B11111);
            //shift_out.setMotorPins(i, 1, B11111);
          break;
          #endif
        }
        i++;
      }
  }
  shift_out.writeRegisters();
      
}
   
void setMotorPinsXY(uint8_t x, uint8_t y, uint8_t pins){
   shift_out.setMotorPins(indexLUT[x][y], boardLUT[x][y], pins);
}



