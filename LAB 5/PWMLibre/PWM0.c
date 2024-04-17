/*
 * PWM0.c
 *
 * Created: 17/4/2024 10:05:30
 *  Author: alane
 */ 
#include "PWMLibre/PWM0.h"
void initPWM0FastA(uint8_t inverted, uint16_t prescaler){
	//Configuracion del PIN PD6
	DDRD |= (1<<DDD6);
	TCCR0A =0;
	TCCR0B=0;
	if (inverted)
	{
		//Invertido
		TCCR0A |= (1<<COM0A1)| (1<<COM0A0);
		}else{
		//No Invertido
		TCCR0A |= (1<<COM0A1);
	}
	//Seteo el top como OCRA
	TCCR0A |= (1<<WGM00) | (1<<WGM01);
	
	switch (prescaler)
	{
		case 0:
		TCCR0B |= (1<<CS00);
		break;

		case 8:
		TCCR0B |= (1<<CS01);
		break;
		
		case 64:
		TCCR0B |= (1<<CS00) | (1<<CS01);
		break;
		
		case 256:
		TCCR0B |= (1<<CS02);
		break;
		
		case 1024:
		TCCR0B |= (1<<CS02) | (1<<CS00);
		break;
		
		default:
		TCCR0B |= (1<<CS00);
	}
	
}

void initPWM0FastB(uint8_t inverted, uint16_t prescaler){
	//Configuracion del PIN PD5
	DDRD |= (1<<DDD5);
	
	if (inverted)
	{
		//Invertido
		TCCR0A |= (1<<COM0B1)| (1<<COM0B0);
		}else{
		//No Invertido
		TCCR0A |= (1<<COM0B1);
	}
	
	//Seteo el top como OCR
	TCCR0A |= (1<<WGM00) | (1<<WGM01);
	
	switch (prescaler)
	{
		case 0:
		TCCR0B |= (1<<CS00);
		break;

		case 8:
		TCCR0B |= (1<<CS01);
		break;
		
		case 64:
		TCCR0B |= (1<<CS00) | (1<<CS01);
		break;
		
		case 256:
		TCCR0B |= (1<<CS02);
		break;
		
		case 1024:
		//Prescaler de 1024
		TCCR0B |= (1<<CS02) | (1<<CS00);
		break;
		
		default:
		TCCR0B |= (1<<CS00);
	}
}

void changeDutyA0(uint8_t duty){
	OCR0A= duty;
}

void changeDutyB0(uint8_t duty){
	OCR0B= duty;
}