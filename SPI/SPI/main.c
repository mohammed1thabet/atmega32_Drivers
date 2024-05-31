/*
 * SPI.c
 *
 * Created: 9/26/2022 10:24:46 PM
 * Author : moham
 */ 

#include "SPI_Interface.h"
#include <avr/interrupt.h>
uint8_t c=5;
ISR (SPI_STC_vect)
{
	c++;
	SPI_IT_SEND(c);
}

int main(void)
{
	
	DDRB|=1<<4;
	PORTB&=~(1<<4);
    SPI_Init(MASTER,SPI_SCK_DIV_4);
	SPI_IT_Enable();
	*((volatile uint8_t*)(0x5f))|=1<<7;
    SPI_Send(c);
	while (1)
    {

		
		//for(i=0;i<1000;i++);
    }
}

