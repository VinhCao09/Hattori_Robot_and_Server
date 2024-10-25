#include <ESP32Servo.h>

Servo neck;  
Servo head;  

int pos = 0;    // variable to store the servo position
int servoHead = 18;
int servoNeck = 19;


void setup() {
	head.attach(servoHead, 1000, 2000); 
  neck.attach(servoNeck, 1000, 2000);
}

void loop() {

	for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
		// in steps of 1 degree
		head.write(pos);    
		delay(15);   
  }          
	for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
		head.write(pos);    
		delay(15);           
	}
  	for (pos = 0; pos <= 180; pos += 1) { 
		neck.write(pos);   
		delay(15);            
	}
	for (pos = 180; pos >= 0; pos -= 1) { 
		neck.write(pos);    
		delay(15);
  }            
}

