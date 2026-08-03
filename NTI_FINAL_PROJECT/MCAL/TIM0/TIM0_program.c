
#include "Std_Types.h"
#include "Bit_Math.h"

#include "TIM0_config.h"
#include "TIM0_private.h"
#include "TIM0_interface.h"


/*==================== CALLBACK POINTERS ====================*/

/* Store the callback function address for the Timer0 Overflow interrupt */
static TIM0_CallBack_pt TIM0_OVCallBack = NULL;

/* Store the callback function address for the Timer0 Compare Match interrupt */
static TIM0_CallBack_pt TIM0_CTCCallBack = NULL;


/*==================== INITIALIZATION ====================*/


/*========================================================
 * Function: TIM0_voidInitialization
 * Purpose : Initialize Timer0 peripheral with the
 *           configured settings
 *========================================================*/
void TIM0_voidInitialization(void)
{
	/* Stop Timer0 while configuring the peripheral */
	TIM0_voidSetPrescaler(TIM0_NO_CLOCK);

	/* Set the configured Timer0 operating mode */
	TIM0_voidSetMode(TIM0_MODE);

	/* Set the configured Timer0 Compare Match output mode */
	TIM0_voidSetCompareOutputMode(TIM0_COMPARE_OUTPUT);

	/* Start with the Timer0 Overflow interrupt disabled */
	TIM0_voidOVInterruptDisable();

	/* Start with the Timer0 Compare Match interrupt disabled */
	TIM0_voidCTCInterruptDisable();

	/* Clear any pending Timer0 Overflow flag */
	TIM0_voidClearOVFlag();

	/* Clear any pending Timer0 Compare Match flag */
	TIM0_voidClearCTCFlag();

	/* Clear the Timer0 Counter Register */
	TIM0_voidSetOVReg(0);

	/* Clear the Timer0 Output Compare Register */
	TIM0_voidSetCTCReg(0);

	/* Start Timer0 with the configured clock prescaler */
	TIM0_voidSetPrescaler(TIM0_PRESCALER);
}


/*==================== GENERAL TIMER0 CONFIGURATION ====================*/


/*========================================================
 * Function: TIM0_voidSetPrescaler
 * Purpose : Set the Timer0 Clock Prescaler
 *========================================================*/
void TIM0_voidSetPrescaler(u8 Prescaler)
{
	/* Clear the old Clock Select bits (CS02:CS00) */
	TCCR0_REG &= 0xF8;

	/* Set the new Clock Select bits */
	TCCR0_REG |= (Prescaler & 0x07);
}



/*========================================================
 * Function: TIM0_voidSetMode
 * Purpose : Set the Timer0 Operating Mode
 *========================================================*/
void TIM0_voidSetMode(u8 Mode)
{
	switch (Mode)
	{
		case TIM0_NORMAL_MODE:

			/* Select Normal Mode: WGM01:WGM00 = 00 */
			CLR_BIT(TCCR0_REG, WGM00_BIT);
			CLR_BIT(TCCR0_REG, WGM01_BIT);
			break;


		case TIM0_PHASE_CORRECT_PWM_MODE:

			/* Select Phase Correct PWM Mode: WGM01:WGM00 = 01 */
			SET_BIT(TCCR0_REG, WGM00_BIT);
			CLR_BIT(TCCR0_REG, WGM01_BIT);
			break;


		case TIM0_CTC_MODE:

			/* Select CTC Mode: WGM01:WGM00 = 10 */
			CLR_BIT(TCCR0_REG, WGM00_BIT);
			SET_BIT(TCCR0_REG, WGM01_BIT);
			break;


		case TIM0_FAST_PWM_MODE:

			/* Select Fast PWM Mode: WGM01:WGM00 = 11 */
			SET_BIT(TCCR0_REG, WGM00_BIT);
			SET_BIT(TCCR0_REG, WGM01_BIT);
			break;


		default: break;
	}
}

/*========================================================
 * Function: TIM0_voidSetCompareOutputMode
 * Purpose : Set the Timer0 Compare Match Output Mode
 *========================================================*/
void TIM0_voidSetCompareOutputMode(u8 CompareOutputMode)
{
	/* Clear the old Compare Output Mode bits (COM01:COM00) */
	TCCR0_REG &= 0xCF;

	/* Set the new Compare Output Mode */
	TCCR0_REG |= (CompareOutputMode & 0x03) << COM00_BIT;
}


/*==================== NORMAL MODE / OVERFLOW ====================*/


/*========================================================
 * Function: TIM0_voidOVInterruptEnable
 * Purpose : Enable the Timer0 Overflow Interrupt
 *========================================================*/
void TIM0_voidOVInterruptEnable(void)
{
	/* Enable Timer0 Overflow Interrupt: TOIE0 = 1 */
	SET_BIT(TIMSK_REG, TOIE0_BIT);
}


/*========================================================
 * Function: TIM0_voidOVInterruptDisable
 * Purpose : Disable the Timer0 Overflow Interrupt
 *========================================================*/
void TIM0_voidOVInterruptDisable(void)
{
	/* Disable Timer0 Overflow Interrupt: TOIE0 = 0 */
	CLR_BIT(TIMSK_REG, TOIE0_BIT);
}


/*========================================================
 * Function: TIM0_voidSetOVReg
 * Purpose : Set the Timer0 Counter Register (TCNT0)
 *           with a specific value
 *========================================================*/
void TIM0_voidSetOVReg(u8 OVRegValue)
{
	/* Set the Timer0 counter value */
	TCNT0_REG = OVRegValue;
}


/*========================================================
 * Function: TIM0_u8GetOVReg
 * Purpose : Get and return the current Timer0 Counter
 *           Register (TCNT0) value
 *========================================================*/
u8 TIM0_u8GetOVReg(void)
{
	/* Return the current Timer0 counter value */
	return TCNT0_REG;
}


/*========================================================
 * Function: TIM0_voidClearOVFlag
 * Purpose : Clear the Timer0 Overflow Flag
 *========================================================*/
void TIM0_voidClearOVFlag(void)
{
	/*
	 * Clear Timer0 Overflow Flag by writing 1 to TOV0.
	 * Writing 0 to the other flag bits leaves them unchanged.
	 */
	TIFR_REG = (1 << TOV0_BIT);
}


/*========================================================
 * Function: TIM0_voidOVSetCallBack
 * Purpose : Set the callback function to be executed when
 *           the Timer0 Overflow interrupt occurs
 *========================================================*/
void TIM0_voidOVSetCallBack(TIM0_CallBack_pt FunctionAddress)
{
	/* Store Timer0 Overflow callback function address */
	TIM0_OVCallBack = FunctionAddress;
}


/*========================================================
 * TIMER0 OVERFLOW ISR
 *
 * signal : Tell the compiler this function is an ISR
 * used   : Keep the function even though it is not
 *          called normally by the program
 *
 * Timer0 Overflow -> __vector_11
 *========================================================*/

void __vector_11(void) __attribute__((signal, used));

void __vector_11(void)
{
	/* Execute callback only if a function was assigned */
	if (TIM0_OVCallBack != NULL)
	{
		TIM0_OVCallBack();
	}
}


/*==================== CTC MODE / COMPARE MATCH ====================*/


/*========================================================
 * Function: TIM0_voidCTCInterruptEnable
 * Purpose : Enable the Timer0 Compare Match Interrupt
 *========================================================*/
void TIM0_voidCTCInterruptEnable(void)
{
	/* Enable Timer0 Compare Match Interrupt: OCIE0 = 1 */
	SET_BIT(TIMSK_REG, OCIE0_BIT);
}


/*========================================================
 * Function: TIM0_voidCTCInterruptDisable
 * Purpose : Disable the Timer0 Compare Match Interrupt
 *========================================================*/
void TIM0_voidCTCInterruptDisable(void)
{
	/* Disable Timer0 Compare Match Interrupt: OCIE0 = 0 */
	CLR_BIT(TIMSK_REG, OCIE0_BIT);
}


/*========================================================
 * Function: TIM0_voidClearCTCFlag
 * Purpose : Clear the Timer0 Compare Match Flag
 *========================================================*/
void TIM0_voidClearCTCFlag(void)
{
	/*
	 * Clear Timer0 Compare Match Flag by writing 1 to OCF0.
	 * Writing 0 to the other flag bits leaves them unchanged.
	 */
	TIFR_REG = (1 << OCF0_BIT);
}


/*========================================================
 * Function: TIM0_voidSetCTCReg
 * Purpose : Set the Timer0 Output Compare Register (OCR0)
 *           with a specific value
 *========================================================*/
void TIM0_voidSetCTCReg(u8 CTCRegValue)
{
	/* Set the Timer0 compare value */
	OCR0_REG = CTCRegValue;
}


/*========================================================
 * Function: TIM0_u8GetCTCReg
 * Purpose : Get and return the current Timer0 Output
 *           Compare Register (OCR0) value
 *========================================================*/
u8 TIM0_u8GetCTCReg(void)
{
	/* Return the current Timer0 compare value */
	return OCR0_REG;
}


/*========================================================
 * Function: TIM0_voidCTCSetCallBack
 * Purpose : Set the callback function to be executed when
 *           the Timer0 Compare Match interrupt occurs
 *========================================================*/
void TIM0_voidCTCSetCallBack(TIM0_CallBack_pt FunctionAddress)
{
	/* Store Timer0 Compare Match callback function address */
	TIM0_CTCCallBack = FunctionAddress;
}


/*========================================================
 * TIMER0 COMPARE MATCH ISR
 *
 * signal : Tell the compiler this function is an ISR
 * used   : Keep the function even though it is not
 *          called normally by the program
 *
 * Timer0 Compare Match -> __vector_10
 *========================================================*/

void __vector_10(void) __attribute__((signal, used));

void __vector_10(void)
{
	/* Execute callback only if a function was assigned */
	if (TIM0_CTCCallBack != NULL)
	{
		TIM0_CTCCallBack();
	}
}

