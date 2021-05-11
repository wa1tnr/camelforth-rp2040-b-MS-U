#include "pico/stdlib.h"

// NEO_PWR is 11, QTPY RP2040
// NEOPIX is 12, QTPY RP2040
#define RGB_PIN_MASTER 11
// #define RGB_PIN_MASTER 16 // rename as NEO_PWR
// NEOPIX on 17 ItsyRP2040

void _pico_RGB_init(void) {
    const uint RGB_PIN = RGB_PIN_MASTER;
    gpio_init(RGB_PIN);
    // is this enough to operate push-pull:
    gpio_set_dir(RGB_PIN, GPIO_OUT);
    gpio_put(RGB_PIN, 1); // feather: raise D11 no harm done,
                          // feather: but no help, either
                          // feather: as its ws2812b has power 3.3 full time
}
