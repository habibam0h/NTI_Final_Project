
#ifndef SERVO_INT_H
#define SERVO_INT_H


/*==================== DOOR ANGLES ====================*/

/* Servo Angle for Closed Elevator Door */
#define DOOR_CLOSED_ANGLE      0

/* Servo Angle for Open Elevator Door */
#define DOOR_OPEN_ANGLE        90


/*==================== FUNCTION PROTOTYPES ====================*/

/*
 * Function: SERVO_voidInitialization
 * Purpose : Initialize the Servo Motor
 */
void SERVO_voidInitialization(void);


/*
 * Function: SERVO_voidSetAngle
 * Purpose : Set the Servo Motor to a specific angle
 */
void SERVO_voidSetAngle(u8 Angle);


#endif /* SERVO_INT_H */
