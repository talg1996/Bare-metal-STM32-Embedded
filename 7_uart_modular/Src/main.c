#include <stdint.h>
#include <stdio.h>
#include "stm32h723xx.h"
#include "usart.h"


int main(void) {

	usart3_init();

	while (1) {
		printf("I Just split usart3 files to make it reusable \n");
	}

}
