/* notes-arduino : A complete reference for Basic and Advanced Arduino Programming
 *
 * Copyright (c) 2023, Augusto Damasceno.
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 */


/* Macro representing the LED control using the IO 13. */
#define LED 13 

void setup() {
    /* Configure IO 13 on Arduino Uno to be output.
       IO 13 is connected to the built-in LED. */
    pinMode(LED, OUTPUT); 
}

void loop() {
    /* Set LED to HIGH */
    digitalWrite(LED, HIGH);
    /* Wait 500ms */
    delay(500);
    /* Set LED to LOW */
    digitalWrite(LED, LOW);
    /* Wait 500ms */
    delay(500);
}
