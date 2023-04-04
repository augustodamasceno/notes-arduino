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
