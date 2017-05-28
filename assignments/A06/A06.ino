/*
 * Assignment #06
 *
 * Single traffic light with one-digit timer
 *
 * The circuit:
 * connect pin 13 of Arduino to the red LED
 * connect pin 12 of Arduino to the yellow LED
 * connect pin 11 of Arduino to the green LED
 * Connect pin 4 of Arduino to input A (pin 7) of 7447
 * Connect pin 5 of Arduino to input B (pin 1) of 7447
 * Connect pin 6 of Arduino to input C (pin 2) of 7447
 * Connect pin 7 of Arduino to input D (pin 6) of 7447
 * Connect outputs of 7447 to seven segment
 *
 * https://mehsen.com/arduino/assignments/
 *
 * To the extent possible under law,
 * Mohsen Dastjerdi Zade (mehsen.com) has waived all copyright
 * and related or neighboring rights to Arduino Assignments.
 * https://creativecommons.org/publicdomain/zero/1.0/
 */


const int red = 13;
const int yellow = 12;
const int green = 11;


// the setup routine runs once when you press reset:
void setup() {
  for(int i = 0; i < 4; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // red light
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  for(int i = 9; i >= 0; i--) {
    PORTD = i;
    delay(1000);
  }
  
  // green light
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  for(int i = 5; i >= 0; i--) {
    PORTD = i;
    delay(1000);
  }

  // yellow light
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  delay(1000);
}
