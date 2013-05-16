/*
look up tables for board numbers and shift register index to be used for the Stepper_Shift class and WS2801_Soft class.
table below outlines the way the display is physically layed out due to the way the motors and LEDs are wired to each board:
formatted - BOARD.INDEX

     x-   0    1    2     3    4    5     6    7    8
 y  0    1.2  1.1  1.0 | 2.2  2.1  2.0 | 3.2  3.1  3.0
    1    1.5  1.5  1.3 | 2.5  2.4  2.3 | 3.5  3.4  3.3
    2    1.8  1.7  1.6 | 2.8  2.7  2.6 | 3.8  3.7  3.6
    3    ----------------------------------------------
    4    4.2  4.1  4.0 | 5.2  5.1  5.0 | 6.2  6.1  6.0
    5    4.5  4.4  4.3 | 5.5  5.4  5.3 | 6.5  6.4  6.3
    6    4.8  4.7  4.6 | 5.8  5.7  5.6 | 6.8  6.7  6.6



*/


int boardLUT[9][6] = { {2, 5, 8, 2, 5, 8},
                       {1, 4, 7, 1, 4, 7},
                       {0, 3, 6, 0, 3, 6},
                       {2, 5, 8, 2, 5, 8},
                       {1, 4, 7, 1, 4, 7},
                       {0, 3, 6, 0, 3, 6},
                       {2, 5, 8, 2, 5, 8},
                       {1, 4, 7, 1, 4, 7},
                       {0, 3, 6, 0, 3, 6} };
                       
int indexLUT[9][6] = { {1, 1, 1, 4, 4, 4},
                       {1, 1, 1, 4, 4, 4},
                       {1, 1, 1, 4, 4, 4},
                       {2, 2, 2, 5, 5, 5},
                       {2, 2, 2, 5, 5, 5},
                       {2, 2, 2, 5, 5, 5},
                       {3, 3, 3, 6, 6, 6} };
