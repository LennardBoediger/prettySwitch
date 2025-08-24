#include <Arduino.h>

// Defines for readability
#define ON 1
#define OFF 0

// chanel settings
#define A_SWITCH 1
#define B_SWITCH 2
#define C_SWITCH 4
#define D_SWITCH 8

// ELRO specific values
#define HIGH_PULSE_ENCODING 136
#define LOW_PULSE_ENCODING 142
#define SYNC_PULSE 128

// The pin the signal will be sent from
const int OUTPUT_PIN = 2;

// Global variables with descriptive names
const int FAMILY_CODE[4][5] = {
    {0, 1, 1, 1, 1},  // Device 0
    {1, 0, 1, 1, 1},  // Device 1
    {1, 1, 0, 1, 1},  // Device 2
    {1, 1, 1, 0, 1}   // Device 3
};
const int REPETITIONS = 10;
const int PULSE_LENGTH_US = 300;

int bitPattern[16];

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
}

void remote(int familyId, int chanelCode, int deviceStatus) {
  // Calculate device code
  for (int i = 0; i < 5; i++) {
    if (FAMILY_CODE[familyId][i] == 0) {
      bitPattern[i] = LOW_PULSE_ENCODING;
    } else {
      bitPattern[i] = HIGH_PULSE_ENCODING;
    }
  }

  // Calculate receiver code
  int currentBit = 1;
  for (int i = 0; i < 5; i++) {
    if ((chanelCode & currentBit) > 0) {
      bitPattern[5 + i] = HIGH_PULSE_ENCODING;
    } else {
      bitPattern[5 + i] = LOW_PULSE_ENCODING;
    }
    currentBit = currentBit << 1;
  }

  // On or Off bit
  if (deviceStatus == ON) {
    bitPattern[10] = HIGH_PULSE_ENCODING;
    bitPattern[11] = LOW_PULSE_ENCODING;
  } else {
    bitPattern[10] = LOW_PULSE_ENCODING;
    bitPattern[11] = HIGH_PULSE_ENCODING;
  }

  // Sync bits
  bitPattern[12] = SYNC_PULSE;
  bitPattern[13] = 0;
  bitPattern[14] = 0;
  bitPattern[15] = 0;

  // Send the full code multiple times for reliability
  for (int repetition = 0; repetition <= REPETITIONS; repetition++) {
    for (int i = 0; i < 16; i++) {
      int pulseCheck = SYNC_PULSE;
      for (int bitPosition = 0; bitPosition < 8; bitPosition++) {
        if ((bitPattern[i] & pulseCheck) > 0) {
          digitalWrite(OUTPUT_PIN, HIGH);
        } else {
          digitalWrite(OUTPUT_PIN, LOW);
        }
        delayMicroseconds(PULSE_LENGTH_US);
        pulseCheck = pulseCheck >> 1;
      }
    }
  }
}

void loop() {
  remote(1, A_SWITCH, ON);
  delay(3000);
  remote(1, A_SWITCH, OFF);
  delay(3000);
}