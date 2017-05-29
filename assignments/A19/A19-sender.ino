/*
 * Assignment #19 - Sender
 *
 * Send a string with Serial (UART)
 *
 * The circuit:
 * Connect pin 1 (TX) of sender (this) Arduino
 * to pin 0 (RX) of reciver Arduino
 * Connect the ground of both Arduinos together
 *
 * https://mehsen.com/arduino/assignments/
 *
 * To the extent possible under law,
 * Mohsen Dastjerdi Zade (mehsen.com) has waived all copyright
 * and related or neighboring rights to Arduino Assignments.
 * https://creativecommons.org/publicdomain/zero/1.0/
 */


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial (USART):
  Serial.begin(9600);
  // send string
  Serial.println("Mohsen Dastjedi Zade");
}

// the loop routine runs over and over again forever:
void loop() {
  
}

