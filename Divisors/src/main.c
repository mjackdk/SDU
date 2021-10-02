#include <avr/io.h>
#include <stdio.h>

#include "usart.h"

int main(void) {
    uart_init();
    io_redirect();

    int x;

    while(1){
        printf("Type in a number: ");
        scanf("%d", &x);
        printf("You typed %d\n", x);
    }
    return 0;
}