/* handling leds.ino
 * Author Diego Perez (http://hotboards.org)
 * On this example we show how to manipulate your leds
 * in a diffrent ways, the first 4 are grouped into a bus
 * the following thirt ones also are grouped in a bus, but manipulated
 * individualy and finally led 8 is manipulated individualy
 * conections:
 * 13 --- led7 -\
 * 12 --- led6  |  leds
 * 11 --- led5  |
 * 10 --- led4 -/
 * 9 ---- led3 -\
 * 8 ---- led2  |  leds123
 * 7 ---- led1 -/
 * 6 ---- led0 ->  led0
 */

#include <Arduino.h>
#include <Hotboards_leds.h>

// create a bus with only four leds
Hotboards_leds leds( 10, 11, 12, 13 );
// create a bus with 3 leds that we will manipulate individualy
Hotboards_leds leds123( 7, 8, 9 );
// create a single led on pin 6
Hotboards_leds led0( 6 );

uint8_t counter;

void setup( void )
{
    counter = 0;
}

void loop( void )
{
    // turn on leds 5, 6 and 7 one by one
    leds123.turnOn( 0 ); // led1
    leds123.turnOn( 1 ); // led2
    leds123.turnOn( 2 ); // led3
    delay( 200 );
    // turn off leds 5, 6 and 7 one by one
    leds123.turnOff( 0 ); // led1
    leds123.turnOff( 1 ); // led2
    leds123.turnOff( 2 ); // led3
    delay( 200 );
    // toggle led number 0
    led0.toggle( );
    // write the fourth lsb of variable counter on leds 4,5,6 and 7
    leds.write( counter );
    counter++;
}
