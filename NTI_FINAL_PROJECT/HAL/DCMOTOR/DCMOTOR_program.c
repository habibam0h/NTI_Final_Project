
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"

#include "DCMOTOR_config.h"
#include "DCMOTOR_private.h"
#include "DCMOTOR_interface.h"


/*==================== INITIALIZATION ====================*/


/*========================================================
 * Function: DCMOTOR_voidInitialization
 * Purpose : Initialize the DC Motor control pins and
 *           start the Motor in the STOP state
 *========================================================*/
void DCMOTOR_voidInitialization(void)
{
	/* Configure the DC Motor control pins as OUTPUT */
	DIO_voidSetPinDirection(DCMOTOR_IN1, DIO_OUTPUT);
	DIO_voidSetPinDirection(DCMOTOR_IN2, DIO_OUTPUT);
	DIO_voidSetPinDirection(DCMOTOR_EN, DIO_OUTPUT);

	/* Start the DC Motor in the STOP state */
	DIO_voidSetPinValue(DCMOTOR_IN1, DIO_LOW);
	DIO_voidSetPinValue(DCMOTOR_IN2, DIO_LOW);

	/* Keep the DC Motor Enable pin HIGH */
	DIO_voidSetPinValue(DCMOTOR_EN, DIO_HIGH);
}


/*==================== MOVE UP ====================*/


/*========================================================
 * Function: DCMOTOR_voidMoveUp
 * Purpose : Rotate the DC Motor in the direction used
 *           to move the Elevator UP
 *========================================================*/
void DCMOTOR_voidMoveUp(void)
{
	/* IN1 = HIGH , IN2 = LOW -> Move UP */
	DIO_voidSetPinValue(DCMOTOR_IN1, DIO_HIGH);
	DIO_voidSetPinValue(DCMOTOR_IN2, DIO_LOW);
}


/*==================== MOVE DOWN ====================*/


/*========================================================
 * Function: DCMOTOR_voidMoveDown
 * Purpose : Rotate the DC Motor in the direction used
 *           to move the Elevator DOWN
 *========================================================*/
void DCMOTOR_voidMoveDown(void)
{
	/* IN1 = LOW , IN2 = HIGH -> Move DOWN */
	DIO_voidSetPinValue(DCMOTOR_IN1, DIO_LOW);
	DIO_voidSetPinValue(DCMOTOR_IN2, DIO_HIGH);
}


/*==================== STOP ====================*/


/*========================================================
 * Function: DCMOTOR_voidStop
 * Purpose : Stop the DC Motor and stop the Elevator
 *========================================================*/
void DCMOTOR_voidStop(void)
{
	/* IN1 = LOW , IN2 = LOW -> STOP */
	DIO_voidSetPinValue(DCMOTOR_IN1, DIO_LOW);
	DIO_voidSetPinValue(DCMOTOR_IN2, DIO_LOW);
}
