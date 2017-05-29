/*
 * Assignment #19 - Reciver
 *
 * Recive a string on serial (UART) and display it on LCD
 *
 * The circuit:
 * Connect pin 1 (TX) of sender Arduino
 * to pin 0 (RX) of reciver (this) Arduino
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

// include the character LCD library:
#include <LiquidCrystal.h>

// initialize LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial (UART):
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.cursor();
}

// the loop routine runs over and over again forever:
void loop() {
  
}

// SerialEvent occurs whenever a new data comes in the
// hardware serial RX.  This routine is run between each
// time loop() runs, so using delay inside loop can delay
// response.  Multiple bytes of data may be available.
void serialEvent() {
  while (Serial.available()) {
    // receive byte as a character
    char inChar = Serial.read();
    // print the character
    lcd.write(inChar);
  }
}
