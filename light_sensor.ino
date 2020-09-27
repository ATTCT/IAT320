
#include <Adafruit_CircuitPlayground.h>

int presets[3][2][3] = { //create a array of preset colors
  {{0, 255, 0}, {255, 0, 0}},
  {{0, 0, 255}, {128, 128, 0}},
  {{255, 255, 0}, {153, 255, 51}}
};
int preset = 0;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}
void loop() {
  int light = CircuitPlayground.lightSensor();
  Serial.println(light); //To show the value collected from the light sensor

  if (light > 100) { //If the value from the light sensor is more than 100, it will switch the preset color
    preset = (preset + 1) % 3;//Increase the preset by 1 and divide it by 3


  }
  if (light < 30) { //If the value from the light sensor is less than 30, it will run a for loop and change to different preset colors.
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, presets[preset][i % 2][0], presets[preset][i % 2][1], presets[preset][i % 2][2]);


    }

  }

}
