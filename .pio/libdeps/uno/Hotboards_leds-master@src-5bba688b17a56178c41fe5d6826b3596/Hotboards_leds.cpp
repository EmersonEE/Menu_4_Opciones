/*
  Hotboards_leds.cpp - Driver to control leds one at a time or in group
  Hotboards leds board (http://hotboards.org)
  Created by Diego Perez, January 16, 2016.
  Released into the public domain.
*/

#include "Hotboards_leds.h"

Hotboards_leds::Hotboards_leds( int led0, bool on )
{
    _leds = 1;
    _state = 0;
    _on = on;
    begin( 0, led0 );
}

Hotboards_leds::Hotboards_leds( int led0, int led1, bool on )
{
    _leds = 2;
    _state = 0;
    _on = on;
    begin( 0, led0 );
    begin( 1, led1 );
}

Hotboards_leds::Hotboards_leds( int led0, int led1, int led2, bool on )
{
    _leds = 3;
    _state = 0;
    _on = on;
    begin( 0, led0 );
    begin( 1, led1 );
    begin( 2, led2 );
}

Hotboards_leds::Hotboards_leds( int led0, int led1, int led2, int led3, bool on )
{
    _leds = 4;
    _state = 0;
    _on = on;
    begin( 0, led0 );
    begin( 1, led1 );
    begin( 2, led2 );
    begin( 3, led3 );
}

Hotboards_leds::Hotboards_leds( int led0, int led1, int led2, int led3, int led4, bool on )
{
    _leds = 5;
    _state = 0;
    _on = on;
    begin( 0, led0 );
    begin( 1, led1 );
    begin( 2, led2 );
    begin( 3, led3 );
    begin( 4, led4 );
}

Hotboards_leds::Hotboards_leds( int led0, int led1, int led2, int led3, int led4, int led5, bool on )
{
    _leds = 6;
    _state = 0;
    _on = on;
    begin( 0, led0 );
    begin( 1, led1 );
    begin( 2, led2 );
    begin( 3, led3 );
    begin( 4, led4 );
    begin( 5, led5 );
}

Hotboards_leds::Hotboards_leds( int led0, int led1, int led2, int led3, int led4, int led5, int led6, bool on )
{
    _leds = 7;
    _state =  0;
    _on = on;
    begin( 0, led0 );
    begin( 1, led1 );
    begin( 2, led2 );
    begin( 3, led3 );
    begin( 4, led4 );
    begin( 5, led5 );
    begin( 6, led6 );
}

Hotboards_leds::Hotboards_leds( int led0, int led1, int led2, int led3, int led4, int led5, int led6, int led7, bool on )
{
    _leds = 8;
    _state = 0;
    _on = on;
    begin( 0, led0 );
    begin( 1, led1 );
    begin( 2, led2 );
    begin( 3, led3 );
    begin( 4, led4 );
    begin( 5, led5 );
    begin( 6, led6 );
    begin( 7, led7 );
}

void Hotboards_leds::turnOn( uint8_t led )
{
    bitWrite( _state, led, _on );
    digitalWrite( _pin[ led ], bitRead( _state, led ) );
}
void Hotboards_leds::turnOff( uint8_t led )
{
    bitWrite( _state, led, !_on );
    digitalWrite( _pin[ led ], bitRead( _state, led ) );
}

void Hotboards_leds::toggle( uint8_t led )
{
    if( bitRead( _state, led ) == _on )
    {
        turnOff( led );
    }
    else
    {
        turnOn( led );
    }
}

uint8_t Hotboards_leds::read( uint8_t led )
{
    uint8_t i;
    uint8_t val = 0;

    if( led == 0xff )
    {
        for( i=0 ; i<_leds ; i++ )
        {
            bitWrite( val, i, bitRead( _state, i ) );
        }
    }
    else
    {
        val = bitRead( _state, led );
    }
    return val;
}

void Hotboards_leds::write( uint8_t val )
{
    uint8_t i;
    for( i=0 ; i<_leds ; i++ )
    {
        if( bitRead( val, i ) )
        {
            turnOn( i );
        }
        else
        {
            turnOff( i );
        }
    }
}

void Hotboards_leds::write( uint8_t pin, bool val )
{
    if( val == 1 )
    {
        turnOn( pin );
    }
    else
    {
        turnOff( pin );
    }
}

void Hotboards_leds::begin( uint8_t led, uint8_t pin )
{
    _pin[ led ] = pin;
    bitWrite( _state, led, !_on );

    pinMode( pin, OUTPUT );
    digitalWrite( pin, bitRead( _state, led ) );
}
