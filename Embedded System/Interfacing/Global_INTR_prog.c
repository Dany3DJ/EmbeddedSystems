#include "avr/io.h"
#include "avr/delay.h"
#include "Bit_Math.h"
#include "Std_Types.h"

void global_intr_init(void){

}
void global_intr_ENA(void){
	set_bit(SREG,7);
}
void global_intr_DIS(void){
	clear_bit(SREG,7);
}
