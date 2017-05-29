/*
 * Assignment #17
 *
 * Use PWM to control the speed of a DC motor
 *
 * The circuit:
 * Connect a transistor (TIP122) to pin 11 and wire it to the DC motor
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
  pinMode(11, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  analogWrite(11, 255);
  delay(3000);
  analogWrite(11, 127);
  delay(3000);
  analogWrite(11, 20);
  delay(3000);
}
