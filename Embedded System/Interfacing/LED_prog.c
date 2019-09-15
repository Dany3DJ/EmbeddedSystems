#include "Bit_Math.h"
#include "Std_Types.h"
#include "LED_int.h"
#include "LED_priv.h"
#include "DIO_int.h"

void LED_ON (u8 led)
{
	DIO_voidSetPin(led);
}
void LED_OFF(u8 led){
	DIO_voidClearPin(led);
}
void LED_TOG(u8 led){
	DIO_voidTogglePin(led);
}
