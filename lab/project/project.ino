#include <ss_sr.h> // https://github.com/mohsend/sevensegment_74595

unsigned long sp = 500;
int8_t st = 1;

void setup() {
  // setup Display with shift register pins: 
  // latch: 10
  // clock: 12
  // data: 11
  // there are 4 sevensegments being driven
  // and seven the seven segment is common anode
  setupDisplay(10, 12, 11, 4, COMMON_ANODE);

  // Connect to button, resets counter
  pinMode(A0, INPUT_PULLUP);
  // Connect to button, toggles up/down 
  pinMode(A2, INPUT_PULLUP);
  // Connect to button, toggles 1/2 
  pinMode(A3, INPUT_PULLUP);
  // Connect to button, toggles odd/even 
  pinMode(A1, INPUT_PULLUP);
}

void loop() {
  char buf[5];
  static int32_t i = 0;
  i += st;
  sprintf(buf, "%4d", i);
  displayString(buf);
  delay(sp);  // accepts unsigned long
  if (!digitalRead(A0)) { // reset
    i = 0;
    strcpy(buf, "0000");
  } else if (!digitalRead(A2)) { // toggle up/down
    st = -st;
    sprintf(buf, " %+d ", st);
  } else if (!digitalRead(A3)) { // toggles 2/1
    st = (st & 1)? 2 : 1;
    sprintf(buf, " %+d ", st);
  } else if (!digitalRead(A1) && !(st & 1)) { // toggles odd/even
    i--;
    if (i & 1) {
      strcpy(buf, " odd");
    } else {
      strcpy(buf, "even");
    }
  }
  while(!digitalRead(A2) || !digitalRead(A3) || !digitalRead(A1) || !digitalRead(A0)) {
    displayString(buf);
  }
}

