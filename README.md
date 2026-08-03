# NTI Final Project

This repository is for our **NTI Final Project using ATmega32 AVR**.

Currently, the repository contains the drivers we have implemented so far.
The final project application has not been decided/implemented yet.

## Available Drivers

### MCAL

* DIO
* ADC
* EXTI
* GIE
* TIM0

### HAL

* LED
* LCD
* Keypad

### LIB

Contains the common libraries and definitions used by the drivers.

### APP

Contains `main.c`, which is currently empty and will be used later for the final project application.

## Note

Please keep the same layered structure when adding or modifying files:

* `APP` → Application code
* `HAL` → Hardware drivers
* `MCAL` → Microcontroller drivers
* `LIB` → Common libraries

More drivers and the final application will be added as we progress.
