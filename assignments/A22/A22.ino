/*
 * Assignment #22
 *
 * 
 *
 * The circuit:
 * DHT11 data pin to pin 8
 * DHT11 VCC to 5V and ground to ground
 * three LEDs to pin 13
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

// include Adafruit Unified Sensor Library:
// https://github.com/adafruit/Adafruit_Sensor
#include <Adafruit_Sensor.h>
// include DHT Sensor Library:
// https://github.com/adafruit/DHT-sensor-library
#include <DHT.h>
#include <DHT_U.h>

// initialize DHT temperature sensor library:
DHT_Unified dht(8, DHT11);

const int led = 13;
const int fan = 9;

// the setup routine runs once when you press reset:
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Initialize DHT11 temperature sensor
  dht.begin();
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  int temp = event.temperature;
  // set led and fan pins as output
  pinMode(led, OUTPUT);
  pinMode(fan, OUTPUT);

  for (int i = 4; i < 22; i += 3) {
    lcd.setCursor(i % 16, i / 16);
    temp = event.temperature;
    lcd.print(temp, DEC);
    lcd.write('C');
    delay(500);
  }
  
  if (temp <= 35) {
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW);
  } else if (temp > 50) {
    lcd.clear();
    lcd.print("ESCAPE");
  } else {
    digitalWrite(fan, HIGH);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  
}
