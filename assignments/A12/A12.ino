/*
 * Assignment #12
 *
 * 
 *
 
 *
 * https://mehsen.com/arduino/assignments/
 *
 * To the extent possible under law,
 * Mohsen Dastjerdi Zade (mehsen.com) has waived all copyright
 * and related or neighboring rights to Arduino Assignments.
 * https://creativecommons.org/publicdomain/zero/1.0/
 */

// include library for use of timer1 interrupts:
// https://www.pjrc.com/teensy/td_libs_TimerOne.html
#include <TimerOne.h>

const int red_light = 11;
const int yellow_light = 12;
const int green_light = 13;

byte lights[4];
byte ss_digit[4];

// this functions gets called by timer1 interrupt
void sweepLights() {
  // show pattern of a digit each time the function runs
  // and light up the corresponding seven segment (multiplexing)
  static byte placeNow = 0;
  PORTB = 0x00;
  digitalWrite(placeNow + 8, HIGH);
  PORTD = ss_digit[placeNow];
  PORTC = lights[placeNow];
  // add 1 to placeNow and keep the first two bits and clear the rest
  // this assigns 0, 1, 2, 3 to placeNow each time
  placeNow = (placeNow + 1) & 3;
}

// the setup routine runs once when you press reset:
void setup() {
  for(int i = 0; i < 12; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  // initialize timer1 and attach timer interrupt
  Timer1.initialize(5000);
  Timer1.attachInterrupt(sweepLights);
}

// the loop routine runs over and over again forever:
void loop() {
  // first light goes green for 2 seconds, rest are red
  lights[0] = 0;
  lights[1] = 0;
  lights[2] = 0;
  lights[3] = 0;
  bitSet(lights[0], 0);
  bitSet(lights[1], 3);
  bitSet(lights[2], 3);
  bitSet(lights[3], 3);
  for (int i = 2; i >= 0; i--) {
    ss_digit[0] = i;
    ss_digit[1] = i + 2;
    ss_digit[2] = i + 4;
    ss_digit[3] = i + 6;
    delay(1000);
  }

  // second light goes green for 2 seconds, rest are red
  lights[0] = 0;
  lights[1] = 0;
  lights[2] = 0;
  lights[3] = 0;
  bitSet(lights[0], 3);
  bitSet(lights[1], 0);
  bitSet(lights[2], 3);
  bitSet(lights[3], 3);
  for (int i = 2; i >= 0; i--) {
    ss_digit[0] = i + 6;
    ss_digit[1] = i;
    ss_digit[2] = i + 2;
    ss_digit[3] = i + 4;
    delay(1000);
  }
}
