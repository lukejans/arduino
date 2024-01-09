/*
Project 07:

Keyboard Instrument:
  - send frequencies to piezo
  - resistor ladder
*/

/*
frequency setup: middle notes
  B4 - 494Hz
  C4 - 262Hz
  D4 - 294Hz
  E4 - 330Hz
*/    
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
