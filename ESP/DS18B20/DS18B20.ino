#include <DallasTemperature.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(){
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);
sensors.begin();
}

void loop(){
sensors.requestTemperatures();
float Temp = sensors.getTempCByIndex(0);
Serial.println(Temp);

if(Temp<23){
  digitalWrite(13,HIGH);
}
else if(Temp>=23 && Temp<25){
  digitalWrite(12,HIGH);
}
else if(Temp>=25){
  digitalWrite(11,HIGH);
}
}
