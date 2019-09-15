#include <avr/io.h>
#include <util/delay.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "SW_int.h"
#include "LED_int.h"
#include "DIO_int.h"
#include "EXT_INTR_int.h"
#include "Global_INTR_int.h"
#include "LCD_int.h"
#include "7_Seg_int.h"
#include "Timer0_int.h"
#include "UART_int.h"
#include "KEYPAD_int.h"
#include "SPI_int.h"
#include "PWM_int.h"
#include <avr/eeprom.h>



void main(void){
	DIO_voidInitialize();
	LCD_voidInitialization();
	while (1){
		u8 x;
		x=GET_KEYPAD();
		LCD_voidWriteData(x);
		_delay_ms(500);
	}
	/*if (eeprom_read_byte(0x00) != '1'){
		PASS_INIT();
		LCD_voidPrint("INITIALIZED, reset now");
	}
	else {
	PASS_STORE();

	u8 a[]={'0','0','0','0','0','0','0','0'};
	if (PASS_COMP(a) == '1'){
		LCD_voidPrint("ACCESSED");
	}

	}*/
}

