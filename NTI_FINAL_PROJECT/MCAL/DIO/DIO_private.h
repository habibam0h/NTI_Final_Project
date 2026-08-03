
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


/*==================== PORT A REGISTERS ====================*/

/* Port A Data Direction Register */
#define DDRA_REG   *((volatile u8 *)0x3A)

/* Port A Data Register */
#define PORTA_REG  *((volatile u8 *)0x3B)

/* Port A Input Pins Register */
#define PINA_REG   *((volatile u8 *)0x39)


/*==================== PORT B REGISTERS ====================*/

/* Port B Data Direction Register */
#define DDRB_REG   *((volatile u8 *)0x37)

/* Port B Data Register */
#define PORTB_REG  *((volatile u8 *)0x38)

/* Port B Input Pins Register */
#define PINB_REG   *((volatile u8 *)0x36)


/*==================== PORT C REGISTERS ====================*/

/* Port C Data Direction Register */
#define DDRC_REG   *((volatile u8 *)0x34)

/* Port C Data Register */
#define PORTC_REG  *((volatile u8 *)0x35)

/* Port C Input Pins Register */
#define PINC_REG   *((volatile u8 *)0x33)


/*==================== PORT D REGISTERS ====================*/

/* Port D Data Direction Register */
#define DDRD_REG   *((volatile u8 *)0x31)

/* Port D Data Register */
#define PORTD_REG  *((volatile u8 *)0x32)

/* Port D Input Pins Register */
#define PIND_REG   *((volatile u8 *)0x30)


#endif
