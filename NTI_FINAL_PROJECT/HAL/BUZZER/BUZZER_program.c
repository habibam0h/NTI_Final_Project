#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"

#include "BUZZER_interface.h"
#include "BUZZER_config.h"


/*========================================================
 * Function: BUZZER_voidInitialization
 * Purpose : Initialize the buzzer by turning it OFF
 *========================================================*/
void BUZZER_voidInitialization(void)
{
	DIO_voidSetPinValue(BUZZER_PORT_PIN, DIO_LOW);
}


/*========================================================
 * Function: BUZZER_voidTurnOn
 * Purpose : Turn the buzzer ON
 *========================================================*/
void BUZZER_voidTurnOn(void)
{
	DIO_voidSetPinValue(BUZZER_PORT_PIN, DIO_HIGH);
}


/*========================================================
 * Function: BUZZER_voidTurnOff
 * Purpose : Turn the buzzer OFF
 *========================================================*/
void BUZZER_voidTurnOff(void)
{
	DIO_voidSetPinValue(BUZZER_PORT_PIN, DIO_LOW);
}
