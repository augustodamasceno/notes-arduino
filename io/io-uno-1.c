/* notes-arduino : A complete reference for Basic and Advanced Arduino Programming
 *
 * Copyright (c) 2023, Augusto Damasceno.
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 */

/* CPU frequency */
#define F_CPU 16000000UL 

/* AVR device-specific IO definitions */
#include <avr/io.h> 
/* Convenience functions for busy-wait delay loops */
#include <util/delay.h> 


int main()
{
        /* Configure PB5 (13 on Arduino Uno) to be output.
           IO 13 is connected to the built-in LED. 
           You can also use:
             DDRB |= (1 << 5);
             or
             DDRB |= (1 << PB5);
        */
        DDRB |= 0b00100000;
 
        while(1)
        { 
                /* Set PB5 to HIGH 
                   You can also use:
                     PORTB |= (1 << PB5);
                */
                PORTB |= 0b00100000;
      
                /* Wait 500ms */
                _delay_ms(500);
 
                /* Set PB5 to LOW 
                   You can also use:
                     PORTB &= ~(1 << PB5);
                */
                PORTB &= 0b11011111;
      
                /* Wait 500ms */
                _delay_ms(500); 
        }
  
        return 0;
}
