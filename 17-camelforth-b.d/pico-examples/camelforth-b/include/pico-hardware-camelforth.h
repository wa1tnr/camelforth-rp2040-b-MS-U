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

#warning in file pico-hardware-camelforth.h
#warning flash limits undefined
#warning want to know how many times this message displays

#ifdef _BOARDS_PICO_H
    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Raspberry Pi Pico RP2040 "
        #define FLASH_LIMIT 0x1FFFFF
        #define FLASH_MASK  0x1FF000
    #endif
#endif

#ifdef ADAFRUIT_ITSYBITSY_RP2040
    #ifndef CF_PICO_PLATFORM
        #define FLASH_LIMIT 0x3FFFFF
        #define FLASH_MASK  0x3FF000
        #define CF_PICO_PLATFORM "Adafruit ItsyBitsy RP2040"
    #endif
#endif

#ifdef ADAFRUIT_FEATHER_RP2040
    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Adafruit Feather RP2040  "
        #define FLASH_LIMIT 0x7FFFFF
        #define FLASH_MASK  0x7FF000
    #endif
#endif

#ifdef PIMORONI_TINY2040
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
