#ifndef LED_INT_H
#define LED_INT_H

#define LED1 DIO_PIN_4
#define LED2 DIO_PIN_5

void LED_ON(u8 led);
void LED_OFF(u8 led);
void LED_TOG(u8 led);

#endif
