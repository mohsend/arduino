/*
 * Assignment #03
 *
 * Direct drive a common anode seven segment to do decimal count down
 *
 * https://mehsen.com/arduino/assignments/
 *
 * To the extent possible under law,
 * Mohsen Dastjerdi Zade (mehsen.com) has waived all copyright
 * and related or neighboring rights to Arduino Assignments.
 * https://creativecommons.org/publicdomain/zero/1.0/
 */

void displayDigit(int d) {
  // seven segment pattern for decimal digits
  const byte digits[10] = {
    0xfc, // 0
    0x60, // 1
    0xda, // 2
    0xf2, // 3
    0x66, // 4
    0xb6, // 5
    0xbe, // 6
    0xe0, // 7
    0xfe, // 8
    0xf6  // 9
  }
  
  if (d >= 0 && d <= 9) {
    // if in range display the digit
    PORTD = digits[d];
  } else {
    // if not in range display error
    PORTD = 0x92;
  } 
}

// the setup routine runs once when you press reset:
void setup() {
  for(int i = 0; i < 8; i++)
    pinMode(i, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  for(int i = 9; i > 0; i--) {
    displayDigit(i);
    delay(200);
  }
}
