/*
 * Program.c
 *
 * Created: 9/28/2022 1:15:23 AM
 *  Author: moham
 */ 

#include "UART_Conf.h"
#include "UART_Interface.h"
#include "UART_Private.h"
#include "..\..\BITS_OPERATIONS.h"
void UART_Init()
{
	
	UCSRA_REG|=(X2_MODE<<1)|(MPCM);
	SET_BIT(UCSRC_REG,7);//select UCSRA Writing 
	UCSRC_REG|=(UART_MODE<<6)|(PARITY<<4)|(STOP_BITS<<3);
	if(UART_MODE==1)//sync mode
	{
		UCSRC_REG|=SYNC_CLK_POLARITY;
	}
	
	//selecting char size
	UCSRC_REG|=(CHAR_SIZE & 0x3)<<1;
	UCSRA_REG|=(CHAR_SIZE&0x4)<<2;
	
	CLEAR_BIT(UCSRC_REG,7);//select UBRRH Writing
	//setting baud rate
	UBRRL_REG=(uint8_t)UBRR_VAL;
	UBRRH_REG=(uint8_t)(UBRR_VAL>>8);
	
	//setting receiving and transmiting state
	UCSRB_REG|=(RXSTATE<<4)|(TXSTATE<<3);
	
}
void UART_Transmit(uint16_t Data)
{
	while(!GET_BIT(UCSRA_REG,5));
	if(CHAR_SIZE==7)
	{
		if( ((Data>>8)&0x1)==0 )
		CLEAR_BIT(UCSRB_REG,0);
		else
		SET_BIT(UCSRB_REG,0);
	}
	
	UDR_REG=Data;
}
uint16_t UART_Recive()
{
	uint16_t Data=0;
	
	while(!GET_BIT(UCSRA_REG,7));
	Data=UDR_REG;
	
	if(CHAR_SIZE==7)
	{
	    Data|=GET_BIT(UCSRB_REG,1)<<8;	
	}
	
	return Data;
}
void UART_TransmitString(uint16_t* Data)
{
	uint16_t i=0;
	while(Data[i]!='\0')
	{
		UART_Transmit(Data[i++]);
	}
}

void UART_IT_RXEnable()
{
	SET_BIT(UCSRB_REG,7);
}

void UART_IT_DataRegisterEmptyEnable()
{
	SET_BIT(UCSRB_REG,5);
}

void UART_IT_TXEnable()
{
	SET_BIT(UCSRB_REG,6);
}




void UART_IT_RXDisable()
{
	CLEAR_BIT(UCSRB_REG,7);
}

void UART_IT_DataRegisterEmptyDisable()
{
	CLEAR_BIT(UCSRB_REG,5);
}

void UART_IT_TXDisable()
{
	CLEAR_BIT(UCSRB_REG,6);
}
