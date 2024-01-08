/*
Project 08:

Digital "Hourglass"
    - currently setup as a 6min timer
*/

// tilt switch 
const int switchPin = 8;

// for comparing states
bool switchState;
bool preSwitchState;

// indicates if the "hourglass" has been flipped
bool timerFlipped = 1;

// indicates the last time an led was turned on
unsigned long previousTime = 0;

// next LED to turn on (start at pin 2)
int led = 2;

// total "hourglass" time: 1min (6 * 10000ms)
unsigned short interval = 10000;

void setup() {
    // set pin direction
    for (int x = 2; x < 8; x++) {
        pinMode(x, OUTPUT);
    }
    pinMode(switchPin, INPUT);

    // initialize tilt switch variables
    switchState = digitalRead(switchPin);
    preSwitchState = switchState;

}

void loop() {
    // tracking time
    unsigned long currentTime = millis();

    //  turn LEDs on at rate of interval
    if (currentTime - previousTime > interval) {
        // check if all the LEDs have been turned on
        if (led < 8 && timerFlipped) {
            previousTime = currentTime;         // track LED turn on time
            digitalWrite(led, HIGH);            // turn LED on
            if (led != 7) {
                led++;                          // switch to next LED
            }
        } else if (led > 1 && !timerFlipped) {
            previousTime = currentTime;         // track LED turn off time
            digitalWrite(led, LOW);             // turn LED off
            if (led != 2) {
                led--;                          // switch to next LED
            }
        }
    }

    switchState = digitalRead(switchPin);

    // check if the "hourglass" has been flipped
    if (switchState != preSwitchState) {
        // reverse process
        timerFlipped = !timerFlipped;
        
        // track time of reset
        previousTime = currentTime;
    }

    // to compare state in next loop
    preSwitchState = switchState;
}
