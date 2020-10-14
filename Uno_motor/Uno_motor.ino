
//Motor's Code from https://learn.sparkfun.com/tutorials/activity-guide-for-sparkfun-tinker-kit/circuit-10-motor-basics

//the motor will be controlled by the motor A pins on the motor driver
const int AIN1 = 13;           //control pin 1 on the motor driver for the motor
const int AIN2 = 12;            //control pin 2 on the motor driver for the motor
const int PWMA = 11;            //speed control pin on the motor driver for the motor

//VARIABLES
int motorSpeed = 0;       //starting speed for the motor
int photoresistor = 0;              //this variable will hold a value based on the position of the knob
int threshold = 500;                //if the photoresistor reading is below this value the motor will turn on

void setup() {
  Serial.begin(9600); // initialize serial.
  
  //set the motor control pins as outputs
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
}

void loop() {
  photoresistor = analogRead(A0);   //set photoresistor to a number between 0 and 1023 read from A0
  Serial.println(photoresistor);    //print the value of photoresistor in the serial monitor on the computer

  if (photoresistor > threshold) {    //if the value of photoresistor is greater than the threshold's value, the bot will move forward
    Serial.println(photoresistor);    //print the value of photoresistor in the serial monitor on the computer



    //drive bot to move forward
    digitalWrite(AIN1, LOW);                          //set pin 1 to low
    digitalWrite(AIN2, HIGH);                         //set pin 2 to high
    analogWrite(PWMA, 255);               //now that the motor direction is set, drive it at max speed


  } else {                           //if the value of photoresistor is less than the threshold's value, the bot will stop
    Serial.println(photoresistor);    //print the value of photoresistor in the serial monitor on the computer

    //stop motor
    digitalWrite(AIN1, LOW);                          //set pin 1 to low
    digitalWrite(AIN2, LOW);                          //set pin 2 to low
    analogWrite(PWMA, 0);               //now that the motor direction is set, stop motor
  }




}
