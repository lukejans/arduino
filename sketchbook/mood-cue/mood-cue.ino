/*
Project 05:

Mood Cue
*/

// import servo library 
#include <Servo.h>

// create servo object
Servo myservo;

// initialize potentiometer / user input
int const potPin = A0;  
int potVal;                              // user input value with potentiometer          
int angle;                               // angle of servo motor

void setup() {
  myservo.attach(9);                     // associate servo object to servo pin location

  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);           // read the potentiometer value

  Serial.print("potVal: ");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179);  // map the potentiometer value to the servo angle

  Serial.print(", angle: ");
  Serial.println(angle);

  myservo.write(angle);                  // set the servo angle
  delay(15);
}