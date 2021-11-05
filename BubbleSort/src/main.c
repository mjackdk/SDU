// libraries from avr-libc, the AVR C runtime library
#include <avr/io.h> // device-specific IO definitions
#include <stdio.h> // standard IO facilities, printf etc.
#include <util/delay.h> // basic busy-wait delay loops, _delay_ms etc.

// local libraries
#include "usart.h" // scanf etc.

#define SIZE 10

void swap(int *, int *);

int main(void) {
    uart_init(); // initialize uart
    io_redirect(); // redirect input and output to host computer

    int a, b;
    int swaps = 0;
    int numbers[SIZE];

    while(1){

        // Exercise 1
        printf("Number a: ");
        scanf("%d", &a);
        printf("\nNumber b: ");
        scanf("%d", &b);
        printf("\nYou typed:\t%d\t%d", a, b);
        swap(&a, &b);
        printf("\nSwapped:\t%d\t%d\n\n", a, b);

        // Exercise 2
        printf("Original array: ");
        for (size_t i = 0; i < SIZE; i++)
        {
            printf("%6d\t", numbers[i]); // dummy values
        }
        printf("\n\n");

        do {
            swaps = 0;
            for (size_t i = 0; i < SIZE - 1; i++) // remember (SIZE - 1), sinde we're using (i + 1) in the loop
            {

                if (numbers[i] > numbers[i+1])
                {
                    swap(&numbers[i], &numbers[i+1]);
                    swaps = swaps + 1;
                }
                
            }
            
            // Bubbling away...
            printf("Sorting...: \t");
            for (size_t i = 0; i < SIZE; i++)
            {
                printf("%6d\t", numbers[i]);
            }
            printf("\n");

        } while (swaps > 0);

        printf("\n\nBubble sorted:\t");
        for (size_t i = 0; i < SIZE; i++)
        {
            printf("%6d\t", numbers[i]);
        }
        printf("\n\n");

    }
    
    return 0;
}

void swap(int * first_ptr, int * last_ptr) {
    int tmp;
    tmp = *first_ptr;
    *first_ptr = *last_ptr;
    *last_ptr = tmp;
}