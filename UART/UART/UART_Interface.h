/*
 * IncFile1.h
 *
 * Created: 9/28/2022 1:14:39 AM
 *  Author: moham
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include <avr/io.h>

void UART_Init();
void UART_Transmit(uint16_t Data);
uint16_t UART_Recive();
void UART_TransmitString(uint16_t* Data);
void UART_IT_Enable();
void UART_IT_Disable();


#endif /* INCFILE1_H_ */