@ asmword.S

@ was: cloop.S

@ Thu 30 Mar 21:31:32 UTC 2023

@ https://wokwi.com/projects/360645588605043713

@ - - - - -   architecture flags   - - - - -

.syntax unified
.cpu    cortex-m0plus
.thumb

.global experiment_a_asm
.align 4


@ - - - - -   pico-sdk constants   - - - - -

.equ IO_BANK0_BASE       , 0x40014000
.equ GPIO_09_CTRL        , IO_BANK0_BASE + 8 *  9 + 4
.equ GPIO_25_CTRL        , IO_BANK0_BASE + 8 * 25 + 4

.equ SIO_BASE            , 0xd0000000
.equ GPIO_OE_SET         , 0x024 @ GPIO output enable set
.equ GPIO_OUT_SET        , 0x014 @ GPIO output value set
.equ GPIO_OUT_CLR        , 0x018 @ GPIO output value clear
.equ GPIO_OUT_XOR        , 0x01c @ GPIO output value XOR

@ - - - - -   program constants   - - - - -

@  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
@  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
@  -  -  -  -  -  -     configure me   -  -  -  -  -  -  -  -

        .equ toggle_flash_vs_buzz, 1 @ or 0 to buzz

@  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
@  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
@  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -


.equ LED_PIN             , 25 @ builtin
.equ LED_ALT_PIN         ,  9

.equ ITERATIONS          ,  8 @ default to buzzer
.equ TRIMMED_ITER        ,  3

.equ TONE_COEFFIC        , 0x40 @ 0x02 0x04 0x08.. only

#include "config.S"

gpio09_lit:
   push  {lr}
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_ALT_PIN @ 9
   str    r0, [r1, #GPIO_OUT_SET]
   pop   {pc}

gpio09_dark:
   push  {lr}
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_ALT_PIN @ 9
   str    r0, [r1, #GPIO_OUT_CLR]
   pop   {pc}

many_nops:
   push  {lr}
   movs   r2, #1
   movs   r3, #1
1: push  {r2}
   push  {r3}
   nop   @ payload
   pop   {r3}
   pop   {r2}
   add    r3, r2
   cmp    r3, #TONE_COEFFIC @ iterations
   bne    1b
   pop   {pc}

payload_a:
   push  {lr}
   push  {r2}
   push  {r3}
   bl many_nops
   pop   {r3}
   pop   {r2}
   pop   {pc}

counted_b:
   push  {lr}
   movs  r2, #1
   movs  r3, #1
1: push  {r2}
   push  {r3}
   bl    payload_a
   pop   {r3}
   pop   {r2}
   add    r3, r2
   cmp    r3, #ITERATIONS
   bne    1b
   pop   {pc}

counted_a:
   push  {lr}
   movs   r2, #1
   movs   r3, #1
1: push  {r2}
   push  {r3}
   bl    counted_b
   pop   {r3}
   pop   {r2}
   add    r3, r2
   cmp    r3, #ITERATIONS
   bne    1b
   pop   {pc}

counted:
   push  {lr}
   movs   r2, #1
   movs   r3, #1
1: push  {r2}
   push  {r3}
   bl    counted_a
   pop   {r3}
   pop   {r2}
   add    r3, r2
   cmp    r3, #ITERATIONS
   bne    1b
   pop   {pc}

led_delayed:
   push  {lr}
   bl counted
   pop   {pc}

toggle_gpio09:
   push  {lr}
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_ALT_PIN
   str    r0, [r1, #GPIO_OUT_XOR]
   pop   {pc}

toggle_gpio25:
   push  {lr}
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_PIN
   str    r0, [r1, #GPIO_OUT_XOR]
   pop   {pc}

blinking:
   push  {lr}
   bl    toggle_gpio25
   bl    toggle_gpio25
   bl    led_delayed
   bl    toggle_gpio09
   bl    led_delayed
   pop   {pc}

gpio25_lit:
   push  {lr}
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_PIN @ 25
   str    r0, [r1, #GPIO_OUT_SET]
   pop   {pc}

gpio25_dark:
   push  {lr}
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_PIN @ 25
   str    r0, [r1, #GPIO_OUT_CLR]
   pop   {pc}

setup_gpio09:
   push  {lr}
   // Set GPIO[09] function to single-cyle I/O
   ldr    r1, =GPIO_09_CTRL
   movs   r0, #5
   str    r0, [r1]
   // Set GPIO[09] output enable
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_ALT_PIN @ 9
   str    r0, [r1, #GPIO_OE_SET]
   pop   {pc}

setup_gpio25:
   push  {lr}
   // Set GPIO[25] function to single-cyle I/O
   ldr    r1, =GPIO_25_CTRL
   movs   r0, #5
   str    r0, [r1]
   // Set GPIO[25] output enable
   ldr    r1, =SIO_BASE
   ldr    r0, =1<<LED_PIN @ 25
   str    r0, [r1, #GPIO_OE_SET]
   pop   {pc}

gpio_setup:
   push  {lr}
   bl    setup_gpio25
   bl    setup_gpio09
   pop   {pc}

program_setup:
   push  {lr}
   bl    gpio_setup
   pop   {pc}

traploop:
1: bl    blinking
   bne   1b

@  --------------------   main   ------------------    

experiment_a_asm:
   bl    program_setup
   bl    gpio09_lit
   bl    toggle_gpio25
   b     traploop

@ Set data alignment
.data
    .align 4

@ end.

