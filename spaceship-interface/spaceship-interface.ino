/*
Project: 02

Spaceship Interface 
*/

//
int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);                    // button
  pinMode(3, OUTPUT);                   // green LED
  pinMode(4, OUTPUT);                   // red LED
  pinMode(5, OUTPUT);                   // blue LED       
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);         // check for button press

  if (switchState == LOW) {
    // button not clicked state:
    digitalWrite(3, HIGH);              // green LED on
    digitalWrite(4, LOW);               // red LED off
    digitalWrite(5, LOW);               // blue LED off
  } else {                                            
    // button clicked state: alternate blinking LEDs.
    digitalWrite(3, LOW);               // green LED off
    digitalWrite(4, LOW);               // red LED off
    digitalWrite(5, HIGH);              // blue LED on
    delay(250);                         // delay 0.25s
    // alternate blinking LEDs
    digitalWrite(4, HIGH);              // red LED on
    digitalWrite(5, LOW);               // blue LED off
    delay(250);                         // delay 0.25s
  }

} // back to the beginning of the loop.
