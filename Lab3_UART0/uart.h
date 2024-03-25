// -----------------------------------uart.h -------------------------------------
/* Auxilary mini UART (UART1) registers */
#define UART_DR (* (volatile unsigned int*)(MMIO_BASE+0x00201000))
#define UART_RSRECR (* (volatile unsigned int*)(MMIO_BASE+0x00201004))
#define UART_FR (* (volatile unsigned int*)(MMIO_BASE+0x00201018))
#define UART_ILPR (* (volatile unsigned int*)(MMIO_BASE+0x00201020))
#define UART_IPRD (* (volatile unsigned int*)(MMIO_BASE+0x00201024))
#define UART_FBRD (* (volatile unsigned int*)(MMIO_BASE+0x00201028))
#define UART_LCRH (* (volatile unsigned int*)(MMIO_BASE+0x0020102c))
#define UART_CR (* (volatile unsigned int*)(MMIO_BASE+0x00201030))
#define UART_IFLS (* (volatile unsigned int*)(MMIO_BASE+0x00201034))
#define UART_IMSC (* (volatile unsigned int*)(MMIO_BASE+0x00201038))
#define UART_RIS (* (volatile unsigned int*)(MMIO_BASE+0x0020103c))
#define UART_MIS (* (volatile unsigned int*)(MMIO_BASE+0x00201040))
#define UART_ICR (* (volatile unsigned int*)(MMIO_BASE+0x00201044))
#define UART_DMACR (* (volatile unsigned int*)(MMIO_BASE+0x00201048))
#define UART_ITCR (* (volatile unsigned int*)(MMIO_BASE+0x00201080))
#define UART_ITIP (* (volatile unsigned int*)(MMIO_BASE+0x00201084))
#define UART_ITOP (* (volatile unsigned int*)(MMIO_BASE+0x00201088))
#define UART_TDR (* (volatile unsigned int*)(MMIO_BASE+0x0020108c))

void uart_init();
void uart_sendc(char c);
void uart_getc();
void uart_puts(char c);