/*
 * SPI_Private.h
 *
 * Created: 9/27/2022 2:08:43 AM
 *  Author: moham
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_




#define SPI_DOUBLE_SPEED 0 // set by 1 to double the frequency

#define SPCR_REG  *((volatile uint8_t*)(0x2d))
#define SPSR_REG  *((volatile uint8_t*)(0x2e))
#define SPDR_REG  *((volatile uint8_t*)(0x2f))
#define SREG_REG  *((volatile uint8_t*)(0x5f))
#define DDRB_REG  *((volatile uint8_t*)(0x37))

#endif /* SPI_PRIVATE_H_ */