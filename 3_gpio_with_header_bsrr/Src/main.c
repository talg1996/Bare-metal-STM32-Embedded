#include "stm32h723xx.h"
//Use BSRR instead of ODR if you need to set/reset a pin or all port
// This set/ reset will be atomic operation
int main(void) {
	RCC->AHB4ENR |= (1u << 4);

	//Set pin mode as output
	GPIOE->MODER &= ~(1U << 3);

	//Change data register value
	GPIOE->ODR |= (1U << 1);
	while (1) {

		GPIOE->BSRR = (1U << 1);
		for (unsigned int i = 0; i < 60000; i++) {
			for (unsigned int j = 0; j < 75; j++);
		}

		GPIOE->BSRR = (1U << 17);
		for (unsigned int i = 0; i < 60000; i++) {
			for (unsigned int j = 0; j < 75; j++);

		}
	}
}



