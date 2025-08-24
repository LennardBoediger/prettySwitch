#include <Arduino.h>
#include "ElroRemote.h"

// Defines for readability
#define ON 1
#define OFF 0


void setup() {
  init();
}

void loop() {
  
  remote(1, A_SWITCH, ON);
  delay(3000);
  remote(1, A_SWITCH, OFF);
  delay(3000);

}