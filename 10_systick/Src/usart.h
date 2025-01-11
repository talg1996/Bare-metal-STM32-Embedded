/*
 * uart.h
 *
 *  Created on: Jan 10, 2025
 *      Author: Tal Gadasi
 */

#ifndef USART_H_
#define USART_H_
#include <stdint.h>

#include "stm32h723xx.h"

void usart3_init(void);

char usart_read(void);

#endif /* USART_H_ */
