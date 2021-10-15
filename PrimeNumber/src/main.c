#include <avr/io.h>
#include <stdio.h>

#include "usart.h"

int is_prime(int);

int main(void) {
    uart_init();
    io_redirect();

    int n;

    while(1){
        printf("Type in a number: ");
        scanf("%d", &n);

        if(is_prime(n) == 1){
            printf("\n%d is not a prime number\n", n);
        }
        else{
            printf("\n%d is a prime number\n", n);
        }
    }
    return 0;
}

int is_prime(int number){
    int flag = 0;

    for (int i = 2; i < number - 1; i++)
    {
        if(number % i == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}