#include <avr/io.h>
#include <util/delay.h>
#include<stdio.h>
#include <avr/eeprom.h>
#include "std_Types.h"
#include "Bit_Math.h"
#include "DIO_Int.h"
#include "LCD_int.h"
#include "PASS_int.h"

u8 MasterKey[]={0x09,0x10,0x11,0x12,0x13,0x14,0x15,0x16};
u8 PASS[]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};

void PASS_INIT(void){
	if (eeprom_read_byte(0x00) != '1'){
		for (int i=0; i<8 ; i++){
				eeprom_write_byte(MasterKey[i],'0');
				eeprom_write_byte(PASS[i],'x');
			}
		eeprom_write_byte(0x00,'1');
		}
}
void PASS_STORE(void){
	for (int i=0; i<8 ; i++){
		eeprom_write_byte(PASS[i],'0');
	}
}
void PASS_PRINT(void){
	for (int i=0; i<8; i++){
		LCD_voidWriteData( eeprom_read_byte(PASS[i]) );
	}
		for (int i=0; i<8; i++){
		LCD_voidWriteData( eeprom_read_byte(MasterKey[i]) );
		}
	}

u8 PASS_COMP(u8 a[]){
	u8 flag1='1',flag2='1';
	u8 num1,num2;
	for (int i=0; i<8; i++){
		num1=eeprom_read_byte(PASS[i]);
		num2=eeprom_read_byte(MasterKey[i]);
		if (a[i] != num1){
			flag1='0';
		}
		if (a[i] != num2){
			flag2='0';
				}
	}
	LCD_voidPrint("Returning ");
	LCD_voidWriteData(flag1 | flag2 );
	return ( flag1|flag2 );
}
