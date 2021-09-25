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

    int min_is_set = 0;
    int max_is_set = 0;

    while(1){
        _delay_ms(1000);
        printf("What is the temperature?: ");
        scanf("%d", &current_temp);

        if (min_is_set == 0){
            min_temp = current_temp;
            min_is_set = 1;
        }
        if (max_is_set == 0){
            max_temp = current_temp;
            max_is_set = 1;
        }

        if (current_temp < min_temp){
            min_temp = current_temp; 
        }

        if (current_temp > max_temp){
            max_temp = current_temp; 
        }

        printf("\nCurrent temp: %d. Min temp: %d. Max temp: %d\n", current_temp, min_temp, max_temp);
    }
    return 0;
}