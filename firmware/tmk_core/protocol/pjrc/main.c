/* Keyboard example with debug channel, for Teensy USB Development Board
 * http://www.pjrc.com/teensy/usb_keyboard.html
 * Copyright (c) 2008 PJRC.COM, LLC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include "keyboard.h"
#include "usb.h"
#include "matrix.h"
#include "print.h"
#include "debug.h"
#include "sendchar.h"
#include "util.h"
#include "suspend.h"
#include "host.h"
#include "pjrc.h"
#include "led.h"
#include "light_ws2812.h"


#define CPU_PRESCALE(n)    (CLKPR = 0x80, CLKPR = (n))

struct cRGB led[1];

int main(void)
{
    // set for 16 MHz clock
    CPU_PRESCALE(0);

    keyboard_setup();

    // Initialize the USB, and then wait for the host to set configuration.
    // If the Teensy is powered without a PC connected to the USB port,
    // this will wait forever.
    usb_init();
    while (!usb_configured()) /* wait */ ;

    print_set_sendchar(sendchar);

    led_init();
    keyboard_init();
    host_set_driver(pjrc_driver());
#ifdef SLEEP_LED_ENABLE
    sleep_led_init();
#endif
    while (1) {
        while (suspend) {
            suspend_power_down();
            if (remote_wakeup && suspend_wakeup_condition()) {
                usb_remote_wakeup();
            }
        }

        keyboard_task(); 
    }

// testing WS2812 LEDs
// while(1)
//   {
//     led[0].r=255;led[0].g=00;led[0].b=0;    // Write red to array
//     ws2812_setleds(led,2);
//     _delay_ms(500);                         // wait for 500ms.

//     led[0].r=0;led[0].g=255;led[0].b=0;         // green
//     ws2812_setleds(led,2);
//     _delay_ms(500);

//     led[0].r=0;led[0].g=00;led[0].b=255;        // blue
//     ws2812_setleds(led,2);
//     _delay_ms(500);
//   }
    
}
