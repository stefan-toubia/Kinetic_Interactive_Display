/*
Adapted Adafruit's WS2801 software SPI implementation to write Stepper Motor shift registers
*/

#include "Stepper_Shift.h"

Stepper_Shift::Stepper_Shift(uint8_t dpin0, uint8_t rclk, uint8_t srclk){
  numBoards = 1;
  alloc(9);  //allocates 9 bytes to store motor commands (only requires 5 bits per motor, but I'm unsure how to manipulate a byte array 5 bits at a time at this point)
  initPins(dpin0, rclk, srclk);
}
   
Stepper_Shift::Stepper_Shift(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t rclk, uint8_t srclk){
  numBoards = 3;
  alloc(6);
  initPins(dpin0, dpin1, dpin2, rclk, srclk);
}
/*
Stepper_Shift::Stepper_Shift(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t dpin3, uint8_t dpin4, uint8_t dpin5, uint8_t rclk, uint8_t srclk){
  numBoards = 6;
  alloc(6);
  initPins(dpin0, dpin1, dpin2, dpin3, dpin4, dpin5, rclk, srclk);
}
*/
void Stepper_Shift::alloc(uint16_t n){
  
  if(numBoards >= 1){
    steps0 = (uint8_t *)calloc(n, 1);
  }
  if(numBoards >= 3){
    steps1 = (uint8_t *)calloc(n, 1);
    steps2 = (uint8_t *)calloc(n, 1);
  }
  if(numBoards == 6){
    steps3 = (uint8_t *)calloc(n, 1);
    steps4 = (uint8_t *)calloc(n, 1);
    steps5 = (uint8_t *)calloc(n, 1);
  }
}

void Stepper_Shift::begin(void){
  if(numBoards >= 1){
    pinMode(datapin0, OUTPUT);
  }
  if(numBoards >= 3){
    pinMode(datapin1, OUTPUT);
    pinMode(datapin2, OUTPUT);
  }
  if(numBoards >= 6){
    pinMode(datapin3, OUTPUT);
    pinMode(datapin4, OUTPUT);
    pinMode(datapin5, OUTPUT);
  }
  pinMode(rclkpin, OUTPUT);
  pinMode(srclkpin, OUTPUT);
}

void Stepper_Shift::initPins(uint8_t dpin0, uint8_t rclk, uint8_t srclk){
 
  datapin0 = dpin0;
  dataport0 = portOutputRegister(digitalPinToPort(dpin0));
  datapinmask0 = digitalPinToBitMask(dpin0);
  
  rclkpin = rclk;
  rclkport = portOutputRegister(digitalPinToPort(rclk));
  rclkpinmask = digitalPinToBitMask(rclk);
  
  srclkpin = srclk;
  srclkport = portOutputRegister(digitalPinToPort(srclk));
  srclkpinmask = digitalPinToBitMask(srclk);
  
}

void Stepper_Shift::initPins(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t rclk, uint8_t srclk){
 
  datapin0 = dpin0;
  datapin1 = dpin1;
  datapin2 = dpin2;
  
  rclkpin = rclk;
  rclkport = portOutputRegister(digitalPinToPort(rclk));
  rclkpinmask = digitalPinToBitMask(rclk);
  
  srclkpin = srclk;
  srclkport = portOutputRegister(digitalPinToPort(srclk));
  srclkpinmask = digitalPinToBitMask(srclk);
  
  dataport0 = portOutputRegister(digitalPinToPort(dpin0));
  datapinmask0 = digitalPinToBitMask(dpin0);
  
  dataport1 = portOutputRegister(digitalPinToPort(dpin1));
  datapinmask1 = digitalPinToBitMask(dpin1);
  
  dataport2 = portOutputRegister(digitalPinToPort(dpin2));
  datapinmask2 = digitalPinToBitMask(dpin2);

}

void Stepper_Shift::initPins(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t dpin3, uint8_t dpin4, uint8_t dpin5, uint8_t rclk, uint8_t srclk){
 
  datapin0 = dpin0;
  datapin1 = dpin1;
  datapin2 = dpin2;
  datapin3 = dpin3;
  datapin4 = dpin4;
  datapin5 = dpin5;
  
  rclkpin = rclk;
  rclkport = portOutputRegister(digitalPinToPort(rclk));
  rclkpinmask = digitalPinToBitMask(rclk);
  
  srclkpin = srclk;
  srclkport = portOutputRegister(digitalPinToPort(srclk));
  srclkpinmask = digitalPinToBitMask(srclk);
  
  dataport0 = portOutputRegister(digitalPinToPort(dpin0));
  datapinmask0 = digitalPinToBitMask(dpin0);
  
  dataport1 = portOutputRegister(digitalPinToPort(dpin1));
  datapinmask1 = digitalPinToBitMask(dpin1);
  
  dataport2 = portOutputRegister(digitalPinToPort(dpin2));
  datapinmask2 = digitalPinToBitMask(dpin2);
  
  dataport3 = portOutputRegister(digitalPinToPort(dpin3));
  datapinmask3 = digitalPinToBitMask(dpin3);
  
  dataport4 = portOutputRegister(digitalPinToPort(dpin4));
  datapinmask4 = digitalPinToBitMask(dpin4);
  
  dataport5 = portOutputRegister(digitalPinToPort(dpin5));
  datapinmask5 = digitalPinToBitMask(dpin5);

}

void Stepper_Shift::writeRegisters(void){
  uint16_t i;
  uint8_t bit;
  
  *rclkport &= ~rclkpinmask;
  *srclkport &= ~srclkpinmask;
   for(i=9; i>0; i-- ) {
     for(bit=0x01; bit < 0x20; bit <<= 1){
        if(steps0[i-1] & bit) *dataport0 |=  datapinmask0;
        else                *dataport0 &= ~datapinmask0;
        
        if(steps1[i-1] & bit) *dataport1 |=  datapinmask1;
        else                *dataport1 &= ~datapinmask1;
        
        if(steps2[i-1] & bit) *dataport2 |=  datapinmask2;
        else                *dataport2 &= ~datapinmask2;
        
        if(steps3[i-1] & bit) *dataport3 |=  datapinmask3;
        else                *dataport3 &= ~datapinmask3;
        
        if(steps4[i-1] & bit) *dataport4 |=  datapinmask4;
        else                *dataport4 &= ~datapinmask4;
        
        if(steps5[i-1] & bit) *dataport5 |=  datapinmask5;
        else                *dataport5 &= ~datapinmask5;
        
        //delayMicroseconds(4);
        *srclkport |= srclkpinmask;
        //delayMicroseconds(4);
        *srclkport &= ~srclkpinmask;
     }
   } 
  *rclkport |= rclkpinmask;   
}
//gets passed byte formatted xxxbbbbb, x = dont care 
void Stepper_Shift::setMotorPins(uint8_t index, uint8_t board, uint8_t pins){
  switch(board){
     case 0:{
       uint8_t *p = &steps0[index];
       *p++ = pins;
       break;
    }case 1:{
       uint8_t *p = &steps1[index];
       *p++ = pins;
       break;
    }case 2:{
       uint8_t *p = &steps2[index];
       *p++ = pins;
       break;
    }case 3:{
       uint8_t *p = &steps3[index];
       *p++ = pins;
       break;
    }case 4:{
       uint8_t *p = &steps4[index];
       *p++ = pins;  
       break;    
    }case 5:{
       uint8_t *p = &steps5[index];
       *p++ = pins;
       break;      
    }
  }  
}

