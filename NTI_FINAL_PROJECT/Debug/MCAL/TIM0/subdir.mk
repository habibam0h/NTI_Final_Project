################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIM0/TIM0_program.c 

OBJS += \
./MCAL/TIM0/TIM0_program.o 

C_DEPS += \
./MCAL/TIM0/TIM0_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIM0/%.o: ../MCAL/TIM0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I../LIB -I../HAL/BUZZER -I../HAL/SERVO -I../HAL/DCMOTOR -I../MCAL -I../MCAL/ADC -I../MCAL/DIO -I../MCAL/EXTI -I../MCAL/GIE -I../MCAL/TIM0 -I../HAL -I../HAL/LED -I../HAL/LCD -I../HAL/KEYPAD -I../APP -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


