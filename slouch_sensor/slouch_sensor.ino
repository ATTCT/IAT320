
//code is learned from https://learn.adafruit.com/circuit-playground-slouch-detector/slouch-detector-v3

#include <Adafruit_CircuitPlayground.h>

#define SLOUCH_ANGLE        10.0      // allowable slouch angle (deg)
#define SLOUCH_TIME         3000      // allowable slouch time (secs) 
#define GRAVITY             9.80665   // standard gravity (m/s^s)
#define RAD2DEG             52.29578  // convert radians to degrees

float currentAngle;
float targetAngle;
unsigned long slouchStartTime;
bool slouching;


void setup() {

  Serial.begin(9600); // initialize serial.

  // Initialize Circuit Playground
  CircuitPlayground.begin();

  // Initialize target angle to zero.
  targetAngle = 0;
}


void loop() {
  // Compute current angle
  currentAngle = RAD2DEG * asin(-CircuitPlayground.motionZ() / GRAVITY);

  // Set target angle on button press
  if (CircuitPlayground.leftButton()) {
    targetAngle = currentAngle;
    CircuitPlayground.playTone(900, 100);
    delay(100);
    CircuitPlayground.playTone(900, 100);
    delay(100);
  }

  //set Timer
  if (CircuitPlayground.rightButton()) {
    CircuitPlayground.playTone(900, 100);
    delay(100);
    CircuitPlayground.playTone(900, 100);
    delay(10000);
    for (int pixel = 0; pixel < 10; pixel++) {
      CircuitPlayground.setPixelColor(pixel, 255, 0, 0); //trun on all Neopixels to red when times up
      delay(50);
    }
    // Play a tone
    CircuitPlayground.playTone(800, 500);
    delay(10);
    CircuitPlayground.playTone(800, 500);
    delay(10);
    CircuitPlayground.playTone(800, 500);
  } else {
    for (int pixel = 0; pixel < 10; pixel++) {
      CircuitPlayground.setPixelColor(pixel, 0, 0, 0); //trun off all Neopixels if no action applied
      delay(10);
    }
  }
  // Check for slouching
  if (currentAngle - targetAngle > SLOUCH_ANGLE) {
    if (!slouching) slouchStartTime = millis();
    slouching = true;
  } else {
    slouching = false;
  }

  // If we are slouching
  if (slouching) {
    // Check how long we've been slouching
    if (millis() - slouchStartTime > SLOUCH_TIME) {
      for (int pixel = 0; pixel < 10; pixel++) {
        CircuitPlayground.setPixelColor(pixel, 255, 0, 0); //trun on all Neopixels to red if detected slouching
        delay(50);
      }
      // Play a tone
      CircuitPlayground.playTone(800, 500);
    }
  } else {
    for (int pixel = 0; pixel < 10; pixel++) {
      CircuitPlayground.setPixelColor(pixel, 0, 0, 0); //trun off all Neopixels if not detected slouching
      delay(10);
    }
  }
}
