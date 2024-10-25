
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
int Touch = 100;


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

const uint8_t* face_when_touch[] = {
  //mat len tren
  image_data_BLINK_UPPERarray,
  image_data_EYES_NIGHTarray,
  image_data_BLINK_UPPERarray,
  image_data_EYES_NIGHTarray,
  image_data_UPPER_LIDSarray,
    image_data_EYES_NIGHTarray,

  //mat xuong duoi
  // image_data_EYES_TIREDarray,
  // image_data_LOWER_LIDSarray,
  // image_data_EYES_MADarray
};
unsigned long previousMillis = 0, previousMillisServo = 0, previousMillisSayHappy;
int currentIndex = 0;
//  unsigned long previousMillisServo = 0;
//----BIEN CHO SERVO WHEN TOUCH -------------
const int interval = 20;  // Interval at which to move the servo (milliseconds)
int targetPos = 90;
int currentPos = 90;
int stepSize = 1;  // Step size to move the servo in each interval
//----BIEN CHO SERVO WHEN TOUCH -------------
//----BIEN CHO SERVO WHEN NORMAL -------------

int targetHeadPos = 90;
int targetNeckPos = 90;
int currentHeadPos = 90;
int currentNeckPos = 90;
float headIncrement = 0.0;
float neckIncrement = 0.0;
float headStep = 0.0;
float neckStep = 0.0;
const int steps = 50;  // Number of steps for smooth interpolation
//----BIEN CHO SERVO WHEN NORMAL -------------

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
  
  myDFPlayer.volume(15);  //Set volume value. From 0 to 30
  myDFPlayer.play(1); //Say "Xin chao"
  delay(1500);
  myDFPlayer.play(3); //Say "rat vui duoc gap ban"
  delay(2000);
}

 
void loop() {

Touch = touchRead(33);
Serial.println(Touch);

  
  // if (millis() - timer > 200000) {
  //   timer = millis();
  //   myDFPlayer.next();  //Play next mp3 every 3 second.
  // }



  if(Touch<50){
  emoji_when_touch();
  // Servo_when_touch();
  }
  else{
    emoji_normal(); 
    Servo_normal();
  }

}
void emoji_normal()
{
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
};
void emoji_when_touch()
{
      unsigned long currentMillis = millis();
        
        if (currentMillis - previousMillis >= 700) {
          previousMillis = currentMillis;

          // Move to the next bitmap
          currentIndex++;
          Serial.println(currentIndex);
          
          // // Restart if we reached the end of the bitmaps array
          if (currentIndex >= sizeof(face_when_touch) / sizeof(face_when_touch[0])) {
            currentIndex = 0;
          }
        }
    display.clearDisplay();
    display.drawBitmap(0, 0, face_when_touch[currentIndex], 128, 64, 1);
    display.display();
    //------Say happy--------
         if (currentMillis - previousMillisSayHappy >= 3000) {
          previousMillisSayHappy = currentMillis;
          myDFPlayer.play(7); 
        }
     //------Say happy--------
};
  
// void Servo_normal()
// {
//   static int pos = 90;
//   unsigned long currentMillis = millis();

// head.write(pos);
//   neck.write(pos);  
  
// };
void updateTargetPositions() {
  targetHeadPos = random(0, 180);  // Random target position for head servo
  targetNeckPos = random(0, 180);  // Random target position for neck servo

  headStep = (targetHeadPos - currentHeadPos) / (float)steps;
  neckStep = (targetNeckPos - currentNeckPos) / (float)steps;
}

void Servo_normal() {
  unsigned long currentMillis = millis();

  // Change target positions at defined intervals
  if (currentMillis - previousMillisServo >= 3000) {
    previousMillisServo = currentMillis;
    updateTargetPositions();
  }

  // Smoothly move towards target positions
  if (abs(currentHeadPos - targetHeadPos) > abs(headStep)) {
    currentHeadPos += headStep;
  } else {
    currentHeadPos = targetHeadPos;
  }

  if (abs(currentNeckPos - targetNeckPos) > abs(neckStep)) {
    currentNeckPos += neckStep;
  } else {
    currentNeckPos = targetNeckPos;
  }

  // Write positions to servos
  head.write(currentHeadPos);
  neck.write(currentNeckPos);

  // Delay for smoother transition
  delay(20);
}

void Servo_when_touch() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisServo >= interval) {
    previousMillisServo = currentMillis;

    if (currentPos != targetPos) {
      if (currentPos < targetPos) {
        currentPos += stepSize;
        if (currentPos > targetPos) currentPos = targetPos;
      } else {
        currentPos -= stepSize;
        if (currentPos < targetPos) currentPos = targetPos;
      }
      head.write(currentPos);
    } else {
      // Update target position every 1500 milliseconds
      static unsigned long lastUpdate = 0;
      if (currentMillis - lastUpdate >= 1500) {
        lastUpdate = currentMillis;
        targetPos = random(7, 110);
      }
    }
  }
  neck.write(90);
}