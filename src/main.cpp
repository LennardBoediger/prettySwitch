#include <Arduino.h>
#include "ElroRemote.h"
#include "HomeSpan.h"   
#include "LED.h"
#include "DEV_RELAY.h"

// Defines for readability
#define ON 1
#define OFF 0


void setup() {
  init();
  Serial.begin(9600);

  homeSpan.setPairingCode("11122333");
  homeSpan.setQRID("111-22-333");

  homeSpan.begin(Category::Bridges, "HomeSpan Bridge");
       

  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
    new LED(15); 

   
  // Accessory 2: Relay Switch
  new SpanAccessory();
    new Service::AccessoryInformation();    
      new Characteristic::Identify();                       
    new DEV_RELAY(17);  // instantiates a new relay
}

void loop() {
  
  homeSpan.poll();

}