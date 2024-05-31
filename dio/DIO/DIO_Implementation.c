/*
 * DIO_Implementation.c
 *
 * Created: 9/18/2022 10:29:00 PM
 *  Author: moham
 */
#include "DIO_Conf.h"
#include "../../BITS_OPERATIONS.h"

 /*
 DIO_Port_st DIOA={&PORTA,&DDRA,&PINA};
 DIO_Port_st DIOB={&PORTB,&DDRB,&PINB};
 DIO_Port_st DIOC={&PORTC,&DDRC,&PINC};
 DIO_Port_st DIOD={&PORTD,&DDRD,&PIND};
*/

void DIO_Port_Init(DIO_Port_st* Portx,uint8_t Direction )
{
	Portx->DDRx=(Direction);
}

void DIO_Pin_Init(DIO_Port_st* Portx,uint8_t Direction,uint8_t Pin_Number )
{
	if(Direction==INPUT)
	CLEAR_BIT( Portx->DDRx ,Pin_Number ) ;
	else if(Direction==OUTPUT)
	SET_BIT(Portx->DDRx,Pin_Number);
}

void DIO_Port_Pullup(DIO_Port_st* Portx,uint8_t PUval)
{
	CLEAR_BIT(SFIOR,2);
	Portx->PORTx=(uint8_t)PUval;
	
}

void DIO_Pin_Pullup(DIO_Port_st* Portx, uint8_t Pin_Number, uint8_t PU_State)
{
	
	if(PU_State==PULL_UP_ENABLE)
	{
	CLEAR_BIT(SFIOR,2);
	SET_BIT(Portx->PORTx,Pin_Number);
	
	}
	else if(PU_State== PULL_UP_DISABLE)
	CLEAR_BIT(Portx->PORTx,Pin_Number);
}

uint8_t DIO_Read_Port(DIO_Port_st* Portx)
{
	return(Portx->PINx);
}
uint8_t DIO_Read_Pin(DIO_Port_st* Portx, uint8_t Pin_Number)
{ 
	if(Pin_Number<8)
	return (( (Portx->PINx)>>Pin_Number  )&0x1);
	else
	return 0;
}

void DIO_Write_Port(DIO_Port_st* Portx,uint8_t Val)
{
	Portx->PORTx=(uint8_t) Val;
}
void DIO_Write_Pin(DIO_Port_st* Portx,uint8_t Pin_Number,uint8_t Val)
{
	if(Val==HIGH)
	SET_BIT(Portx->PORTx,Pin_Number);
	else if(Val==LOW)
	CLEAR_BIT(Portx->PORTx,Pin_Number);
	
}
