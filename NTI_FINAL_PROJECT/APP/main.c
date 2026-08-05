
#include "Std_Types.h"
#include "Bit_Math.h"

#include <util/delay.h>

#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include "LED_interface.h"
#include "DCMOTOR_interface.h"
#include "SERVO_interface.h"
#include "BUZZER_interface.h"
#include "EXTI_interface.h"
#include "GIE_interface.h"
#include "TIM0_interface.h"


/*==================== FUNCTION PROTOTYPES ====================*/

void MAIN_voidInitialization(void);

void MAIN_voidEmergencyHandler(void);

void MAIN_voidHandleEmergency(void);

void MAIN_voidMoveElevator(void);

void MAIN_voidOpenDoor(void);

void MAIN_voidCloseDoor(void);


/*==================== FLOOR LIMITS ====================*/

#define MIN_FLOOR    1
#define MAX_FLOOR    9


/*==================== APPLICATION STATES ====================*/

typedef enum
{
	ELEVATOR_IDLE,
	ELEVATOR_MOVING_UP,
	ELEVATOR_MOVING_DOWN,
	ELEVATOR_DOOR_OPEN,
	ELEVATOR_EMERGENCY

} ElevatorState_t;


/*==================== APPLICATION VARIABLES ====================*/

u8 CurrentFloor = MIN_FLOOR;

u8 TargetFloor = MIN_FLOOR;

volatile u8 EmergencyFlag = 0;

ElevatorState_t ElevatorState = ELEVATOR_IDLE;


/*========================================================
 * Function: MAIN_voidInitialization
 * Purpose : Initialize all the drivers used in the project
 *========================================================*/
void MAIN_voidInitialization(void)
{
	DIO_voidInitialization();

	LCD_voidInitialization();

	KEYPAD_voidInitialization();

	DCMOTOR_voidInitialization();

	TIM0_voidInitialization();

	SERVO_voidInitialization();

	BUZZER_voidInitialization();

	EXTI_voidInitialization();

	DIO_voidSetPinValue(DIO_PORTD, DIO_PIN2, DIO_HIGH); // enable internal pull-up on PD2/INT0

	EXTI_voidSetCallBack(EXTI_INT0, MAIN_voidEmergencyHandler);

	EXTI_voidInterruptEnable(EXTI_INT0);

	GIE_voidEnable();

	/* LED0 is ON while the system is ready */
	LED_voidTurnOn(LED0);

	LCD_voidWriteString((u8*)"SMART ELEVATOR");

	LCD_voidGoToXY(0, 2);

	LCD_voidWriteString((u8*)"Floor: 1");
}


/*========================================================
 * Function: MAIN_voidEmergencyHandler
 * Purpose : Called from the EXTI ISR when the Emergency
 *           button is pressed, stops the Motor immediately
 *========================================================*/
void MAIN_voidEmergencyHandler(void)
{
	EmergencyFlag = 1;

	DCMOTOR_voidStop();
}


/*========================================================
 * Function: MAIN_voidHandleEmergency
 * Purpose : Handle the Emergency state, sound the alarm,
 *           and wait until the user acknowledges it
 *========================================================*/
void MAIN_voidHandleEmergency(void)
{
	ElevatorState = ELEVATOR_EMERGENCY;

	LED_voidTurnOff(LED0);

	LED_voidTurnOn(LED1);

	BUZZER_voidTurnOn();

	LCD_voidClear();

	LCD_voidWriteString((u8*)"EMERGENCY STOP!");

	LCD_voidGoToXY(0, 2);

	LCD_voidWriteString((u8*)"Press # to reset");

	/* Wait until the user presses # to clear the Emergency */
	while(KEYPAD_u8GetPressedKey() != '#');

	BUZZER_voidTurnOff();

	LED_voidTurnOff(LED1);

	LED_voidTurnOn(LED0);

	EmergencyFlag = 0;

	ElevatorState = ELEVATOR_IDLE;

	LCD_voidClear();

	LCD_voidWriteString((u8*)"SMART ELEVATOR");

	LCD_voidGoToXY(0, 2);

	LCD_voidWriteString((u8*)"Floor: ");

	LCD_voidWriteNumber(CurrentFloor);
}


/*========================================================
 * Function: MAIN_voidMoveElevator
 * Purpose : Move the Elevator cabin floor by floor from
 *           the Current Floor to the Target Floor
 *========================================================*/
void MAIN_voidMoveElevator(void)
{
	if(TargetFloor > CurrentFloor)
	{
		ElevatorState = ELEVATOR_MOVING_UP;
	}
	else if(TargetFloor < CurrentFloor)
	{
		ElevatorState = ELEVATOR_MOVING_DOWN;
	}
	else{ /* Already at the Target Floor */ }

	while(CurrentFloor != TargetFloor && EmergencyFlag == 0)
	{
		LCD_voidClear();

		if(ElevatorState == ELEVATOR_MOVING_UP)
		{
			LCD_voidWriteString((u8*)"Moving UP...");

			DCMOTOR_voidMoveUp();

			CurrentFloor++;
		}
		else
		{
			LCD_voidWriteString((u8*)"Moving DOWN...");

			DCMOTOR_voidMoveDown();

			CurrentFloor--;
		}

		LCD_voidGoToXY(0, 2);

		LCD_voidWriteString((u8*)"Floor: ");

		LCD_voidWriteNumber(CurrentFloor);

		/* Time taken to travel one floor */
		_delay_ms(1000);
	}

	DCMOTOR_voidStop();
}


/*========================================================
 * Function: MAIN_voidOpenDoor
 * Purpose : Open the Elevator door and keep it open for
 *           a period of time before it is closed again
 *========================================================*/
void MAIN_voidOpenDoor(void)
{
	ElevatorState = ELEVATOR_DOOR_OPEN;

	SERVO_voidSetAngle(DOOR_OPEN_ANGLE);

	LCD_voidClear();

	LCD_voidWriteString((u8*)"Door Opening..");

	_delay_ms(1000);

	LCD_voidGoToXY(0, 2);

	LCD_voidWriteString((u8*)"Door OPEN");

	/* Keep the door open for a period of time */
	_delay_ms(3000);
}


/*========================================================
 * Function: MAIN_voidCloseDoor
 * Purpose : Close the Elevator door and go back to the
 *           Idle state, ready for the next request
 *========================================================*/
void MAIN_voidCloseDoor(void)
{
	SERVO_voidSetAngle(DOOR_CLOSED_ANGLE);

	LCD_voidClear();

	LCD_voidWriteString((u8*)"Door Closing..");

	_delay_ms(1000);

	ElevatorState = ELEVATOR_IDLE;

	LCD_voidClear();

	LCD_voidWriteString((u8*)"SMART ELEVATOR");

	LCD_voidGoToXY(0, 2);

	LCD_voidWriteString((u8*)"Floor: ");

	LCD_voidWriteNumber(CurrentFloor);
}


int main(void)
{
	u8 Key;

	/* Initialization */
	MAIN_voidInitialization();

	while(1)
	{
		if(EmergencyFlag)
		{
			MAIN_voidHandleEmergency();
			continue;
		}

		/* Read the requested Floor from the Keypad */
		Key = KEYPAD_u8GetPressedKey();

		if((Key >= ('0' + MIN_FLOOR)) && (Key <= ('0' + MAX_FLOOR)))
		{
			TargetFloor = Key - '0';

			MAIN_voidMoveElevator();

			if(EmergencyFlag)
			{
				continue;
			}

			MAIN_voidOpenDoor();

			if(EmergencyFlag)
			{
				continue;
			}

			MAIN_voidCloseDoor();
		}
		else{ /* No valid Floor key pressed */ }
	}

	return 0;
}
