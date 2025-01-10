#include"usart.h"
#define Pclk 64000000 //clk

static void usart_set_baudrate(USART_TypeDef *USARTx,uint32_t PeriClk,uint32_t BaudRate);
static uint16_t compte_uart_baudrate(uint32_t PeriClk, uint32_t BaudRate);
void usart_write (int ch);

int __io_putchar(int ch);


void usart3_init(void) {

	RCC->AHB4ENR |= (1u << 3); //Enable port D
	GPIOD->MODER &= ~(1u << 16);//Set pin as alternate function

	//For USART3 set the ADR to 0111
	GPIOD->AFR[1] |= (1u << 0);
	GPIOD->AFR[1] |= (1u << 1);
	GPIOD->AFR[1] |= (1u << 2);
	RCC->APB1LENR |= (1u << 18); //ENABLE USART3 CLK


	usart_set_baudrate(USART3,Pclk,9600);
	USART3->CR1=(1U<<3); //enable transmit
	USART3->CR1|=(1U<<0); //Enable USART3
}
void usart_write(int ch)
{
    while (!(USART3->ISR & (1U << 7))); // Wait until TXE is set
    USART3->TDR = ch & 0xFF; //Send only 1 byte
}

static void usart_set_baudrate(USART_TypeDef *USARTx,uint32_t PeriClk,uint32_t BaudRate){
	USARTx->BRR=compte_uart_baudrate(PeriClk,BaudRate);
}
static uint16_t compte_uart_baudrate(uint32_t PeriClk, uint32_t BaudRate){
	return((PeriClk + (BaudRate/2U))/BaudRate);
}

int __io_putchar(int ch)
{
	usart_write (ch);
	return ch;

}
