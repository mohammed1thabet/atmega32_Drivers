/*
 * SPI_Program.c
 *
 * Created: 9/27/2022 2:09:01 AM
 *  Author: moham
 */ 
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "..\..\BITS_OPERATIONS.h"
void SPI_Init(SPI_Mode Mode, SPI_SCK CLK)
{

	if(SPI_DOUBLE_SPEED==1)
	{
		SET_BIT(SPSR_REG,0);
	}
	
	
	if(Mode==MASTER)
	{
		SET_BIT(DDRB_REG,5);
		SET_BIT(DDRB_REG,7);
		SET_BIT(SPCR_REG,4);

		
	}
	else if(Mode==SLAVE)
	{
		CLEAR_BIT(SPCR_REG,4);
		SET_BIT(DDRB_REG,6);
	}
	CLEAR_BIT(SPCR_REG,5);
	SET_BIT(SPCR_REG,6);
	SPCR_REG&=0xfc;
	SPCR_REG|=CLK;
	
}
void SPI_Send(uint8_t Data)
{
	SPDR_REG=Data;
	while(GET_BIT(SPSR_REG,7)==0);
}
uint8_t SPI_Recive()
{
	while(!GET_BIT(SPSR_REG,7));
	return SPDR_REG;
}

void SPI_IT_Enable()
{
	SET_BIT(SPCR_REG,7);
}
void SPI_IT_Disable()
{
	CLEAR_BIT(SPCR_REG,7);
}
void SPI_Disable()
{
	CLEAR_BIT(SPCR_REG,6);	
}
