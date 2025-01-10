#include "stm32h723xx.h"
//Push BTN is Port C Pin 13
//Yellow led is Port E pin 1
int main(void) {
	RCC->AHB4ENR |= (1u << 4); //Enable port E
	RCC->AHB4ENR |= (1u << 2); //Enable port C

	//Set pin mode as output
	GPIOE->MODER &= ~(1U << 3);

	//Set pin mode as input
	GPIOC->MODER &= ~(1U << 27);
	GPIOC->MODER &= ~(1U << 26);



	while (1) {
if(GPIOC->IDR&(1U<<13)) // check input data register for BTN pin
	GPIOE->ODR |= (1U << 1);
else
	GPIOE->ODR &= ~(1U << 1);

		}

}
