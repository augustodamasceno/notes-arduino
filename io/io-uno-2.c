/* notes-arduino : A complete reference for Basic and Advanced Arduino Programming
 *
 * Copyright (c) 2023, Augusto Damasceno.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * 
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
