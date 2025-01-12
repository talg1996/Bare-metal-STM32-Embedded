#include <stdint.h>
#include <stdio.h>
#include "stm32h723xx.h"
#include "usart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"

int main(void) {

	usart3_init();

	PC13_push_BTN_Interrupt();
	while (1) {

	}

}


//Interrupt function
void EXTI15_10_IRQHandler(void)
{
	printf("Interrupt has been occur\n");

	if(EXTI->PR1&(1U<<13))

	{
		//Clear the interrupt
		EXTI->PR1|=(1U<<13);
	printf("Interrupt has been occur from EXTI13\n");


	}

}
