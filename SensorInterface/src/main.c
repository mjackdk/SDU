#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#define ADC_PIN 0 // ADC channel

// Function declaration
uint16_t adc_read(uint8_t adc_channel);

int main(){

    uint16_t adc_result;

    // Set Vref = AVcc
    ADMUX = (1<<REFS0);

    // Set prescaler to 128 and turn on ADC module
    ADCSRA = (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);

    while(1){

        adc_result = adc_read(ADC_PIN);

        // do something...
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