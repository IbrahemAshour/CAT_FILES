################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO_prorg.c \
../MCAL/EXTI_config.c \
../MCAL/EXTI_prog.c \
../MCAL/GIE_prog.c 

OBJS += \
./MCAL/DIO_prorg.o \
./MCAL/EXTI_config.o \
./MCAL/EXTI_prog.o \
./MCAL/GIE_prog.o 

C_DEPS += \
./MCAL/DIO_prorg.d \
./MCAL/EXTI_config.d \
./MCAL/EXTI_prog.d \
./MCAL/GIE_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


