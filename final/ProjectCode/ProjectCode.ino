
// Demo from NewPing library was used in the creation of this code

#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN  A6  // Input pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A7  // Input pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Servo myservo;  // create servo object to control a servo
Servo myservo2; // create servo2 object to control a servo

int pos = 0;
int pos2 = 180;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  myservo.attach(A2);
  myservo2.attach(A1);
}

void loop() {
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  if (sonar.ping_cm() <= 150) {
    for (pos = pos; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
    }
    for (pos2 = pos2; pos2 >= 0; pos2 -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    }
  }
  else {
    for (pos = pos; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
    }
    for (pos2 = pos2; pos2 <= 180; pos2 += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    }
  }
}
