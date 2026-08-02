
#include "Std_Types.h"
#include "Bit_Math.h"

#include "GIE_private.h"
#include "GIE_interface.h"


/*========================================================
 * Function: GIE_voidEnable
 * Purpose : Enable global interrupts
 *========================================================*/
void GIE_voidEnable(void)
{
	SET_BIT(SREG_REG, SREG_I);
}


/*========================================================
 * Function: GIE_voidDisable
 * Purpose : Disable global interrupts
 *========================================================*/
void GIE_voidDisable(void)
{
	CLR_BIT(SREG_REG, SREG_I);
}
