// libraries from avr-libc, the AVR C runtime library
#include <avr/io.h> // device-specific IO definitions
#include <stdio.h> // standard IO facilities, printf etc.
#include <util/delay.h> // basic busy-wait delay loops, _delay_ms etc.

// local libraries
#include "usart.h" // scanf etc.
#include "lcd.h" // LCD
#include "i2cmaster.h" // I2C
#include "ds1621.h" // Temperature sensor

int main (void){
    i2c_init(); // initialize I2C communication
    ds1621_init(); // initialize temperature sensor
    LCD_init(); //initialize the LCD

    double temperature;

    while (1){
        temperature = get_temperature();
        _delay_ms(500);
        LCD_set_cursor(1,1);
        printf("Temp = %.2f\337C   ", temperature);
    }
}