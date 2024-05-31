/*
 * UART.c
 *
 * Created: 9/28/2022 1:14:03 AM
 * Author : moham
 */ 

#include "UART_Interface.h"



int main(void)
{
	uint8_t i=0;
	uint16_t j=0;
	UART_Init();
	
	while (1)
	{
		if(UART_Recive()==60)
		{
			DDRA=0x01<<i;
			PORTA=0x01<<i;
		}
	}
}
