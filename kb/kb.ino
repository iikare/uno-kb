#define PIN_KEYSWITCH 7
#define ITEM_F7 0x40

uint8_t buf[8] = {0};

void setup(){
  Serial.begin(9600);

  pinMode(PIN_KEYSWITCH, INPUT);
  digitalWrite(PIN_KEYSWITCH, 1);

  delay(200);
}

void loop(){
  if(digitalRead(PIN_KEYSWITCH) != 1) {
    buf[2] = ITEM_F7;

    Serial.write(buf, 8);
  }
  else{
  	endstroke();
  }
}

void endstroke(){
  buf[0] = 0;
  buf[2] = 0;

  Serial.write(buf, 8);

  delay(25);
}