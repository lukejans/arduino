/*
Project 14:

Tweak The Logo:
    - serial communication with a computer program, Processing
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0) / 4;
  Serial.println(sensorValue);  // Sending the value as a line with println
  delay(5);
}

