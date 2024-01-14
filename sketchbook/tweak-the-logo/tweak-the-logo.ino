/*
Project 14:

Tweak The Logo:
    - serial communication with a computer program, Processing
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(analogRead(A0) / 4);
  delay(1);
}
