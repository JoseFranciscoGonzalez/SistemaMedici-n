#define F_CPU 16000000UL
#define BAUD 500000
#define PRESCALER 1

#include <avr/io.h>
#include <avr/delay.h>

#include "usart.h"

extern void pwmInit();
extern void adcInit();
extern void adcGet();

extern uint8_t HIGH, LOW;
	
uint16_t adc_data = 0;

int main(void)
{
	pwmInit();
	uartInit(PRESCALER);
	adcInit();
	
	while(1)
	{
		adcGet();
		adc_data =  LOW;
		adc_data |=  HIGH << 8;
		send(adc_data);
	}
	
	return 0;
}