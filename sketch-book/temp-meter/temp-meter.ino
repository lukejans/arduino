/*
Project: 03

Temperature Meter
*/

/*
temperature input: @int {sensorPin}
          - specified: -40C to +125C    
          - scale factor: 10mV / +-1C  
          - offset from 0C: 500mV
          - sensor value: 0-1023
*/
const int sensorPin = A0;
                                        
const float baselineTemp = 20.0;        // baseline temperature (degrees celsius)

void setup() {
  Serial.begin(9600);                   // open serial port to view analog input

  for (int pinNumber = 2; pinNumber < 6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);         // set LED pins to output
    digitalWrite(pinNumber, LOW);       // initial LED state is off
  }
}

void loop() {
  // get current sensor value representing voltage:
  int sensorValue = analogRead(sensorPin);  

  // send sensor value to computer:
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);

  /*
  convert sensor reading value to voltage:
            - formula: 
              (sensor value / sensor range) * voltage range 
  */
  float voltage = (sensorValue/1024.0) * 5.0;
  // send measured voltage(V) to computer:
  Serial.print(", Voltage: ");
  Serial.print(voltage);

  /*
  convert voltage to temperature:
            - 0.10V at -40C
            - 0.50V at 0C
            - 0.51V at +1C
            - formula:
              (voltage - offset) * scaling factor
  */ 
  float temperature = (voltage - 0.5) * 100;
  // send temperature(C) to computer:
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  // set LEDs according to temperature:
  if (temperature < baselineTemp - 2) {
    digitalWrite(5, HIGH);
  } else if (temperature < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else if (temperature >= baselineTemp + 2  && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(250); 
}
