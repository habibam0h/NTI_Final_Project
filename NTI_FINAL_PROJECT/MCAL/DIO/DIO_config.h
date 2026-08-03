#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_


/*==================== PORT A CONFIGURATION ====================*/

/* Configure the direction of each pin in Port A */
#define DIO_PORTA_PIN0_DIR DIO_INPUT
#define DIO_PORTA_PIN1_DIR DIO_OUTPUT
#define DIO_PORTA_PIN2_DIR DIO_OUTPUT
#define DIO_PORTA_PIN3_DIR DIO_OUTPUT
#define DIO_PORTA_PIN4_DIR DIO_OUTPUT
#define DIO_PORTA_PIN5_DIR DIO_OUTPUT
#define DIO_PORTA_PIN6_DIR DIO_OUTPUT
#define DIO_PORTA_PIN7_DIR DIO_OUTPUT


/*==================== PORT B CONFIGURATION ====================*/

/* Configure the direction of each pin in Port B */
#define DIO_PORTB_PIN0_DIR DIO_OUTPUT
#define DIO_PORTB_PIN1_DIR DIO_OUTPUT
#define DIO_PORTB_PIN2_DIR DIO_OUTPUT
#define DIO_PORTB_PIN3_DIR DIO_OUTPUT
#define DIO_PORTB_PIN4_DIR DIO_OUTPUT
#define DIO_PORTB_PIN5_DIR DIO_OUTPUT
#define DIO_PORTB_PIN6_DIR DIO_OUTPUT
#define DIO_PORTB_PIN7_DIR DIO_OUTPUT


/*==================== PORT C CONFIGURATION ====================*/

/* Configure the direction of each pin in Port C */
#define DIO_PORTC_PIN0_DIR DIO_OUTPUT
#define DIO_PORTC_PIN1_DIR DIO_OUTPUT
#define DIO_PORTC_PIN2_DIR DIO_OUTPUT
#define DIO_PORTC_PIN3_DIR DIO_OUTPUT
#define DIO_PORTC_PIN4_DIR DIO_INPUT
#define DIO_PORTC_PIN5_DIR DIO_INPUT
#define DIO_PORTC_PIN6_DIR DIO_INPUT
#define DIO_PORTC_PIN7_DIR DIO_INPUT


/*==================== PORT D CONFIGURATION ====================*/

/* Configure the direction of each pin in Port D */
#define DIO_PORTD_PIN0_DIR DIO_INPUT
#define DIO_PORTD_PIN1_DIR DIO_INPUT
#define DIO_PORTD_PIN2_DIR DIO_INPUT
#define DIO_PORTD_PIN3_DIR DIO_INPUT
#define DIO_PORTD_PIN4_DIR DIO_INPUT
#define DIO_PORTD_PIN5_DIR DIO_INPUT
#define DIO_PORTD_PIN6_DIR DIO_INPUT
#define DIO_PORTD_PIN7_DIR DIO_INPUT


/*==================== PORT DIRECTION CONFIGURATION ====================*/

/*
 * Combine the individual Port A pin directions into one
 * 8-bit value used to configure the Port A direction register
 */
#define DIO_PORTA_DIRECTIONS  CONC_BIT( \
    DIO_PORTA_PIN7_DIR, \
    DIO_PORTA_PIN6_DIR, \
    DIO_PORTA_PIN5_DIR, \
    DIO_PORTA_PIN4_DIR, \
    DIO_PORTA_PIN3_DIR, \
    DIO_PORTA_PIN2_DIR, \
    DIO_PORTA_PIN1_DIR, \
    DIO_PORTA_PIN0_DIR)

/*
 * Combine the individual Port B pin directions into one
 * 8-bit value used to configure the Port B direction register
 */
#define DIO_PORTB_DIRECTIONS  CONC_BIT( \
    DIO_PORTB_PIN7_DIR, \
    DIO_PORTB_PIN6_DIR, \
    DIO_PORTB_PIN5_DIR, \
    DIO_PORTB_PIN4_DIR, \
    DIO_PORTB_PIN3_DIR, \
    DIO_PORTB_PIN2_DIR, \
    DIO_PORTB_PIN1_DIR, \
    DIO_PORTB_PIN0_DIR)

/*
 * Combine the individual Port C pin directions into one
 * 8-bit value used to configure the Port C direction register
 */
#define DIO_PORTC_DIRECTIONS  CONC_BIT( \
    DIO_PORTC_PIN7_DIR, \
    DIO_PORTC_PIN6_DIR, \
    DIO_PORTC_PIN5_DIR, \
    DIO_PORTC_PIN4_DIR, \
    DIO_PORTC_PIN3_DIR, \
    DIO_PORTC_PIN2_DIR, \
    DIO_PORTC_PIN1_DIR, \
    DIO_PORTC_PIN0_DIR)

/*
 * Combine the individual Port D pin directions into one
 * 8-bit value used to configure the Port D direction register
 */
#define DIO_PORTD_DIRECTIONS  CONC_BIT( \
    DIO_PORTD_PIN7_DIR, \
    DIO_PORTD_PIN6_DIR, \
    DIO_PORTD_PIN5_DIR, \
    DIO_PORTD_PIN4_DIR, \
    DIO_PORTD_PIN3_DIR, \
    DIO_PORTD_PIN2_DIR, \
    DIO_PORTD_PIN1_DIR, \
    DIO_PORTD_PIN0_DIR)


#endif
