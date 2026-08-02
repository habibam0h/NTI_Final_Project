################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD/LCD_program.c 

OBJS += \
./HAL/LCD/LCD_program.o 

C_DEPS += \
./HAL/LCD/LCD_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD/%.o: ../HAL/LCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/LIB -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/MCAL -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/MCAL/ADC -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/MCAL/DIO -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/MCAL/EXTI -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/MCAL/GIE -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/HAL -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/HAL/LED -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/HAL/LCD -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/HAL/KEYPAD -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/APP -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


