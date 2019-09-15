#ifndef KEYPAD_INT_H
#define KEYPAD_INT_H

#include "KEYPAD_config.h"
#include "KEYPAD_int.h"
#include "KEYPAD_reg.h"
#include "Std_Types.h"

u8 GET_KEYPAD(void);
void KEYPAD_OUTSEQ(int seq);

#endif
