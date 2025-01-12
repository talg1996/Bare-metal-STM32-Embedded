/*
 * adc.c
 *
 *  Created on: Jan 11, 2025
 *      Author: tlgdsy
 */

#include "stm32h723xx.h"
#include "adc.h"

#define ADC3_EN (1U<<24) //At RCC-> AHB4
#define GPIOF_EN (1U<<5) //At RCC-> GPIOF
//ADC3_IN17- Temp sensor

//ADC3_INP5 -> PF3

void pf3_ADC_int(void) {

	//** Configure ADC GPIO pin PF3 **//
	//Enable GPIOF clock
	RCC->AHB4ENR |= GPIOF_EN;

	//Configure PF3 as analog pin
	GPIOF->MODER |= (1U << 6);
	GPIOF->MODER |= (1U << 7);

	//Enable clock to ADC3
	RCC->AHB4ENR |= ADC3_EN;

	//Configure ADC3 parameters
	//Convention seq start
	//ADC3_INP5 -> PF3
	ADC3->SQR1|=(1U<<6);
	ADC3->SQR1|=(1U<<8);

	/*//ADC3_IN17- Temp sensor
		ADC3->SQR2|=(1U<<16);
		ADC3->SQR2|=(1U<<12);
		*/


	//Converttion seq length

	//ADC3->SQR1|=(1U<<0); //For two channels

	//Enable ADC3 module
	ADC3->CR|=(1U<<0);


}

void ADC_START(void){
	ADC3->CR|=(1U<<2);
}
uint32_t read_ADC(void){
	//Wait for end of conversion
	while(!(ADC3->ISR&(1U<<2)));
	return ADC3->DR;
}
