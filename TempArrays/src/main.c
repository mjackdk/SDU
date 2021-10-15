#include <avr/io.h>
#include <stdio.h>

#include "usart.h"

#define DAYS 7

int main(void) {
    uart_init();
    io_redirect();

    int min_temp = 100;
    int max_temp = -100;
    float sum_temp = 0;

    int temp_celcius[DAYS];

    for (int i = 0; i < DAYS; i++)
    {
        printf("\nTemp for day %d: ", i + 1);
        scanf("%d", &temp_celcius[i]);
    }
    for (int i = 0; i < DAYS; i++)
    {
        printf("\nTemp for day %d: %d", i + 1, temp_celcius[i]);
    }
    for (int i = 0; i < DAYS; i++)
    {
        if(temp_celcius[i] < min_temp){
            min_temp = temp_celcius[i];
        }
        if(temp_celcius[i] > max_temp){
            max_temp = temp_celcius[i];
        }
        sum_temp += temp_celcius[i];
    }
    printf("\nMinimal temp is: %d", min_temp);
    printf("\nMaximal temp is: %d", max_temp);
    printf("\nAverage temp is: %.1f", sum_temp/DAYS);

    return 0;
}