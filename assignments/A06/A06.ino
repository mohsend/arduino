/*
 * Assignment #06
 *
 * Single traffic light with one-digit timer
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
  for(int i = 0; i < 4; i++)
    pinMode(i, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // Red light
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  for(int i = 9; i => 0; i--) {
    PORTD = i;
    delay(1000);
  }
  
  // Green light
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  for(int i = 5; i => 0; i--) {
    PORTD = i;
    delay(1000);
  }

  // Yellow light
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  delay(1000);
}
