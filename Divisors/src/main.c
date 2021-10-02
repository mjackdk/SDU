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
        printf("\nDivisors:");

        for (int i = 1; i <= x; i++) {
          if (x % i == 0) {
            printf(" %d", i);
          }          
        }

        printf("\n");        
    }
    return 0;
}