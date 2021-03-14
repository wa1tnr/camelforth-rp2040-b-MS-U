/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#undef LED_PIN_MASTER

#ifdef _BOARDS_PICO_H
    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 25;
    #endif
#endif

#ifdef ADAFRUIT_FEATHER_RP2040
    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 13;
    #endif
#endif

#ifdef PIMORONI_TINY2040
    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 13; // NO RESEARCH - validate me
    #endif
#endif

#ifndef LED_PIN_MASTER
    #warning -7777 // pico-LED.h  found no researched definition for the onboard LED pin
    #warning -7778 // pico-LED.h  LED_PIN_MASTER assigned to GPIO13, on a guess!
    #define LED_PIN_MASTER 13 // assumes 'standard' D13 assignment per Arduino IDE sensibilities
    // -7777 // throw compile error
#endif
