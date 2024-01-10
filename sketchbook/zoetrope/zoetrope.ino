/*
Project 10:

Zoetrope

  - using H-bridge integrated circuit (IC)
                    _   _
        [PWM]   1 -|     |- 16   [PWR]
       [SPIN]   2 -|  L  |- 15
         [M-]   3 -|  2  |- 14
        [GND]   4 -|  9  |- 13
        [GND]   5 -|  3  |- 12
         [M+]   6 -|  D  |- 11
       [SPIN]   7 -|     |- 10
        [PWR]   8 -|_____|- 9

  [PWM]  
    - PWM dc motor speed
  [SPIN]
    - communicate spin direction
    - 2:HIGH 7:LOW = clockwise
    - 2:LOW 7:HIGH = counter-clockwise
    - if both pins are HIGH or both LOW = stop
  [M]
    - dc motor positive and negative direction
  [PWR]
     8: dc motor power
    16: dc motor power
*/

void setup() {  

}

void loop() {
}
