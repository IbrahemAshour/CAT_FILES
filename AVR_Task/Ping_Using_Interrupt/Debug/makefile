################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
TAsk_Interuupt.lss \

FLASH_IMAGE += \
TAsk_Interuupt.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TAsk_Interuupt.elf secondary-outputs

# Tool invocations
TAsk_Interuupt.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TAsk_Interuupt.map -mmcu=atmega32 -o "TAsk_Interuupt.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TAsk_Interuupt.lss: TAsk_Interuupt.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TAsk_Interuupt.elf  >"TAsk_Interuupt.lss"
	@echo 'Finished building: $@'
	@echo ' '

TAsk_Interuupt.hex: TAsk_Interuupt.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TAsk_Interuupt.elf  "TAsk_Interuupt.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TAsk_Interuupt.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TAsk_Interuupt.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TAsk_Interuupt.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
