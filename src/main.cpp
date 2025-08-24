#include <Arduino.h>
#include "ElroRemote.h"
#include "HomeSpan.h"
//#include "DEV_LED.h"

// Defines for readability
#define ON 1
#define OFF 0

struct CONTROL_ELRO : Service::LightBulb {               // First we create a derived class from the HomeSpan LightBulb Service
  int familyId;  
  int channelCode;                                    
  SpanCharacteristic *power;                        // here we create a generic pointer to a SpanCharacteristic named "power" that we will use below
  
  CONTROL_ELRO(int familyId,int channelCode) : Service::LightBulb(){
    power=new Characteristic::On();                 // this is where we create the On Characterstic we had previously defined in setup().  Save this in the pointer created above, for use below
    this->familyId=familyId;      
    this->channelCode=channelCode;
  }
  boolean update(){            
    remote(familyId, channelCode, power->getNewVal());
    return(true);
  }
};

void setup() {
  init();
  Serial.begin(9600);

  homeSpan.setPairingCode("11122333");
  homeSpan.setQRID("111-22-333");

  homeSpan.begin(Category::Lighting,"HomeSpan LED");
  
  new SpanAccessory(); 
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();               
  new CONTROL_ELRO(0,A_SWITCH);

  new SpanAccessory(); 
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();               
  new CONTROL_ELRO(0,B_SWITCH);

  new SpanAccessory(); 
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();               
  new CONTROL_ELRO(0,C_SWITCH);

  new SpanAccessory(); 
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();               
  new CONTROL_ELRO(0,D_SWITCH);

  new SpanAccessory(); 
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();               
  new CONTROL_ELRO(1,A_SWITCH);

  new SpanAccessory(); 
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();               
  new CONTROL_ELRO(1,B_SWITCH);

  new SpanAccessory(); 
  new Service::AccessoryInformation();    
  new Characteristic::Identify();                       
  new CONTROL_ELRO(1,C_SWITCH);                                  // ...and replaced with a single line that instantiates a second DEV_LED Service on Pin 17

  new SpanAccessory(); 
  new Service::AccessoryInformation();    
  new Characteristic::Identify();                       
  new CONTROL_ELRO(1,D_SWITCH);    
} // end of setup()

//////////////////////////////////////

void loop(){
  
  homeSpan.poll();
  
} // end of loop()