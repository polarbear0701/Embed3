// -----------------------------------main.c -------------------------------------
#include "uart3.h"
void main(){
// intitialize UART
uart_init();
// say hello
uart_puts("Hello World!\n");
// echo everything back
while(1) {
//read each char
char c = uart_getc();
if (c>=65 && c <= 90){
    c +=32;
}
else if (c>= 97 && c <=122){
    c -= 32;
}
//send back twice
uart_sendc(c);
uart_sendc(c);
}
}