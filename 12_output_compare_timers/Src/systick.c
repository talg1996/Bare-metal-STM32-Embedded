/*
 * systick.c
 *
 *  Created on: Jan 11, 2025
 *      Author: tlgdsy
 */
#include "stm32h723xx.h"

#include <stdint.h>

#include"systick.h"

#define CTRL_EN (1U<<0)
#define CTRL_CLK_SRC (1U<<2)
#define CTRL_COUNT_FLAG (1U<<16)

#define SISTICK_LOAD_VAL_mealy 64000
#define SISTICK_LOAD_VAL_micro 64
void sysTickDelayMealy(uint32_t delay)
{
// SysTick configure

	//Relaod the number of clock per milisec
SysTick->LOAD = SISTICK_LOAD_VAL_mealy;

// Clear systick current value register
SysTick->VAL=0;
//Enable systick and select internal clk
SysTick->CTRL|=CTRL_CLK_SRC|CTRL_EN;
for(int i=0;i<delay;i++){
	//wait until the count flag is set
	while((SysTick->CTRL & CTRL_COUNT_FLAG)==0);

}
//Disable systick
SysTick->CTRL=0;

}

void sysTickDelayMicro(uint32_t delay)
{
// SysTick configure

	//Relaod the number of clock per milisec
SysTick->LOAD = SISTICK_LOAD_VAL_micro;

// Clear systick current value register
SysTick->VAL=0;
//Enable systick and select internal clk
SysTick->CTRL|=CTRL_CLK_SRC|CTRL_EN;

for(int i=0;i<delay;i++){
	//wait until the count flag is set
	while((SysTick->CTRL & CTRL_COUNT_FLAG)==0);

}
//Disable systick
SysTick->CTRL=0;
}
