// cloop.c

// Thu 30 Mar 21:32:55 UTC 2023

// @ https://wokwi.com/projects/360645588605043713

#define PBLINKS 5 // how many blinks?

#include "hardware/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

void experiment_a_asm();

#ifdef __cplusplus
}
#endif

void asmword(void) {
    volatile static int c;
    c = (PBLINKS * 2) + 2;
    char *ram;
    ram = (char *) c;
    unsigned int *cptr = &ram;
    // passes both the value and the address to assembler routine:
    return experiment_a_asm(c, cptr);
}

// END.
