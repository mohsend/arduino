/*
 * Assignment #16
 *
 * Read temperature value from sensor, if it's more than 40*C
 * turn on a fan and blink an LED
 *
 * The circuit:
 * DHT11 data pin to pin 7
 * DHT11 VCC to 5V and ground to ground
 * Connect a transistor (TIP122) to pin 12 and wire it to the DC motor
 * Connect an LED to pin 13
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

// initialize DHT temperature sensor library:
DHT_Unified dht(8, DHT11);

const int led = 13;
const int motor = 12;
bool blink_led;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  // Initialize DHT11 temperature sensor
  dht.begin();
}

// the loop routine runs over and over again forever:
void loop() {
  // Get temperature event
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  // display error if temperature is not a number
  if (isnan(event.temperature)) {
    digitalWrite(led, HIGH);
  } else if (event.temperature > 40) {
    digitalWrite(motor, HIGH);
    blink_led = true;
  } else {
    digitalWrite(motor, LOW);
    blink_led = false;
  }
  // delay between measurements
  delay(500);
  // Blink LED
  if (blink_led) {
    static bool state = HIGH;
    digitalWrite(led, state);
    state = !state;
  }
}
