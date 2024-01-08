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
      with analogWrite() on pins 3 and 11 (using pin 8). The tone
      function also does not require a setup using pinMode(8, OUTPUT)
      because tone handles this on its own.

Blueface Song:
  sources: 
    - https://en.wikipedia.org/wiki/Category:Musical_notes
    - https://www.youtube.com/watch?v=5YLpE26GCa0

  music notes:
    Eb5 - 622Hz
    F#5 - 740Hz 
    Ab6 - 1661Hz
    Bb6 - 1865Hz
    B6  - 1976Hz
*/
int notes[] = {622, 740, 1661, 1865, 1976};

/*
play  note functions:


*/
void playNote(int pin, int note, int duration, int notePause) {
    digitalWrite(pin, HIGH);
    tone(8, note, duration);
    delay(duration);
    digitalWrite(pin, LOW);
    delay(notePause);
}


void setup() {
  // LED's
  pinMode(2, OUTPUT);       // Eb5
  pinMode(3, OUTPUT);       // Ab6
  pinMode(4, OUTPUT);       // Bb6
  pinMode(5, OUTPUT);       // B6
  pinMode(6, OUTPUT);       // F#5

  // piezo does not require a setup
}

void loop() {
  playNote(2, notes[0], 240, 240);
  playNote(2, notes[0], 120, 0);  
  playNote(3, notes[2], 120, 120);
  playNote(4, notes[3], 120, 120);
  playNote(5, notes[4], 120, 120);
  playNote(4, notes[3], 120, 0);
  delay(1880);  // 2000 - last note duration (120)

  playNote(5, notes[4], 120, 120);
  playNote(4, notes[3], 120, 120);
  playNote(3, notes[2], 120, 120);
  playNote(6, notes[1], 120, 120);
  playNote(2, notes[0], 240, 240);
  playNote(2, notes[0], 120, 0);
  playNote(3, notes[2], 120, 120);
  playNote(4, notes[3], 120, 120);
  playNote(5, notes[4], 120, 120);
  playNote(4, notes[3], 480, 0);
  delay(1560);  // 2000 - last note duration (480)

  playNote(3, notes[2], 120, 0);
  playNote(4, notes[3], 120, 0);
  playNote(5, notes[4], 120, 120);
  playNote(4, notes[3], 120, 120);
  playNote(3, notes[2], 120, 120);
  playNote(2, notes[0], 240, 240);
  playNote(2, notes[0], 120, 0);
  playNote(3, notes[2], 120, 120);
  playNote(4, notes[3], 120, 120);
  playNote(5, notes[4], 120, 120);
  playNote(4, notes[3], 120, 0);
  delay(1880);  // 2000 - last note duration (120)
}
