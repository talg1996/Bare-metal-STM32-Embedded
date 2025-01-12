#include <stdint.h>
#include <stdio.h>
#include "stm32h723xx.h"
#include "usart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

int cnt=0;
int main(void) {

	usart3_init();
	tim2_1hz_init();
	//Enable GPIOE
	RCC->AHB4ENR |= (1u << 4);

	//Set LED pin mode as output
	GPIOE->MODER &= ~(1U << 3);

	//Change data register value
	GPIOE->ODR |= (1U << 1); //Default led on

	while (1) {
		//Wait until timer finish count (update event)
		while (!(TIM2->SR & (1U << 0)));
		TIM2->SR &=~(1U<<0);
		printf("Counter is %d\n",cnt++);
		GPIOE->ODR ^= (1U << 1); //Toggle led
	}

}
