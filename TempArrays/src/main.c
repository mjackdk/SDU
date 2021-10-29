#include <avr/io.h>
#include <stdio.h>

#include "usart.h"

#define DAYS 7


// Function prototype
float convert(int);

int main(void) {
    uart_init();
    io_redirect();

    // Placeholder values
    int min_temp = 100;
    int max_temp = -100;
    float sum_temp = 0;

    int temp_celcius[DAYS];
    float temp_fahrenheit[DAYS];

    for (int i = 0; i < DAYS; i++)
    {
        printf("\nTemp for day %d: ", i + 1);
        scanf("%d", &temp_celcius[i]);
    }
    for (int i = 0; i < DAYS; i++)
    {
        printf("\nDay %d:\t%d C", i + 1, temp_celcius[i]);
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
    printf("\nMinimal temp is: %d C", min_temp);
    printf("\nMaximal temp is: %d C", max_temp);
    printf("\nAverage temp is: %.1f C", sum_temp/DAYS);

    for (int i = 0; i < DAYS; i++)
    {
        temp_fahrenheit[i] = convert(temp_celcius[i]);
        printf("\nDay %d:\t%d C\t%.1f F", i + 1, temp_celcius[i], temp_fahrenheit[i]);
    }
    return 0;
}

float convert(int c_temp){
    float f_temp = c_temp * 9.0 / 5 + 32;
    return f_temp;
}