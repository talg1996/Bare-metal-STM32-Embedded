
#include "exti.h"

//Configure the push BTN as intup interrupt
//PC13 is the push button
void PC13_push_BTN_Interrupt(void) {
	//Disable global interrupt - not a must, just for practice
	__disable_irq();
	//Enable clock access to GPIOC
	RCC->AHB4ENR|=(1U<<2);

	//Set PC13 as input
	GPIOC->MODER&=~(1U<<26);
	GPIOC->MODER&=~(1U<<27);
	//Enable clock access to SYSCGF
	RCC->APB4ENR|=RCC_APB4ENR_SYSCFGEN;

	//Select PORT C for EXTI13
	SYSCFG->EXTICR[3]|=(1U<<5);
	//Unmask EXTI13
	EXTI->IMR1|=(1U<<13);
	//Select falling edge trigger
	EXTI->FTSR1|=(1U<<13);
	//Enable the EXTI line in NVIC
	NVIC_EnableIRQ(EXTI15_10_IRQn);
	//Enable global interrupts
	__enable_irq();


}
