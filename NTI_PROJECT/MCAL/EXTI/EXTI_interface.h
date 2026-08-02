
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*==================== CALLBACK TYPE ====================*/

/* Pointer to a function that takes no parameters and returns void */
typedef void (*EXTI_CallBack_pt)(void);


/*==================== INTERRUPT NUMBERS ====================*/

/* External Interrupt Channels */
#define EXTI_INT0              0
#define EXTI_INT1              1
#define EXTI_INT2              2


/*==================== SENSE MODES ====================*/

/* INT0 & INT1 Sense Modes */
#define EXTI_LOW_LEVEL         0
#define EXTI_ANY_CHANGE        1
#define EXTI_FALLING_EDGE      2
#define EXTI_RISING_EDGE       3

/* Note: INT2 supports Falling Edge and Rising Edge only */


/*==================== FUNCTION PROTOTYPES ====================*/


/*
 * Function: EXTI_voidInitialization
 * Purpose : Initialise INT0, INT1, and INT2 with their
 *           configured sense modes, disable them initially,
 *           and clear any pending interrupt flags
 */
void EXTI_voidInitialization(void);



/*
 * Function: EXTI_voidSetSenseMode
 * Purpose : Set the trigger mode for INT0, INT1, or INT2
 */
void EXTI_voidSetSenseMode(u8 InterruptNumber, u8 SenseMode);


/*
 * Function: EXTI_voidInterruptEnable
 * Purpose : Enable INT0, INT1, or INT2 individually
 */
void EXTI_voidInterruptEnable(u8 InterruptNumber);


/*
 * Function: EXTI_voidInterruptDisable
 * Purpose : Disable INT0, INT1, or INT2 individually
 */
void EXTI_voidInterruptDisable(u8 InterruptNumber);


/*
 * Function: EXTI_voidSetCallBack
 * Purpose : Set the callback function to be executed when
 *           INT0, INT1, or INT2 interrupt occurs
 */
void EXTI_voidSetCallBack(u8 InterruptNumber, EXTI_CallBack_pt FunctionAddress);


#endif
