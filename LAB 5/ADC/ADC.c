/*
 * ADC.c
 *
 * Created: 16/4/2024 23:18:40
 *  Author: alane
 */ 
#include "ADC.h"
void initADC(){
	ADMUX=0;
	ADMUX |= (1<<REFS0);
	ADMUX |= (1<<ADLAR);
	ADMUX |= ((1<<MUX2) | (1<<MUX1));
	ADCSRA = 0;
	ADCSRA |= ((1<<ADEN) | (1<<ADIE));
	ADCSRA |= ((1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0));
	DIDR0 =0;
}
	