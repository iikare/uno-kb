/* Arduino USB HID Keyboard Demo
 * Random Key/Random Delay
 */

uint8_t buf[8] = { 
  0 }; 	/* Keyboard report buffer */

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  delay(200);
}

void loop() {
  int RChar = random(4, 130);
  long RDel = random(1000, 10000);

  delay(RDel);

  buf[2] = RChar;
  Serial.write(buf, 8);
  EndPress();
}

void EndPress() {
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);
}