

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

class WS2801_Soft2 {

 public:
  WS2801_Soft2(uint8_t dpin0,  uint8_t dpin1, uint8_t dpin2, uint8_t cpin),
  WS2801_Soft2(uint8_t dpin0,  uint8_t dpin1, uint8_t dpin2, uint8_t dpin3, uint8_t dpin4, uint8_t dpin5, uint8_t cpin),
  WS2801_Soft2(uint8_t dpin0,  uint8_t dpin1, uint8_t dpin2, uint8_t dpin3, uint8_t dpin4, uint8_t dpin5, uint8_t dpin6, uint8_t dpin7, uint8_t dpin8, uint8_t cpin); // Configurable pins

  void
    begin(void),
    show(void),
    setPixelColor(uint16_t index, uint16_t board, uint32_t c),
    setPixelColor(uint16_t n, uint16_t board, uint8_t r, uint8_t g, uint8_t b),
    updatePins(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t cpin), // Change pins, configurable
    updatePins(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t dpin3, uint8_t dpin4, uint8_t dpin5, uint8_t cpin),
    updatePins(uint8_t dpin0, uint8_t dpin1, uint8_t dpin2, uint8_t dpin3, uint8_t dpin4, uint8_t dpin5, uint8_t dpin6, uint8_t dpin7, uint8_t dpin8, uint8_t cpin);

 private:

  uint16_t
    numLEDs,
    numBoards;
  uint8_t
    *pixels0, // Holds color values for each LED (3 bytes each)
    *pixels1,
    *pixels2,
    *pixels3,
    *pixels4,
    *pixels5,
    *pixels6,
    *pixels7,
    *pixels8,
    clkpin , 
    datapin0,     // Clock & data pin numbers
    datapin1,
    datapin2,
    datapin3,
    datapin4,
    datapin5,
    datapin6,
    datapin7,
    datapin8,
    clkpinmask, 
    datapinmask0, // Clock & data PORT bitmasks
    datapinmask1,
    datapinmask2,
    datapinmask3,
    datapinmask4,
    datapinmask5,
    datapinmask6,
    datapinmask7,
    datapinmask8;
    
  volatile uint8_t
    *clkport  , 
    *dataport0,
    *dataport1,
    *dataport2,
    *dataport3,
    *dataport4,
    *dataport5,
    *dataport6,
    *dataport7,
    *dataport8;   // Clock & data PORT registers
  void
    alloc(uint16_t n);
};


