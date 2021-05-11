// #warning was called in itsy.h

// itsybitsy
// https://github.com/adafruit/circuitpython/blob/main/ports/raspberrypi/boards/adafruit_itsybitsy_rp2040/pins.c#L32
// boot2_w25q080
#ifdef ADAFRUIT_ITSYBITSY_RP2040
    #ifndef LED_PIN_MASTER
        #define LED_PIN_MASTER 11
        #define NPX_PIN 17
        #define NPX_PWR_PIN 16
        #define PIP_LENGTH 19777 // probably okay
        #define KB_PIP_LN  2444
        #define BLINK_MS_CF 60
    #endif

    #ifndef CF_PICO_PLATFORM
        #define FLASH_LIMIT 0x3FFFFF
        #define FLASH_MASK  0x3FF000
        #define CF_PICO_PLATFORM "Adafruit ItsyBitsy RP2040"
    #endif
#endif
