#include <avr/io.h>
#include <stdio.h>

#include "usart.h"

int main(void) {
    uart_init();
    io_redirect();

    int secret;
    int guess;
    int attempts = 1;

    printf("[User 1] input number to guess: ");
    scanf("%d", &secret);
    printf("\n[User 2] make initial guess: ");
    scanf("%d", &guess);

    do
    {
        if(secret > guess) {
            attempts ++;
            printf("\n[User 2]: too low, try again: ");
            scanf("%d", &guess);
        }

        if(secret < guess) {
            attempts ++;
            printf("\n[User 2] too high, try again: ");
            scanf("%d", &guess);
        }
    } while (secret != guess);

    printf("\n[User 2] you found the secret number %d in %d attempts", secret, attempts);

    return 0;
}