#include "avr/io.h"
#include "avr/delay.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include "EXT_INTR_config.h"
#include "EXT_INTR_int.h"
#include "EXT_INTR_priv.h"
#include "DIO_int.h"

static volatile void (*pf)(void);

void EXT_INTR0_INIT(void){
	EXT_INTR0_DIS();
	EXT_INTR0_MODE();
}
void EXT_INTR0_ENA(void){
	set_bit(GICR,6);
}
void EXT_INTR0_DIS(void){
	clear_bit(GICR,6);
}
void EXT_INTR0_SetCallBack(void (*p)(void)){
	pf=p;
}
void __Vector_1(void)__attribute__((signal,used));
void __Vector_1(void){
	pf();
}
static void EXT_INTR0_MODE(void)
{
#if INTR_Sense_Mode == RISING_EDGE
	set_bit(MCUCR,1);
	set_bit(MCUCR,0);
#elif INTR_Sense_Mode == FALLING_EDGE
	set_bit(MCUCR,1);
	clear_bit(MCUCR,0);
#elif INTR_Sense_Mode == ON_CHANGE
	set_bit(MCUCR,0);
	clear_bit(MCUCR,1);
#elif INTR_Sense_Mode == LOW_LEVEL
	clear_bit(MCUCR,1);
	clear_bit(MCUCR,0);
#endif
}
