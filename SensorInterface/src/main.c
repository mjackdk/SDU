#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include "usart.h" // scanf etc.

#define ADC_PIN 0 // ADC channel

// Function declaration
uint16_t adc_read(uint8_t adc_channel);

int main(){
    uart_init(); // initialize uart
    io_redirect(); // redirect input and output to host computer

    uint16_t adc_result;
    float voltage;
    float temperature;

    // Set Vref = AVcc
    ADMUX = (1<<REFS0);

    // Set prescaler to 128 and turn on ADC module
    ADCSRA = (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);

    while(1){
        _delay_ms(1000);
        adc_result = adc_read(ADC_PIN);
        printf("ADC reading: %d\n", adc_result);

        voltage = ((5.077/1024.0) * adc_result) - 1.0;
        printf("Voltage: %f\n", voltage);

        temperature = 100.0 * voltage;
        printf("Temperature: %f\n\n", temperature);

    }   
}

// Function definition
uint16_t adc_read(uint8_t adc_channel){

    ADMUX &= 0xf0; // clear previous channel
    ADMUX |= adc_channel; // set channel
    ADCSRA |= (1<<ADSC); // start conversion

    while((ADCSRA & (1<<ADSC))); // wait for conversion to complete

    return ADC;
}