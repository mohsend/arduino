/*
 * blink.c
 *
 * Created: 10/12/2017 8:21:02 AM
 * Author: Mohsen Dastjerdi Zade
 *
 * Connect an LED to pin 0 and a push button to pin 7 of port B.
 * The LED flashes every second.
 * When the botton is pressed LED retains its current state.
 */

#include <io.h>
#include <delay.h>

void main(void)                                        
{

// Define pin 0 from port B as output and set low
// LED
DDRB.0 = 1;
PORTB.0 = 0;

// define pin 7 from port B as pulled up input
// Push button 
DDRB.7 = 0;
PORTB.7 = 1;

while (1)
    {
    // If push button is not pressed (pin in high)
    if (PINB.7) { 
        // Toggle LED pin 
        PORTB.0 = !PORTB.0;
        // Wait half a second
        delay_ms(500);
        }
    }
}
