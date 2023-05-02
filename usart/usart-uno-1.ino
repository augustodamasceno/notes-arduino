/* notes-arduino : A complete reference for Basic and Advanced Arduino Programming
 *
 * Copyright (c) 2023, Augusto Damasceno.
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 */

int messageNum;

void setup() {
    Serial.begin(9600);
    messageNum = 0;
}

void loop() {
    /* Send message through USART */
    Serial.print("Message ");
    Serial.println(messageNum);  
    messageNum++;
    
    /* Wait 1 second */
    delay(1000);
}