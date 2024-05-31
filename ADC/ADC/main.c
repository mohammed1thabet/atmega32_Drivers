/*
 * main.c
 *
 * Created: 9/25/2022 12:04:56 AM
 *  Author: moham
 */ 

#include "ADC_Interface.h"
#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include Delay header file */
#include <avr/interrupt.h>
#define LCD_Dir  DDRB			/* Define LCD data port direction */
#define LCD_Port PORTB			/* Define LCD data port */
#define RS PB0				/* Define Register Select pin */
#define EN PB1 				/* Define Enable signal pin */

#define NULL '\0'
void LCD_Command( unsigned char cmnd )
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0); /* sending upper nibble */
	LCD_Port &= ~ (1<<RS);		/* RS=0, command reg. */
	LCD_Port |= (1<<EN);		/* Enable pulse */
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);  /* sending lower nibble */
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}


void LCD_Char( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0); /* sending upper nibble */
	LCD_Port |= (1<<RS);		/* RS=1, data reg. */
	LCD_Port|= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (data << 4); /* sending lower nibble */
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_Init (void)			/* LCD Initialize function */
{
	LCD_Dir = 0xFF;			/* Make LCD port direction as o/p */
	_delay_ms(20);			/* LCD Power ON delay always >15ms */
	
	LCD_Command(0x02);		/* send for 4 bit initialization of LCD  */
	LCD_Command(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	LCD_Command(0x0c);              /* Display on cursor off*/
	LCD_Command(0x06);              /* Increment cursor (shift cursor to right)*/
	LCD_Command(0x01);              /* Clear display screen*/
	_delay_ms(2);
}


void LCD_String (char *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}

void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_String(str);		/* Call LCD string function */
}

void LCD_Clear()
{
	LCD_Command (0x01);		/* Clear display */
	_delay_ms(2);
	LCD_Command (0x80);		/* Cursor at home position */
}

int main()
{
	uint16_t d=0;
	float amount=0;
    uint16_t i=0;
	LCD_Init();			/* Initialization of LCD*/
    char s[30]="ElectronicWINGS";
	//LCD_String(s);	/* Write string on 1st line of LCD*/
	//LCD_Command(0xC0);		/* Go to 2nd line*/
	
	//LCD_String(s);	/* Write string on 2nd line*/
	
	ADC_Init(AVCC,ADC_PRESCALAR_64);
	ADC_AutoTriggerEnable( ADC_FREE_RUNNING );
	
	ADC_ChSelect(0);
	ADC_SOC();
	
	d=ADC_read();
	ADC_IT_Enable();
	*(volatile uint8_t*)(0x5F)|=1<<7;
	while(1)
	{
		//for(i=0;i<5000;i++);
		d=ADC_read();
		//ADC_SOC();
		amount=d*0.5;
		amount/=100;
		char c[10]="2.5V";
		
		/*
		int len = snprintf(NULL, 0, "%f", 6.5f);
		char *result = malloc(len + 1);
		snprintf(result, len + 1, "%f", 6.5f);
		*/
		
		if((d>510)&&(d<520))
		//if((amount>3.5)&&(amount<4.5))
		{
		LCD_Clear();
		LCD_String(c);
		}
		//TODO:: Please write your application code
	}
}
