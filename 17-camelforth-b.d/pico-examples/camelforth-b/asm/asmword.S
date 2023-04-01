@ asmword.S

@ Sat  1 Apr 21:01:54 UTC 2023

@ https://wokwi.com/

@ - - - - -   architecture flags   - - - - -

.syntax unified
.cpu    cortex-m0plus
.thumb

.global experiment_a_asm
.align 4



@ - - - - -   program constants   - - - - -
.equ LED_ALT_PIN         , 25 @ 9

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
.equ GPIO_OUT_XOR        , 0x01c @ GPIO output value XOR

#include "config.S"

experiment_b_asm:

   ldr    r0, =GPIO_CTRL
   movs   r1, #5
   str    r1, [r0, 0]

   movs   r1, #1
   lsls   r1, r1, #LED_ALT_PIN

   ldr    r0, =SIO_BASE
   str    r1, [r0, #GPIO_OE_SET]

loop:
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_ALT_PIN
   str    r0, [r1, #GPIO_OUT_XOR]

   ldr    r3, =COUNT
   bl     decrement
   b      loop

decrement:
   subs   r3, #1
   bne    decrement
   bx     lr

@  --------------------   main   ------------------    

experiment_a_asm:
   b      experiment_b_asm

@ Set data alignment
.data
    .align 4

@ end.

