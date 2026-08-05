
#ifndef SERVO_CONFIG_H
#define SERVO_CONFIG_H


/*==================== SERVO PIN ====================*/

#define SERVO                  DIO_PORTA, DIO_PIN0


/*==================== SERVO ANGLE ====================*/

/* Servo Maximum Angle */
#define SERVO_MAX_ANGLE        180


/*==================== SERVO PULSE ====================*/

/*
 * Timer0 Interrupt = 100 us
 *
 * 10 Counts = 1.0 ms
 * 20 Counts = 2.0 ms
 */

/* Servo Minimum Pulse Count */
#define SERVO_MIN_COUNT        10

/* Servo Maximum Pulse Count */
#define SERVO_MAX_COUNT        20


/*==================== SERVO FRAME ====================*/

/*
 * 200 Counts * 100 us = 20 ms
 */

/* Servo Complete Frame Count */
#define SERVO_FRAME_COUNTS     200


#endif
