/*
 * UART_Private.h
 *
 * Created: 9/28/2022 1:14:33 AM
 *  Author: moham
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UDR_REG        *((volatile uint8_t*)(0x2c))
#define UCSRA_REG      *((volatile uint8_t*)(0x2b))
#define UCSRB_REG      *((volatile uint8_t*)(0x2a))
#define UCSRC_REG      *((volatile uint8_t*)(0x40))
#define UBRRH_REG      *((volatile uint8_t*)(0x40))
#define UBRRL_REG      *((volatile uint8_t*)(0x29))


#endif /* UART_PRIVATE_H_ */