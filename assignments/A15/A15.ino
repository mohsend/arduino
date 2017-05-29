/*
 * Assignment #15
 *
 * Read temperature value from sensor
 * display "safe" if temp is less than 10*C
 * display "normal" if 10*C <= temp <= 40*C
 * display "danger" if temp is more than 40*C
 *
 * The circuit:
 * DHT11 data pin to pin 8
 * DHT11 VCC to 5V and ground to ground
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

// include Adafruit Unified Sensor Library:
// https://github.com/adafruit/Adafruit_Sensor
#include <Adafruit_Sensor.h>
// include DHT Sensor Library:
// https://github.com/adafruit/DHT-sensor-library
#include <DHT.h>
#include <DHT_U.h>

// include the character LCD library:
#include <LiquidCrystal.h>

// initialize DHT temperature sensor library:
DHT_Unified dht(8, DHT11);

// initialize LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// the setup routine runs once when you press reset:
void setup() {
  // Initialize DHT11 temperature sensor
  dht.begin();
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

// the loop routine runs over and over again forever:
void loop() {
  // Get temperature event
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  // display error if temperature is not a number
  if (isnan(event.temperature)) {
    lcd.print("Error reading temp!");
  } else { // else print corresponding message
    // Position the LCD cursor to column 0 of row 1
    lcd.setCursor(0, 1);
    float temp = event.temperature;
    if (temp < 10.0) {
      lcd.print("safe");
    } else if (temp >= 10.0 && temp <= 40.0) {
      lcd.print("normal");
    } else if (temp > 40.0) {
      lcd.print("danger");
    }
  }
  // delay between measurements
  delay(200);
}
