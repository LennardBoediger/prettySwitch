
#ifndef ELRO_REMOTE_H
#define ELRO_REMOTE_H

#include <Arduino.h>


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
void remote(int familyId, int channelCode, int deviceStatus);

// broadcast to all devices of the given familyId
// familyId:
//    {0, 1, 1, 1, 1}  // Device 0
//    {1, 0, 1, 1, 1}  // Device 1
//    {1, 1, 0, 1, 1}  // Device 2
//    {1, 1, 1, 0, 1}  // Device 3
// deviceStatus: ON or OFF
void broadcast(int familyId, int deviceStatus);

#endif // ELRO_REMOTE_H
