#include <stdio.h> // puts
#include "pico/stdlib.h"
#include "pico-hardware-camelforth.h" // NPX_PWR_PIN defined

// NEO_PWR is 11, QTPY RP2040
// NEOPIX is 12, QTPY RP2040
// #define RGB_PWR_PIN NPX_PWR_PIN
// #define RGB_PIN_MASTER 16 // rename as NEO_PWR
// NEOPIX on 17 ItsyRP2040

void _pico_RGB_init(void) {
    if (NPX_PWR_PIN == -1) {
        // puts("ck77p");
        // puts("Skipping power pin init entirely. Use no GPIO pin to power the NEOPIX.");
        return;
    }
    const uint RGB_PWR_PIN = NPX_PWR_PIN;
    gpio_init(RGB_PWR_PIN);
    // is this enough to operate push-pull:
    gpio_set_dir(RGB_PWR_PIN, GPIO_OUT);
    gpio_put(RGB_PWR_PIN, 1); // feather: raise D11 no harm done,
                              // feather: but no help, either
                              // feather: as its ws2812b has power 3.3 full time
}
