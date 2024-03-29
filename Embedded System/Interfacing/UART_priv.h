#ifndef _UART_PRIV_H
#define _UART_PRIV_H

#define ENABLE 	1
#define DISABLE 0

#define BR_2400		207
#define BR_4800		103
#define BR_9600		51

#define CHAR_SIZE_5	0
#define CHAR_SIZE_6	1
#define CHAR_SIZE_7	2
#define CHAR_SIZE_8	3
#define CHAR_SIZE_9	4

#define ASYNCH_OP 	0
#define SYNCH_OP	1

#define STOP_1	0
#define STOP_2 	1

#define PARITY_DISABLED 	(u8)0
#define PARITY_EVEN 		(u8)2
#define PARITY_ODD 			(u8)3

#define U2X			1
#define UDRE		5
#define TXC			6
#define RXC			7

#define RXCIE		7
#define TXCIE		6
#define UDRIE		5
#define RXEN		4
#define TXEN		3
#define UCSZ2		2

#define URSEL		7
#define UMSEL		6
#define UPM1 		5
#define UPM0		4
#define USBS		3
#define UCSZ1		2
#define UCSZ0		1

#endif
