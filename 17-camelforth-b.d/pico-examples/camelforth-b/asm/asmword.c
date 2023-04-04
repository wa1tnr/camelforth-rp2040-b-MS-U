// cloop.c

// Thu 30 Mar 21:32:55 UTC 2023

// @ https://wokwi.com/projects/360645588605043713

#define PBLINKS 17 // how many blinks?

#include "hardware/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

void experiment_a_asm();

#ifdef __cplusplus
}
#endif

void asmword(void) {
    static volatile int c; // not volatile static as it was, prior
    c = (PBLINKS * 2) + 2;
    char *ram;
    ram = (char *) c;
    return experiment_a_asm(c, ram);
}

// END.
