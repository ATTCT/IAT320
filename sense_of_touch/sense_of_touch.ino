//Codes were inspired from the lab

#include <Adafruit_CircuitPlayground.h>

void setup() {
  Serial.begin(9600); // initialize serial.

  CircuitPlayground.begin(); // initialize Circuit Playground library.
}

void loop() { 

  CircuitPlayground.speaker.enable(false); // set the speaker to off 

  int x = CircuitPlayground.readCap(6); // set x as the digits from A1
  int pixel; // set pixel as int
  if (x > 1015) { // if x is greater than 1015, the speaker will turn on and change Neopixels 0 to 4 in to red color & Neopixels 5 to 9 in to blue color. And it will play 2 tones for different duration


    CircuitPlayground.speaker.enable(true);

    CircuitPlayground.setPixelColor(0, 255, 0, 0);
    CircuitPlayground.setPixelColor(1, 255, 0, 0);
    CircuitPlayground.setPixelColor(2, 255, 0, 0);
    CircuitPlayground.setPixelColor(3, 255, 0, 0);
    CircuitPlayground.setPixelColor(4, 255, 0, 0);

    CircuitPlayground.playTone(494, 300);

    CircuitPlayground.setPixelColor(5, 0, 128, 255);
    CircuitPlayground.setPixelColor(6, 0, 128, 255);
    CircuitPlayground.setPixelColor(7, 0, 128, 255);
    CircuitPlayground.setPixelColor(8, 0, 128, 255);
    CircuitPlayground.setPixelColor(9, 0, 128, 255);

    CircuitPlayground.playTone(523, 100);

  }

  if (x > 1000) { // if x is greater than 1000, it will run a for loop and set all neopixels to no color.

    for (int pixel = 0; pixel < 10; pixel++) {

      CircuitPlayground.setPixelColor(pixel, 0, 0, 0);


      delay(10);
    }

  }

  int y = CircuitPlayground.readCap(9); // set x as the digits from A2
  if (y > 1015) { // if y is greater than 1015, the speaker will turn on and change all Neopixels to yellow. And it will play 2 tones with different durations.
    CircuitPlayground.speaker.enable(true);
    Serial.print(y);
    Serial.print(" ");

    for (int pixel = 0; pixel < 10; pixel++) {
      CircuitPlayground.setPixelColor(pixel, 255, 255, 0);
      delay(50);

    }

    CircuitPlayground.playTone(400, 100);
    delay(150);
    CircuitPlayground.playTone(400, 50);
    delay(150);
  }

  if (y > 1000) { // if y is greater than 1000, it will run a for loop and set all neopixels to no color.

    for (int pixel = 0; pixel < 10; pixel++) {

      CircuitPlayground.setPixelColor(pixel, 0, 0, 0);


      delay(10);
    }

  }


}
