#include "avr/io.h"
#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_int.h"
#include "SW_int.h"
#include "LCD_int.h"
#include "KEYPAD_priv.h"
#include "KEYPAD_config.h"
#include "KEYPAD_int.h"
#include "KEYPAD_reg.h"
#include "util/delay.h"

#define ROWS 4
#define COLMNS 4

 u8 key[ROWS][COLMNS]={
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'*','0','X','D'},
};
void KEYPAD_OUTSEQ(int seq){

	switch (seq){
	case 0:
		DIO_voidSetPin(KEYPAD_PIN_1);
		DIO_voidClearPin(KEYPAD_PIN_2);
		DIO_voidClearPin(KEYPAD_PIN_3);
		DIO_voidClearPin(KEYPAD_PIN_4);
		//DIO_voidTogglePin(1);
		break;
	case 1:
		DIO_voidSetPin(KEYPAD_PIN_2);
		DIO_voidClearPin(KEYPAD_PIN_1);
		DIO_voidClearPin(KEYPAD_PIN_3);
		DIO_voidClearPin(KEYPAD_PIN_4);
		//DIO_voidTogglePin(2);
		break;
	case 2:
		DIO_voidSetPin(KEYPAD_PIN_3);
		DIO_voidClearPin(KEYPAD_PIN_1);
		DIO_voidClearPin(KEYPAD_PIN_2);
		DIO_voidClearPin(KEYPAD_PIN_4);
		//DIO_voidTogglePin(3);
		break;
	case 3:
		DIO_voidSetPin(KEYPAD_PIN_4);
		DIO_voidClearPin(KEYPAD_PIN_1);
		DIO_voidClearPin(KEYPAD_PIN_2);
		DIO_voidClearPin(KEYPAD_PIN_3);
		//DIO_voidTogglePin(4);
		break;
	default: break;
	}
	_delay_us(100);

}


u8 GET_KEYPAD(void){
	for (int x=0 ; x<4 ; x++){
		KEYPAD_OUTSEQ(x);
		if (DIO_uint8PinState(KEYPAD_PIN_5) == 1 || DIO_uint8PinState(KEYPAD_PIN_6) == 1 || DIO_uint8PinState(KEYPAD_PIN_7) == 1 ||DIO_uint8PinState(KEYPAD_PIN_8) == 1){
		if (DIO_uint8PinState(KEYPAD_PIN_5) == 1){
			//LCD_voidWriteData('A');
			_delay_ms(500);
			return key[0][x];
		}
		if (DIO_uint8PinState(KEYPAD_PIN_6) == 1){
			//LCD_voidWriteData('B');
			_delay_ms(500);
			return key[1][x];

		}
		if (DIO_uint8PinState(KEYPAD_PIN_7) == 1){
			//LCD_voidWriteData('C');
			_delay_ms(500);
			return key[2][x];
		}
		if (DIO_uint8PinState(KEYPAD_PIN_8) == 1){
			//LCD_voidWriteData('D');
			_delay_ms(500);
			return key[3][x];

		}
		}
	}
	 return '\0';

}
