/*
 * Assignment #13
 *
 * Display 'RAMTIN' on 16x2 character LCD
 * Starting on column 2 of row 1
 *
 * The circuit:
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
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // position the LCD cursor to column 2 of row 1
  lcd.setCursor(2, 1);
  // print message to the LCD
  lcd.print("RAMTIN");
}

// the loop routine runs over and over again forever:
void loop() {
  
}
