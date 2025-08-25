#include <Arduino.h>
#include "ElroRemote.h"
#include "HomeSpan.h"
//#include "DEV_LED.h"

// Defines for readability
#define ON 1
#define OFF 0

struct CONTROL_ELRO : Service::LightBulb {
  int familyId;  
  int channelCode;                                    
  SpanCharacteristic *power;
  
  CONTROL_ELRO(int familyId,int channelCode) : Service::LightBulb(){
    power=new Characteristic::On();
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

  homeSpan.begin(Category::Bridges,"HomeSpan LED");
  new SpanAccessory();                            // This first Accessory is the new "Bridge" Accessory.  It contains no functional Services, just the Accessory Information Service
  new Service::AccessoryInformation();
  new Characteristic::Identify();  

  new SpanAccessory();
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();
  new Characteristic::Name("0 A");            
  new CONTROL_ELRO(0,A_SWITCH); 

  new SpanAccessory(); 
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();  
  new Characteristic::Name("0 B");                  
  new CONTROL_ELRO(0,B_SWITCH);

  new SpanAccessory(); 
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();   
  new Characteristic::Name("0 C");                 
  new CONTROL_ELRO(0,C_SWITCH);

  new SpanAccessory(); 
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();   
  new Characteristic::Name("0 D");                 
  new CONTROL_ELRO(0,D_SWITCH);

  new SpanAccessory();
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();
  new Characteristic::Name("1 A");            
  new CONTROL_ELRO(1,A_SWITCH); 

  new SpanAccessory(); 
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();  
  new Characteristic::Name("1 B");                  
  new CONTROL_ELRO(1,B_SWITCH);

  new SpanAccessory(); 
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();   
  new Characteristic::Name("1 C");                 
  new CONTROL_ELRO(1,C_SWITCH);

  new SpanAccessory(); 
  new Service::AccessoryInformation(); 
  new Characteristic::Identify();   
  new Characteristic::Name("1 D");                 
  new CONTROL_ELRO(1,D_SWITCH);
}

void loop(){
  homeSpan.poll();
}