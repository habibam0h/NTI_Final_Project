#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


/*==================== KEYPAD SIZE ====================*/

/* Number of rows in the keypad */
#define KEYPAD_ROWS_NUM    4

/* Number of columns in the keypad */
#define KEYPAD_COLS_NUM    3


/*==================== KEYPAD COLUMN PINS ====================*/

/* Keypad Column Connections */
#define KEYPAD_COL0    DIO_PORTC, DIO_PIN0
#define KEYPAD_COL1    DIO_PORTC, DIO_PIN1
#define KEYPAD_COL2    DIO_PORTC, DIO_PIN2


/*==================== KEYPAD ROW PINS ====================*/

/* Keypad Row Connections */
#define KEYPAD_ROW0    DIO_PORTC, DIO_PIN3
#define KEYPAD_ROW1    DIO_PORTC, DIO_PIN4
#define KEYPAD_ROW2    DIO_PORTC, DIO_PIN5
#define KEYPAD_ROW3    DIO_PORTC, DIO_PIN6


#endif
