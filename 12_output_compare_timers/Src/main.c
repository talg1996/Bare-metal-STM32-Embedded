#include <stdint.h>
#include <stdio.h>
#include "stm32h723xx.h"
#include "usart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

int cnt=0;
int main(void) {

	usart3_init();
	tim12_1hz_init_output_compare_PA5();


	while (1) {

	}

}
