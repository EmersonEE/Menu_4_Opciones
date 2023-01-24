/* led.ino
 * Author Diego Perez (http://hotboards.org)
 * The most simple program, blink a led on pin number 13
 */

#include <Arduino.h>
#include <Hotboards_leds.h>

// create a simgle led object, this led will turn on with a HIGH value
Hotboards_leds led( 13 );
// if your led will turn on with a LOW value, the we need to create the led
// object with an extra parameter: Hotboards_leds led( 13, LOW );

void setup( void )
{
    // nothing to do here
}

void loop( void )
{
    // turn on led
    led.turnOn( );
    delay( 100 );
    // turn off led
    led.turnOff( );
    delay( 100 );
}
