/*
Project 11: Crystal Ball

a mystical tour to answer all your tough questions.

  - using LCD screen, visit: arduinocc/lcdlibrary

      VSS VDD V0  RS  R/W  E  DB0 DB1 DB2 DB3 DB4 DB5 DB6 DB7 LED+ LED-
       |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
      ----------------------------------------------------------------------------
     |                                                                            |
    {|                                                                            |}
    {|                                L   C   D                                   |}
    {|                                                                            |}
     |                                                                            |
      ----------------------------------------------------------------------------
*/

#include <LiquidCrystal.h>
// arduino pins to communicate with LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// tilt switch
const int switchPin = 6;
bool switchState = 0;
bool prevSwitchState = 0;

// for displaying screen replies
int reply;

void setup() {
  pinMode(switchPin, INPUT);

  // start LCD library with screen size
  lcd.begin(16, 2);

  // welcome message
  lcd.print("Ask, the");               
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
}

void loop() {
  switchState = digitalRead(switchPin);

  // choose random reply on shake (tilt sensor)
  if (switchState != prevSwitchState) {
    if (switchState != 1) {
      reply = random(8);                // pick random reply

      // reply setup
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The ball says: ");
      lcd.setCursor(0, 1);

      // possible replies
      switch (reply){
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("Most likely");
        break;
        case 2:
        lcd.print("Certainly");
        break;
        case 3:
        lcd.print("Outlook good");
        break;
        case 4:
        lcd.print("Unsure");
        break;
        case 5:
        lcd.print("Ask again");
        break;
        case 6:
        lcd.print("Doubtful");
        break;
        case 7:
        lcd.print("No");
        break;
      }
    }
  }
  prevSwitchState = switchState;
}
