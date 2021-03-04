#define __SFR_OFFSET 0

#include <avr/io.h>

.global pwmInit

pwmInit:
	sbi DDRD, 6	

	ldi R16, (1<<COM0A1)|(1<<WGM01)|(1<<WGM00)
	out TCCR0A, R16

	ldi R16, (1<<CS02)|(1<<CS00) 
	out TCCR0B, R16

	ldi R16, 127 
	out OCR0A, R16
	ret
