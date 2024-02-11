################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad_prog.c \
../HAL/LCD_prog.c \
../HAL/S_Segment_prog.c 

OBJS += \
./HAL/Keypad_prog.o \
./HAL/LCD_prog.o \
./HAL/S_Segment_prog.o 

C_DEPS += \
./HAL/Keypad_prog.d \
./HAL/LCD_prog.d \
./HAL/S_Segment_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


