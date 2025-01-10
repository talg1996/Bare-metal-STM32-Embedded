// YELLOW LED
// PORT: E
// PIN: 1
#include <stdint.h>
#define AHB4_BASE    			(0x58020000UL)
#define GPIOE_OFFSET 			(0x1000UL)
#define GPIOE_BASE 	 			(AHB4_BASE + GPIOE_OFFSET)

#define RCC_OFFSET 	 			(0X4400UL)
#define RCC_BASE 	 			(AHB4_BASE+RCC_OFFSET)
#define RCC_AHB4ENR  			(*(volatile unsigned int *)(RCC_BASE+0x0E0UL))

#define GPIO_E_EN      			(1U<<4)

#define GPIOE_MODER_OFFSET      (0X00UL)

#define GPIOE_ODR_OFFSET        (0x14UL)

#define PIN_5     				((1U<<1))
#define LED_G   			    (PIN_5)

// GPIO structure definition
typedef struct {
	volatile uint32_t MODER;    // GPIO mode register
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR;      // GPIO output data register

} GPIO_TypeDef;

// RCC Register Structure Definition

#define GPIOE ((GPIO_TypeDef*) GPIOE_BASE)

int main(void) {
	//**** Init **** LED PE1
	//Enable clk to AHB4
	RCC_AHB4ENR |= GPIO_E_EN;

	//Set pin mode as output
	GPIOE->MODER &= ~(1U << 3);

	//Change data register value
	GPIOE->ODR |= LED_G;
	while (1) {
		//Toggle output data register
		GPIOE->ODR ^= LED_G;
		for (unsigned int i = 0; i < 90000; i++) {
			for (unsigned int j = 0; j < 75; j++)
				;
		}

		//toggle
	}

}
