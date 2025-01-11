#include <stdint.h>
#include <stdio.h>
#include "stm32h723xx.h"
#include "usart.h"
#include "adc.h"
	uint32_t data;


int main(void) {

	usart3_init();
	pf3_ADC_int();
	while (1) {
		ADC_START();
		data=read_ADC();
		printf("The res is: %d\n",data);
	}

}
