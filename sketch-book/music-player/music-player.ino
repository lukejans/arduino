/*
Songs Using Piezo

abstract: this is obviously ridiculous to hardcode songs note by note 
          but this is all just fun as im just getting started with 
          arduino's. For the future I would like to hardcode only the 
          notes and build a gui to make a song easier and add it to 
          you library of songs to be played.

piezo: one note at a time can be played unless more pins attached. 
       or calculate the new wave from the added frequencies. until 
       then notes that play in the background will be removed.

tone: only one tone can play at a time. Tone will interfere
      with analogWrite() on pins 3 and 11. (using pin 8)

Blueface Song:
  musical notes from: https://en.wikipedia.org/wiki/Category:Musical_notes
  0  Eb5 - 622Hz
  1  F#5 - 740Hz 
  2  Ab6 - 1661Hz
  3  Bb6 - 1865Hz
  4  B6  - 1976Hz
*/
int notes[] = {622, 740, 1661, 1865, 1976};

void setup() {
  // nothing to setup :(
}

// if the duration of the note is the same as the delay,
// it means there is no delay between notes.
void loop() {
  tone(8, notes[0], 240);
  delay(480);
  tone(8, notes[0], 120);      
  delay(120);
  tone(8, notes[2], 120);
  delay(240);
  tone(8, notes[3], 120);
  delay(240);
  tone(8, notes[4], 120);
  delay(240);
  tone(8, notes[3], 120);
  delay(2000);

  tone(8, notes[4], 120);
  delay(240);
  tone(8, notes[3], 120);
  delay(240);
  tone(8, notes[2], 120);
  delay(240);
  tone(8, notes[1], 120);
  delay(240);
  tone(8, notes[0], 240);
  delay(480);
  tone(8, notes[0], 120);
  delay(120);
  tone(8, notes[2], 120);
  delay(240);
  tone(8, notes[3], 120);
  delay(240);
  tone(8, notes[4], 120);
  delay(240);
  tone(8, notes[3], 480);
  delay(2000);

  tone(8, notes[2], 120);
  delay(120);
  tone(8, notes[3], 120);
  delay(240);
  tone(8, notes[4], 120);
  delay(240);
  tone(8, notes[3], 120);
  delay(240);
  tone(8, notes[2], 120);
  delay(240);
  tone(8, notes[0], 240);
  delay(480);
  tone(8, notes[0], 120);
  delay(120);
  tone(8, notes[2], 120);
  delay(240);
  tone(8, notes[3], 120);
  delay(240);
  tone(8, notes[4], 120);
  delay(240);
  tone(8, notes[3], 120);
  delay(2000);

  delay(4000);
}
