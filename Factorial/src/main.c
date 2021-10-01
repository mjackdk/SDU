#include <avr/io.h>
#include <stdio.h>

#include "usart.h"

int main(void) {
    uart_init();
    io_redirect();

    int n;

    while(1) {
        printf("Type in a number: ");
        scanf("%d", &n);
        printf("\nThe factorial of %d is ", n);

        for (int i = n - 1; i > 1; i--) {
            n = n * i;
        }

        printf("%d\n\n", n);
    }
    return 0;
}