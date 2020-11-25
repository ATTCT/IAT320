//Code learned from https://learn.adafruit.com/circuit-playground-bike-glove?view=all#caternuson-hand-position-detection

#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

#define THRESHOLD_UP        5   // threshold for hand up test
#define THRESHOLD_RIGHT     5   // threshold for right turn
#define THRESHOLD_LEFT     -5   // threshold for left turn

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, A2, NEO_GRB + NEO_KHZ800); // Declare the NeoPixel strip object:


void setup() {
  Serial.begin(9600); // Initialize serial.
  CircuitPlayground.begin(); // Initialize Circuit Playground
  strip.begin();           // INITIALIZE NeoPixel strip object
  strip.show();            // Turn OFF all pixels
  strip.setBrightness(255); // Set brightness to 255
}

void loop() {
  if (CircuitPlayground.motionZ() > THRESHOLD_UP) { // check for hand up or down

  } else {
    if (CircuitPlayground.motionX() > THRESHOLD_RIGHT) {  // check for right turn

      rightTurnAnimation();

    } else if (CircuitPlayground.motionY() < THRESHOLD_LEFT) {  // check for left turn

      leftTurnAnimation();

    }
  }
}


void leftTurnAnimation() {
  
  strip.show(); // turn off all NeoPixels

  for (int i = 0; i < 6; i++) { // For first 6 neopixels in strip...
    strip.setPixelColor(i, strip.Color(255,   0,   0));         //  Set pixel's color (Red)
    strip.show();                          //  Update strip to match
  }

  delay(200);

  // turn them all off one by one
  for (int i = 0; i < 6; i++) {

    strip.setPixelColor(i, strip.Color(0,   0,   0));
    strip.show();
    delay(2000);

  }
}

void rightTurnAnimation() {
  strip.show(); //turn off all NeoPixels

  for (int j = 6; j < 12; j++) { // For 7 to 12 neopixels in strip...
    strip.setPixelColor(j, strip.Color(0,   0,   255));         //  Set pixel's color (Blue)
    strip.show();                          //  Update strip to match
  }

  delay(200);

  // turn them all off
  for (int j = 6; j < 12; j++) {

    strip.setPixelColor(j, strip.Color(0,   0,   0));
    strip.show();
    delay(2000);

  }

}
