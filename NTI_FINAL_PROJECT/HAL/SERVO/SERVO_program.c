#include "Std_Types.h"

#include "DIO_interface.h"
#include "TIM0_interface.h"

#include "SERVO_config.h"
#include "SERVO_private.h"
#include "SERVO_interface.h"


/*==================== SERVO VARIABLES ====================*/

/* Count the 100 us intervals inside the 20 ms Servo frame */
static u8 SERVO_FrameCounter = 0;

/* Store the number of 100 us intervals that the Servo signal stays HIGH */
static u8 SERVO_PulseCount = SERVO_MIN_COUNT;


/*==================== INITIALIZATION ====================*/


/*========================================================
 * Function: SERVO_voidInitialization
 * Purpose : Initialize the Servo Motor and register the
 *           Servo Timer0 CTC callback function
 *========================================================*/
void SERVO_voidInitialization(void)
{
	/* Start the Servo at the minimum position */
	SERVO_PulseCount = SERVO_MIN_COUNT;

	/* Start from the beginning of the Servo frame */
	SERVO_FrameCounter = 0;

	/* Start the Servo control signal HIGH */
	DIO_voidSetPinValue(SERVO, DIO_HIGH);

	/* Register the Servo handler as the Timer0 CTC callback */
	TIM0_voidCTCSetCallBack(SERVO_voidTimerHandler);

	/* Enable the Timer0 Compare Match interrupt */
	TIM0_voidCTCInterruptEnable();
}


/*==================== SERVO ANGLE ====================*/


/*========================================================
 * Function: SERVO_voidSetAngle
 * Purpose : Set the Servo Motor to a specific angle
 *           from 0 to SERVO_MAX_ANGLE
 *========================================================*/
void SERVO_voidSetAngle(u8 Angle)
{
	/* Check that the requested Servo angle is valid */
	if(Angle <= SERVO_MAX_ANGLE)
	{
		/* Convert the Servo angle to the required HIGH pulse count */
		SERVO_PulseCount =
				SERVO_MIN_COUNT +
				(((u16)Angle *
				(SERVO_MAX_COUNT - SERVO_MIN_COUNT))
				/ SERVO_MAX_ANGLE);
	}
	else{ /* Invalid Servo Angle */ }
}


/*==================== SERVO TIMER HANDLER ====================*/


/*========================================================
 * Function: SERVO_voidTimerHandler
 * Purpose : Generate the Servo control signal using the
 *           Timer0 CTC interrupt every 100 us
 *========================================================*/
static void SERVO_voidTimerHandler(void)
{
	/* Increment the Servo frame counter every 100 us */
	SERVO_FrameCounter++;

	/* Check if the required Servo HIGH pulse time is completed */
	if(SERVO_FrameCounter == SERVO_PulseCount)
	{
		/* Set the Servo control signal LOW */
		DIO_voidSetPinValue(SERVO, DIO_LOW);
	}

	/* Check if the complete 20 ms Servo frame is completed */
	if(SERVO_FrameCounter >= SERVO_FRAME_COUNTS)
	{
		/* Start a new Servo frame */
		SERVO_FrameCounter = 0;

		/* Start the next Servo control pulse HIGH */
		DIO_voidSetPinValue(SERVO, DIO_HIGH);
	}
}
