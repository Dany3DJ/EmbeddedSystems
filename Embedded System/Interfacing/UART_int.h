#ifndef _UART_INT_H
#define _UART_INT_H

#include"Std_Types.h"
void UART_Init(void);
void UART_voidSend(u8 data );
u8 UART_voidRecieve(void);
void UART_RX_SetCallBack(void (*p)(void));
void UART_TX_SetCallBack(void (*p)(void));
#endif

