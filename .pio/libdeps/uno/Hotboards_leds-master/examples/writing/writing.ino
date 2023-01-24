/* writing.ino
 * Author Diego Perez (http://hotboards.org)
 * This program blink a led (again) but this time show how to
 * use the write function to manipulate the led state according
 + to a variable value
 */

#include <Arduino.h>
#include <Hotboards_leds.h>

// create a simgle led object, this led will turn on with a HIGH value
Hotboards_leds led( 13 );
// if your led will turn on with a LOW value, the we need to create the led
// object with an extra parameter: Hotboards_leds led( 13, LOW );


uint8_t counter;

void setup( void )
{
    counter = 0;
}

void loop( void )
{
    // the led will blink because we are writing the LSB
    // of the variable counter wich on each iteration is
    // incrmented by one.
    led.write( bitRead( counter, 0 ) );
    delay( 200 );
    counter++;
}
