/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <avr/io.h>
#include "stdint.h"
#include "led.h"
#include "light_ws2812.h"


struct cRGB led[1];


void led_set(uint8_t usb_led)
{
	if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // output low
        // C7
	    DDRC  &= ~(1<<7);
	    PORTC |=  (1<<7);
	} else if (usb_led & (1<<USB_LED_STATUS1)) {
		// C6
	    DDRC  &= ~(1<<6);
	    PORTC |=  (1<<6);
	    // turn USB_LED_STATUS2 off
	    // DDRD  &= ~(1<<3);
	    // PORTD &= ~(1<<3);
	} else if (usb_led & (1<<USB_LED_STATUS2)) {
		// D3
	    DDRD  &= ~(1<<3);
	    PORTD |=  (1<<3);
	    // turn USB_LED_STATUS1 off
	    // DDRC  &= ~(1<<6);
	    // PORTC &= ~(1<<6);
    } else {
    	// Hi-Z
        DDRC  &= ~(1<<7);
        PORTC &= ~(1<<7);
	    DDRC  &= ~(1<<6);
	    PORTC &= ~(1<<6);
	    DDRD  &= ~(1<<3);
	    PORTD &= ~(1<<3);
    }
}

void led_toggle(uint8_t usb_led)
{
	if (usb_led & (1<<USB_LED_STATUS1)) {
		// C6
	    // DDRC  &= ~(1<<6);	
	    // PORTC ^=  (1<<6);
	    // D6
	    // DDRD  &= ~(1<<6);	
	    PORTD ^=  (1<<6);
    }
}

void led_init() 
{
	// set D6 low, turn off led
	// DDRD  |= (1<<6);
	// PORTD &= ~(1<<6);

	// // set C7 as output
	// DDRC  |= (1<<7);
	// set D4 as output
	DDRD  |= (1<<4);
	// drive red 
	led[0].r=50;led[0].g=0;led[0].b=0; 
	// drive green
	// led[1].r=0;led[1].g=0;led[1].b=50; 
    ws2812_setleds(led,1);

}
