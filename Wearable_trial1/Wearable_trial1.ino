//Code learned from https://learn.adafruit.com/circuit-playground-bike-glove?view=all#caternuson-hand-position-detection

#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

#define THRESHOLD_UP        5   // threshold for hand up test
#define THRESHOLD_RIGHT     5   // threshold for right turn
#define THRESHOLD_LEFT     -5   // threshold for left turn

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, A2, NEO_GRB + NEO_KHZ800); // Declare our NeoPixel strip object:


void setup() {
  Serial.begin(9600); // Initialize serial.

  CircuitPlayground.begin(); // Initialize Circuit Playground

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {

  // check for hand up or down
  if (CircuitPlayground.motionZ() > THRESHOLD_UP) {

//    Serial.print(CircuitPlayground.motionZ());
//    NoTurnAnimation();

  } else {

    // check for right turn
    if (CircuitPlayground.motionX() > THRESHOLD_RIGHT) {
      Serial.print(CircuitPlayground.motionX());
      rightTurnAnimation();


      // check for left turn
    } else if (CircuitPlayground.motionY() < THRESHOLD_LEFT) {
      Serial.print(CircuitPlayground.motionY());
      leftTurnAnimation();

    }
  }
}

//void NoTurnAnimation() {
//  // just to be sure, turn off all NeoPixels
//  strip.show();
//
//  // turn them all off
//  for (int i = 0; i < strip.numPixels(); i++) {
//
//    strip.setPixelColor(i, strip.Color(0,   0,   0));
//    strip.show();
//    delay(2000);
//
//  }
//}

void leftTurnAnimation() {
  // just to be sure, turn off all NeoPixels
  strip.show();

  for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, strip.Color(255,   0,   0));         //  Set pixel's color (Red)
    strip.show();                          //  Update strip to match
  }

  delay(200);
  // turn them all off
  for (int i = 0; i < strip.numPixels(); i++) {

    strip.setPixelColor(i, strip.Color(0,   0,   0));
    strip.show();
    delay(2000);

  }
}

void rightTurnAnimation() {
  // just to be sure, turn off all NeoPixels
  strip.show();

  for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, strip.Color(0,   0,   255));         //  Set pixel's color (Blue)
    strip.show();                          //  Update strip to match
  }

  // wait a little bit
  delay(200);

  // turn them all off
  for (int i = 0; i < strip.numPixels(); i++) {

    strip.setPixelColor(i, strip.Color(0,   0,   0));
    strip.show();
    delay(2000);

  }

}
