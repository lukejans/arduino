/*
Project 08:

Digital Hourglass
    - currently setup as a 6min timer
*/

/*
tilt switch 
    - stating position (1)
*/ 
const int switchPin = 8;
bool switchState;
bool preSwitchState;

// indicates the last time an led was turned on
unsigned long previousTime = 0;

// next LED to turn on (start at pin 2)
int led = 2;

// hour glass time: 1 min
unsigned short interval = 4000;

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

    //  turn LEDs on 
    if (currentTime - previousTime > interval) {
        // track last LED turn on time
        previousTime = currentTime;

        // turn on the next LED
        digitalWrite(led, HIGH);
        led++;

        // check if all the LEDs have been turned on
        if (led > 7) {
            // TODO
        }
    }

    switchState = digitalRead(switchPin);

    // check if the hour glass has been flipped
    if (switchState != preSwitchState) {
        // reverse process
        for (int x = 2; x < 8; x++) {
            digitalWrite(x, LOW);
        }
        led = 2;

        // track time of reset
        previousTime = currentTime;
    }

    // to compare state in next loop
    preSwitchState = switchState;
}
