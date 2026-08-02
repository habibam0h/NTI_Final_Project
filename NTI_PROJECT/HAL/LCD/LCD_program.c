
#define F_CPU 8000000UL
#include <util/delay.h>

#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"


/*========================================================
 * Function: LCD_voidInitialization
 * Purpose : Initialize the LCD in 8-bit mode
 *========================================================*/
void LCD_voidInitialization(void)
{
	/* Wait for the LCD to power up */
	_delay_ms(35);

	/* Return the cursor to the home position */
	LCD_voidSendCommand(LCD_HOME);
	_delay_ms(1);

	/* Configure the LCD in 8-bit mode */
	LCD_voidSendCommand(LCD_FUNCTION_SET_8BIT);
	_delay_ms(1);

	/* Turn the LCD display on */
	LCD_voidSendCommand(LCD_DISPLAY_ON);
	_delay_ms(1);

	/* Clear the LCD display */
	LCD_voidSendCommand(LCD_CLEAR);
	_delay_ms(2);

	/* Configure the LCD entry mode */
	LCD_voidSendCommand(LCD_ENTRY_MODE);
	_delay_ms(1);
}


/*========================================================
 * Function: LCD_voidSendCommand
 * Purpose : Send a command to the LCD
 *========================================================*/
void LCD_voidSendCommand(u8 Command)
{
	/* Select the instruction register: RS = 0 */
	DIO_voidSetPinValue(LCD_RS, DIO_LOW);

	/* Select write operation: RW = 0 */
	DIO_voidSetPinValue(LCD_RW, DIO_LOW);

	/* Send the command to the LCD data bus */
	LCD_voidWriteBus(Command);
}


/*========================================================
 * Function: LCD_voidSendData
 * Purpose : Send data to be displayed on the LCD
 *========================================================*/
void LCD_voidSendData(u8 Data)
{
	/* Select the data register: RS = 1 */
	DIO_voidSetPinValue(LCD_RS, DIO_HIGH);

	/* Select write operation: RW = 0 */
	DIO_voidSetPinValue(LCD_RW, DIO_LOW);

	/* Send the data to the LCD data bus */
	LCD_voidWriteBus(Data);
}


/*========================================================
 * Function: LCD_voidWriteString
 * Purpose : Display a string on the LCD
 *========================================================*/
void LCD_voidWriteString(u8* String)
{
	/* Send characters one by one until the null terminator */
	while(*String != '\0')
	{
		LCD_voidSendData(*String);
		String++;
	}
}


/*========================================================
 * Function: LCD_voidWriteNumber
 * Purpose : Display an unsigned number on the LCD
 *========================================================*/
void LCD_voidWriteNumber(u64 Number)
{
	if(Number <= MAX_16_DIGITS)
	{
		u8 Local_u8Digits[16];
		u8 Local_u8Count = 0;

		/* Handle zero separately */
		if(Number == 0)
		{
			LCD_voidSendData('0');
		}
		else
		{
			/* Store the digits in reverse order */
			while(Number != 0)
			{
				Local_u8Digits[Local_u8Count] = Number % 10;
				Number /= 10;
				Local_u8Count++;
			}

			/* Display the digits in the correct order */
			for(s8 Local_s8Iterator = Local_u8Count - 1;
					Local_s8Iterator >= 0;
					Local_s8Iterator--)
			{
				LCD_voidSendData(Local_u8Digits[Local_s8Iterator] + '0');
			}
		}
	}
	else
	{
		/* Number exceeds the supported 16-digit limit */
	}
}


/*========================================================
 * Function: LCD_voidGoToXY
 * Purpose : Move the LCD cursor to the specified position
 *========================================================*/
void LCD_voidGoToXY(u8 X, u8 Y)
{
	/* Check that the column position is valid */
	if(X <= 15)
	{
		switch(Y){
		case 1: LCD_voidSendCommand(LCD_FIRST_LINE + X); break;
		case 2: LCD_voidSendCommand(LCD_SECOND_LINE + X); break;
		default: break;
		}
	}
	else
	{
		/* Invalid column position */
	}
}


/*========================================================
 * Function: LCD_voidWriteBus
 * Purpose : Send an 8-bit value to the LCD data bus
 *========================================================*/
static void LCD_voidWriteBus(u8 Value)
{
	/* Send each bit of the value to its corresponding data pin */
	DIO_voidSetPinValue(LCD_D0, GET_BIT(Value, 0));
	DIO_voidSetPinValue(LCD_D1, GET_BIT(Value, 1));
	DIO_voidSetPinValue(LCD_D2, GET_BIT(Value, 2));
	DIO_voidSetPinValue(LCD_D3, GET_BIT(Value, 3));
	DIO_voidSetPinValue(LCD_D4, GET_BIT(Value, 4));
	DIO_voidSetPinValue(LCD_D5, GET_BIT(Value, 5));
	DIO_voidSetPinValue(LCD_D6, GET_BIT(Value, 6));
	DIO_voidSetPinValue(LCD_D7, GET_BIT(Value, 7));

	/* Generate the Enable pulse to latch the data */
	DIO_voidSetPinValue(LCD_EN, DIO_HIGH);
	_delay_ms(2);

	DIO_voidSetPinValue(LCD_EN, DIO_LOW);
	_delay_ms(2);
}


/*========================================================
 * Function: LCD_voidClear
 * Purpose : Clear the LCD display
 *========================================================*/
void LCD_voidClear(void)
{
	/* Send the Clear Display command */
	LCD_voidSendCommand(LCD_CLEAR);

	/* Wait for the LCD to complete the clear operation */
	_delay_ms(2);
}

