/*
 * Timer_Implementation.c
 *
 * Created: 9/21/2022 2:41:44 AM
 *  Author: moham
 */ 
#include "Timers_Interface.h"
#include "Timers_Private.h"
#include "..\..\BITS_OPERATIONS.h"

void Setup_Timer0(uint8_t CLK_Mode, uint8_t Timer_Mode)
{
	uint8_t T0_Conf=0;
	T0_Conf|=Timer_Mode;
	T0_Conf|=CLK_Mode;
	
	REG_TCCR0=T0_Conf;
	
}
void Setup_Timer0_COM(uint8_t COM_Mode)
{
	REG_TCCR0|=COM_Mode;
}

void Setup_Timer0_PWM(double Duty_Cycle,uint8_t PWM_Mode)
{
	REG_TCCR0|=PWM_Mode;
	if((Duty_Cycle>=0)&&(Duty_Cycle<=100))
	{
		REG_OCR0=(uint8_t)((Duty_Cycle/100.0)*255.0);
	}
	
}


void Timer0_Compare_set(uint8_t Compare_match)
{
	REG_OCR0=Compare_match;
}

void Timer0_Preload(uint8_t Val)
{
	REG_TCNT0=Val;
}

uint8_t Timer0_Get_Timer()
{
	return REG_TCNT0;
}


void IT_Timer0_OF_Enable()
{
	CLEAR_BIT(REG_TIFR,0);
	SET_BIT(REG_TIMSK,0);
}


void IT_Timer0_OF_Disable()
{
	CLEAR_BIT(REG_TIMSK,0);
}

void IT_Timer0_COM_Enable()
{
	    
		CLEAR_BIT(REG_TIFR,1);
		SET_BIT(REG_TIMSK,1);
}


void IT_Timer0_COM_Disable()
{
	CLEAR_BIT(REG_TIMSK,1);
}



