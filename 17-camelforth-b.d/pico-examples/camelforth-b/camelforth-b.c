// Wed Apr 14 20:45:28 UTC 2021
// wa1tnr
// camelforth

/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdio.h"     // rp2040_flash_ops.inc
#include <stdlib.h>         // rp2040_flash_ops.inc
#include "pico/stdlib.h"
#include "hardware/flash.h" // rp2040_flash_ops.inc
#include "tusb.h"
// #include "cdc_device.h" // mystery location

// #define FLASH_TARGET_OFFSET_B (256 * 1024)
#define FLASH_TARGET_OFFSET_B 0x1E0000

// super kludge to do this here this way 27 Feb 2021:
const uint8_t *flash_target_contents_b = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET_B);


/// \tag::hello_uart[]

#define UART_ID uart0
#define BAUD_RATE 115200

#define UART_TX_PIN 0
#define UART_RX_PIN 1
extern void interpreter(void);
extern void _this_ws2812(void);
extern void crufty_printer(void);

extern void _pico_LED_init(void);
extern void _pico_pip(void);
extern void _pico_LED(void);

void _loop_delay_local(void) {
    if (tud_cdc_n_connected (0)) return;
    for (volatile int i=288;i>0;i--) { // 144 okay
        for (volatile int j=455555;j>0;j--) {
        }
        if (tud_cdc_n_connected (0)) return;
    }
}

void blink_loop(void) {
    _pico_pip();
    _loop_delay_local();
}

int main(void) {
    sleep_ms(1800);
    uart_init(UART_ID, BAUD_RATE);

    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    stdio_init_all();

    // uart_putc_raw(UART_ID, 'A');

    sleep_ms(800);
    // if bool     tud_cdc_n_connected       (uint8_t itf);
    _pico_LED_init();
    while (! tud_cdc_n_connected (0)) {
        blink_loop(); // no while - done only once
    }
    for (int i=3;i>0;i--) _pico_LED();
    // stale message text follows - poorly maintained.
    // poor testing of latest edits - may cause issues.  However, brief test seemed okay.
    uart_puts(UART_ID, "\r\n   camelforth-rp2040-b-MS-U r0.1.8-pre-alpha\r\n\r\n");
    printf(              "\n   camelforth-rp2040-b-MS-U r0.1.8-pre-alpha\n\n");

    uart_puts(UART_ID, "        +fl_sizing +alltargets +itsybitsy +blinkwait +feather\r\n");
    printf(            "        +fl_sizing +alltargets +itsybitsy +blinkwait +feather\n");

    uart_puts(UART_ID, "        +no_emit +auto_load +rewind +flaccept +erase +flwrite\r\n");
    printf(            "        +no_emit +auto_load +rewind +flaccept +erase +flwrite\n");

    uart_puts(UART_ID, "        +reflash +dump +blink +UART +USB\r\n");
    printf(            "        +reflash +dump +blink +UART +USB\n");

    crufty_printer(); // examine ram with this nonsense function

    _this_ws2812(); // do a NEOPIX thing here

    printf( "   NEOPIX activity here\n\n");

// kludge: bug with flash access in no_flash binary compile (see CMakeLists.txt for the toggle)
// #undef NO_FLASH_CMAKE
#ifdef NO_FLASH_CMAKE
    flash_range_erase(FLASH_TARGET_OFFSET_B, FLASH_SECTOR_SIZE);
    printf("   flash_range_erase is required (and completed).\n\n");
#endif

#define WANT_FORCED_ERASE_QTPY
#undef WANT_FORCED_ERASE_QTPY
#ifdef WANT_FORCED_ERASE_QTPY
    flash_range_erase(FLASH_TARGET_OFFSET_B, FLASH_SECTOR_SIZE);
    printf("   flash_range_erase is required (and completed).\n\n");
#endif // #ifdef WANT_FORCED_ERASE_QTPY

    // unsigned int start_address = (uint32_t) XIP_BASE + (uint32_t) FLASH_TARGET_OFFSET_B ;
    // printf("%s", "\n\n       start_address: ");
    // printf("%8X", start_address);

    // printf("%s", "\n");

    while(1) {
        interpreter(); // camelforth
    }
}
// END.

