
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <ESP32Servo.h>
#include "bitmap_face_robot.h"
#include "DFRobotDFPlayerMini.h"
#if (defined(ARDUINO_AVR_UNO) || defined(ESP8266))   // Using a soft serial port
#include <SoftwareSerial.h>
SoftwareSerial softSerial(/*rx =*/4, /*tx =*/5);
#define FPSerial softSerial;
#else
#define FPSerial Serial1
#endif
DFRobotDFPlayerMini myDFPlayer;

#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
//#define i2c_Address 0x3d //initialize with the I2C addr 0x3D Typically Adafruit OLED's

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Servo neck;  
Servo head;  

int pos = 0;    // variable to store the servo position
int servoHead = 18;
int servoNeck = 19;



const uint8_t* bitmaps[] = {
  image_data_EYES_SLEEParray,
  image_data_EYES_TIREDarray,
  image_data_EYES_CROSSEDarray,
  image_data_EYES_FRONTarray,
  image_data_EYES_RIGHTarray,
  image_data_EYES_FRONTarray,
  image_data_EYES_LEFTarray,
  image_data_EYES_FRONTarray,
  image_data_EYES_NARROWarray,
  image_data_EYES_FRONTarray,
  image_data_EYES_GLAREarray,
  image_data_EYES_MADarray,
  image_data_EYES_DISTRESSEDarray,
  image_data_EYES_CRYarray,
  image_data_EYES_GLASSESarray,
  image_data_EYES_CROSSEDarray,
  image_data_EYES_UParray,
  image_data_EYES_RIGHT_UParray,
  image_data_EYES_RIGHTarray,
  image_data_EYES_RIGHT_DOWNarray,
  image_data_EYES_DOWNarray,
  image_data_EYES_LEFT_DOWNarray,
  image_data_EYES_LEFTarray,
  image_data_EYES_LEFT_UParray,
  image_data_EYES_UParray,
  image_data_EYES_FRONTarray,
  image_data_CONFUSSED_1array,
  image_data_EYES_FRONTarray,
  image_data_CONFUSSED_2array,
  image_data_EYES_FRONTarray,
  image_data_EYES_NARROWarray,
  image_data_BLINK_UPPERarray,
  image_data_EYES_NIGHTarray,
  image_data_UPPER_LIDSarray,
  image_data_EYES_TIREDarray,
  image_data_LOWER_LIDSarray,
  image_data_EYES_MADarray
};


unsigned long previousMillis = 0, previousMillisServo = 0;
int currentIndex = 0;
 
void setup() {
  FPSerial.begin(9600, SERIAL_8N1, /*rx =*/26, /*tx =*/27);
  Serial.begin(115200);
  display.begin(i2c_Address, true); 
  delay(300); // Pause for 2 seconds

// Clear the buffer.
  display.clearDisplay();
  display.drawBitmap(0, 0, logo_codingninja_array, 128, 64, 1);
  display.display();
  delay(3000);
  // Clear the buffer.
  display.clearDisplay();
// Draw W01 WORD_HELLO bitmap on the screen
  display.drawBitmap(0, 0, image_data_WORD_HELLOarray, 128, 64, 1);
  display.display();
  delay(2500);
  head.attach(servoHead, 1000, 2000); 
  neck.attach(servoNeck, 1000, 2000);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(FPSerial, /*isACK = */true, /*doReset = */true)) {  //Use serial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(20);  //Set volume value. From 0 to 30
  myDFPlayer.play(1); //Say "Xin chao"
  delay(1500);
  myDFPlayer.play(3); //Say "rat vui duoc gap ban"
  delay(2000);
}

 
void loop() {

  static unsigned long timer = millis();
  
  if (millis() - timer > 200000) {
    timer = millis();
    myDFPlayer.next();  //Play next mp3 every 3 second.
  }

unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= 700) {
    previousMillis = currentMillis;

    // Move to the next bitmap
    currentIndex++;
    Serial.println(currentIndex);
    
    // // Restart if we reached the end of the bitmaps array
    if (currentIndex >= sizeof(bitmaps) / sizeof(bitmaps[0])) {
      currentIndex = 0;
    }
  }
    
    // Clear the buffer and draw the next bitmap
    display.clearDisplay();
    display.drawBitmap(0, 0, bitmaps[currentIndex], 128, 64, 1);
    display.display();
  // Servo control code here, non-blocking if needed
  // Example for head servo
  static int pos = 0;
  static bool increasing = true;

  if (currentMillis - previousMillisServo >= 15) {
    previousMillisServo = currentMillis;
    if (increasing) {
      pos++;
      if (pos >= 180) {
        increasing = false;
      }
    } else {
      pos--;
      if (pos <= 0) {
        increasing = true;
      }
    }
    head.write(pos);
    	neck.write(pos);   
  }
}

  