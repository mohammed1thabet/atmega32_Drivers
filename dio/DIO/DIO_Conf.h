/*
 * DIO_Conf.h
 *
 * Created: 9/18/2022 11:11:54 AM
 *  Author: moham
 */ 


#ifndef DIO_CONF_H_

#define DIO_CONF_H_

#include <xc.h>

/*
typedef struct
{
	volatile uint8_t* PORTx;
	volatile uint8_t* DDRx;
	volatile uint8_t* PINx;
}DIO_Port_st;
extern  DIO_Port_st DIOA;
extern  DIO_Port_st DIOB;
extern  DIO_Port_st DIOC;
extern  DIO_Port_st DIOD;
*/
typedef struct
{
	volatile uint8_t PINx ;
	volatile uint8_t DDRx ;
	volatile uint8_t PORTx ;

}DIO_Port_st;





void DIO_Port_Init(DIO_Port_st* Portx,uint8_t Direction );
void DIO_Pin_Init(DIO_Port_st* Portx,uint8_t Direction,uint8_t Pin_Number );

void DIO_Port_Pullup(DIO_Port_st* Portx,uint8_t PUval);
void DIO_Pin_Pullup(DIO_Port_st* Portx,uint8_t Pin_Number, uint8_t PU_State);

uint8_t DIO_Read_Port(DIO_Port_st* Portx);
uint8_t DIO_Read_Pin(DIO_Port_st* Portx, uint8_t Pin_Number);

void DIO_Write_Port(DIO_Port_st* Portx,uint8_t Val);
void DIO_Write_Pin(DIO_Port_st* Portx,uint8_t Pin_Number,uint8_t Val);


#define INPUT 0
#define OUTPUT 1
#define PULL_UP_ENABLE 1
#define PULL_UP_DISABLE 0
#define HIGH 1
#define LOW 0

#define DIOA ((DIO_Port_st*)(0x39))
#define DIOB ((DIO_Port_st*)(0x36))
#define DIOC ((DIO_Port_st*)(0x33))
#define DIOD ((DIO_Port_st*)(0x30))
#endif /* DIO_CONF_H_ */ 