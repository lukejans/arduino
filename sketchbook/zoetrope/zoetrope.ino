/*
Project 10:

Zoetrope

  - using H-bridge integrated circuit (IC)
                    _   _
        [PWM]   1 -|     |- 16   [PWR]
       [SPIN]   2 -|  L  |- 15
         [M-]   3 -|  2  |- 14
        [GND]   4 -|  9  |- 13
        [GND]   5 -|  3  |- 12
         [M+]   6 -|  D  |- 11
       [SPIN]   7 -|     |- 10
        [PWR]   8 -|_____|- 9

  [PWM]  
    - PWM dc motor speed
  [SPIN]
    - communicate spin direction
    - 2:HIGH 7:LOW = clockwise
    - 2:LOW 7:HIGH = counter-clockwise
    - if both pins are HIGH or both LOW = stop
  [M]
    - dc motor positive and negative direction
  [PWR]
     8: dc motor power
    16: h-bridge power
*/

// arduino uno pin setup
const int potPin = A0;
// for [SPIN] on h-bridge to change direction (polarity)
const int controlPin1 = 2; // 7
const int controlPin2 = 3; // 2
// for [PWM] on h-bridge to dc motor
const int enablePin = 9;
// switch buttons
const int onOffSwitchStateSwitchPin = 5;
const int directionSwitchPin = 4;

// remember program state
bool onOffSwitchState = 0;
bool previousOnOffSwitchState = 0;
bool directionSwitchState = 0;
bool previousDirectionSwitchState = 0;

// motor control 
bool motorEnabled = 0;
short motorSpeed = 0;
bool motorDirection = 1;

void setup() {  
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  // motor off in initial state
  digitalWrite(enablePin, LOW);
}

void loop() {
  // read button information
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  delay(1);

  // read motor speed
  int potValue = analogRead(potPin);
  motorSpeed = map(potValue, 0, 1023, 0, 255);

  // check if motor on/off button was pressed
  if (onOffSwitchState != previousOnOffSwitchState) {
    if (onOffSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }

  // check if the spin direction button was pressed
  if (directionSwitchState != previousDirectionSwitchState) {
    if (directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }

  // set motor direction
  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  // PWM motor speed
  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  }
  else {
    analogWrite(enablePin, 0);
  }

  // remember current state for next loop
  previousOnOffSwitchState = onOffSwitchState;
  previousDirectionSwitchState = directionSwitchState;
}
