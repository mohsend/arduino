/*
 * Assignment #10
 *
 * A 4-digit seven segment count down (9999 to 0000)
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
  // seven segment pattern for decimal digits
  const byte digits[10] = {
    0xfc, // 0
    0x60, // 1
    0xda, // 2
    0xf2, // 3
    0x66, // 4
    0xb6, // 5
    0xbe, // 6
    0xe0, // 7
    0xfe, // 8
    0xf6  // 9
  }
  
  // calculate decimal digits and assign them to corresponding seven segment
  ss_digits[0] = digits[number % 10];
  ss_digits[1] = digits[(number / 10) % 10];
  ss_digits[2] = digits[(number / 100) % 10];
  ss_digits[3] = digits[(number / 1000) % 10];
}

// this functions gets called by timer1 interrupt
void updateDisplay() {
  // show pattern of a digit each time the function runs
  // and light up the corresponding seven segment (multiplexing)
  static byte placeNow = 8;
  PORTB = 0xF;
  digitalWrite(placeNow, LOW);
  PORTD = ss_digit[placeNow];
  // add 1 to placeNow and keep the 1st, 2nd, 4th bits and clear the rest
  // this assigns 8, 9, 10, 11 to placeNow each time
  placeNow = (placeNow + 1) & 11;
}

// the setup routine runs once when you press reset:
void setup() {
  for(int i = 0; i <= 11; i++)
    pinMode(i, OUTPUT);
  
  // initialize timer1 and attach timer interrupt
  Timer1.initialize(4000);
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
