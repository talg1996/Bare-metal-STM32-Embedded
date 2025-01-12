/*
 * tim.c
 *
 *  Created on: Jan 12, 2025
 *      Author: tlgdsy
 */

#include "stm32h723xx.h"

#include "tim.h"
//Use timer 2 at APB1 bus
inline __attribute__((always_inline)) void tim2_1hz_init(void){
	//Enable clock access to timer 2
		RCC->APB1LENR|=(1U<<0);
		//Let APB1LENR clock to stabilize.
		sysTickDelayMicro(1000);

	//Set prescalar value
	TIM2->PSC=6400-1;
	//Set auto reload value
	TIM2->ARR=10000-1;
	//Clear counter
	TIM2->CNT=0;

	//Enable timer
	TIM2->CR1|=(1U<<0);
}
