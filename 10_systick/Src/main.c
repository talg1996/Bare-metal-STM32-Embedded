#include <stdint.h>
#include <stdio.h>
#include "stm32h723xx.h"
#include "usart.h"
#include "adc.h"
#include "systick.h"


int main(void) {

	usart3_init();

	//Enable GPIOE
			RCC->AHB4ENR |= (1u << 4);

			//Set LED pin mode as output
			GPIOE->MODER &= ~(1U << 3);

			//Change data register value
			GPIOE->ODR |= (1U << 1); //Default led on

	while (1) {
		sysTickDelayMicro(1000000);
		GPIOE->ODR ^= (1U << 1); //Toggle led
	}

}
