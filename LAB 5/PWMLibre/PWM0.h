/*
 * PWM0.h
 *
 * Created: 17/4/2024 10:04:18
 *  Author: alane
 */ 


#ifndef PWM0_H_
#define PWM0_H_

#define F_CPU 16000000

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#define invertido 1
#define no_invertido 0

void initPWM0FastA(uint8_t inverted, uint16_t prescaler);
void initPWM0FastB(uint8_t inverted, uint16_t prescaler);
void changeDutyA0(uint8_t duty);
void changeDutyB0(uint8_t duty);




#endif /* PWM0_H_ */