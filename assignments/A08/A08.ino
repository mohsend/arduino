/*
 * Assignment #08
 *
 * Drive 3 common anode seven segments to display "721"
 * with a single 7447 BCD-to-Decimal decoder
 * light each one up when a corresponding button is pressed
 *
 * The circuit:
 * Connect pin 0 of Arduino to input A (pin 7) of 7447
 * Connect pin 1 of Arduino to input B (pin 1) of 7447
 * Connect pin 2 of Arduino to input C (pin 2) of 7447
 * Connect pin 3 of Arduino to input D (pin 6) of 7447
 * Connect outputs of 7447 to seven segments
 * Connect pin 8 of Arduino to common of first seven segment
 * Connect pin 9 of Arduino to common of second seven segment
 * Connect pin 10 of Arduino to common of third seven segment
 * Connect pin A0 of Arduino to a push-button hooked to ground
 * Connect pin A1 of Arduino to a push-button hooked to ground
 * Connect pin A2 of Arduino to a push-button hooked to ground
 *
 * https://mehsen.com/arduino/assignments/
 *
 * To the extent possible under law,
 * Mohsen Dastjerdi Zade (mehsen.com) has waived all copyright
 * and related or neighboring rights to Arduino Assignments.
 * https://creativecommons.org/publicdomain/zero/1.0/
 */

// button pins
const int button0 = A0;
const int button1 = A1;
const int button2 = A2;

// seven segment select pins
const int ssegment0 = 8;
const int ssegment1 = 9;
const int ssegment2 = 10;

// the setup routine runs once when you press reset:
void setup() {
  for(int i = 0; i < 4; i++) {
    pinMode(i, OUTPUT);
  }
  // Define button pins as input with internal pullup resistors
  pinMode(button0, INPUT_PULLUP);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  // Define seven segment select pins as output
  pinMode(ssegment0, OUTPUT);
  pinMode(ssegment1, OUTPUT);
  pinMode(ssegment2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // when a button is pressed its pin reads low
  // so a button is pressed when its state is low(false)
  if (!digitalRead(button0)) {
    // pull the common of seven segment we want to light up low
    // and others high
    digitalWrite(ssegment0, HIGH);
    digitalWrite(ssegment1, LOW);
    digitalWrite(ssegment2, LOW);
    // write BCD code for 7447's input
    PORTD = 1;
  } else if (!digitalRead(button1)) {
    digitalWrite(ssegment0, LOW);
    digitalWrite(ssegment1, HIGH);
    digitalWrite(ssegment2, LOW);
    PORTD = 2;
  } else if (!digitalRead(button2)) {
    digitalWrite(ssegment0, LOW);
    digitalWrite(ssegment1, LOW);
    digitalWrite(ssegment2, HIGH);
    PORTD = 7;
  } else {
    // turn all seven segments off if no button is pressed
    digitalWrite(ssegment0, LOW);
    digitalWrite(ssegment1, LOW);
    digitalWrite(ssegment2, LOW);
  }
}
