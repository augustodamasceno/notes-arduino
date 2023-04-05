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

char buffer[32];
int ad;
int freq;

int main() {
  /* ADC Configuration
       Voltage Reference = AVCC.
       No ADC Left Adjust Result (use the 10 bits).
       Input Channel = ADC0.
       ADC Enable.
       ADC Prescaler = 128 (125 KHz). */ 
  ADMUX |= (1<<REFS0);
  ADCSRA |= (1<<ADEN) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);

  while (1) {
    /* Start Conversion: bit ADSC to one. */
    ADCSRA |= 0b01000000;
    /* Wait Conversion */
    while ( !(ADCSRA & (1 << ADIF)) ){}
    /* Get AD conversion result (0 to 1023 representing 0V to the voltage reference).
       You can set ADLAR in ADMUX to one 
         and use the ADCH to get only 8 bits resolution 
         (0 to 255 representing 0V to Reference Voltage).
    */
    ad = ADC;

    /* Use the ad value in your system. */
  }

  return 0;
}
