################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LED/LED_program.c 

OBJS += \
./HAL/LED/LED_program.o 

C_DEPS += \
./HAL/LED/LED_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LED/LED_program.o: ../HAL/LED/LED_program.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/LIB -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/MCAL -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/HAL -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/APP -IC:/Users/habib/Development/Eclipse/NTI_PROJECT/MCAL/DIO -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"HAL/LED/LED_program.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


