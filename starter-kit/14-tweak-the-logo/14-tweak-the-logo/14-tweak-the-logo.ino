/*
Project 14: Tweak The Logo

control your personal computer from your Arduino.
    - serial communication with a computer program (Processing)
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0) / 4;
  Serial.write(sensorValue);
  delay(5);
}

