// #include "pico/stdlib.h"

// #warning was called in tiny.h

#ifdef PIMORONI_TINY2040

    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 13; // NO RESEARCH - validate me
        #define PIP_LENGTH 74777 // untested - no target locally available to try this
        #define KB_PIP_LN  2444
        #define BLINK_MS_CF 60
    #endif

    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Pimoroni Tiny2040        "
        #define FLASH_LIMIT 0x7FFFFF
        #define FLASH_MASK  0x7FF000
    #endif

#endif

