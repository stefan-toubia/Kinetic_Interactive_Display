#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
//Board = Arduino Mega 2560 or Mega ADK
#define __AVR_ATmega2560__
#define ARDUINO 104
#define __AVR__
#define F_CPU 16000000L
#define __cplusplus
#define __attribute__(x)
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__
#define __builtin_va_list
#define __builtin_va_start
#define __builtin_va_end
#define __DOXYGEN__
#define prog_void
#define PGM_VOID_P int
#define NOINLINE __attribute__((noinline))

typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {;}

//
//
void calculate_delays();
void time_steps();
void homing();
void clearRegisters();
void writeRegisters();
void setRegisterPin(int index, int value);
void create_shift_pattern();
void get_serial();
void roll_over_index();
void copy_data();
void next_frame();
void generate_sine();
void generate_sine_frame();
void print_current_step();
void print_sine();
void print_next_position();

#include "C:\Program Files\Arduino\arduino-1.0.4\hardware\arduino\variants\mega\pins_arduino.h" 
#include "C:\Program Files\Arduino\arduino-1.0.4\hardware\arduino\cores\arduino\arduino.h"
#include "C:\Users\Stefan\Documents\Arduino\Kinetic_Interactive_Display\Kinetic_Interactive_Display.ino"
#include "C:\Users\Stefan\Documents\Arduino\Kinetic_Interactive_Display\MotionPlanning.ino"
#include "C:\Users\Stefan\Documents\Arduino\Kinetic_Interactive_Display\Output.ino"
#include "C:\Users\Stefan\Documents\Arduino\Kinetic_Interactive_Display\RX.ino"
#include "C:\Users\Stefan\Documents\Arduino\Kinetic_Interactive_Display\TestValues.ino"
#include "C:\Users\Stefan\Documents\Arduino\Kinetic_Interactive_Display\debug.ino"
#include "C:\Users\Stefan\Documents\Arduino\Kinetic_Interactive_Display\def.h"
#include "C:\Users\Stefan\Documents\Arduino\Kinetic_Interactive_Display\pins.h"
#include "C:\Users\Stefan\Documents\Arduino\Kinetic_Interactive_Display\testValues.h"
#endif
