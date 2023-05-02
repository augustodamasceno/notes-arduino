/* notes-arduino : A complete reference for Basic and Advanced Arduino Programming
 *
 * Copyright (c) 2023, Augusto Damasceno.
 * All rights reserved.
 * 
 * SPDX-License-Identifier: BSD-2-Clause
 */

int ad = 0;

void setup() {
}

void loop() {
    /* Get AD conversion result for input A0 */
    ad = analogRead(A0);

    /* Use the ad value in your system. */
}