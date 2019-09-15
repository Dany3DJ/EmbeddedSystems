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
#include "Timer0_int.h"
#include "UART_int.h"
#include "SPI_int.h"
#include "SPI_config.h"
#include "SPI_priv.h"
#include "SPI_reg.h"

void SPI_voidINIT(void){
	SPCR= 0b00000000;
#if SPI_INTR == ENA
	set_bit(SPCR,7);
#endif
	set_bit(SPCR,6);
#if DATA_ORDER == LSB
	set_bit(SPCR,5);
#endif
#if SPI_MODE == MASTER
	set_bit(SPCR,4);
#endif
#if SPI_CLOCK_PHASE == MODE1
	set_bit(SPCR,2);
#elif SPI_CLOCK_PHASE == MODE2
	set_bit(SPCR,3);
#elif SPI_CLOCK_PHASE == MODE3
	set_bit(SPCR,3);
	set_bit(SPCR,2);

#endif
#if	SPI_CLOCK_RATE == F_4
	clear_bit(SPSR,0);
#elif SPI_CLOCK_RATE == F_16
	set_bit(SPCR,0);
	clear_bit(SPSR,0);
#elif SPI_CLOCK_RATE == F_64
	set_bit(SPCR,1);
	clear_bit(SPSR,0);
#endif
}

void SPI_voidSEND(u8 data){
	SPDR=data;
	while (!(SPSR & (1<<SPIF) ) );
}
u8 SPI_u8RECIEVE(void){

#if SPI_MODE == MASTER
	SPI_voidSEND(0xff);
	while (!(SPSR & (1<<SPIF) ) );
	return SPDR;

#elif SPI_MODE == SLAVE
	while (!(SPSR & (1<<SPIF) ) );
	return SPDR;
#endif
}
