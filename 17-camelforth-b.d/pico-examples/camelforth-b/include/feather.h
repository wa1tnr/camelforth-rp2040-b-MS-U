// #include "pico/stdlib.h"

// #warning was called in feather.h

#ifdef ADAFRUIT_FEATHER_RP2040

    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 13
        #define NPX_PIN 16
        #define NPX_PWR_PIN -1
        #define PIP_LENGTH 74777
        #define KB_PIP_LN  2444
        #define BLINK_MS_CF 60
    #endif

    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Adafruit Feather RP2040  "
        #define FLASH_LIMIT 0x7FFFFF
        #define FLASH_MASK  0x7FF000
    #endif

#endif

