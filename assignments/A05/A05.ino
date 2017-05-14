/*
 * Assignment #05
 *
 * Drive a common anode seven segment with a 7447 BCD-to-Decimal decoder
 * to do count up
 *
 * https://mehsen.com/arduino
 *
 * To the extent possible under law,
 * Mohsen Dastjerdi Zade (mehsen.com) has waived all copyright
 * and related or neighboring rights to Arduino Assignments.
 * https://creativecommons.org/publicdomain/zero/1.0/
 */

// the setup routine runs once when you press reset:
void setup() {
  for(int i = 0; i < 4; i++)
    pinMode(i, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  for(int i = 0; i <= 9; i++) {
    PORTD = i;
    delay(200);
  }
}
