/*
 * main.c
 *
 * Created: 9/21/2022 2:15:31 AM
 *  Author: moham
 */ 
#include "..\..\dio2\dio2\\DIO_Conf.h"
#include "Timers_Interface.h"
#include <avr/interrupt.h>
int i=0;
ISR (TIMER0_OVF_vect)    // Timer1 ISR
{
	
	DDRC=0xff;
	PORTC^=0xff;
	
}

ISR (TIMER0_COMP_vect)
{
	
		DDRD=0xff;
		PORTD^=0xff;
		
	
}
int main(void)
{
	//DIO_Pin_Init(DIOB,OUTPUT,3);
	uint32_t j=0;
	DDRB=0b01000;
	*((uint8_t*)(0x5F))|=1<<7;
	Setup_Timer0(T0_INTERNAL_NO_PRESCALAR, T0_CTC_MODE);
	Setup_Timer0_COM(T0_COM_TOGGLE);
	//Setup_Timer0_PWM(50,T0_PWM_NOINVERT);
	Timer0_Compare_set(127);

    
	while(1)
    {
		//for(j=0;j<100000;j++);
		//IT_Timer0_OF_Disable();
		
        //TODO:: Please write your application code 
    }
}