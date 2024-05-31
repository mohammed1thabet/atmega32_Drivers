/*
 * Timers_Interface.h
 *
 * Created: 9/21/2022 2:42:10 AM
 *  Author: moham
 */ 


#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_
#include <xc.h>


void Setup_Timer0(uint8_t CLK_Mode, uint8_t Timer_Mode);
void Setup_Timer0_COM(uint8_t COM_Mode);
void Setup_Timer0_PWM(double Duty_Cycle,uint8_t PWM_Mode);


void Timer0_Compare_set(uint8_t Compare_match);
void Timer0_Preload(uint8_t Val);
uint8_t Timer0_Get_Timer();
void IT_Timer0_OF_Enable();
void IT_Timer0_OF_Disable();
void IT_Timer0_COM_Enable();
void IT_Timer0_COM_Disable();

#define T0_NORMAL_MODE               0x0
#define T0_PC_PWM_MODE               0x8
#define T0_CTC_MODE                  0x8
#define T0_FPWM_MODE                 0x40

#define T0_NO_COM                    0x0
#define T0_COM_TOGGLE                0x10
#define T0_COM_CLEAR                 0x20
#define T0_COM_SET                   0x30
#define T0_PWM_NOINVERT              0x20
#define T0_PWM_INVERT                0x30


#define T0_CLK_DISABLE               0x0
#define T0_INTERNAL_NO_PRESCALAR     0x1
#define T0_INTERNAL_PRESCALAR_8      0x2
#define T0_INTERNAL_PRESCALAR_64     0x3
#define T0_INTERNAL_PRESCALAR_256    0x4
#define T0_INTERNAL_PRESCALAR_1024   0x5
#define T0_EXTERNAL_RE               0x6
#define T0_EXTERNAL_FE               0x7

#endif /* TIMERS_INTERFACE_H_ */