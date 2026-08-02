
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "Std_Types.h"


/*==================== NUMBER OF PORTS & PINS ====================*/

/* Number of DIO ports in ATmega32 */
#define DIO_NUMBER_OF_PORTS     4

/* Number of pins in each DIO port */
#define DIO_NUMBER_OF_PINS      8


/*==================== PORT IDs ====================*/

/* DIO Port Identifiers */
#define DIO_PORTA               0
#define DIO_PORTB               1
#define DIO_PORTC               2
#define DIO_PORTD               3


/*==================== PIN IDs ====================*/

/* DIO Pin Identifiers */
#define DIO_PIN0                0
#define DIO_PIN1                1
#define DIO_PIN2                2
#define DIO_PIN3                3
#define DIO_PIN4                4
#define DIO_PIN5                5
#define DIO_PIN6                6
#define DIO_PIN7                7


/*==================== PIN DIRECTION ====================*/

/* DIO Pin Direction Options */
#define DIO_INPUT               0
#define DIO_OUTPUT              1


/*==================== PIN VALUE ====================*/

/* DIO Pin Value Options */
#define DIO_LOW                 0
#define DIO_HIGH                1


/*==================== FUNCTION PROTOTYPES ====================*/


/*
 * Function: DIO_voidInitialization
 * Purpose : Initialize all DIO port directions according
 *           to the configured settings
 */
void DIO_voidInitialization(void);


/*
 * Function: DIO_voidSetPinDirection
 * Purpose : Set the direction of a specific DIO pin
 */
void DIO_voidSetPinDirection(u8 PortID, u8 PinID, u8 Direction);


/*
 * Function: DIO_voidSetPortDirection
 * Purpose : Set the direction of an entire DIO port
 */
void DIO_voidSetPortDirection(u8 PortID, u8 Direction);


/*
 * Function: DIO_voidSetPinValue
 * Purpose : Set the output value of a specific DIO pin
 */
void DIO_voidSetPinValue(u8 PortID, u8 PinID, u8 Value);


/*
 * Function: DIO_voidTogglePin
 * Purpose : Toggle the output value of a specific DIO pin
 */
void DIO_voidTogglePin(u8 PortID, u8 PinID);


/*
 * Function: DIO_voidSetPortValue
 * Purpose : Set the output value of an entire DIO port
 */
void DIO_voidSetPortValue(u8 PortID, u8 Value);


/*
 * Function: DIO_u8GetPinValue
 * Purpose : Read and return the value of a specific DIO pin
 */
u8 DIO_u8GetPinValue(u8 PortID, u8 PinID);


#endif
