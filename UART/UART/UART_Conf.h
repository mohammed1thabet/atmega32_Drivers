/*
 * UART_Conf.h
 *
 * Created: 9/28/2022 1:18:58 AM
 *  Author: moham
 */ 


#ifndef UART_Conf_H_
#define UART_Conf_H_


#define X2_MODE               0 //1 = enable 2x mode , 0 = disable 2x mode , must be 0 while using sync mode
#define MPCM                  0 //1 = enable multiprocessor communication mode , 0 = disable multiprocessor communication mode
#define RXSTATE               1 //1 = enable Receiver , 0 = disable Receiver
#define TXSTATE               1 //1 = enable Transmitter , 0 = disable Transmitter
#define UART_MODE             0 //1 = enable Synchronization mode , 0 = disable Synchronization mode
#define PARITY                0 //0 means no parity, 2 meanseven parity, 3 means odd parity
#define STOP_BITS             0 //1 = two stop bits , 0 = one stop bit
#define CHAR_SIZE             3 //0 = 5bits, 1 = 6bits, 2 = 7bits, 3 = 8bits, 7 = 9bits
#define SYNC_CLK_POLARITY     0 //0 = TX data changes with rising edge and RX data changes with faling edge, 1 = opposite
#define CLK                   ((uint16_t)(1000000))
#define BAUD                  9600
#define UBRR_VAL              ((uint16_t)( (CLK)/(8+(8*(!X2_MODE))) -1 ))

#endif /* UART_Conf_H_ */