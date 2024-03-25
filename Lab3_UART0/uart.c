#include "uart.h"
#include "gpio.h"
uart_init(){
    unsigned int r;
    UART_CR = 0x00;
    r = GPFSEL1;

    r &= ~(7<<12);
    r &= ~(7<<15);

    r |= (4<<12);
    r |= (4<<15);

    GPFSEL1 = r;

    GPPUD = 0;
    r = 150; while(r--){ asm volatile ("nop"); };
    GPPUDCLK0 = (1<<14) | (1<<15);
    r = 150; while(r--){ asm volatile ("nop"); };
    GPPUDCLK0 = 0;


}