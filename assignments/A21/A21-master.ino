/*
 * Assignment #21 - Master
 *
 * Recive a string on Wire (I2C) and display it on LCD
 *
 * The circuit:
 * Connect pin SDA (A4) of master and slave Arduinos together
 * Connect pin SCL (A5) of master and slave Arduinos together
 * Connect the ground of both Arduinos together
 *
 * https://mehsen.com/arduino/assignments/
 *
 * To the extent possible under law,
 * Mohsen Dastjerdi Zade (mehsen.com) has waived all copyright
 * and related or neighboring rights to Arduino Assignments.
 * https://creativecommons.org/publicdomain/zero/1.0/
 */

// include Wire (I2C) library
#include <Wire.h>

// the setup routine runs once when you press reset:
void setup() {
  // join i2c bus (address optional for master)
  Wire.begin();
  // transmit to device #8
  Wire.beginTransmission(8);
  Wire.write("Mohsen\0");
  Wire.endTransmission();
}

// the loop routine runs over and over again forever:
void loop() {
  
}

