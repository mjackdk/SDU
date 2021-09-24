// libraries from avr-libc, the AVR C runtime library
#include <avr/io.h> // device-specific IO definitions
#include <stdio.h> // standard IO facilities. printf etc.
#include <util/delay.h> // basic busy-wait delay loops, _delay_ms etc.

// local libraries
#include "usart.h" // scanf etc.

int main(void) {
    uart_init(); // initialize uart
    io_redirect(); // redirect input and output to host computer

    int x;

    while(1){
        _delay_ms(1000);
        printf("Type in a number: ");
        scanf("%d", &x);
        printf("You typed %d\n", x);
    }
    return 0;
}