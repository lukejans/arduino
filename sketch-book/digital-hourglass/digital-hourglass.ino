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
int switchState = 0;
int preSwitchState = 0;

// indicates the last time an led was turned on
unsigned long previousTime = 0;

// next LED to turn on (start at pin 2)
int led = 2;

// hour glass time: 1 min
unsigned short interval = 4000;

void setup() {
    Serial.begin(9600);

    for (int x = 2; x < 8; x++) {
        pinMode(x, OUTPUT);
    }
    pinMode(switchPin, INPUT);
}

void loop() {
    // tracking time
    unsigned long currentTime = millis();

    // evaluate the amount of time that has passed 
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

    Serial.print("tilt switch: ");
    Serial.println(switchState);

    // check if the tilt switch changed state
    switchState = digitalRead(switchPin);

    if (switchState != preSwitchState) {
        // reset hour glass
        for (int x = 2; x < 8; x++) {
            digitalWrite(x, LOW);
        }

        led = 2;
        previousTime = currentTime;
    }

    // to compare state in next loop
    preSwitchState = switchState;
}
