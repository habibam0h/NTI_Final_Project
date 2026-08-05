
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


/*==================== LCD CONTROL PINS ====================*/

/* LCD Register Select Pin */
#define LCD_RS    DIO_PORTB, DIO_PIN2

/* LCD Read/Write Pin */
#define LCD_RW    DIO_PORTB, DIO_PIN1

/* LCD Enable Pin */
#define LCD_EN    DIO_PORTB, DIO_PIN0


/*==================== LCD DATA PINS ====================*/

/* LCD 8-bit Data Pins */
#define LCD_D0    DIO_PORTA, DIO_PIN7
#define LCD_D1    DIO_PORTA, DIO_PIN6
#define LCD_D2    DIO_PORTA, DIO_PIN5
#define LCD_D3    DIO_PORTA, DIO_PIN4
#define LCD_D4    DIO_PORTA, DIO_PIN3
#define LCD_D5    DIO_PORTA, DIO_PIN2
#define LCD_D6    DIO_PORTA, DIO_PIN1
#define LCD_D7    DIO_PORTA, DIO_PIN0


#endif
