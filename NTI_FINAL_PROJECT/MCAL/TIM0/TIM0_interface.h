
#ifndef TIM0_INTERFACE_H_
#define TIM0_INTERFACE_H_


/*==================== CALLBACK TYPE ====================*/

/* Pointer to a function that takes no parameters and returns void */
typedef void (*TIM0_CallBack_pt)(void);


/*==================== TIMER0 PRESCALER ====================*/

/* Timer0 Clock Prescaler Options */
#define TIM0_NO_CLOCK          0
#define TIM0_NO_PRESCALER      1
#define TIM0_PRESCALER_8       2
#define TIM0_PRESCALER_64      3
#define TIM0_PRESCALER_256     4
#define TIM0_PRESCALER_1024    5

/*==================== TIMER0 MODES ====================*/

/* Timer0 Operating Modes */
#define TIM0_NORMAL_MODE             0
#define TIM0_PHASE_CORRECT_PWM_MODE  1
#define TIM0_CTC_MODE                2
#define TIM0_FAST_PWM_MODE           3


/*==================== COMPARE OUTPUT MODES ====================*/

/* Timer0 Non-PWM Compare Match Output Options */
#define TIM0_OC0_DISCONNECTED       0
#define TIM0_OC0_TOGGLE             1
#define TIM0_OC0_CLEAR              2
#define TIM0_OC0_SET                3


/* Timer0 PWM Compare Output Options */
#define TIM0_PWM_OC0_DISCONNECTED   0
#define TIM0_PWM_NON_INVERTING      2
#define TIM0_PWM_INVERTING          3


/*==================== FUNCTION PROTOTYPES ====================*/

/*
 * Function: TIM0_voidInitialization
 * Purpose : Initialize Timer0 peripheral with the
 *           configured settings
 */
void TIM0_voidInitialization(void);


/*
 * Function: TIM0_voidSetPrescaler
 * Purpose : Set the Timer0 Clock Prescaler
 */
void TIM0_voidSetPrescaler(u8 Prescaler);


/*
 * Function: TIM0_voidSetMode
 * Purpose : Set the Timer0 Operating Mode
 */
void TIM0_voidSetMode(u8 Mode);


/*
 * Function: TIM0_voidSetCompareOutputMode
 * Purpose : Set the Timer0 Compare Match Output Mode
 */
void TIM0_voidSetCompareOutputMode(u8 CompareOutputMode);


/*
 * Function: TIM0_voidOVInterruptEnable
 * Purpose : Enable the Timer0 Overflow Interrupt
 */
void TIM0_voidOVInterruptEnable(void);


/*
 * Function: TIM0_voidOVInterruptDisable
 * Purpose : Disable the Timer0 Overflow Interrupt
 */
void TIM0_voidOVInterruptDisable(void);


/*
 * Function: TIM0_voidClearOVFlag
 * Purpose : Clear the Timer0 Overflow Flag
 */
void TIM0_voidClearOVFlag(void);


/*
 * Function: TIM0_voidSetOVReg
 * Purpose : Set the Timer0 Counter Register (TCNT0)
 *           with a specific value
 */
void TIM0_voidSetOVReg(u8 OVRegValue);


/*
 * Function: TIM0_u8GetOVReg
 * Purpose : Get and return the current Timer0 Counter
 *           Register (TCNT0) value
 */
u8 TIM0_u8GetOVReg(void);


/*
 * Function: TIM0_voidOVSetCallBack
 * Purpose : Set the callback function to be executed when
 *           the Timer0 Overflow interrupt occurs
 */
void TIM0_voidOVSetCallBack(TIM0_CallBack_pt FunctionAddress);


/*
 * Function: TIM0_voidCTCInterruptEnable
 * Purpose : Enable the Timer0 Compare Match Interrupt
 */
void TIM0_voidCTCInterruptEnable(void);


/*
 * Function: TIM0_voidCTCInterruptDisable
 * Purpose : Disable the Timer0 Compare Match Interrupt
 */
void TIM0_voidCTCInterruptDisable(void);


/*
 * Function: TIM0_voidClearCTCFlag
 * Purpose : Clear the Timer0 Compare Match Flag
 */
void TIM0_voidClearCTCFlag(void);


/*
 * Function: TIM0_voidCTCSetCallBack
 * Purpose : Set the callback function to be executed when
 *           the Timer0 Compare Match interrupt occurs
 */
void TIM0_voidCTCSetCallBack(TIM0_CallBack_pt FunctionAddress);


/*
 * Function: TIM0_voidSetCompareReg
 * Purpose : Set the Timer0 Output Compare Register (OCR0)
 *           with a specific value
 */
void TIM0_voidSetCompareReg(u8 CompareRegValue);


/*
 * Function: TIM0_u8GetCompareReg
 * Purpose : Get and return the current Timer0 Output
 *           Compare Register (OCR0) value
 */
u8 TIM0_u8GetCompareReg(void);


/*
 * Function: TIM0_voidSetPWMDutyCycle
 * Purpose : Set the Timer0 PWM Duty Cycle according to
 *           the configured PWM mode and output mode
 */
void TIM0_voidSetPWMDutyCycle(u8 DutyCycle);
#endif
