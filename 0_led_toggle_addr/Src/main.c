//How to toggle the yellow led on the NUCLEO-H723ZG without header
// YELLOW LED
// PORT: E
// PIN: 1
//NUCLEO-H723ZG
#include <stdint.h>
#define AHB4_BASE    			(0x58020000UL)
#define GPIOE_OFFSET 			(0x1000UL)
#define GPIOE_BASE 	 			(AHB4_BASE + GPIOE_OFFSET)

#define RCC_OFFSET 	 			(0X4400UL)
#define RCC_BASE 	 			(AHB4_BASE+RCC_OFFSET)
#define RCC_AHB4ENR  			(*(volatile unsigned int *)(RCC_BASE+0x0E0UL))

#define GPIO_E_EN      			(1U<<4)

#define GPIOE_MODER_OFFSET      (0X00UL)
#define GPIOE_MODER    		    (*(volatile unsigned int *)(GPIOE_MODER_OFFSET+GPIOE_BASE))

#define GPIOE_ODR_OFFSET        (0x14UL)
#define GPIOE_ODR     			(*(volatile unsigned int *)(GPIOE_ODR_OFFSET+GPIOE_BASE))

#define PIN_5     				((1U<<1))
#define LED_G   			    (PIN_5)

//&=~(1U<<3); FOR GPIOE_MODER
//|=(1U<<1); FOR GPIOE_ODR

int main(void) {

	//**** Init **** LED PE1
	//Enable clk to AHB4
	RCC_AHB4ENR |= GPIO_E_EN;

	//Set pin mode as output
	GPIOE_MODER &= ~(1U << 3);

	//Change data register value
	GPIOE_ODR |= LED_G;
	while (1) {
		//Toggle output data register
		GPIOE_ODR ^= LED_G;
		for (unsigned int i = 0; i < 90000; i++) {
			for (unsigned int j = 0; j < 75; j++)
				;
		}

		//toggle
	}

}
