
#include <ESP32Servo.h>

// create four servo objects 
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
// Published values for SG90 servos; adjust if needed
int minUs = 1000;
int maxUs = 2000;

// These are all GPIO pins on the ESP32
// Recommended pins include 2,4,12-19,21-23,25-27,32-33
// for the ESP32-S2 the GPIO pins are 1-21,26,33-42
int servo1Pin = 15;
int servo2Pin = 16;
int servo3Pin = 14;
#if defined(ARDUINO_ESP32S2_DEV)
int servo4Pin = 13;
#else
int servo4Pin = 32;
#endif
int servo5Pin = 4;

int pos = 0;      // position in degrees
ESP32PWM pwm;
void setup() {
	// Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	Serial.begin(115200);
	servo1.setPeriodHertz(50);      // Standard 50hz servo
	servo2.setPeriodHertz(50);      // Standard 50hz servo
	servo3.setPeriodHertz(330);      // Standard 50hz servo
	servo4.setPeriodHertz(200);      // Standard 50hz servo
	//servo5.setPeriodHertz(50);      // Standard 50hz servo


}

void loop() {
	servo1.attach(servo1Pin, minUs, maxUs);
	servo2.attach(servo2Pin, minUs, maxUs);
#if defined(ARDUINO_ESP32S2_DEV)
	pwm.attachPin(37, 10000);//10khz
#else
	pwm.attachPin(27, 10000);//10khz
#endif
	servo3.attach(servo3Pin, minUs, maxUs);
	servo4.attach(servo4Pin, minUs, maxUs);

	//servo5.attach(servo5Pin, minUs, maxUs);


	for (pos = 0; pos <= 180; pos += 1) { // sweep from 0 degrees to 180 degrees
		// in steps of 1 degree
		servo1.write(pos);
		delay(1);             // waits 20ms for the servo to reach the position
	}
	for (pos = 180; pos >= 0; pos -= 1) { // sweep from 180 degrees to 0 degrees
		servo1.write(pos);
		delay(1);
	}

	for (pos = 0; pos <= 180; pos += 1) { // sweep from 0 degrees to 180 degrees
		// in steps of 1 degree
		servo2.write(pos);
		delay(1);             // waits 20ms for the servo to reach the position
	}
	for (pos = 180; pos >= 0; pos -= 1) { // sweep from 180 degrees to 0 degrees
		servo2.write(pos);
		delay(1);
	}

	for (pos = 0; pos <= 180; pos += 1) { // sweep from 0 degrees to 180 degrees
		// in steps of 1 degree
		servo3.write(pos);
		delay(1);             // waits 20ms for the servo to reach the position
	}
	for (pos = 180; pos >= 0; pos -= 1) { // sweep from 180 degrees to 0 degrees
		servo3.write(pos);
		delay(1);
	}

	for (pos = 0; pos <= 180; pos += 1) { // sweep from 0 degrees to 180 degrees
		// in steps of 1 degree
		servo4.write(pos);
		delay(1);             // waits 20ms for the servo to reach the position
	}
	for (pos = 180; pos >= 0; pos -= 1) { // sweep from 180 degrees to 0 degrees
		servo4.write(pos);
		delay(1);
	}
	for (pos = 0; pos <= 180; pos += 1) { // sweep from 0 degrees to 180 degrees
		// in steps of 1 degree
		servo5.write(pos);
		delay(1);             // waits 20ms for the servo to reach the position
	}
	for (pos = 180; pos >= 0; pos -= 1) { // sweep from 180 degrees to 0 degrees
		servo5.write(pos);
		delay(1);
	}
	servo1.detach();
	servo2.detach();;
	servo3.detach();
	servo4.detach();
	pwm.detachPin(27);

	delay(5000);

}

