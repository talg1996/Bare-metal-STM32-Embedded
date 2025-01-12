/*
 * tim.c
 *
 *  Created on: Jan 12, 2025
 *      Author: tlgdsy
 */

#include "stm32h723xx.h"
//PE1 to AF1
#include "tim.h"
//Use timer 2 at APB1 bus
 void tim2_1hz_init(void){
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

void tim12_1hz_init_output_compare_PA5(void){

	//Enable GPIOB
		RCC->AHB4ENR |= (1u << 1);
		sysTickDelayMicro(1000);

		//Set LED pin mode as alternate
		GPIOB->MODER &= ~(1U << 28);

		//Enable timer 2 output
		GPIOB->AFR[1]|=(1U<<25);




	//Enable clock access to timer 2
		RCC->APB1LENR|=(1U<<6);
		//Let APB1LENR clock to stabilize.
		sysTickDelayMicro(1000);

	//Set prescalar value
	TIM12->PSC=6400-1;
	//Set auto reload value
	TIM12->ARR=10000-1;

	//Set  output compare toggle mode
	//Enable ch1 in compare mode

	TIM12->CCMR1|=(1U<<4)|(1U<<5);// when CNT reach the compare value the output toggle

	//Enable output compare
	TIM12->CCER|=(1U<<0);
	//Clear counter
	TIM12->CNT=0;

	//Enable timer
	TIM12->CR1|=(1U<<0);
}
