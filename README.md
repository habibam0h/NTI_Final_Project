# 🚀 Smart Elevator System using ATmega32

## Overview

The **Smart Elevator System** is an embedded systems project developed using the **ATmega32 microcontroller** and simulated in **Proteus**. The project demonstrates how multiple hardware peripherals and software drivers can be integrated to implement a realistic elevator control system.

The elevator accepts floor requests through a keypad, determines the appropriate movement direction, controls the elevator motor, simulates door operation using a servo motor, displays system information on an LCD, and provides emergency handling through an external interrupt.

This project was developed following a **layered architecture (LIB → MCAL → HAL → APP)** to ensure modularity, reusability, and maintainability.

---

## Features

* Supports **9 elevator floors (1–9)**
* Floor selection using a **4×3 keypad**
* Automatic movement direction detection

  * Moving Up
  * Moving Down
  * Idle
* LCD displays:

  * Current floor
  * System status
  * Emergency messages
* Door control using a **Servo Motor**
* Elevator movement using a **DC Motor**
* Emergency stop using an **External Interrupt (INT0)**
* Audible emergency alarm using a **Buzzer**
* Status indication using **LEDs**
* Timer0-based software PWM for servo control
* Modular driver-based software architecture

---

## Hardware Components

* ATmega32 Microcontroller
* 16×2 LCD
* 4×3 Keypad
* DC Motor
* L293D Motor Driver
* Servo Motor
* Buzzer
* LEDs
* Push Button (Emergency Stop)
* Proteus Virtual Components

---

## Software Architecture

The project follows a layered architecture:

```text
APP
│
├── Elevator Application Logic
│
HAL
├── LCD Driver
├── Keypad Driver
├── DC Motor Driver
├── Servo Driver
├── LED Driver
└── Buzzer Driver
│
MCAL
├── DIO
├── Timer0
├── EXTI
├── GIE
└── ADC
│
LIB
├── Std_Types
└── Bit_Math
```

This structure separates hardware abstraction from application logic, making the code easier to maintain and extend.

---

## Project Workflow

1. System initialization
2. User selects the destination floor
3. Controller validates the requested floor
4. Elevator determines the movement direction
5. DC motor moves the elevator
6. LCD updates the current floor
7. Upon arrival:

   * Motor stops
   * Servo opens the door
   * Waits for passengers
   * Servo closes the door
8. System returns to the idle state

---

## Emergency Mode

The elevator includes an emergency safety mechanism:

* Emergency button connected to **INT0**
* Motor stops immediately
* Buzzer alarm is activated
* LCD displays an emergency warning
* System remains locked until the user acknowledges the alarm by pressing **#**
* Elevator resumes normal operation after reset

---

## Drivers Implemented

### MCAL Drivers

* DIO
* Timer0
* External Interrupt (EXTI)
* Global Interrupt Enable (GIE)
* ADC

### HAL Drivers

* LCD
* Keypad
* DC Motor
* Servo Motor
* LED
* Buzzer

---

## Technologies Used

* Embedded C
* AVR-GCC
* Eclipse IDE
* Proteus ISIS
* ATmega32

---

## Repository Structure

```text
.
├── APP/
├── HAL/
├── MCAL/
├── LIB/
├── Debug/
├── Proteus/
├── HEX/
└── README.md
```

---

## How to Run

1. Open the project in Eclipse AVR.
2. Build the project to generate the `.hex` file.
3. Open the Proteus simulation.
4. Load the generated `.hex` file into the ATmega32.
5. Run the simulation.
6. Select floors using the keypad and observe the elevator operation.

---

## Learning Outcomes

This project demonstrates practical implementation of:

* Embedded software architecture
* Driver development
* Digital I/O programming
* Interrupt handling
* Timer-based software PWM
* Servo motor control
* DC motor control
* LCD interfacing
* Keypad scanning
* Embedded state-machine design
* Modular software development

---

## Future Improvements

* Floor request queue management
* Multiple simultaneous requests
* Door obstruction detection
* Weight sensor integration
* Seven-segment floor indicator
* UART-based monitoring
* EEPROM storage of last floor
* Automatic power recovery
* Real-time clock integration

---

## Author

**Habiba Elawadly**

Computer Engineering Student

Embedded Systems | AVR | Embedded C | ATmega32 | Proteus

---

## License

This project is intended for educational and learning purposes.
