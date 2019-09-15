#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "DIO_priv.h"
#include "DIO_Config.h"
#include "DIO_Int.h"
#include "KEYPAD_config.h"
#include "KEYPAD_int.h"
#include "KEYPAD_priv.h"
#include "SW_INT.h"
#include "Global_INTR_int.h"
#include "Timer0_priv.h"
#include "Timer0_int.h"
#include "Timer0_config.h"
#include "UART_int.h"
#include "UART_priv.h"
#include "UART_config.h"


static volatile void (*pfrx)(void);
static volatile void (*pftx)(void);

void UART_Init(void){
u8 Local_u8UCSRC = 0x80;
	UBRRL= BR ;
	UCSRA=0;
	UCSRB=0;
	#if DOUBLE_UART_RATE==ENABLE
	SET_BIT(UCSRA,U2X);
	#endif

	SET_BIT(Local_u8UCSRC,URSEL);
	UCSRC |= (PARITY_SELECT<<UPM1);

	#if NUM_OF_STOP_BITS==2
	SET_BIT(Local_u8UCSRC,USBS);
	#endif

	#if OP_MODE==SYNCH_OP
	SET_BIT(Local_u8UCSRC,UMSEL);
	#endif


	#if CHAR_SIZE==CHAR_SIZE_6
	SET_BIT(Local_u8UCSRC,UCSZ0);

	#elif 	CHAR_SIZE==CHAR_SIZE_7
	SET_BIT(Local_u8UCSRC,UCSZ1);

	#elif 	CHAR_SIZE==CHAR_SIZE_8
	SET_BIT(Local_u8UCSRC,UCSZ1);
	SET_BIT(Local_u8UCSRC,UCSZ0);

	#elif CHAR_SIZE==CHAR_SIZE_9
	SET_BIT(Local_u8UCSRC,UCSZ1);
		SET_BIT(Local_u8UCSRC,UCSZ0);
		SET_BIT(Local_u8UCSRC,UCSZ2);
	#endif

	#if TX_ENABLE==ENABLE
		SET_BIT(UCSRB,TXEN);
	#endif
	#if RX_ENABLE==ENABLE
		SET_BIT(UCSRB,RXEN);
	#endif

	UCSRC = Local_u8UCSRC;

}

void UART_voidSend(u8 data ){
	UDR=data;
while((red_bit(UCSRA,6))==0);
SET_BIT(UCSRA,6);
return;

}

u8 UART_voidRecieve(void){
	while((red_bit(UCSRA,7))==0);
	return UDR;
}

void __vector_16(void)__attribute__((signal,used));
void __vector_16(void){
	pfrx();
}
void UART_RX_SetCallBack(void (*p)(void)){

	pfrx=p;
}
void UART_TX_SetCallBack(void (*p)(void)){

	pftx=p;
}




