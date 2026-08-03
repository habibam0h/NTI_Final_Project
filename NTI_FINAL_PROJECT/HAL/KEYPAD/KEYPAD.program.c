#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"

#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include "KEYPAD_interface.h"


/*==================== KEYPAD KEYS ====================*/

/* Store the character corresponding to each keypad position */
static const u8 KEYPAD_KEYS[KEYPAD_ROWS_NUM][KEYPAD_COLS_NUM] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};


/*==================== KEYPAD ROWS ====================*/

/* Store the Port ID and Pin ID of each keypad row */
static const u8 KEYPAD_ROWS[KEYPAD_ROWS_NUM][2] =
{
    {KEYPAD_ROW0},
    {KEYPAD_ROW1},
    {KEYPAD_ROW2},
    {KEYPAD_ROW3}
};


/*==================== KEYPAD COLUMNS ====================*/

/* Store the Port ID and Pin ID of each keypad column */
static const u8 KEYPAD_COLS[KEYPAD_COLS_NUM][2] =
{
    {KEYPAD_COL0},
    {KEYPAD_COL1},
    {KEYPAD_COL2}
};


/*========================================================
 * Function: KEYPAD_voidInitialization
 * Purpose : Initialize the keypad rows and columns to High
 *========================================================*/
void KEYPAD_voidInitialization(void)
{
    for(u8 Local_u8Iterator = 0; Local_u8Iterator < KEYPAD_ROWS_NUM; Local_u8Iterator++)
    {
        /* Set the current row to High */
        DIO_voidSetPinValue(KEYPAD_ROWS[Local_u8Iterator][0],
                            KEYPAD_ROWS[Local_u8Iterator][1],
                            DIO_HIGH);
    }

    for(u8 Local_u8Iterator = 0; Local_u8Iterator < KEYPAD_COLS_NUM; Local_u8Iterator++)
    {
        /* Set the current column to High */
        DIO_voidSetPinValue(KEYPAD_COLS[Local_u8Iterator][0],
                            KEYPAD_COLS[Local_u8Iterator][1],
                            DIO_HIGH);
    }
}


/*========================================================
 * Function: KEYPAD_u8GetPressedKey
 * Purpose : Scan the keypad and return the pressed key
 *========================================================*/
u8 KEYPAD_u8GetPressedKey(void)
{
	u8 Local_u8Row;
	u8 Local_u8Col;

	/* Scan each keypad column */
	for(Local_u8Col = 0; Local_u8Col < KEYPAD_COLS_NUM; Local_u8Col++)
	{
		/* Activate the current column */
		KEYPAD_voidActivateColumn(Local_u8Col);

		/* Check each row in the current column */
		for(Local_u8Row = 0; Local_u8Row < KEYPAD_ROWS_NUM; Local_u8Row++)
		{
			/* Check if the current key is pressed */
			if(DIO_u8GetPinValue(KEYPAD_ROWS[Local_u8Row][0],
			                     KEYPAD_ROWS[Local_u8Row][1]) == DIO_LOW)
			{
				/* Wait until the key is released */
				while(DIO_u8GetPinValue(KEYPAD_ROWS[Local_u8Row][0],
				                        KEYPAD_ROWS[Local_u8Row][1]) == DIO_LOW);

				/* Restore the current column */
				KEYPAD_voidDeactivateColumn(Local_u8Col);

				/* Return the character of the pressed key */
				return KEYPAD_KEYS[Local_u8Row][Local_u8Col];
			}
		}

		/* Restore the current column */
		KEYPAD_voidDeactivateColumn(Local_u8Col);
	}

	/* No key is currently pressed */
	return 0xFF;
}


/*========================================================
 * Function: KEYPAD_voidActivateColumn
 * Purpose : Activate the selected keypad column
 *========================================================*/
static void KEYPAD_voidActivateColumn(u8 Col)
{
    /* Activate the column by setting it Low */
    DIO_voidSetPinValue(KEYPAD_COLS[Col][0],
                        KEYPAD_COLS[Col][1],
                        DIO_LOW);
}


/*========================================================
 * Function: KEYPAD_voidDeactivateColumn
 * Purpose : Deactivate the selected keypad column
 *========================================================*/
static void KEYPAD_voidDeactivateColumn(u8 Col)
{
    /* Deactivate the column by setting it High */
    DIO_voidSetPinValue(KEYPAD_COLS[Col][0],
                        KEYPAD_COLS[Col][1],
                        DIO_HIGH);
}
