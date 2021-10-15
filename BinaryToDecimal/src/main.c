#include <avr/io.h>
#include <stdio.h>

#include "usart.h"

int power_of_2(int);

int main(void) {
    uart_init();
    io_redirect();

    while(1){
        long int bin;
        int dec = 0;
        int rem;

        printf("Type in a number: ");
        scanf("%ld", &bin);
        printf("\nBinary: %ld", bin);

        for (int i = 0; bin != 0; i++)
        {
            rem = bin % 10;
            bin /= 10;
            dec += rem * power_of_2(i);
        }
  
        printf("\nDecimal: %d\n\n", dec);
      
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