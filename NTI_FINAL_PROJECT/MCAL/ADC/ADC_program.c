#include "Std_Types.h"
#include "Bit_Math.h"

#include "ADC_config.h"
#include "ADC_private.h"
#include "ADC_interface.h"


/*==================== CALLBACK POINTER ====================*/

/* Store the callback function address for the ADC interrupt */
static ADC_CallBack_pt ADC_CallBack = NULL;


/*========================================================
 * Function: ADC_voidInitialization
 * Purpose : Initialize the ADC peripheral with the
 *           configured settings
 *========================================================*/
void ADC_voidInitialization(void)
{
	/* Start with the ADC disabled */
	ADC_voidADCDisable();

	/* Start with Auto Trigger disabled */
	ADC_voidAutoTriggerDisable();

	/* Start with the ADC interrupt disabled */
	ADC_voidInterruptDisable();

	/* Set the configured ADC result adjustment */
	ADC_voidSetAdjustment(REG_ADJ);

	/* Select the configured initial ADC channel */
	ADC_voidSelectChannel(ADC_CHANNEL);

	/* Set the configured ADC clock prescaler */
	ADC_voidSetPrescaler(ADC_PRESCALER);

	/* Set the configured ADC reference voltage */
	ADC_voidSetReference(ADC_REFERENCE);

	/* Clear any pending ADC conversion complete flag */
	ADC_voidClearInterruptFlag();
}


/*========================================================
 * Function: ADC_voidADCEnable
 * Purpose : Enable the ADC peripheral
 *========================================================*/
void ADC_voidADCEnable(void)
{
	/* Enable ADC: ADEN = 1 */
	SET_BIT(ADCSRA_REG, ADEN_BIT);
}


/*========================================================
 * Function: ADC_voidADCDisable
 * Purpose : Disable the ADC peripheral
 *========================================================*/
void ADC_voidADCDisable(void)
{
	/* Disable ADC: ADEN = 0 */
	CLR_BIT(ADCSRA_REG, ADEN_BIT);
}


/*========================================================
 * Function: ADC_voidStartConversion
 * Purpose : Start a new ADC conversion
 *========================================================*/
void ADC_voidStartConversion(void)
{
	/* Start ADC conversion: ADSC = 1 */
	SET_BIT(ADCSRA_REG, ADSC_BIT);
}


/*========================================================
 * Function: ADC_voidInterruptEnable
 * Purpose : Enable the ADC conversion complete interrupt
 *========================================================*/
void ADC_voidInterruptEnable(void)
{
	/* Enable ADC interrupt: ADIE = 1 */
	SET_BIT(ADCSRA_REG, ADIE_BIT);
}


/*========================================================
 * Function: ADC_voidInterruptDisable
 * Purpose : Disable the ADC conversion complete interrupt
 *========================================================*/
void ADC_voidInterruptDisable(void)
{
	/* Disable ADC interrupt: ADIE = 0 */
	CLR_BIT(ADCSRA_REG, ADIE_BIT);
}


/*========================================================
 * Function: ADC_u16Read
 * Purpose : Read and return the ADC conversion result
 *           according to the configured adjustment
 *========================================================*/
u16 ADC_u16Read(void)
{
	#if REG_ADJ == ADC_LEFT_ADJUSTMENT

		/* Left adjusted: read the upper 8 bits from ADCH */
		return (u16)ADCH_REG;

	#elif REG_ADJ == ADC_RIGHT_ADJUSTMENT

		/*
		 * Read ADCL first to lock the ADC data registers,
		 * then read ADCH to release the lock.
		 */
		u8 LowReg = ADCL_REG;
		u8 HighReg = ADCH_REG;

		/* Combine the high and low bytes to form the 10-bit result */
		return ((u16)HighReg << 8) | LowReg;

	#endif
}


/*========================================================
 * Function: ADC_voidSetCallBack
 * Purpose : Set the callback function to be executed when
 *           the ADC conversion complete interrupt occurs
 *========================================================*/
void ADC_voidSetCallBack(ADC_CallBack_pt FunctionAddress)
{
	/* Store ADC callback function address */
	ADC_CallBack = FunctionAddress;
}


/*========================================================
 * ADC CONVERSION COMPLETE ISR
 *
 * signal : Tell the compiler this function is an ISR
 * used   : Keep the function even though it is not
 *          called normally by the program
 *
 * ADC Conversion Complete -> __vector_16
 *========================================================*/

void __vector_16(void) __attribute__((signal, used));

void __vector_16(void)
{
	/* Execute callback only if a function was assigned */
	if (ADC_CallBack != NULL)
	{
		ADC_CallBack();
	}
}

/*========================================================
 * Function: ADC_voidAutoTrigger
 * Purpose : Enable ADC Auto Trigger and select the
 *           Auto Trigger source
 *========================================================*/
void ADC_voidAutoTrigger(u8 TriggerSource)
{
	/* Enable ADC Auto Trigger: ADATE = 1 */
	SET_BIT(ADCSRA_REG, ADATE_BIT);

	/* Clear the old Auto Trigger source bits ADTS2:ADTS0 */
	SFIOR_REG &= 0x1F;

	/* Set the new Auto Trigger source */
	SFIOR_REG |= ((TriggerSource & 0x07) << ADTS0_BIT);
}


/*========================================================
 * Function: ADC_voidAutoTriggerDisable
 * Purpose : Disable ADC Auto Trigger
 *========================================================*/
void ADC_voidAutoTriggerDisable(void)
{
	/* Disable ADC Auto Trigger: ADATE = 0 */
	CLR_BIT(ADCSRA_REG, ADATE_BIT);
}


/*========================================================
 * Function: ADC_voidSelectChannel
 * Purpose : Select the ADC input channel
 *========================================================*/
void ADC_voidSelectChannel(u8 Channel)
{
	/* Clear the old channel selection bits MUX4:MUX0 */
	ADMUX_REG &= 0xE0;

	/* Set the new channel without affecting the upper ADMUX bits */
	ADMUX_REG |= (Channel & 0x1F);
}


/*========================================================
 * Function: ADC_voidSetPrescaler
 * Purpose : Set the ADC Clock Prescaler
 *========================================================*/
void ADC_voidSetPrescaler(u8 Prescaler)
{
	/* Clear the old ADC Prescaler bits ADPS2:ADPS0 */
	ADCSRA_REG &= 0xF8;

	/* Set the new Prescaler without affecting the upper ADCSRA bits */
	ADCSRA_REG |= (Prescaler & 0x07);
}


/*========================================================
 * Function: ADC_voidSetReference
 * Purpose : Set the ADC Reference Voltage
 *========================================================*/
void ADC_voidSetReference(u8 Reference)
{
	/* Clear the old Reference Selection bits REFS1:REFS0 */
	ADMUX_REG &= 0x3F;

	/* Set the new Reference without affecting the lower ADMUX bits */
	ADMUX_REG |= ((Reference & 0x03) << REFS0_BIT);
}


/*========================================================
 * Function: ADC_voidSetAdjustment
 * Purpose : Set the ADC result adjustment to Left or Right
 *========================================================*/
void ADC_voidSetAdjustment(u8 Adjustment)
{
	if (Adjustment == ADC_LEFT_ADJUSTMENT)
	{
		/* Select Left Adjustment: ADLAR = 1 */
		SET_BIT(ADMUX_REG, ADLAR_BIT);
	}
	else if (Adjustment == ADC_RIGHT_ADJUSTMENT)
	{
		/* Select Right Adjustment: ADLAR = 0 */
		CLR_BIT(ADMUX_REG, ADLAR_BIT);
	}
}


/*========================================================
 * Function: ADC_voidClearInterruptFlag
 * Purpose : Clear the ADC conversion complete interrupt flag
 *========================================================*/
void ADC_voidClearInterruptFlag(void)
{
	/*
	 * Clear ADC Interrupt Flag.
	 * ADIF is cleared by writing 1 to it.
	 */
	SET_BIT(ADCSRA_REG, ADIF_BIT);
}

/*========================================================
 * Function: ADC_voidWaitForConversion
 * Purpose : Wait until the current ADC conversion is complete
 *========================================================*/
void ADC_voidWaitForConversion(void)
{
	/* Wait while the ADC conversion is not complete */
	while(GET_BIT(ADCSRA_REG, ADIF_BIT) == 0);
}


