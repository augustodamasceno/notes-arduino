/* notes-arduino : A complete reference for Basic and Advanced Arduino Programming
 *
 * Copyright (c) 2023, Augusto Damasceno.
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 */

void setup() {
    /* Configure IO 8 on Arduino Uno to be input. */
    pinMode(8, INPUT); 
    /* Configure IO 9 on Arduino Uno to be input with PULL UP activated. */
    pinMode(9, INPUT_PULLUP); 
}

void loop() {
    int val8 = digitalRead(8);
    int val9 = digitalRead(9);
    
    if (val8 == HIGH) {
        /* High level on port PB0. */
    } else {
        /* Low level on port PB0. */
    }

    if (val9 == HIGH) {
        /* No connection or High level on port PB1. */
    } else {
        /* GND on port PB1. */
    }
}
