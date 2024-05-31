/*
 * main.c
 *
 * Created: 9/18/2022 11:35:35 PM
 *  Author: moham
 */ 
#define F_CPU 8000000UL

#include "DIO_Conf.h"

int main(void)
{
	uint32_t i=0;
	DIO_Port_Init(DIOA,0x00);
	DIO_Port_Init(DIOB,0xff);
	DIO_Port_Init(DIOC,0xff);
	DIO_Pin_Init(DIOD,INPUT,0);
   	DIO_Pin_Init(DIOD,OUTPUT,5);
	   
    while(1)
    {
		
		//DIO_Write_Pin(&DIOA,2,HIGH);
	    DIO_Write_Port(DIOB,0b01011110);
		DIO_Write_Port(DIOC , DIO_Read_Port(DIOA) );
		DIO_Write_Pin(DIOD,5,DIO_Read_Pin(DIOD,0));
	    for(i=0;i<1000000;i++);
		//DIO_Write_Pin(&DIOA,2,LOW);
	    DIO_Write_Port(DIOB, ~(0b01011110));
	    DIO_Write_Port(DIOC , DIO_Read_Port(DIOA) );
	    DIO_Write_Pin(DIOD,5,DIO_Read_Pin(DIOD,0));
		for(i=0;i<1000000;i++);
		

    }
}