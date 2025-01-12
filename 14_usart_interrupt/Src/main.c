#include <stdint.h>
#include <stdio.h>
#include "stm32h723xx.h"
#include "usart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

int main(void) {

	usart3_Rxinterrupt_init();

	//Enable GPIOE
		RCC->AHB4ENR |= (1u << 4);

		//Set LED pin mode as output
		GPIOE->MODER &= ~(1U << 3);

		//Change data register value
		GPIOE->ODR |= (1U << 1); //Default led on

	while (1) {

	}

}


//Interrupt function
void USART3_IRQHandler(void)
{
	 if((USART3->ISR & (1U << 5))) // check until RXFNE: RXFIFO not empty
	   if( USART3->RDR=='1')


				//Change data register value
				GPIOE->ODR |= (1U << 1); //Default led on
	   else
			GPIOE->ODR &=~ (1U << 1); //Default led on


}
