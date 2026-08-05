# 🚀 Smart Elevator System using ATmega32

## Overview

The **Smart Elevator System** is an embedded systems project developed in **Embedded C** using the **ATmega32 microcontroller** and simulated in **Proteus ISIS**.

The system simulates the operation of a **9-floor elevator**, allowing the user to select a destination floor through a **4×3 keypad**. The controller determines the required direction, drives the elevator motor, controls the door using a servo motor, updates the LCD with the elevator status, and handles emergency situations using an external interrupt.

The project follows a **layered software architecture (LIB → MCAL → HAL → APP)**, where each peripheral is implemented as an independent driver to improve modularity, readability, and code reusability.

---

# Features

* Supports **9 floors (1–9)**
* Floor selection using a **4×3 keypad**
* Automatic movement direction detection (Up / Down)
* Current floor displayed on a **16×2 LCD**
* Elevator door controlled using a **servo motor**
* Elevator movement controlled by a **DC motor** through an **L293D motor driver**
* Emergency stop using **INT0 External Interrupt**
* Audible alarm using a **buzzer**
* Emergency status indication using an **LED**
* Emergency reset using the **'#' key**
* **TIM0 configured in CTC (Clear Timer on Compare Match) mode** for precise timing and servo control
* Fully modular driver-based software design

---

# Hardware Components

* ATmega32 Microcontroller
* 16×2 LCD
* 4×3 Matrix Keypad
* DC Motor
* L293D Motor Driver IC
* Servo Motor
* Buzzer
* LED
* Push Button (Emergency Switch)
* Proteus Virtual Components

---

# Software Architecture

The project is organized into four software layers:

```text
APP/
│
├── Elevator Control Logic
│
HAL/
├── LCD Driver
├── Keypad Driver
├── DC Motor Driver
├── Servo Driver
├── LED Driver
└── Buzzer Driver
│
MCAL/
├── DIO
├── TIM0
├── EXTI
└── GIE
│
LIB/
├── Std_Types
└── Bit_Math
```

Each layer is responsible for a specific abstraction level, making the project easier to maintain, debug, and expand.

---

# System Operation

1. The system initializes all peripherals.
2. The user enters a destination floor using the keypad.
3. The controller validates the selected floor.
4. The elevator determines whether to move **up** or **down**.
5. The DC motor moves the elevator.
6. The LCD continuously displays the current floor.
7. Once the destination floor is reached:

   * The motor stops.
   * The servo motor opens the elevator door.
   * The system waits for a predefined period.
   * The servo closes the door.
8. The elevator returns to the idle state awaiting the next request.

---

# Emergency Mode

An emergency button connected to **INT0** provides immediate interruption of normal operation.

When the emergency interrupt occurs:

* Elevator movement stops immediately.
* The buzzer is activated.
* The emergency LED turns on.
* The LCD displays an emergency message.
* The system ignores new floor requests until the emergency is cleared.
* Pressing the **'#' key** resets the emergency state and resumes normal operation.

---

# Drivers Implemented

## MCAL Drivers

* Digital Input/Output (DIO)
* Timer0 (CTC Mode)
* External Interrupt (EXTI)
* Global Interrupt Enable (GIE)

## HAL Drivers

* LCD Driver
* Matrix Keypad Driver
* DC Motor Driver
* Servo Motor Driver
* LED Driver
* Buzzer Driver

---

# Technologies Used

* Embedded C
* AVR-GCC
* Eclipse IDE
* Proteus ISIS
* ATmega32 Microcontroller

---

# Repository Structure

```text
Smart-Elevator-System/
│
├── APP/
├── HAL/
├── MCAL/
├── LIB/
├── Proteus/
├── HEX/
├── Debug/
└── README.md
```

---

# How to Run

1. Open the project in Eclipse AVR.
2. Build the project to generate the HEX file.
3. Open the Proteus simulation.
4. Load the generated HEX file into the ATmega32.
5. Start the simulation.
6. Select a floor using the keypad and observe the elevator operation.

---

# Learning Outcomes

This project demonstrates practical experience with:

* Embedded C programming
* Layered software architecture
* Driver development
* Digital I/O interfacing
* Timer programming using **Timer0 CTC Mode**
* External interrupts
* LCD interfacing
* Matrix keypad scanning
* Servo motor control
* DC motor control using the L293D
* Embedded state-machine design
* Modular software engineering

---

# Future Improvements

* Queue multiple floor requests
* Add floor request prioritization
* Door obstruction detection
* Weight sensor integration
* UART-based monitoring and debugging
* EEPROM storage for the last elevator state
* Power failure recovery
* Seven-segment floor indicator

---

# License

This project is intended for educational purposes and to demonstrate embedded systems concepts using the ATmega32 microcontroller.
