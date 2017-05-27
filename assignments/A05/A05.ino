/*
 * Assignment #05
 *
 * Drive a common anode seven segment with a 7447 BCD-to-Decimal decoder
 * to do count up
 *
 * The circuit:
 * Connect pin 4 of arduino to input A (pin 7) of 7447
 * Connect pin 5 of arduino to input B (pin 1) of 7447
 * Connect pin 6 of arduino to input C (pin 2) of 7447
 * Connect pin 7 of arduino to input D (pin 6) of 7447
 * Connect outputs of 7447 to seven segment
 *
 * https://mehsen.com/arduino/assignments/
 *
 * To the extent possible under law,
 * Mohsen Dastjerdi Zade (mehsen.com) has waived all copyright
 * and related or neighboring rights to Arduino Assignments.
 * https://creativecommons.org/publicdomain/zero/1.0/
 */

// the setup routine runs once when you press reset:
void setup() {
  for(int i = 4; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  for(int i = 0; i <= 9; i++) {
    PORTD = i << 4;
    delay(700);
  }
}
