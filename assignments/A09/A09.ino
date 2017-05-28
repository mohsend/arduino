/*
 * Assignment #09
 *
 * Drive a DC motor counter clockwise when a button0 is pressed
 * Drive another DC motor clockwise when a button1 is pressed
 *
 * https://mehsen.com/arduino/assignments/
 *
 * To the extent possible under law,
 * Mohsen Dastjerdi Zade (mehsen.com) has waived all copyright
 * and related or neighboring rights to Arduino Assignments.
 * https://creativecommons.org/publicdomain/zero/1.0/
 */

// button pins
const int button0 = A0;
const int button1 = A1;

// DC motor pins
const int motor0 = 8;
const int motor1 = 9;

// the setup routine runs once when you press reset:
void setup() {
  // Define button pins as input with internal pullup resistors
  pinMode(button0, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  // Define motor pins as output
  pinMode(motor0, OUTPUT);
  pinMode(motor1, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // when a button is pressed its pin reads low
  // so a button is pressed when its state is low(false)
  if (!digitalRead(button0)) {
    digitalWrite(motor0, HIGH);
  } else {
    digitalWrite(motor0, LOW);
  }
  
  if (!digitalRead(button1)) {
    digitalWrite(motor1, HIGH);
  } else {
    digitalWrite(motor1, LOW);
  }
}
