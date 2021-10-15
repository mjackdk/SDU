#include <avr/io.h>
#include <stdio.h>

#include "usart.h"

int n;

int power_of_2(int);

int main(void) {
    uart_init();
    io_redirect();

    while(1){
        printf("Type in a number: ");
        scanf("%d", &n);
        printf("\n2^%d = %d\n\n", n, power_of_2(n));
    }
    return 0;
}

int power_of_2(int n){
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result = 2 * result;
    }
    return result;
}