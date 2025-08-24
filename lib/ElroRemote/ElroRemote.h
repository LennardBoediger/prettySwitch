
#ifndef ELRO_REMOTE_H
#define ELRO_REMOTE_H

#include <Arduino.h>

// These preprocessor macros define readable aliases for the device Status
#define ON 1
#define OFF 0

// Chanel settings are defined as bitwise values to be used in a mask.
#define A_SWITCH 1
#define B_SWITCH 2
#define C_SWITCH 4
#define D_SWITCH 8

// Use this GPIO for connecting the FS1000A 
#define FS1000A_DATA_PIN 2

// --- Function Prototypes ---
void init();
int clearBit(int N, int K);
// familyId:
//    {0, 1, 1, 1, 1}  // Device 0
//    {1, 0, 1, 1, 1}  // Device 1
//    {1, 1, 0, 1, 1}  // Device 2
//    {1, 1, 1, 0, 1}  // Device 3
// chanelCode: A_SWITCH or B_SWITCH  or C_SWITCH or  D_SWITCH 
// deviceStatus: ON or OFF
void remote(int familyId, int chanelCode, int deviceStatus);

#endif // ELRO_REMOTE_H
