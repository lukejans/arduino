/*
Project 13:

Capacitive Sensor
*/

#include <CapacitiveSensor.h>

/*
sensor initialization
    - pin 4: sends to conductive sensor
    - pin 2: senses capacity
*/
CapacitiveSensor capSensor = CapacitiveSensor(4, 2);

int threshold = 1000;
const int ledPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(10);
}
