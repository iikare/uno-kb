#include "kb.h"

int pinstate = 1;
uint8_t buf[8] = { 0 };

void setup(){
  Serial.begin(9600);
  
  pinMode(PIN_SPECIAL, INPUT);
  digitalWrite(PIN_SPECIAL, 1);

  delay(200);
}

void loop(){
  if(digitalRead(PIN_SPECIAL) != 1){
    buf[2] = INPUT_F7;
    Serial.write(buf, 8);
    DeInitKey();
  }
}

void DeInitKey(){
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);
}