#include <stdint.h>
#include <stdio.h>
#include "stm32h723xx.h"
#include "usart.h"


int main(void) {

	usart3_init();
		//Enable GPIOE
		RCC->AHB4ENR |= (1u << 4);

		//Set LED pin mode as output
		GPIOE->MODER &= ~(1U << 3);

		//Change data register value
		GPIOE->ODR |= (1U << 1); //Default led on
	char c; // Store user keyboard press from PC
	while (1) {
		//Wait until the receive buffer is not empty due a user PC keypress
		c=usart_read();
		if(c=='1')
			//Turn on LED
			GPIOE->ODR |= (1U << 1);
		else
			//Turn off LED
			GPIOE->ODR &= ~(1U << 1);
		printf("char was press: %c\n",c);
	}

}
