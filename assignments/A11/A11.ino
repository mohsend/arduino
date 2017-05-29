/*
 * Assignment #11
 *
 * A traffic light with 3-digit seven segment count down timer
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
 * Connect pin A0 of Arduino to the red LED
 * Connect pin A1 of Arduino to the yellow LED
 * Connect pin A2 of Arduino to the green LED
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
byte ss_digits[3];

const int red_light = A0;
const int yellow_light = A1;
const int green_light = A2;

// display number as decimal on 4 seven segments
void displayDecimal(int number) {
  // calculate decimal digits and assign them to corresponding seven segment
  ss_digits[0] = number % 10;
  ss_digits[1] = (number / 10) % 10;
  ss_digits[2] = (number / 100) % 10;
}

// this functions gets called by timer1 interrupt
void updateDisplay() {
  // show pattern of a digit each time the function runs
  // and light up the corresponding seven segment (multiplexing)
  static byte placeNow = 0;
  PORTB = 0x00;
  digitalWrite(placeNow + 8, HIGH);
  PORTD = ss_digits[placeNow];
  // add 1 to placeNow if it's less than 2 or set to zero otherwise
  // this assigns 0, 1, 2 to placeNow each time
  placeNow = (placeNow < 2) ? (placeNow + 1) : 0;
}

// the setup routine runs once when you press reset:
void setup() {
  for(int i = 0; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(red_light, OUTPUT);
  pinMode(yellow_light, OUTPUT);
  pinMode(green_light, OUTPUT);
  // initialize timer1 and attach timer interrupt
  Timer1.initialize(4000);
  Timer1.attachInterrupt(updateDisplay);
}

// the loop routine runs over and over again forever:
void loop() {
  // start with red light
  digitalWrite(red_light, HIGH);
  digitalWrite(yellow_light, LOW);
  digitalWrite(green_light, LOW);
  // set count down to 119 go down to 80
  for (int i = 119; i >= 80; i--) {
    displayDecimal(i);
    delay(1000);
  }
  // go green
  digitalWrite(red_light, LOW);
  digitalWrite(yellow_light, LOW);
  digitalWrite(green_light, HIGH);
  // set count down to 24 go down to 0
  for (int i = 24; i >= 0; i--) {
    displayDecimal(i);
    delay(1000);
  }
  // wait for 6 more seconds
  delay(6000);
  // go yellow
  digitalWrite(red_light, LOW);
  digitalWrite(yellow_light, HIGH);
  digitalWrite(green_light, LOW);
}
