#include <Arduino.h>
#include "ElroRemote.h"
#include "HomeSpan.h"
#include "DEV_LED.h"

// Defines for readability
#define ON 1
#define OFF 0



void setup() {
  init();
  Serial.begin(9600);

  homeSpan.setPairingCode("11122333");
  homeSpan.setQRID("111-22-333");

  homeSpan.begin(Category::Lighting,"HomeSpan LED");
  
  new SpanAccessory(); 
  
    new Service::AccessoryInformation(); 
      new Characteristic::Identify();  //  In Example 2 we instantiated a LightBulb Service and its "On" Characteristic here.  We are now going to replace these two lines (by commenting them out)...

  //  new Service::LightBulb();                   
  //    new Characteristic::On();                 

  // ...with a single new line instantiating a new class we will call DEV_LED():

    new DEV_LED(16);        // this instantiates a new LED Service.  Where is this defined?  What happpened to Characteristic::On?  Keep reading...

  // The full definition and code for DEV_LED is implemented in a separate file called "DEV_LED.h" that is specified using the #include at the top of this program.
  // The prefix DEV_ is not required but it's a helpful convention when naming all your device-specific Services. Note that DEV_LED will include all the required
  // Characterictics of the Service, so you DO NOT have to separately instantiate Characteristic::On --- everything HomeSpan needs for DEV_LED should be implemented
  // in DEV_LED itself (though it's not all that much).  Finally, note that we created DEV_LED to take a single integer argument.  If you guessed this is
  // the number of the Pin to which you have attached an LED, you'd be right.  See DEV_LED.h for a complete explanation of how it works.

  new SpanAccessory(); 
  
    new Service::AccessoryInformation();    
      new Characteristic::Identify();                       

  //  new Service::LightBulb();                       // Same as above, this line is deleted...
  //    new Characteristic::On();                     // This line is also deleted...
  
    new DEV_LED(17);                                  // ...and replaced with a single line that instantiates a second DEV_LED Service on Pin 17

} // end of setup()

//////////////////////////////////////

void loop(){
  
  homeSpan.poll();
  
} // end of loop()