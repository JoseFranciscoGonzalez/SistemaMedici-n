#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uartInit(unsigned int prescaler)
{
	UBRR0 = prescaler;
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
	UCSR0B = (1<<TXEN0);
}

void uartTX(unsigned char data)
{
  while(!(UCSR0A & (1<<UDRE0)));
  UDR0 = data;
}

void uartSendString(char * str)
{
  while(*str != '\0')
  {	
    uartTX(*str);	
    str++;
  }
}	

void send(uint16_t data)
{
	char buffer[2];
	sprintf(buffer, "%u", data);
	uartSendString(buffer);
	uartTX('\n');
}