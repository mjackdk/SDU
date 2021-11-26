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
    DDRC = 0xF0; // IO board PC0...3 as inputs, for buttons
    DDRD = 0xFF; // IO board PD4...7 as outputs, for LEDs
    PORTC = 0x3F; // enable internal pullups for PC0...3
    PORTD = 0x00; // set output LEDs to off
    i2c_init(); // initialize I2C communication
    ds1621_init(); // initialize temperature sensor
    LCD_init(); //initialize the LCD

    // double temperature;

    while (1){
        PORTC = 0b00111111;
        LCD_set_cursor(2,1);
        if (PINC == 0b00111110) { // is PC0 (DI1) connected to ground?
            printf("DI0");
            PORTD = 0b00010000; // then turn on PD4 (LED1)
        }
        _delay_ms(500);


/*      temperature = get_temperature();
        _delay_ms(500);
        LCD_set_cursor(1,1);
        printf("Temp = %.2f\337C   ", temperature);
 */

    }
}