
#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


/*==================== FUNCTION PROTOTYPES ====================*/


/*
 * Function: LCD_voidInitialization
 * Purpose : Initialize the LCD
 */
void LCD_voidInitialization(void);


/*
 * Function: LCD_voidSendCommand
 * Purpose : Send a command to the LCD
 */
void LCD_voidSendCommand(u8 Command);


/*
 * Function: LCD_voidSendData
 * Purpose : Send data to be displayed on the LCD
 */
void LCD_voidSendData(u8 Data);


/*
 * Function: LCD_voidGoToXY
 * Purpose : Move the LCD cursor to the specified position
 */
void LCD_voidGoToXY(u8 X, u8 Y);


/*
 * Function: LCD_voidWriteString
 * Purpose : Display a string on the LCD
 */
void LCD_voidWriteString(u8* String);


/*
 * Function: LCD_voidWriteNumber
 * Purpose : Display a number on the LCD
 */
void LCD_voidWriteNumber(u64 Number);


/*
 * Function: LCD_voidClear
 * Purpose : Clear the LCD display
 */
void LCD_voidClear(void);


#endif
