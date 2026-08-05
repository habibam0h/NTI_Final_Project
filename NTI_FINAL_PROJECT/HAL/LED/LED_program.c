
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"


/*========================================================
 * Function: LED_voidTurnOn
 * Purpose : Turn on the selected LED
 *========================================================*/
void LED_voidTurnOn(u8 LedID)
{
	switch(LedID){
	case LED0: DIO_voidSetPinValue(LED0_PORT_PIN, DIO_HIGH); break;
	case LED1: DIO_voidSetPinValue(LED1_PORT_PIN, DIO_HIGH); break;
	default: break;
	}
}


/*========================================================
 * Function: LED_voidTurnOff
 * Purpose : Turn off the selected LED
 *========================================================*/
void LED_voidTurnOff(u8 LedID)
{
	switch(LedID){
	case LED0: DIO_voidSetPinValue(LED0_PORT_PIN, DIO_LOW); break;
	case LED1: DIO_voidSetPinValue(LED1_PORT_PIN, DIO_LOW); break;
	default: break;
	}
}


/*========================================================
 * Function: LED_voidToggle
 * Purpose : Toggle the state of the selected LED
 *========================================================*/
void LED_voidToggle(u8 LedID)
{
	switch(LedID){
	case LED0: DIO_voidTogglePin(LED0_PORT_PIN); break;
	case LED1: DIO_voidTogglePin(LED1_PORT_PIN); break;
	default: break;
	}
}

