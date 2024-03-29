// -----------------------------------main.c -------------------------------------

#ifdef UART0
    #include "../inc/uart0.h"
    #define UART_MSG "Hello, this is UART0\n"
#else
    #include "../inc/uart1.h"
    #define UART_MSG "Hello, this is UART1\n"
#endif
void main(){
    // intitialize UART
    uart_init();
    
    // say hello
    uart_puts(UART_MSG);
    printRpi();

    // echo everything back 
    while(1) {
    	//read each char
    	char c = uart_getc();

    	//send back twice
    	uart_sendc(c);
    	uart_sendc(c);
    }
}
