#define F_CPU 16000000UL

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#include "usart.h"

int main(void) {

    uart_init(); // open the communication to the microcontroller
    io_redirect(); // redirect input and output to the communication

    while(1) {

        _delay_ms(1000)	;
		
        printf("Hello World!!! \n");

    }

    return 0;
    
}
