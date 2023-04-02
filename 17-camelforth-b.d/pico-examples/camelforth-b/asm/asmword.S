@ asmword.S

@ Sun  2 Apr 21:09:45 UTC 2023

@ pry-points (mecrisp though)
@   tos .req r6
@   str tos, [psp]

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
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_ALT_PIN
   str    r0, [r1, #GPIO_OUT_XOR]
   ldr    r3, =COUNT

1: subs   r3, #1
   bne    1b
   pop    {pc}

.equ BLINKS, 3 + 1
.equ BLINK_TOGGLES, BLINKS * 2

run_program:
   push   {lr}
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_ALT_PIN
   str    r0, [r1, #GPIO_OUT_SET]

   movs   r2, #1
   movs   r3, #1

2: push  {r2}
   push  {r3}

   bl    blinking

   pop   {r3}
   pop   {r2}

   add    r3, r2
   cmp    r3, #BLINK_TOGGLES
   bne    2b
   pop    {pc}

@  --------------------   main   ------------------    

experiment_a_asm:
   push   {lr}
   bl     program_setup
   bl     run_program
   pop    {pc}

@ Set data alignment
.data
    .align 4

@ end.

