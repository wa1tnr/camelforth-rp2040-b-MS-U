// establish an ident string to print to console
#include "pico/stdlib.h"
#undef CF_PICO_PLATFORM

#ifdef _BOARDS_PICO_H
    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Raspberry Pi Pico RP2040 "
    #endif
#endif

#ifdef ADAFRUIT_ITSYBITSY_RP2040
    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Adafruit ItsyBitsy RP2040"
    #endif
#endif

#ifdef ADAFRUIT_FEATHER_RP2040
    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Adafruit Feather RP2040  "
    #endif
#endif

#ifdef PIMORONI_TINY2040
    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Pimoroni Tiny2040        "
    #endif
#endif

#ifndef CF_PICO_PLATFORM
    #warning -7777 // pico-hardware-camelforth.h
    #warning -7778 // pico-hardware-camelforth.h
    #define CF_PICO_PLATFORM "Generic RP2040 target    "
    // -7777 // throw compile error
#endif
