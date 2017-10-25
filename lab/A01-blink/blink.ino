/*
 * blink.ino
 *
 * Created: 10/12/2017 8:21:02 AM
 * Author: Mohsen Dastjerdi Zade
 *
 * Connect an LED to pin 0 and a push button to pin 7 of port B.
 * The LED blinks every second.
 * When the botton is pressed LED retains its current state.
 */

void setup()                                        
{
	// Define pin 0 from port B as output and set low
	// LED
	pinMode(0, OUTPUT);
	digitalWrite(0, LOW);

	// define pin 7 from port B as pulled up input
	// Push button 
	pinMode(7, INPUT_PULLUP);
}

loop ()
{
	// If push button is not pressed (pin in high)
	if (digitalRead(7)) { 
		// Toggle LED pin 
		digitalWrite(0, !digitalRead(0));
		// Wait half a second
		delay(500);
	}
}
