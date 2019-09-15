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
#include "PWM_config.h"
#include "PWM_int.h"
#include "PWM_priv.h"
#include "PWM_reg.h"

void PWM_INIT(void){
	TCCR0=0x69;
	TCCR2=0x69;
}
void PWM_OC0_SET(u8 DC){
	OCR0=((DC*256)/100)-1;
}
void PWM_OC2_SET(u8 DC){
	OCR2=((DC*256)/100)-1;
}
