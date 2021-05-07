// #include "pico/stdlib.h"

// #warning was called in qtpy.h
#warning was called in qtpy.h

#ifdef ADAFRUIT_QTPY_RP2040

    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 26;
        #define PIP_LENGTH 74777
        #define KB_PIP_LN  2444
        #define BLINK_MS_CF 60
    #endif

    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Adafruit QT Py RP2040    "
        #define FLASH_LIMIT 0x3FFFFF // says 8 MB here and there - not sure
        #define FLASH_MASK  0x3FF000
    #endif

#endif

