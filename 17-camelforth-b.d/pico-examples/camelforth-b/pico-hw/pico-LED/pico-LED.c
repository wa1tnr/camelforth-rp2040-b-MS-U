/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
//here

#include "pico/stdlib.h"
#define HW_CALLED_IN_PICO_LED_C
#include "pico-hardware-camelforth.h"
// #include "pico-LED.h"

void _pico_LED_init(void) {
    const uint LED_PIN = LED_PIN_MASTER; // pico_LED.h
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

/*
void _sht_sleep(void) {
    for (volatile int i = 4777; i>0; i--) { }
}
*/
extern void _sht_sleep(void); // pico-LED.h

void _pico_pip(void) {
    const uint LED_PIN = LED_PIN_MASTER;
    gpio_put(LED_PIN, 1);
    _sht_sleep();
    gpio_put(LED_PIN, 0);
    sleep_ms(11);
}

void _pico_LED(void) {
    const uint LED_PIN = LED_PIN_MASTER;
    gpio_put(LED_PIN, 1);
    sleep_ms(BLINK_MS_CF); // 60 ms recent
    gpio_put(LED_PIN, 0);
    sleep_ms(500);
}
