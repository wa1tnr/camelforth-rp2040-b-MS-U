#include <stdio.h>
#include "pico/stdio.h"     // rp2040_flash_ops.inc
#include <stdlib.h>         // rp2040_flash_ops.inc
#include "pico/stdlib.h"
#include "hardware/flash.h" // rp2040_flash_ops.inc
#include "tusb.h"
#include "pico/fix/rp2040_usb_device_enumeration.h" // COMMENT SOURCE OF THIS
#define FLASH_TARGET_OFFSET_B 0x1E0000
const uint8_t *flash_target_contents_b = (const uint8_t *) (XIP_BASE + FLASH_TARGET_OFFSET_B);

#define UART_ID uart0
#define BAUD_RATE 115200

#define UART_TX_PIN 0
#define UART_RX_PIN 1
extern void interpreter(void);
extern int _this_ws2812();
extern void crufty_printer(void);
extern void _pico_LED_init(void);
extern void _pico_pip(void);
extern int _pico_LED(void);

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

extern void rp2040_usb_device_enumeration_fix(void);
int main(void) {
    stdio_init_all();
    sleep_ms(1200);
    rp2040_usb_device_enumeration_fix();
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    _pico_LED_init();
    while (! tud_cdc_n_connected (0)) {
        blink_loop(); // no while - done only once
    }
    for (int i=3;i>0;i--) _pico_LED();
    uart_puts(UART_ID, "\r\n   camelforth-rp2040-b-MS-U r0.1.8-pre-alpha\r\n\r\n");
    int result = _this_ws2812(); // do a NEOPIX thing here
    printf( "   NEOPIX activity here\n\n\n");
    printf( "   gowfann rheadi      \n\n");
    uint32_t start_address = (uint32_t) XIP_BASE + (uint32_t) FLASH_TARGET_OFFSET_B ;
    while(1) {
        interpreter(); // camelforth
    }
}
