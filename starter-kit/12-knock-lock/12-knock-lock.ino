/*
Project 12: Knock Lock

tap out the secret code to open the door.
*/

#include <Servo.h>
// create servo motor object
Servo myServo;

// I/O 
const int piezo = A0;
const int switchPin = 2;
const int yellowLED = 3;
const int greenLED = 4;
const int redLED = 5;

// switch and piezo variables
int knockVal;
int switchVal;

// knock values
const int quietKnock = 10;
const int loudKnock = 100;

// lock state
bool locked = false;

// valid knocks tracker
short numberOfKnocks = 0; 

void setup() {
  myServo.attach(9);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);

  // start in unlocked state
  digitalWrite(greenLED, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
}

void loop() {
  if (locked == false) {
    // lock button
    switchVal = digitalRead(switchPin);

    // lock the box
    if (switchVal == HIGH) {
      locked = true;
      digitalWrite(greenLED, LOW);
      digitalWrite(redLED, HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }

  // check for knocks to unlock 
  if (locked == true) {
    // read knocks
    knockVal = analogRead(piezo);

    // count only valid knocks
    if (numberOfKnocks < 3 && knockVal > 0) {
      if (checkForKnock(knockVal) == true) {
        numberOfKnocks++;
      }
      Serial.print(3 - numberOfKnocks);
      Serial.println(" more knocks to go");
    }

    // unlock the box
    if (numberOfKnocks >= 3) {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLED, HIGH);
      digitalWrite(redLED, LOW);
      Serial.println("The box is unlocked!");
      numberOfKnocks = 0;
    }
  }
}

// function to check valid knocks
bool checkForKnock(int value){
  if (value > quietKnock && value < loudKnock) {
    // blink led to indicate a valid knock
    digitalWrite(yellowLED, HIGH);
    delay(50);
    digitalWrite(yellowLED, LOW);
    Serial.print("Valid knock of value: ");
    Serial.println(value);
    return true;
  } else {
    Serial.print("Bad knock value ");
    Serial.println(value);
    return false;
  }
}