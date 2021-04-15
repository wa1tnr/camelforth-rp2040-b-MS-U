// establish an ident string to print to console
// establish flash limits

/*

// 8 MB target flash:
#define FLASH_LIMIT 0x7FFFFF
#define FLASH_MASK  0x7FF000

// 4 MB target flash:
#define FLASH_LIMIT 0x3FFFFF
#define FLASH_MASK  0x3FF000

// 2 MB target flash:
#define FLASH_LIMIT 0x1FFFFF
#define FLASH_MASK  0x1FF000

*/

#include "pico/stdlib.h"
#undef CF_PICO_PLATFORM
#undef FLASH_LIMIT
#undef FLASH_MASK

#ifdef HW_CALLED_IN_FORTH_C
#warning was called in forth.c
#endif


#undef LED_PIN_MASTER


#ifdef _BOARDS_PICO_H
    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 25;
        #define PIP_LENGTH 4777 // untested
    #endif

    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Raspberry Pi Pico RP2040 "
        #define FLASH_LIMIT 0x1FFFFF
        #define FLASH_MASK  0x1FF000
    #endif
#endif

#ifdef ADAFRUIT_ITSYBITSY_RP2040

// itsybitsy
// https://github.com/adafruit/circuitpython/blob/main/ports/raspberrypi/boards/adafruit_itsybitsy_rp2040/pins.c#L32

    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 11;
        #define PIP_LENGTH 19777 // probably okay
    #endif

    #ifndef CF_PICO_PLATFORM
        #define FLASH_LIMIT 0x3FFFFF
        #define FLASH_MASK  0x3FF000
        #define CF_PICO_PLATFORM "Adafruit ItsyBitsy RP2040"
    #endif
#endif

#ifdef ADAFRUIT_FEATHER_RP2040

    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 13;
        #define PIP_LENGTH 74777
    #endif

    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Adafruit Feather RP2040  "
        #define FLASH_LIMIT 0x7FFFFF
        #define FLASH_MASK  0x7FF000
    #endif
#endif

#ifdef PIMORONI_TINY2040


    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 13; // NO RESEARCH - validate me
        #define PIP_LENGTH 74777 // untested - no target locally available to try this
    #endif


    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Pimoroni Tiny2040        "
        #define FLASH_LIMIT 0x7FFFFF
        #define FLASH_MASK  0x7FF000
    #endif
#endif

#ifndef CF_PICO_PLATFORM
    #warning -7777 // pico-hardware-camelforth.h
    #warning -7778 // pico-hardware-camelforth.h
    #define CF_PICO_PLATFORM "Generic RP2040 target    "
    #define FLASH_LIMIT 0x1FFFFF
    #define FLASH_MASK  0x1FF000
    // -7777 // throw compile error
#endif

#ifndef LED_PIN_MASTER
    #warning -7777 // pico-LED.h  found no researched definition for the onboard LED pin
    #warning -7778 // pico-LED.h  LED_PIN_MASTER assigned to GPIO13, on a guess!
    #define LED_PIN_MASTER 13 // assumes 'standard' D13 assignment per Arduino IDE sensibilities
    #define PIP_LENGTH 74777 // generic
    // -7777 // throw compile error
#endif

#ifdef HW_CALLED_IN_PICO_LED_C
#warning was called in pico-LED.c
void _sht_sleep(void) {
    for (volatile int i = PIP_LENGTH ; i>0; i--) { }
}
#endif

