/*
 * PWM1.h
 *
 * Created: 17/4/2024 10:07:26
 *  Author: alane
 */ 


#ifndef PWM1_H_
#define PWM1_H_

#define F_CPU 16000000

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#define invertido 1
#define no_invertido 0

void initPWM1FastA(uint8_t inverted, uint16_t prescaler);
void initPWM1FastB(uint8_t inverted, uint16_t prescaler);
void changeDutyA1(uint8_t duty);
void changeDutyB1(uint8_t duty);




#endif /* PWM1_H_ */