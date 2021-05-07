#ifndef _PICO_HARDWARE_INCLUDES_LOCAL_CF
#define _PICO_HARDWARE_INCLUDES_LOCAL_CF
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
#undef LED_PIN_MASTER
#undef CF_PICO_PLATFORM
#undef FLASH_LIMIT
#undef FLASH_MASK
#undef KB_PIP_LN
#undef BLINK_MS_CF

// this message appears twice during the build:

// #warning all defs undef in pico-harware-camelforth.h

#ifdef HW_CALLED_IN_FORTH_C
// #warning was called in forth.c
#endif

#include "pico2040.h"
#include "itsy.h"
#include "feather.h"
#include "tiny2040.h"
#include "qtpy.h"

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
    #define KB_PIP_LN  2444
    #define BLINK_MS_CF 60
    // -7777 // throw compile error
#endif

#ifdef HW_CALLED_IN_PICO_LED_C
// #warning was called in pico-LED.c
void _sht_sleep(void) {
    for (volatile int i = PIP_LENGTH ; i>0; i--) { }
}
#endif

#endif // #define _PICO_HARDWARE_INCLUDES_LOCAL_CF
