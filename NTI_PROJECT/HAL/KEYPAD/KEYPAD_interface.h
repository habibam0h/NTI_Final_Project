
#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_


/*==================== FUNCTION PROTOTYPES ====================*/


/*
 * Function: KEYPAD_voidInitialization
 * Purpose : Initialize the keypad
 */
void KEYPAD_voidInitialization(void);


/*
 * Function: KEYPAD_u8GetPressedKey
 * Purpose : Scan the keypad and return the pressed key
 */
u8 KEYPAD_u8GetPressedKey(void);


#endif
