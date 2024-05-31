

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "../../BITS_OPERATIONS.h"

void ADC_Init(ADC_Rference REF,ADC_Prescalar Prescalar)
{
	uint8_t ADC_Conf=0;
	SET_BIT(ADC_Conf,7);
	ADC_Conf|=Prescalar;
	ADCSRA_REG=ADC_Conf;
	ADC_Conf=0;
	ADC_Conf|=REF<<6;
	
	CLEAR_BIT(ADC_Conf,5);
	ADMUX_REG=ADC_Conf;
}

void ADC_ChSelect(uint8_t Channel_Number)
{
   	uint8_t select=0;
   	Channel_Number&=0x7;
	CLEAR_BIT(DDRA,Channel_Number);
    select=ADMUX_REG&0xf8;
	select|=Channel_Number;
	ADMUX_REG=select;
}
void ADC_AutoTriggerEnable(ADC_AutoTriggerSource Sc)
{
	ADC_AutoFlag=1;
    CLEAR_BIT(SFIOR_REG,7);
    CLEAR_BIT(SFIOR_REG,6);
    CLEAR_BIT(SFIOR_REG,5);
	
	SFIOR_REG|=Sc<<5;
	SET_BIT(ADCSRA_REG,5);
}
void ADC_AutoTriggerDisable()
{
	ADC_AutoFlag=0;
	CLEAR_BIT(ADCSRA_REG,5);
}
void ADC_SOC()
{
    
	SET_BIT(ADCSRA_REG,6);
}
uint16_t ADC_read()
{
	//if(ADC_AutoFlag==0)
//	{
	while((ADCSRA_REG)&(1<<6));
	return ( (uint16_t)ADCDATA_REG );
	//}
	//else
//	{
	//return ( (uint16_t)ADCDATA_REG );
	//}
}

void ADC_IT_Enable()
{
	SET_BIT(ADCSRA_REG,3);
}
void ADC_IT_Disable()
{
	CLEAR_BIT(ADCSRA_REG,3);
}
