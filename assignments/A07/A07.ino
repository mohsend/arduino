/*
 * Assignment #07
 *
 * Direct drive one seven segment to display letters is sequence
 *
 * The circuit:
 * Connect 'a' of seven segment to pin 7 of arduino
 * Connect 'b' of seven segment to pin 6 of arduino
 * ...
 * Connect 'g' of seven segment to pin 1 of arduino
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
  for(int i = 0; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  // Display A
  PORTD = 0xEE;
  delay(200);
  // Display L
  PORTD = 0x1C;
  delay(200);
  // Display I
  PORTD = 0x0C;
  delay(200);
}
