#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


/*==================== RESULT ADJUSTMENT ====================*/

/* Select ADC Result Adjustment */
#define REG_ADJ    ADC_RIGHT_ADJUSTMENT


/*==================== AUTO TRIGGER ====================*/

/* Select ADC Auto Trigger Source */
#define TRIGGER_SELECT    ADC_FREE_RUNNING


/*==================== ADC CHANNEL ====================*/

/* Select Initial ADC Input Channel */
#define ADC_CHANNEL    ADC0_CHANNEL


/*==================== ADC PRESCALER ====================*/

/* Select ADC Clock Prescaler */
#define ADC_PRESCALER    ADC_PRESCALER_64


/*==================== ADC REFERENCE VOLTAGE ====================*/

/* Select ADC Reference Voltage */
#define ADC_REFERENCE    ADC_AVCC


#endif
