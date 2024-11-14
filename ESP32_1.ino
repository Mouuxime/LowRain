#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);                 
  mySwitch.enableReceive(21);         
}

void loop() {
  if (mySwitch.available()) {          //Check if a message is received
    int receivedValue = mySwitch.getReceivedValue();
    
    if (receivedValue == 0) {
      Serial.println("Signal not recognized"); //Message if the signal isn't recognized
    } else {
      Serial.print("Signal received : ");
      Serial.println(receivedValue);         //Display signal in monitoring
    }
    
    mySwitch.resetAvailable();          //Reset to capture next signal
  }
}
