/* notes-arduino : A complete reference for Basic and Advanced Arduino Programming
 *
 * Copyright (c) 2023, Augusto Damasceno.
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 */

/* CPU frequency */
#define F_CPU 16000000UL


int main(){
    /* Timer/Counter 0 
         Mode of Operation Normal (OC0A and OC0B disconnected):
           In this mode the counting direction is always up (incrementing),
             and no counter clear is performed. The counter simply overruns 
             when it passes its maximum 8-bit value (TOP = 0xFF) and then 
             restarts from the bottom (0x00).
         No clock prescaling
    */
    TCCR0B |= (1 << CS00);
    /* Call an interruption at overflow (16 MHz divided by 256 parts = 62.5 KHz, 16us to count to 255). */
    TIMSK0 |= (1 << TOIE0);

    /* Set Global Interrupt Enable */
    sei();

    while (1){}

  return 0;
}

/* Interruption by overflow of counter 0 */
ISR(TIMER0_OVF_vect)
{
    /* Do someting. */
}