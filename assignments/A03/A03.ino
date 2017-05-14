/*
 * Assignment #03
 *
 * Turn on 8 LEDs connected to PORTD in succession,
 * turn all off, repeat
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
  for (int i = 0; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  PORTD = 0;
  for(int i = 0; i < 8; i++) {
    digitalWrite(i, HIGH);
    delay(1000);
  }
}
