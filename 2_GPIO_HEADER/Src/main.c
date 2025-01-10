#include "stm32h723xx.h"
// Use ODR over BSRR if you want to give values to a port different from 0xFF or 0x 00
// Note ODR is not a atomic operation so can be interrupt by an interrupt
// Impotent: for fast reset (like OCP bit) use BSRR
int main(void) {
	RCC->AHB4ENR |= (1u << 4);

	//Set pin mode as output
	GPIOE->MODER &= ~(1U << 3);

	//Change data register value
	GPIOE->ODR |= (1U << 1);
	while (1) {
		//Toggle output data register
		GPIOE->ODR ^= (1U << 1);
		for (unsigned int i = 0; i < 90000; i++) {
			for (unsigned int j = 0; j < 75; j++);

		}
	}
}
