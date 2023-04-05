@ asmword.S

@ Wed  5 Apr 22:29:36 UTC 2023
@ https://wokwi.com/projects/361207971675445249

@ pry-points (mecrisp though)
@   tos .req r6
@   str tos, [psp]

@ - - - - -   architecture flags   - - - - -

.syntax unified
.cpu    cortex-m0plus
.thumb

.global experiment_a_asm
.align 4


@ - - - - -   program constants   - - - - -


#ifndef NOT_WOKWI
#define HAVE_FOUND_WOKWI_ASM_ENVIRONMENT
#endif

#ifdef NOT_WOKWI
#define HAVE_FOUND_NON_WOKWI_ASM_ENVIRONMENT
#endif

#ifdef HAVE_FOUND_WOKWI_ASM_ENVIRONMENT
#warning led alt pin is 25 pio or wokwi

@ is also pio

    #ifndef IS_PIO_NOT_WOKWI
        #warning LINE 37  it is NOT PIO  I am not Herbert -Spok
        #warning LINE 38  LED_ALT_PIN_X  is  9  not  25
.equ LED_ALT_PIN         , 9 @ 25 @ 9
    #endif
    #ifdef IS_PIO_NOT_WOKWI
        #warning LINE 42  it is PIO
        #warning LINE 43  LED_ALT_PIN_X  is  25  not  9
.equ LED_ALT_PIN         , 25 @ 9 @ 25 @ 9
    #endif
#endif

#ifdef HAVE_FOUND_NON_WOKWI_ASM_ENVIRONMENT
#warning led alt pin is 25 non wokwi - expecting pico-sdk
#warning should not see this in pio build log - should see in pico-sdk cli build
#warning have seen this in the pico-sdk 5 April 2023 21:21 UTC
.equ LED_ALT_PIN         , 25 @ 9
#endif

.equ BLINKS              , 3 + 1
.equ BLINK_TOGGLES       , BLINKS * 2

@  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
@  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
@  -  -  -  -  -  -     configure me   -  -  -  -  -  -  -  -

        .equ toggle_flash_vs_buzz, 1 @ or 0 to buzz

@  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
@  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
@  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -


@ - - - - -   pico-sdk constants   - - - - -
.equ IO_BANK0_BASE       , 0x40014000
.equ GPIO_CTRL           , IO_BANK0_BASE + 8 *  LED_ALT_PIN + 4
.equ SIO_BASE            , 0xd0000000

.equ GPIO_OE_SET         , 0x024 @ GPIO output enable set

.equ GPIO_OUT_SET        , 0x014 @ GPIO output value set
.equ GPIO_OUT_XOR        , 0x01c @ GPIO output value XOR

#include "config.S"

program_setup:
   push   {lr}
   ldr    r0, =GPIO_CTRL
   movs   r1, #5
   str    r1, [r0, 0]
   movs   r1, #1
   lsls   r1, r1, #LED_ALT_PIN
   ldr    r0, =SIO_BASE
   str    r1, [r0, #GPIO_OE_SET]
   pop    {pc}

blinking:
   push   {lr}
   push   {r0}
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_ALT_PIN
   str    r0, [r1, #GPIO_OUT_XOR]
   ldr    r3, =COUNT
1: subs   r3, #1
   bne    1b
   pop    {r0}
   pop    {pc}

run_program:
   push   {lr}
   push   {r0}
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_ALT_PIN
   str    r0, [r1, #GPIO_OUT_SET]
   pop   {r0}
   movs   r2, #1
   movs   r3, #1
2:
   push  {r2}
   push  {r3}
   bl    blinking
   pop   {r3}
   pop   {r2}
   add    r3, r2  // r3 accumulates the count
   push  {r3}
   mov    r1, r0
   pop   {r3}
   cmp    r3, r1     // cmp r3, #BLINK_TOGGLES
   bne    2b
   pop    {pc}

@  --------------------   main   ------------------

experiment_a_asm:
   push  {lr}
   ldr    r2, [r1, #0]
   @ movs   r0, r2         @ - - -  works with hard-coded constant for ram address?
   push  {r0}
   bl    program_setup
   pop   {r0}
   bl    run_program
   pop   {pc}

@ Set data alignment
.data
    .align 4

@ end.
