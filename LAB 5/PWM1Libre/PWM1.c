/*
 * PWM1.c
 *
 * Created: 17/4/2024 10:08:07
 *  Author: alane
 */ 
#include "PWM1Libre/PWM1.h"


void initPWM1FastA(uint8_t inverted, uint16_t prescaler){
	//Configuracion del PIN PB1
	DDRB |= (1<<DDB1);
	TCCR1A =0;
	TCCR1B=0;
	if (inverted)
	{
		//Invertido
		TCCR1A |= (1<<COM1A1)| (1<<COM1A0);
		}else{
		//No Invertido
		TCCR1A |= (1<<COM1A1);
	}
	//Seteo el FAST con Top ICR
	TCCR1A |= (1<<WGM11);
	TCCR1B |= (1<<WGM12) | (1<<WGM13);
	
	ICR1= 137;
	switch (prescaler)
	{
		case 0:
		TCCR1B |= (1<<CS10);
		break;

		case 8:
		TCCR1B |= (1<<CS11);
		break;
		
		case 64:
		TCCR1B |= (1<<CS10) | (1<<CS11);
		break;
		
		case 256:
		TCCR1B |= (1<<CS12);
		break;
		
		case 1024:
		TCCR1B |= (1<<CS12) | (1<<CS10);
		break;
		
		default:
		TCCR1B |= (1<<CS10);
	}
}
void initPWM1FastB(uint8_t inverted, uint16_t prescaler){
	//Configuracion del PIN PB2
	DDRB |= (1<<DDB2);
	if (inverted)
	{
		//Invertido
		TCCR1A |= (1<<COM1B1)| (1<<COM1B0);
		}else{
		//No Invertido
		TCCR1A |= (1<<COM1B1);
	}
	//Seteo el FAST de 10bits como OCR
	TCCR1A |= (1<<WGM10) | (1<<WGM11);
	TCCR1B |= (1<<WGM12);
	
	switch (prescaler)
	{
		case 0:
		TCCR1B |= (1<<CS10);
		break;

		case 8:
		TCCR1B |= (1<<CS11);
		break;
		
		case 64:
		TCCR1B |= (1<<CS10) | (1<<CS11);
		break;
		
		case 256:
		TCCR1B |= (1<<CS12);
		break;
		
		case 1024:
		TCCR1B |= (1<<CS12) | (1<<CS10);
		break;
		
		default:
		TCCR1B |= (1<<CS10);
	}
}
void changeDutyA1(uint8_t duty){
	OCR1A= duty;
}
void changeDutyB1(uint8_t duty){
	OCR1B= duty;
}