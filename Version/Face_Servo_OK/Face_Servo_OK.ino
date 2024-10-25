
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <ESP32Servo.h>
#include "bitmap_face_robot.h"
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
  Serial.begin(9600);
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
}

 
void loop() {



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

  