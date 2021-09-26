#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include "usart.h"

int main(void) {
    uart_init();
    io_redirect();

    int current_temp;
    int min_temp;
    int max_temp;

    char initial_run = 1;

    while(1){
        _delay_ms(1000);
        printf("What is the temperature?: ");
        scanf("%d", &current_temp);

        if (initial_run == 1){
            min_temp = current_temp;
            max_temp = current_temp;
            initial_run = 0;
        }

        if (current_temp < min_temp){
            min_temp = current_temp; 
        }

        if (current_temp > max_temp){
            max_temp = current_temp; 
        }

        printf("\nCurrent temp: %d. ", current_temp);
        printf("Min temp: %d. Max temp: %d\n", min_temp, max_temp);
    }
    return 0;
}
