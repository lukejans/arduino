<div align="center">

<pre>
   ___          __     _         
  / _ | _______/ /_ __(_)__  ___ 
 / __ |/ __/ _  / // / / _ \/ _ \
/_/ |_/_/  \_,_/\_,_/_/_//_/\___/
----------------------------------
projects repo for arduino sketches and circuits
</pre>

</div>

This repository currently only consists of simple projects created from reading the _starter kit [arduino projects book](https://www.goodreads.com/book/show/17935843-arduino-projects-book)_. All projects in the starter kit use the Arduino Uno.

## Arduino Uno

```
                                  +-----+
     +----[PWR]-------------------| USB |--+
     |                            +-----+  |
     |         GND/RST2  [ ][ ]            |
     |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |   C5
     |          5V/MISO2 [ ][ ]  A4/SDA[ ] |   C4
     |                             AREF[ ] |
     |                              GND[ ] |
     | [ ]N/C                    SCK/13[ ] |   B5
     | [ ]v.ref                 MISO/12[ ] |   .
     | [ ]RST                   MOSI/11[ ]~|   .
     | [ ]3V3    +---+               10[ ]~|   .
     | [ ]5v     | A |                9[ ]~|   .
     | [ ]GND   -| R |-               8[ ] |   B0
     | [ ]GND   -| D |-                    |
     | [ ]Vin   -| U |-               7[ ] |   D7
     |          -| I |-               6[ ]~|   .
     | [ ]A0    -| N |-               5[ ]~|   .
     | [ ]A1    -| O |-               4[ ] |   .
     | [ ]A2     +---+           INT1/3[ ]~|   .
     | [ ]A3                     INT0/2[ ] |   .
     | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |   .
     | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |   D0
     |            [ ] [ ] [ ]              |
     |  UNO_R3    GND MOSI 5V  ____________/
      \_______________________/
```
