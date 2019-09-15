#include "Std_Types.h"
#include "SW_config.h"
#include "SW_int.h"
#include "SW_priv.h"
#include "SW_reg.h"
#include "DIO_int.h"

u8 READSW(u8 sw){
	return DIO_uint8PinState(sw);
}
