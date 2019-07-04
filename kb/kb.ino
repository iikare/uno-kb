#define PIN_KEYSWITCH 7
#define ITEM_F7 0x40

uint8_t buf[8] = {0};
static unsigned int init_timer = 0;
static int run_counter = 0;
static bool timeout = false;

void setup(){
	Serial.begin(9600);

	pinMode(PIN_KEYSWITCH, INPUT);
	digitalWrite(PIN_KEYSWITCH, 1);

	delay(100);
}

void loop(){
	init_timer = (millis() % 500);

	if(!timeout){
		if(digitalRead(PIN_KEYSWITCH) != 1) {
			run_counter++;
			buf[2] = ITEM_F7;

			Serial.write(buf, 8);
		}
		else{
			endstroke();
		}
 	}

	if(run_counter >= 3){
		timeout = true;
		run_counter = 0;
		if(buf[2] == ITEM_F7){
			endstroke();
		}
	}

	if(init_timer == 0){
		timeout = false;
	}

}

void endstroke(){
	buf[0] = 0;
	buf[2] = 0;

	Serial.write(buf, 8);

	delay(25);
}