

#ifndef ADC_PRIVATE_H_

#define ADC_PRIVATE_H_



uint8_t ADC_AutoFlag=0;

#define ADMUX_REG      *((volatile uint8_t*)0x27)
#define ADCSRA_REG     *((volatile uint8_t*)0x26)
#define ADCDATA_REG    *((volatile uint16_t*)0x24)
#define SFIOR_REG      *((volatile uint8_t*)0x50)
#define SREG_REG       *(volatile uint8_t*)(0x5F)

#endif