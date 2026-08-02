
#include "Std_Types.h"
#include "Bit_Math.h"

#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"

/*==================== CALLBACK POINTERS ====================*/

/* Store the callback function address for INT0 */
static EXTI_CallBack_pt INT0_CallBack = NULL;

/* Store the callback function address for INT1 */
static EXTI_CallBack_pt INT1_CallBack = NULL;

/* Store the callback function address for INT2 */
static EXTI_CallBack_pt INT2_CallBack = NULL;


/*========================================================
 * Function: EXTI_voidInitialization
 * Purpose : Initialize INT0, INT1, and INT2
 *========================================================*/
void EXTI_voidInitialization(void)
{
	/* Set the initial sense modes */
	EXTI_voidSetSenseMode(EXTI_INT0, EXTI_INT0_SENSE_MODE);
	EXTI_voidSetSenseMode(EXTI_INT1, EXTI_INT1_SENSE_MODE);
	EXTI_voidSetSenseMode(EXTI_INT2, EXTI_INT2_SENSE_MODE);

	/* Start all external interrupts disabled */
	EXTI_voidInterruptDisable(EXTI_INT0);
	EXTI_voidInterruptDisable(EXTI_INT1);
	EXTI_voidInterruptDisable(EXTI_INT2);

	/*
	 * Clear all pending interrupt flags.
	 * GIFR flags are cleared by writing 1 to them.
	 * Writing 0 leaves the flag unchanged.
	 */
	GIFR_REG = (1 << GIFR_INTF0) |
			   (1 << GIFR_INTF1) |
			   (1 << GIFR_INTF2);
}


/*========================================================
 * Function: EXTI_voidSetSenseMode
 * Purpose : Set the trigger mode for INT0, INT1, or INT2
 *========================================================*/
void EXTI_voidSetSenseMode(u8 InterruptNumber, u8 SenseMode)
{
	switch(InterruptNumber)
	{
		/*==================== INT0 ====================*/
		case EXTI_INT0:

			switch(SenseMode)
			{
				/* Low Level: ISC01 = 0, ISC00 = 0 */
				case EXTI_LOW_LEVEL:
					CLR_BIT(MCUCR_REG, MCUCR_ISC00);
					CLR_BIT(MCUCR_REG, MCUCR_ISC01);
					break;

				/* Any Logical Change: ISC01 = 0, ISC00 = 1 */
				case EXTI_ANY_CHANGE:
					SET_BIT(MCUCR_REG, MCUCR_ISC00);
					CLR_BIT(MCUCR_REG, MCUCR_ISC01);
					break;

				/* Falling Edge: ISC01 = 1, ISC00 = 0 */
				case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCR_REG, MCUCR_ISC00);
					SET_BIT(MCUCR_REG, MCUCR_ISC01);
					break;

				/* Rising Edge: ISC01 = 1, ISC00 = 1 */
				case EXTI_RISING_EDGE:
					SET_BIT(MCUCR_REG, MCUCR_ISC00);
					SET_BIT(MCUCR_REG, MCUCR_ISC01);
					break;

				default:
					break;
			}
			break;


		/*==================== INT1 ====================*/
		case EXTI_INT1:

			switch(SenseMode)
			{
				/* Low Level: ISC11 = 0, ISC10 = 0 */
				case EXTI_LOW_LEVEL:
					CLR_BIT(MCUCR_REG, MCUCR_ISC10);
					CLR_BIT(MCUCR_REG, MCUCR_ISC11);
					break;

				/* Any Logical Change: ISC11 = 0, ISC10 = 1 */
				case EXTI_ANY_CHANGE:
					SET_BIT(MCUCR_REG, MCUCR_ISC10);
					CLR_BIT(MCUCR_REG, MCUCR_ISC11);
					break;

				/* Falling Edge: ISC11 = 1, ISC10 = 0 */
				case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCR_REG, MCUCR_ISC10);
					SET_BIT(MCUCR_REG, MCUCR_ISC11);
					break;

				/* Rising Edge: ISC11 = 1, ISC10 = 1 */
				case EXTI_RISING_EDGE:
					SET_BIT(MCUCR_REG, MCUCR_ISC10);
					SET_BIT(MCUCR_REG, MCUCR_ISC11);
					break;

				default:
					break;
			}
			break;


		/*==================== INT2 ====================*/
		case EXTI_INT2:

			/* INT2 supports Falling and Rising Edge only */
			switch(SenseMode)
			{
				/* Falling Edge: ISC2 = 0 */
				case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCSR_REG, MCUCSR_ISC2);
					break;

				/* Rising Edge: ISC2 = 1 */
				case EXTI_RISING_EDGE:
					SET_BIT(MCUCSR_REG, MCUCSR_ISC2);
					break;

				default:
					break;
			}
			break;


		/* Invalid Interrupt Number */
		default:
			break;
	}
}


/*========================================================
 * Function: EXTI_voidInterruptEnable
 * Purpose : Enable INT0, INT1, or INT2 individually
 *========================================================*/
void EXTI_voidInterruptEnable(u8 InterruptNumber)
{
	switch(InterruptNumber)
	{
		/*==================== INT0 ====================*/
		case EXTI_INT0:

			/* Enable INT0 */
			SET_BIT(GICR_REG, GICR_INT0);
			break;


		/*==================== INT1 ====================*/
		case EXTI_INT1:

			/* Enable INT1 */
			SET_BIT(GICR_REG, GICR_INT1);
			break;


		/*==================== INT2 ====================*/
		case EXTI_INT2:

			/* Enable INT2 */
			SET_BIT(GICR_REG, GICR_INT2);
			break;


		/* Invalid Interrupt Number */
		default:
			break;
	}
}


/*========================================================
 * Function: EXTI_voidInterruptDisable
 * Purpose : Disable INT0, INT1, or INT2 individually
 *========================================================*/
void EXTI_voidInterruptDisable(u8 InterruptNumber)
{
	switch(InterruptNumber)
	{
		/*==================== INT0 ====================*/
		case EXTI_INT0:

			/* Disable INT0 */
			CLR_BIT(GICR_REG, GICR_INT0);
			break;


		/*==================== INT1 ====================*/
		case EXTI_INT1:

			/* Disable INT1 */
			CLR_BIT(GICR_REG, GICR_INT1);
			break;


		/*==================== INT2 ====================*/
		case EXTI_INT2:

			/* Disable INT2 */
			CLR_BIT(GICR_REG, GICR_INT2);
			break;


		/* Invalid Interrupt Number */
		default:
			break;
	}
}


/*========================================================
 * Function: EXTI_voidSetCallBack
 * Purpose : Set the callback function to be executed when
 *           INT0, INT1, or INT2 interrupt occurs
 *========================================================*/
void EXTI_voidSetCallBack(u8 InterruptNumber, EXTI_CallBack_pt FunctionAddress)
{
	switch(InterruptNumber)
	{
		/*==================== INT0 ====================*/
		case EXTI_INT0:

			/* Store INT0 callback function address */
			INT0_CallBack = FunctionAddress;
			break;


		/*==================== INT1 ====================*/
		case EXTI_INT1:

			/* Store INT1 callback function address */
			INT1_CallBack = FunctionAddress;
			break;


		/*==================== INT2 ====================*/
		case EXTI_INT2:

			/* Store INT2 callback function address */
			INT2_CallBack = FunctionAddress;
			break;


		/* Invalid Interrupt Number */
		default:
			break;
	}
}


/*========================================================
 * EXTERNAL INTERRUPT ISRs
 *
 * signal : Tell the compiler these functions are ISRs
 * used   : Keep the functions even though they are not
 *          called normally by the program
 *
 * INT0 -> __vector_1
 * INT1 -> __vector_2
 * INT2 -> __vector_3
 *========================================================*/


/*==================== INT0 ISR ====================*/

void __vector_1(void) __attribute__((signal, used));

void __vector_1(void)
{
	/* Execute callback only if a function was assigned */
	if (INT0_CallBack != NULL)
	{
		INT0_CallBack();
	}
}


/*==================== INT1 ISR ====================*/

void __vector_2(void) __attribute__((signal, used));

void __vector_2(void)
{
	/* Execute callback only if a function was assigned */
	if (INT1_CallBack != NULL)
	{
		INT1_CallBack();
	}
}


/*==================== INT2 ISR ====================*/

void __vector_3(void) __attribute__((signal, used));

void __vector_3(void)
{
	/* Execute callback only if a function was assigned */
	if (INT2_CallBack != NULL)
	{
		INT2_CallBack();
	}
}
