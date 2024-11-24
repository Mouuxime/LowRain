#include <DallasTemperature.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 25

int Bleu = 2;
int Orange = 4;
int Rouge = 17;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(){
pinMode(Bleu,OUTPUT);
pinMode(Orange,OUTPUT);
pinMode(Rouge,OUTPUT);
Serial.begin(9600);
sensors.begin();
}

void loop(){
sensors.requestTemperatures();
float Temp = sensors.getTempCByIndex(0);
Serial.println(Temp);

if(Temp<23){
  digitalWrite(Bleu,HIGH);
  digitalWrite(Orange,LOW);
  digitalWrite(Rouge,LOW);
}
else if(Temp>=23 && Temp<=25){
  digitalWrite(Bleu,LOW);
  digitalWrite(Orange,HIGH);
  digitalWrite(Rouge,LOW);

}
else if(Temp>=25){
  digitalWrite(Bleu,LOW);
  digitalWrite(Orange,LOW);
  digitalWrite(Rouge,HIGH);
}
}
