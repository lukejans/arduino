/*
Project 06:

Light Theremin
*/

// create variables for calibrating sensor
int sensorValue;
// ensure value is changed
int sensorLow = 1023;                   
int sensorHigh = 0;

// indicator for when sensor is done calibrating
const int ledPin = 13;

void setup() {
  // setup calibration indicator 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // calibrate sensor
  while(millis() < 5000) {              // run time since powered on < 5s
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if(sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);            // calibration finished
}

void loop() {
  sensorValue = analogRead(A0);

  /*
  pitch: determines what frequency to play
      - mapped from sensorValue
      - calibrated sensor low correlates to a frequency value of 50
      - calibrated sensor high correlates to a frequency value of 4000
  */
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 1000);

  tone(8, pitch, 20);                  // play sound for 20ms
  delay(10);
}
