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
    /* Configure PB0 (8 on Arduino Uno) to be input.
        You can also use:
            DDRB &= ~(1 << PB0);
    */
    DDRB &= 0b11111110;
    /* Configure PB1 (9 on Arduino Uno) to be input.
        You can also use:
            DDRB &= ~(1 << PB1);
    */
    DDRB &= 0b11111101;
    /* Activate PULL UP for PB1 (9 on Arduino Uno).
        You can also use:
            DDRB |= (1 << PB1);
    */
    PORTB |= 0b00000010;

    while(1)
    { 
        if (PINB & 0b00000001) {
            /* High level on port PB0. */
        } else {
            /* Low level on port PB0. */
        }

        if (PINB & 0b00000010) {
            /* No connection or High level on port PB1. */
        } else {
            /* GND on port PB1. */
        }

    }

    return 0;
}
