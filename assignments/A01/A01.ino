/*
 * Assignment #01
 *
 * Blinks two 4-set LEDs connected to PORTD in succession
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
  for (int i = 0; i < 8; i++)
    pinMode(i, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  PORTD = 0xF0;
  delay(200);
  PORTD = 0x0F;
  delay(200);
}
