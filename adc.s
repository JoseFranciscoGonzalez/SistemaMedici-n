#define __SFR_OFFSET 0
#include <avr/io.h>

.global adcInit
.global adcGet

.comm LOW, 1
.comm HIGH, 1

.global LOW
.global HIGH

adcInit:
	ldi R16, (1<<MUX0)
	sts ADMUX, R16

	ldi R16, (1<<ADEN)|(1<<ADSC)|(1<<ADPS2)|(1<<ADPS1)|(0<<ADPS1)
	sts ADCSRA, R16
	ret

adcGet:

	wait:
		lds R16, ADCSRA       
		sbrs R16, ADIF   
		rjmp wait 

		lds R16, ADCL
		sts LOW, R16

		lds R16, ADCH
		sts HIGH, R16
	
	lds R16, ADCSRA
	ori R16, (1<<ADSC)
	sts ADCSRA, R16
		
	ret
