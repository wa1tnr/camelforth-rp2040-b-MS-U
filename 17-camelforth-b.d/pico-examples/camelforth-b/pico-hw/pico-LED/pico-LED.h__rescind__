/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#undef LED_PIN_MASTER

#ifdef _BOARDS_PICO_H
    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 25;
        #define PIP_LENGTH 4777 // untested
    #endif
#endif

// itsybitsy
// https://github.com/adafruit/circuitpython/blob/main/ports/raspberrypi/boards/adafruit_itsybitsy_rp2040/pins.c#L32
#ifdef ADAFRUIT_ITSYBITSY_RP2040
    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 11;
        #define PIP_LENGTH 4777 // probably okay
    #endif
#endif

#ifdef ADAFRUIT_FEATHER_RP2040
    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 13;
        #define PIP_LENGTH 74777
    #endif
#endif

#ifdef PIMORONI_TINY2040
    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 13; // NO RESEARCH - validate me
        #define PIP_LENGTH 74777 // untested - no target locally available to try this
    #endif
#endif

#ifndef LED_PIN_MASTER
    #warning -7777 // pico-LED.h  found no researched definition for the onboard LED pin
    #warning -7778 // pico-LED.h  LED_PIN_MASTER assigned to GPIO13, on a guess!
    #define LED_PIN_MASTER 13 // assumes 'standard' D13 assignment per Arduino IDE sensibilities
    #define PIP_LENGTH 74777 // generic
    // -7777 // throw compile error
#endif

void _sht_sleep(void) {
    for (volatile int i = PIP_LENGTH ; i>0; i--) { }
}
