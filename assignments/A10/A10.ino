/*
 * Assignment #10
 *
 * A 4-digit seven segment count down (9999 to 0000)
 *
 * The circuit:
 * Connect pin 0 of Arduino to input A (pin 7) of 7447
 * Connect pin 1 of Arduino to input B (pin 1) of 7447
 * Connect pin 2 of Arduino to input C (pin 2) of 7447
 * Connect pin 3 of Arduino to input D (pin 6) of 7447
 * Connect outputs of 7447 to seven segments
 * Connect pin 8 of Arduino to common of first seven segment
 * Connect pin 9 of Arduino to common of second seven segment
 * Connect pin 10 of Arduino to common of third seven segment
 * Connect pin 11 of Arduino to common of fourth seven segment
 *
 * https://mehsen.com/arduino/assignments/
 *
 * To the extent possible under law,
 * Mohsen Dastjerdi Zade (mehsen.com) has waived all copyright
 * and related or neighboring rights to Arduino Assignments.
 * https://creativecommons.org/publicdomain/zero/1.0/
 */

// include library for use of timer1 interrupts
// https://www.pjrc.com/teensy/td_libs_TimerOne.html
#include <TimerOne.h>

// array to store the pattern of each seven segment digit
byte ss_digits[4];

// display number as decimal on 4 seven segments
void displayDecimal(int number) {
  // calculate decimal digits and assign them to corresponding seven segment
  ss_digits[0] = number % 10;
  ss_digits[1] = (number / 10) % 10;
  ss_digits[2] = (number / 100) % 10;
  ss_digits[3] = (number / 1000) % 10;
}

// this functions gets called by timer1 interrupt
void updateDisplay() {
  // show pattern of a digit each time the function runs
  // and light up the corresponding seven segment (multiplexing)
  static int placeNow = 0;
  PORTB = 0x00;
  digitalWrite(placeNow + 8, HIGH);
  PORTD = ss_digits[placeNow];
  // add 1 to placeNow and keep the 1st, 2nd, 4th bits and clear the rest
  // this assigns 8, 9, 10, 11 to placeNow each time
  placeNow = (placeNow + 1) & 3;
}

// the setup routine runs once when you press reset:
void setup() {
  for(int i = 0; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
  // initialize timer1 and attach timer interrupt
  Timer1.initialize(5000);
  Timer1.attachInterrupt(updateDisplay);
}

// the loop routine runs over and over again forever:
void loop() {
  // count down from 9999 to 0 and display on seven segments
  for (int i = 9999; i >= 0; i--) {
    displayDecimal(i);
    delay(200);
  }
}
