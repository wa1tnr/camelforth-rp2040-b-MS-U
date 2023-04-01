@ Thu 30 Mar 22:11:51 UTC 2023

@ config.S

@ https://wokwi.com/projects/360645588605043713

@ not the user interface:
.if (toggle_flash_vs_buzz == 1)
.equ it_buzzes, 0
.equ it_flashes, 1
.endif

.if (toggle_flash_vs_buzz == 0)
.equ it_buzzes, 1
.equ it_flashes, 0
.endif

.if (it_buzzes == 1)
  .equ ITERATIONS          ,  8
  .equ TRIMMED_ITER        ,  4
.endif

.if (it_flashes == 1)
  .equ ITERATIONS          ,  32
  .equ TRIMMED_ITER        ,  8
.endif

@ end.

