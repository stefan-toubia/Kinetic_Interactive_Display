Kinetic-Interactive-Display

This is the code to run the Kinetic Interactive Display. Code by Stefan Toubia K.I.D. designed by Stefan Toubia, Nur Alkas, Johnny Araujo

K.I.D. is an mechatronic version of the classic pin art toy. An array of 81 small linear actuators with RGB LEDs (Pixels) is controlled from downsampled RGB+D data from a Microsoft Kinect 3D camera. THe linear actuator is composed of a 3D printed body and gear rack, 15mm bipolar stepper motor, and two small injection moulded toy gears. The display is composed of 9 identical 3x3 pixel modules, each with their own driver circuit PCB. Each driver circuit contains 9 dual h-bridge motor drivers (DRV8833) and 9 RGB LED drivers (WS2801). The motor drivers are controlled with 5 signals, 1A, 1B, 2A, 2B, and power save. The 9 drivers on a single board are interfaced with a string of 6 8-bit shift registers (74HC595) in order to be controlled via serial, reducing the required number of control signals from 45 to 3 (Serial data, Shift Register Clock, Register Clock). LED Drivers are chained and controlled via a 2-wire serial interface (Data, Clock).

The K.I.D. is a senior design project for the George Washington University school of Engineering department of Electical and Computer Engineering. Faculty mentor is Professor Can Korman, Associate Dean of Research and Graduate Studies.
