
#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_


/*==================== FUNCTION PROTOTYPES ====================*/


/*
 * Function: DCMOTOR_voidInitialization
 * Purpose : Initialize the DC Motor control pins and
 *           start the Motor in the STOP state
 */
void DCMOTOR_voidInitialization(void);


/*
 * Function: DCMOTOR_voidMoveUp
 * Purpose : Move the Elevator cabin UP
 */
void DCMOTOR_voidMoveUp(void);


/*
 * Function: DCMOTOR_voidMoveDown
 * Purpose : Move the Elevator cabin DOWN
 */
void DCMOTOR_voidMoveDown(void);


/*
 * Function: DCMOTOR_voidStop
 * Purpose : Stop the DC Motor and the Elevator cabin
 */
void DCMOTOR_voidStop(void);


#endif
