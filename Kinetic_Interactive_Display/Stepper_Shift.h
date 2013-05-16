#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

class Stepper_Shift {
  
  public:
    Stepper_Shift(uint8_t dpin0, uint8_t rclk, uint8_t srclk),
    Stepper_Shift(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t rclk, uint8_t srclk),
    Stepper_Shift(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t dpin3, uint8_t dpin4, uint8_t dpin5, uint8_t rclk, uint8_t srclk);
  void 
    begin(void),
    writeOut(void),
    writeRegisters(void),
    createShiftPattern(uint8_t board, uint8_t stp),
    initPins(uint8_t dpin0, uint8_t rclk,  uint8_t srclk),
    setMotorPins(uint8_t index, uint8_t board, uint8_t pins),
    initPins(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t rclk,  uint8_t srclk),
    initPins(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t dpin3, uint8_t dpin4, uint8_t dpin5, uint8_t rclk, uint8_t srclk);
    
  private:
    uint16_t
      numBoards;
    uint8_t
      *steps0,
      *steps1,
      *steps2,
      *steps3,
      *steps4,
      *steps5,
      rclkpin,
      srclkpin,
      datapin0,
      datapin1,
      datapin2,
      datapin3,
      datapin4,
      datapin5,
      rclkpinmask,
      srclkpinmask,
      datapinmask0,
      datapinmask1,
      datapinmask2,
      datapinmask3,
      datapinmask4,
      datapinmask5;
      
    volatile uint8_t
      *rclkport,
      *srclkport,
      *dataport0,
      *dataport1,
      *dataport2,
      *dataport3,
      *dataport4,
      *dataport5;
      
    void
      alloc(uint16_t n);
      
      
      
     
    
    
    
  
  
  
};
