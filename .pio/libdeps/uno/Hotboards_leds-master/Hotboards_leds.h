/*
  Hotboards_leds.h - Driver to control leds one at a time or in group
  Hotboards leds board (http://hotboards.org)
  Created by Diego Perez, January 16, 2016.
  Released into the public domain.
*/

#ifndef Hotboards_leds_h
#define Hotboards_leds_h

#include <Arduino.h>

/** Hotboards_leds class.
 *  Used to control general purpose leds
 *
 * Example:
 * @code
 * #include "Hotboards_leds.h"
 *
 * Hotboards_leds led( 5 );
 *
 * void setup( void )
 * {
 *     pin.mode( OUTPUT );
 * }
 *
 * void loop( void )
 * {
 *     led.toggle( );
 *     delay( 200 );
 * }
 * @endcode
 */
class Hotboards_leds
{
    public :
        /** Create Hotboards_leds instance for one led
          * @param led0 pin where the led 0 will be connected
          * @param on logic level to turn on the led
          *
          * Example:
          * @code
          *   // instance one led on pin 5
          *   Hotboards_leds led( 5 );
          * @endcode
          */
        Hotboards_leds( int led0, bool on=HIGH );

        /** Create Hotboards_leds instance for two leds
          * @param led1 pin where the led 1 will be connected
          * @param led0 pin where the led 0 will be connected
          * @param on logic level to turn on the leds
          *
          * Example:
          * @code
          *   // one instance with 2 leds on pins 5 and 6
          *   Hotboards_leds led( 5, 6 );
          * @endcode
          */
        Hotboards_leds( int led0, int led1, bool on=HIGH );

        /** Create Hotboards_leds instance for three leds
          * @param led2 pin where the led 2 will be connected
          * @param led1 pin where the led 1 will be connected
          * @param led0 pin where the led 0 will be connected
          * @param on logic level to turn on the leds
          *
          * Example:
          * @code
          *   // one instance with 3 leds on pins 5, 6 and 7
          *   Hotboards_leds led( 5, 6, 7 );
          * @endcode
          */
        Hotboards_leds( int led0, int led1, int led2, bool on=HIGH );

        /** Create Hotboards_leds instance for four leds
          * @param led3 pin where the led 3 will be connected
          * @param led2 pin where the led 2 will be connected
          * @param led1 pin where the led 1 will be connected
          * @param led0 pin where the led 0 will be connected
          * @param on logic level to turn on the leds
          *
          * Example:
          * @code
          *   // one instance with 4 leds on pins 5, 6, 7 and 8
          *   Hotboards_leds led( 5, 6, 7, 8 );
          * @endcode
          */
        Hotboards_leds( int led0, int led1, int led2, int led3, bool on=HIGH );

        /** Create Hotboards_leds instance for five leds
          * @param led4 pin where the led 4 will be connected
          * @param led3 pin where the led 3 will be connected
          * @param led2 pin where the led 2 will be connected
          * @param led1 pin where the led 1 will be connected
          * @param led0 pin where the led 0 will be connected
          * @param on logic level to turn on the leds
          *
          * Example:
          * @code
          *   // one instance with 5 leds on pins 5, 6, 7, 8 and 9
          *   Hotboards_leds led( 5, 6, 7, 8, 9 );
          * @endcode
          */
        Hotboards_leds( int led0, int led1, int led2, int led3, int led4, bool on=HIGH );

        /** Create Hotboards_leds instance for six leds
          * @param led5 pin where the led 5 will be connected
          * @param led4 pin where the led 4 will be connected
          * @param led3 pin where the led 3 will be connected
          * @param led2 pin where the led 2 will be connected
          * @param led1 pin where the led 1 will be connected
          * @param led0 pin where the led 0 will be connected
          * @param on logic level to turn on the leds
          *
          * Example:
          * @code
          *   // one instance with 6 leds on pins 5, 6, 7, 8, 9 and 10
          *   Hotboards_leds led( 5, 6, 7, 8, 9, 10 );
          * @endcode
          */
        Hotboards_leds( int led0, int led1, int led2, int led3, int led4, int led5, bool on=HIGH );

        /** Create Hotboards_leds instance for seven leds
          * @param led6 pin where the led 6 will be connected
          * @param led5 pin where the led 5 will be connected
          * @param led4 pin where the led 4 will be connected
          * @param led3 pin where the led 3 will be connected
          * @param led2 pin where the led 2 will be connected
          * @param led1 pin where the led 1 will be connected
          * @param led0 pin where the led 0 will be connected
          * @param on logic level to turn on the leds
          *
          * Example:
          * @code
          *   // one instance with 7 leds on pins 5, 6, 7, 8, 9, 10 and 11
          *   Hotboards_leds led( 5, 6, 7, 8, 9, 10, 11 );
          * @endcode
          */
        Hotboards_leds( int led0, int led1, int led2, int led3, int led4, int led5, int led6, bool on=HIGH );

        /** Create Hotboards_leds instance for eight leds
          * @param led7 pin where the led 7 will be connected
          * @param led6 pin where the led 6 will be connected
          * @param led5 pin where the led 5 will be connected
          * @param led4 pin where the led 4 will be connected
          * @param led3 pin where the led 3 will be connected
          * @param led2 pin where the led 2 will be connected
          * @param led1 pin where the led 1 will be connected
          * @param led0 pin where the led 0 will be connected
          * @param on logic level to turn on the leds
          *
          * Example:
          * @code
          *   // one instance with 8 leds on pins 5, 6, 7, 8, 9, 10, 11 and 12
          *   Hotboards_leds led( 5, 6, 7, 8, 9, 10, 11, 12 );
          * @endcode
          */
        Hotboards_leds( int led0, int led1, int led2, int led3, int led4, int led5, int led6, int led7, bool on=HIGH );

        /** Turn on a single led
          * @param led led number to be turn on
          *
          * Example:
          * @code
          *   // instance one led on pin 5 and turn it on
          *   Hotboards_leds led( 5 );
          *   led.turnOn( );
          *
          *   // instance a bus with 4 leds
          *   Hotboards_leds leds( 5, 6, 7, 8 );
          *   // turn on led 2 on pin 7
          *   leds.turnOn( 2 );
          *   // turn on led 0 on pin 5
          *   leds.turnOn( 0 );
          * @endcode
          */
        void turnOn( uint8_t led=0 );

        /** Turn off a single led
          * @param led led number to be turn off
          *
          * Example:
          * @code
          *   // instance one led on pin 5 and turn it off
          *   Hotboards_leds led( 5 );
          *   led.turnOff( );
          *
          *   // instance a bus with 4 leds
          *   Hotboards_leds leds( 5, 6, 7, 8 );
          *   // turn off led 3 on pin 8
          *   leds.turnOff( 3 );
          *   // turn off led 0 on pin 5
          *   leds.turnOff( 0 );
          * @endcode
          */
        void turnOff( uint8_t led=0 );

        /** Toggle a single led
          * @param led led number to be toggled
          *
          * Example:
          * @code
          *   // instance one led on pin 7 and toggle it
          *   Hotboards_leds led( 7 );
          *   led.toggle( );
          *
          *   // instance a bus with 3 leds
          *   Hotboards_leds leds( 2, 3, 4 );
          *   // toggle led 2 on pin 4
          *   leds.toggle( 2 );
          *   // toggle led 1 on pin 3
          *   leds.toggle( 1 );
          * @endcode
          */
        void toggle( uint8_t led=0 );

        /** Write to an entire led bus
          * @param val value to be written
          *
          * Example:
          * @code
          *   // instance one led on pin 7 and write a 1 (aceptara valores de 0 a 1)
          *   Hotboards_leds led( 7 );
          *   led.write( 1 );
          *
          *   // instance a 4 leds bus (pin2->led0 ..... pin5->led3)
          *   Hotboards_leds leds( 2, 3, 4, 5 );
          *   // write the 10 value (it will accept values from 0 to 15)
          *   leds.write( 10 );
          *
          *   // instance an 8 leds bus (pin4->led0 ..... pin3->led7)
          *   Hotboards_leds leds( 4, 5, 6, 7, 8, 9, 10, 12 );
          *   // write the 134 value (it will accept values from 0 to 255)
          *   leds.write( 134 );
          * @endcode
          */
        void write( uint8_t val );

        /** Write to a single led on the bus created
          * @param val value to be written (0 or 1)
          *
          * Example:
          * @code
          * instance a 4 pins led bus (pin2->led0 ..... pin5->led3)
          *   Hotboards_expander leds( 2, 3, 4, 5 );
          *   // write a '1' (turn on) led2 (pin 4) and a '0' (turn off) on led3 (pin 5)
          *   leds.write( 2, 1 );
          *   leds.write( 3, 0 );
          * @endcode
          */
        void write( uint8_t pin, bool val );

        /** Read a single led or the entire bus
          * @return led states
          *
          * Example:
          * @code
          *   // instance on led on 7 and read its state (0 o 1)
          *   Hotboards_leds led( 7 );
          *   uint8_t var = led.read( );
          *
          *   // instance an 8 leds bus (pin2->led0 ..... pin9->led7)
          *   Hotboards_leds leds( 2, 3, 4, 5, 6, 7, 8, 9 );
          *   // read the leds value (from 0 to 255)
          *   uint8_t var = leds.read( );
          *
          *   // nstance a 4 leds bus (pin2->led0 ..... pin5->led3)
          *   Hotboards_leds leds( 2, 3, 4, 5 );
          *   // read led 1 state (pin 3)
          *   uint8_t val1 = leds.read( 1 );
          *   // read led 0 state (pin 2)
          *   uint8_t val2 = leds.read( 0 );
          * @endcode
          */
        uint8_t read( uint8_t led=0xff );

    private :
        void begin( uint8_t led, uint8_t pin );
        uint8_t _pin[ 8 ];
        uint8_t _leds;
        uint8_t _state;
        bool _on;
};

#endif
