/*
 * IncFile1.h
 *
 * Created: 9/27/2022 2:08:05 AM
 *  Author: moham
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include <avr/io.h>
//#include "..\"
typedef enum{
	MASTER,
	SLAVE
	}SPI_Mode;
typedef enum{
	SPI_SCK_DIV_4=0,
	SPI_SCK_DIV_16,
	SPI_SCK_DIV_64,
	SPI_SCK_DIV_128,
	}SPI_SCK;
	

void SPI_Init(SPI_Mode Mode, SPI_SCK CLK);
void SPI_Send(uint8_t Data);
uint8_t SPI_Recive();
void SPI_IT_Enable();
void SPI_IT_Disable();
void SPI_Disable();

/*
these macros are the same as SPI send,read but without checking interrupt flag
*/
#define SPI_IT_SEND(C) (*((volatile uint8_t*)(0x2f))=C);
#define SPI_IT_READ(C) (*((volatile uint8_t*)(0x2f)));



#endif /* INCFILE1_H_ */