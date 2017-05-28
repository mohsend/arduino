/*
 * Assignment #18
 *
 * Turn 2 LEDs on with PWM, one should have a shorter duty cycle
 *
 * The circuit:
 * Connect 2 LEDs to pins 9 and 10 of arduino
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
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  analogWrite(9, 20);
  analogWrite(10, 100);
}

// the loop routine runs over and over again forever:
void loop() {
  
}
