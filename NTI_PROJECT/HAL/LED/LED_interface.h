
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "Std_Types.h"


/*==================== LED IDs ====================*/

/* LED Identifiers */
#define LED0    0
#define LED1    1


/*==================== FUNCTION PROTOTYPES ====================*/


/*
 * Function: LED_voidTurnOn
 * Purpose : Turn on the selected LED
 */
void LED_voidTurnOn(u8 LedID);


/*
 * Function: LED_voidTurnOff
 * Purpose : Turn off the selected LED
 */
void LED_voidTurnOff(u8 LedID);


/*
 * Function: LED_voidToggle
 * Purpose : Toggle the state of the selected LED
 */
void LED_voidToggle(u8 LedID);


#endif
