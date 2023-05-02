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

int ad;

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
