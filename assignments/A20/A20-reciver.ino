/*
 * Assignment #20 - Reciver
 *
 * Turn on/off a DC motor accourding to the incoming Serial (UART) command
 *
 * The circuit:
 * Connect pin 1 (TX) of sender Arduino
 * to pin 0 (RX) of reciver (this) Arduino
 * Connect the ground of both Arduinos together
 * Connect a transistor (TIP122) to pin 2 and wire it to the DC motor
 *
 * https://mehsen.com/arduino/assignments/
 *
 * To the extent possible under law,
 * Mohsen Dastjerdi Zade (mehsen.com) has waived all copyright
 * and related or neighboring rights to Arduino Assignments.
 * https://creativecommons.org/publicdomain/zero/1.0/
 */

// include the character LCD library:
#include <LiquidCrystal.h>

// initialize LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial (USART):
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  while (Serial.available()) {
    // parse integer
    int command = Serial.parseInt();
    // if incoming number was 1 trun on and if 0 turn off the motor
    digitalWrite(2, command);
  }
}
