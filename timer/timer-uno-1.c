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