#include "avr/io.h"
#include "Std_Types.h"
#include "Bit_Math.h"
#include "util/delay.h"
#include "DIO_int.h"
#include "Timer0_priv.h"
#include "Timer0_config.h"
#include "Timer0_int.h"

static volatile void (*pf) (void);

void Timer0_INIT(void){
	TCCR0=0b00000000;
	Timer0_INTR_DIS_OCR();
	Timer0_INTR_DIS_OCR();
	set_mode();
	set_prescaller();
}
void Timer0_SetCallBack(void (*p)(void)){
	pf = p;
}
#if Timer0_mode == OUTPUT_COMPARE
	void Timer0_INTR_ENA_OCR(void){
		set_bit(TIMSK,1);
		clear_bit(TIMSK,0);
	}
	void Timer0_INTR_DIS_OCR(void){
		clear_bit(TIMSK,1);
	}
#endif

#if Timer0_mode == NORMAL_MODE
	void Timer0_INTR_ENA_OV(void){
		set_bit(TIMSK,0);
		clear_bit(TIMSK,1);
	}
	void Timer0_INTR_DIS_OV(void){
		clear_bit(TIMSK,0);
	}
#endif

void Set_counter_Timer0(u8 time){
	#if TIMER_MODE == OUTPUT_COMPARE
		OCR0 = time;
	#elif TIMER_MODE == NORMAL_MODE
		TCNT0=time;
#endif
}


static void set_mode(void){
	#if Timer0_mode==NORMAL_MODE
		clear_bit(TCCR0,3);
		clear_bit(TCCR0,6);
	#elif Timer0_mode == OUTPUT_COMPARE
		set_bit(TCCR0,3);
		clear_bit(TCCR0,6);
#endif
}
#if TIMER0_MODE == NORMAL_MODE
		void __vector_11 (void) __attribute__((signal,used));
		void __vector_11 (void)
		{
			pf();
		}
#endif
#if TIMER0_MODE == OUTPUT_COMPARE
		void __vector_10 (void) __attribute__((signal,used));
		void __vector_10 (void)
		{
			pf();
		}
#endif
static void set_prescaller(void){
	#if PRESCALLER== PRE_1024
		set_bit(TCCR0,0);
		set_bit(TCCR0,2);
		clear_bit(TCCR0,1);
#endif
}
