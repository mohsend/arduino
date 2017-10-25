/*
 * 7segmentcounter.c
 *
 * Created: 10/19/2017 11:22:35 AM
 * Author: Mohsen Dastjerdi Zade
 *
 * Connect A-G pins of a Common-Cathode 7segment to pins 0-6 of PORTB
 * Connect a push button to pin 0 of PORTC and to ground
 * Connect a switch to pin 1 of PORTC and to ground
 * Counts 0-9 up and down on a seven segment with the push of the push button
 */

#include <io.h>
#include <delay.h>
#include <stdint.h>

// Store sven segment patterns on a byte array
const uint8_t digit[19] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6 
    0x07, // 7
    0x7F, // 8
    0x67, // 9
  };

int i = 0;

void main(void)
{

// Define all pins from port B as output and set low
// 7 Segment
DDRB = 0xFF;
PORTB = 0x00;

// define pin 0 from port C as pulled up input
// Push button 
DDRC.0 = 0;
PORTC.0 = 1;

// define pin 1 from port C as pulled up input
// Inc or Dec 
DDRC.1 = 0;
PORTC.1 = 1;

while (1)
    {    
    if (!PINC.0) { // If push button is pressed
      if (PINC.1) { // If in increment mode
        i = (i + 1) % 10;    
      } else { // If in Decrement mode
        i = (i <= 0)? 9 : i - 1;
      }
      PORTB = digit[i]; // Look up digit pattern from array and map to PORTB
      while(!PINC.0); // Lock (busy wait) till the button is released   
    }
  }
}
