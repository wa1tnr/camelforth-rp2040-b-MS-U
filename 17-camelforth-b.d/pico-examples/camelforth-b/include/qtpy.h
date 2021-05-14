// #warning was called in qtpy.h

#ifdef ADAFRUIT_QTPY_RP2040
    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 26 // your choice; arbitrary
        #define NPX_PIN PICO_DEFAULT_WS2812_PIN // 12
        #define NPX_PWR_PIN PICO_DEFAULT_WS2812_POWER_PIN // 11
        #define PIP_LENGTH 74777
        #define KB_PIP_LN  2444
        #define BLINK_MS_CF 60
    #endif

    #ifndef CF_PICO_PLATFORM
        #define CF_PICO_PLATFORM "Adafruit QT Py RP2040    "
        #define FLASH_LIMIT 0x7FFFFF // 8 MB tested, somewhat
        #define FLASH_MASK  0x7FF000
    #endif
#endif
