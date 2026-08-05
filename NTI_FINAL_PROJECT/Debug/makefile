################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIM0/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/SERVO/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/DCMOTOR/subdir.mk
-include HAL/BUZZER/subdir.mk
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
NTI_FINAL_PROJECT.lss \

FLASH_IMAGE += \
NTI_FINAL_PROJECT.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: NTI_FINAL_PROJECT.elf secondary-outputs

# Tool invocations
NTI_FINAL_PROJECT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NTI_FINAL_PROJECT.map -mmcu=atmega32 -o "NTI_FINAL_PROJECT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NTI_FINAL_PROJECT.lss: NTI_FINAL_PROJECT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NTI_FINAL_PROJECT.elf  >"NTI_FINAL_PROJECT.lss"
	@echo 'Finished building: $@'
	@echo ' '

NTI_FINAL_PROJECT.hex: NTI_FINAL_PROJECT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NTI_FINAL_PROJECT.elf  "NTI_FINAL_PROJECT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NTI_FINAL_PROJECT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NTI_FINAL_PROJECT.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NTI_FINAL_PROJECT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
