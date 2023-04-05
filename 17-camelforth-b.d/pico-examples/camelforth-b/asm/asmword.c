// cloop.c
// Tue  4 Apr 23:33:11 UTC 2023
// https://wokwi.com/projects/361121269426995201

#ifndef NOT_WOKWI
#define HAVE_FOUND_WOKWI_ENVIRONMENT
#warning this is very much wokwi
#endif

#ifdef NOT_WOKWI
#define HAVE_FOUND_NON_WOKWI_ENVIRONMENT
#warning this is not wokwi
#endif

#define PBLINKS 17 // how many blinks?
#include "hardware/gpio.h"

#ifdef HAVE_FOUND_WOKWI_ENVIRONMENT
#warning this is very much wokwi
#include <Arduino.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

void experiment_a_asm();

#ifdef __cplusplus
}
#endif



#ifdef HAVE_FOUND_WOKWI_ENVIRONMENT
#warning this setup function header
void setup(void) {
#endif

#ifdef HAVE_FOUND_NON_WOKWI_ENVIRONMENT
#warning this is  not wokwi asmword function header
void asmword(void) {
#endif
    static volatile int c; // not volatile static as it was, prior
    c = (PBLINKS * 2) + 2;
    unsigned int ram = &c;
    return experiment_a_asm(c, ram);
}

#ifdef HAVE_FOUND_WOKWI_ENVIRONMENT
#warning this is very much wokwi
void loop() {
    while(-1);
}
#endif

// END.
