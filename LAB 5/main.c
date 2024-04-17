/*
 * LAB 5.c
 *
 * Created: 16/4/2024 20:39:39
 * Author : alane
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <PWM1Libre/PWM1.h>
#include <ADC/ADC.h>
#define F_CPU 16000000

volatile uint8_t iADC = 0;
ISR(ADC_vect){
	
	ADCSRA &= ~(1<<ADIF);
	iADC = ADCH;
	changeDutyA1(iADC);
}

int main(void)
{	
	UCSR0B = 0;
	initADC();
    initPWM1FastA(0, 1024);
    while (1) 
    {
		
    }
}

