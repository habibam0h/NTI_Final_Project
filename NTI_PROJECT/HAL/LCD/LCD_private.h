
#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_


/*==================== NUMBER LIMIT ====================*/

/* Maximum number that can be displayed using 16 digits */
#define MAX_16_DIGITS    9999999999999999ULL


/*==================== LCD COMMANDS ====================*/

/* Clear the LCD display */
#define LCD_CLEAR               0x01

/* Return the cursor to the home position */
#define LCD_HOME                0x02

/* Set entry mode */
#define LCD_ENTRY_MODE          0x06

/* Turn the LCD display off */
#define LCD_DISPLAY_OFF         0x08

/* Turn the LCD display on */
#define LCD_DISPLAY_ON          0x0C

/* Reset the LCD function configuration */
#define LCD_FUNCTION_RESET      0x30

/* Configure the LCD for 8-bit mode */
#define LCD_FUNCTION_SET_8BIT   0x38

/* Move the cursor to the beginning of the first line */
#define LCD_FIRST_LINE          0x80

/* Move the cursor to the beginning of the second line */
#define LCD_SECOND_LINE         0xC0


/*==================== PRIVATE FUNCTION PROTOTYPES ====================*/


/*
 * Function: LCD_voidWriteBus
 * Purpose : Send an 8-bit value to the LCD data bus
 */
static void LCD_voidWriteBus(u8 Value);


#endif
