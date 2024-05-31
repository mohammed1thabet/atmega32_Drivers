/* Timers_Private.h
 *
 * Created: 9/21/2022 3:49:32 AM
 *  Author: moham
 */ 


#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_



#define REG_TCNT0                 *(volatile uint8_t*)(0x52)
#define REG_TCCR0                 *(volatile uint8_t*)(0x53)
#define REG_OCR0                  *(volatile uint8_t*)(0x5C)
#define REG_TIFR                  *(volatile uint8_t*)(0x58)
#define REG_TIMSK                 *(volatile uint8_t*)(0x59)
#define REG_SREG                  *(volatile uint8_t*)(0x5F)




#endif /* TIMERS_PRIVATE_H_ */