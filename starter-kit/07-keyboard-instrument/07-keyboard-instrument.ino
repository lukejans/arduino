/*
Project 07: Keyboard Instrument

play music and make some noise with this keyboard.

concepts:
  - send frequencies to piezo
  - resistor ladder
*/
   
//             B4   C4   D4   E4
int notes[] = {494, 262, 294, 330};

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read voltage
  int keyVal = analogRead(A0);

  Serial.println(keyVal);

  // play notes depending on voltage
  if (keyVal == 1023) {
    tone(8, notes[0]);
  } else if (keyVal >= 990 && keyVal <= 1010) {
    tone(8, notes[1]);
  } else if (keyVal >= 505 && keyVal <= 515) {
    tone(8, notes[2]);
  } else if (keyVal > 0 && keyVal <= 30) {
    tone(8, notes[3]);
  } else {
    noTone(8);
  }
}
