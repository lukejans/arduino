/*
Project 09: Motorized Pinwheel

a colored wheel that will make your head spin.
*/

const int potPin = A0;       // potentiometer connected to this pin
int potValue;

const int motorPin = 9;      // motor speed connected to PWM pin
int motorSpeed;

int led = 10;                // LED connected to PWM pin (light level)
int lightLevel;

void setup() {
  pinMode(motorPin, OUTPUT);

  // initialize LED
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW); 
}

void loop() {
  // read the analog value from the potentiometer
  potValue = analogRead(potPin);


  // map the potentiometer value to a motor speed range: (0-7500rpm) <- noload
  motorSpeed = map(potValue, 0, 1023, 0, 255);

  // map the motor speed to a light level range:
  lightLevel = map(potValue, 0, 1023, 0, 90);

  analogWrite(motorPin, motorSpeed);       // set motor speed using PWM
  analogWrite(led, lightLevel);            // set light level using PWM
}
