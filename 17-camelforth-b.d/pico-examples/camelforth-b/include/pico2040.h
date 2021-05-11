// #include "pico/stdlib.h"

// #warning was called in pico.h

#ifdef _BOARDS_PICO_H

    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 25;
        #define NPX_PIN 19 // arbitrary external WS2812
        #define NPX_PWR_PIN -1
        #define PIP_LENGTH 4777 // untested
        #define KB_PIP_LN  2444
        #define BLINK_MS_CF 60
    #endif

    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Raspberry Pi Pico RP2040 "
        #define FLASH_LIMIT 0x1FFFFF
        #define FLASH_MASK  0x1FF000
    #endif

#endif

