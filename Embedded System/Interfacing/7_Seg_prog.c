#include "avr/io.h"
#include "Std_Types.h"
#include "DIO_int.h"
#include "LED_int.h"
#include "7_Seg_config.h"
#include "7_Seg_int.h"
#include "7_Seg_priv.h"
#include "7_Seg_reg.h"

void Seg_num0(void){
	LED_OFF(a);
	LED_OFF(b);
	LED_OFF(c);
	LED_OFF(d);
	LED_OFF(e);
	LED_OFF(f);
	LED_OFF(g);
	LED_ON(TOP_L);
	LED_ON(TOP_R);
	LED_ON(TOP);
	LED_ON(BOT_L);
	LED_ON(BOT_R);
	LED_ON(BOT);
}
void Seg_num1(void){
	LED_OFF(a);
	LED_OFF(b);
	LED_OFF(c);
	LED_OFF(d);
	LED_OFF(e);
	LED_OFF(f);
	LED_OFF(g);
	LED_ON(TOP_R);
	LED_ON(BOT_R);
}
void Seg_num2(void){
	LED_OFF(a);
	LED_OFF(b);
	LED_OFF(c);
	LED_OFF(d);
	LED_OFF(e);
	LED_OFF(f);
	LED_OFF(g);
	LED_ON(TOP_R);
	LED_ON(TOP);
	LED_ON(BOT_L);
	LED_ON(MID);
	LED_ON(BOT);
}
void Seg_num3(void){
	LED_OFF(a);
	LED_OFF(b);
	LED_OFF(c);
	LED_OFF(d);
	LED_OFF(e);
	LED_OFF(f);
	LED_OFF(g);
	LED_ON(MID);
	LED_ON(TOP_R);
	LED_ON(TOP);
	LED_ON(BOT_R);
	LED_ON(BOT);
}
void Seg_num4(void){
	LED_OFF(a);
	LED_OFF(b);
	LED_OFF(c);
	LED_OFF(d);
	LED_OFF(e);
	LED_OFF(f);
	LED_OFF(g);
	LED_ON(TOP_L);
	LED_ON(TOP_R);
	LED_ON(MID);
	LED_ON(BOT_R);
}
void Seg_num5(void){
	LED_OFF(a);
	LED_OFF(b);
	LED_OFF(c);
	LED_OFF(d);
	LED_OFF(e);
	LED_OFF(f);
	LED_OFF(g);
	LED_ON(TOP_L);
	LED_ON(MID);
	LED_ON(TOP);
	LED_ON(BOT_R);
	LED_ON(BOT);
}
void Seg_num6(void){
	LED_OFF(a);
	LED_OFF(b);
	LED_OFF(c);
	LED_OFF(d);
	LED_OFF(e);
	LED_OFF(f);
	LED_OFF(g);
	LED_ON(TOP_L);
	LED_ON(MID);
	LED_ON(TOP);
	LED_ON(BOT_L);
	LED_ON(BOT_R);
	LED_ON(BOT);
}
void Seg_num7(void){
	LED_OFF(a);
	LED_OFF(b);
	LED_OFF(c);
	LED_OFF(d);
	LED_OFF(e);
	LED_OFF(f);
	LED_OFF(g);
	LED_ON(TOP_R);
	LED_ON(TOP);
	LED_ON(BOT_R);
}
void Seg_num8(void){
	LED_OFF(a);
	LED_OFF(b);
	LED_OFF(c);
	LED_OFF(d);
	LED_OFF(e);
	LED_OFF(f);
	LED_OFF(g);
	LED_ON(TOP_L);
	LED_ON(TOP_R);
	LED_ON(TOP);
	LED_ON(BOT_L);
	LED_ON(BOT_R);
	LED_ON(BOT);
	LED_ON(MID);
}
void Seg_num9(void){
	LED_OFF(a);
	LED_OFF(b);
	LED_OFF(c);
	LED_OFF(d);
	LED_OFF(e);
	LED_OFF(f);
	LED_OFF(g);
	LED_ON(TOP_L);
	LED_ON(TOP_R);
	LED_ON(TOP);
	LED_ON(MID);
	LED_ON(BOT_R);
	LED_ON(BOT);
}
void Seg_DISPLAY(u8 num){
	switch (num){
	case 0: Seg_num0();
			break;
	case 1: Seg_num1();
				break;
	case 2: Seg_num2();
				break;
	case 3: Seg_num3();
				break;
	case 4: Seg_num4();
				break;
	case 5: Seg_num5();
				break;
	case 6: Seg_num6();
				break;
	case 7: Seg_num7();
				break;
	case 8: Seg_num8();
				break;
	case 9: Seg_num9();
				break;
	}
}
