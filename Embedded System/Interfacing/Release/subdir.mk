################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../7_Seg_prog.c \
../DIO_prog.c \
../EXT_INTR_prog.c \
../Global_INTR_prog.c \
../KEYPAD_prog.c \
../LCD_prog.c \
../LED_prog.c \
../PASS_prog.c \
../PWM_prog.c \
../SPI_prog.c \
../SW_prog.c \
../Timer0_prog.c \
../UART_prog.c \
../main.c 

OBJS += \
./7_Seg_prog.o \
./DIO_prog.o \
./EXT_INTR_prog.o \
./Global_INTR_prog.o \
./KEYPAD_prog.o \
./LCD_prog.o \
./LED_prog.o \
./PASS_prog.o \
./PWM_prog.o \
./SPI_prog.o \
./SW_prog.o \
./Timer0_prog.o \
./UART_prog.o \
./main.o 

C_DEPS += \
./7_Seg_prog.d \
./DIO_prog.d \
./EXT_INTR_prog.d \
./Global_INTR_prog.d \
./KEYPAD_prog.d \
./LCD_prog.d \
./LED_prog.d \
./PASS_prog.d \
./PWM_prog.d \
./SPI_prog.d \
./SW_prog.d \
./Timer0_prog.d \
./UART_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


