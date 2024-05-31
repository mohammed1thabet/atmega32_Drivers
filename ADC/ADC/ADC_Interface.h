

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#include <xc.h>

typedef enum{
	AREF=0,
	AVCC=0x1,
	Internal_2_56=0x3
	}ADC_Rference;

typedef enum{
	ADC_PRESCALAR_2=1,
	ADC_PRESCALAR_4,
	ADC_PRESCALAR_8,
	ADC_PRESCALAR_16,
	ADC_PRESCALAR_32,
	ADC_PRESCALAR_64,
	ADC_PRESCALAR_128
	}ADC_Prescalar;

typedef enum{
	ADC_FREE_RUNNING=0,
	ADC_ANALOG_COMPARATOR,
	ADC_EXTI,
	ADC_T0_COM,
	ADC_T0_OF,
	ADC_T1_COM,
	ADC_T1_OF,
	ADC_T1_CAP,
	}ADC_AutoTriggerSource;

void ADC_Init(ADC_Rference REF,ADC_Prescalar Prescalar);
void ADC_ChSelect(uint8_t Channel_Number);
void ADC_AutoTriggerEnable(ADC_AutoTriggerSource Sc);
void ADC_AutoTriggerDisable();
void ADC_SOC();
uint16_t ADC_read();
void ADC_IT_Enable();
void ADC_IT_Disable();

#endif