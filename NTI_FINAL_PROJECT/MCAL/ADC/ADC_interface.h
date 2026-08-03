#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


/*==================== CALLBACK TYPE ====================*/

/* Pointer to a function that takes no parameters and returns void */
typedef void (*ADC_CallBack_pt)(void);


/*==================== RESULT ADJUSTMENT ====================*/

/* ADC Result Adjustment Options */
#define ADC_RIGHT_ADJUSTMENT     0
#define ADC_LEFT_ADJUSTMENT      1


/*==================== AUTO TRIGGER SOURCES ====================*/

/* ADC Auto Trigger Source Options */
#define ADC_FREE_RUNNING              0
#define ADC_ANALOG_COMPARATOR         1
#define ADC_EXTERNAL_INTERRUPT_0      2
#define ADC_TIMER0_COMPARE_MATCH      3
#define ADC_TIMER0_OVERFLOW           4
#define ADC_TIMER1_COMPARE_MATCH_B    5
#define ADC_TIMER1_OVERFLOW           6
#define ADC_TIMER1_CAPTURE_EVENT      7


/*==================== ADC CHANNELS ====================*/

/* ADC Single-Ended Input Channels */
#define ADC0_CHANNEL        0
#define ADC1_CHANNEL        1
#define ADC2_CHANNEL        2
#define ADC3_CHANNEL        3
#define ADC4_CHANNEL        4
#define ADC5_CHANNEL        5
#define ADC6_CHANNEL        6
#define ADC7_CHANNEL        7

/*==================== ADC PRESCALER ====================*/

/* ADC Clock Prescaler Options */
#define ADC_PRESCALER_2       0
#define ADC_PRESCALER_4       2
#define ADC_PRESCALER_8       3
#define ADC_PRESCALER_16      4
#define ADC_PRESCALER_32      5
#define ADC_PRESCALER_64      6
#define ADC_PRESCALER_128     7


/*==================== ADC REFERENCE VOLTAGE ====================*/

/* ADC Reference Voltage Options */
#define ADC_AREF                0
#define ADC_AVCC                1
#define ADC_INTERNAL_2_56V      3


/*==================== FUNCTION PROTOTYPES ====================*/


/*
 * Function: ADC_voidInitialization
 * Purpose : Initialize the ADC peripheral with the
 *           configured settings
 */
void ADC_voidInitialization(void);


/*
 * Function: ADC_voidADCEnable
 * Purpose : Enable the ADC peripheral
 */
void ADC_voidADCEnable(void);


/*
 * Function: ADC_voidADCDisable
 * Purpose : Disable the ADC peripheral
 */
void ADC_voidADCDisable(void);


/*
 * Function: ADC_voidStartConversion
 * Purpose : Start a new ADC conversion
 */
void ADC_voidStartConversion(void);


/*
 * Function: ADC_voidInterruptEnable
 * Purpose : Enable the ADC conversion complete interrupt
 */
void ADC_voidInterruptEnable(void);


/*
 * Function: ADC_voidInterruptDisable
 * Purpose : Disable the ADC conversion complete interrupt
 */
void ADC_voidInterruptDisable(void);


/*
 * Function: ADC_u16Read
 * Purpose : Read and return the ADC conversion result
 */
u16 ADC_u16Read(void);


/*
 * Function: ADC_voidSetCallBack
 * Purpose : Set the callback function to be executed when
 *           the ADC conversion complete interrupt occurs
 */
void ADC_voidSetCallBack(ADC_CallBack_pt FunctionAddress);


/*
 * Function: ADC_voidAutoTrigger
 * Purpose : Enable ADC Auto Trigger and select the
 *           Auto Trigger source
 */
void ADC_voidAutoTrigger(u8 TriggerSource);


/*
 * Function: ADC_voidAutoTriggerDisable
 * Purpose : Disable ADC Auto Trigger
 */
void ADC_voidAutoTriggerDisable(void);


/*
 * Function: ADC_voidSelectChannel
 * Purpose : Select the ADC input channel
 */
void ADC_voidSelectChannel(u8 Channel);


/*
 * Function: ADC_voidSetPrescaler
 * Purpose : Set the ADC Clock Prescaler
 */
void ADC_voidSetPrescaler(u8 Prescaler);


/*
 * Function: ADC_voidSetReference
 * Purpose : Set the ADC Reference Voltage
 */
void ADC_voidSetReference(u8 Reference);


/*
 * Function: ADC_voidSetAdjustment
 * Purpose : Set the ADC result adjustment to Left or Right
 */
void ADC_voidSetAdjustment(u8 Adjustment);


/*
 * Function: ADC_voidClearInterruptFlag
 * Purpose : Clear the ADC conversion complete interrupt flag
 */
void ADC_voidClearInterruptFlag(void);


/*
 * Function: ADC_voidWaitForConversion
 * Purpose : Wait until the current ADC conversion is complete
 */
void ADC_voidWaitForConversion(void);


#endif
