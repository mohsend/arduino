/*
 * Assignment #21 - Slave
 *
 * Recive a string on Wire (I2C) and display it on LCD
 *
 * The circuit:
 * Connect pin SDA (A4) of master and slave Arduinos together
 * Connect pin SCL (A5) of master and slave Arduinos together
 * Connect the ground of both Arduinos together
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K potentiometer:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3) 
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

// include the character LCD library:
#include <LiquidCrystal.h>

// initialize LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// the setup routine runs once when you press reset:
void setup() {
  // join i2c bus with address #8
  Wire.begin(8);
  // register event
  Wire.onReceive(receiveEvent);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.cursor();
}

// the loop routine runs over and over again forever:
void loop() {
  
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  // loop through all recived bytes
  while (Wire.available()) {
    // receive byte as a character
    char inChar = Wire.read();
    // print the character
    lcd.write(inChar);
  }
}
