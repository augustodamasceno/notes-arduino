/* notes-arduino : A complete reference for Basic and Advanced Arduino Programming
 *
 * Copyright (c) 2023, Augusto Damasceno.
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 */

/* CPU frequency */
#define F_CPU 16000000UL

/* Convenience functions for busy-wait delay loops */
#include <util/delay.h> 


char buffer[32];

unsigned char sendBufferUsart();


int main(){
    /* USART
         Character Size 8
         Stop Bit 1
         Baud Rate 9600
         No Parity */
    UCSR0B |= ( 1 << RXEN0) | ( 1 << TXEN0);
    UCSR0C |= ( 1 << UCSZ01 ) | ( 1 << UCSZ00 ) | ( 1 << USBS0) ;
    
    /* Baud Rate Setting for f_osc = 16MHz */
    unsigned int ubrr = 103;
    UBRR0H = ( unsigned char ) ( ubrr>>8) ;
    UBRR0L = ( unsigned char ) ubrr ;

    unsigned int messageNum = 0;

    while (1){
        /* Write a message in the buffer */
        sprintf(buffer,"Message %d\n", messageNum);
        messageNum++;

        /* Send buffer through USART */
        sendBufferUsart();

        /* Wait 1 second */
        _delay_ms(1000); 
    }

  return 0;
}

/* Send the buffer over USART */
unsigned char sendBufferUsart()
{
  unsigned char c = 0;
  while( buffer[c] != '\0' )
  {
    while (!( UCSR0A & (1<<UDRE0) )) ;
    UDR0 = buffer[c];
    c++;
  }
}
