#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


/*========================================================
 * Function: DIO_voidInitialization
 * Purpose : Initialize all DIO port directions according
 *           to the configured settings
 *========================================================*/
void DIO_voidInitialization(void){
	DDRA_REG = DIO_PORTA_DIRECTIONS;
	DDRB_REG = DIO_PORTB_DIRECTIONS;
	DDRC_REG = DIO_PORTC_DIRECTIONS;
	DDRD_REG = DIO_PORTD_DIRECTIONS;
}


/*========================================================
 * Function: DIO_voidSetPinDirection
 * Purpose : Set the direction of a specific DIO pin
 *========================================================*/
void DIO_voidSetPinDirection(u8 PortID, u8 PinID, u8 Direction){

	if((PortID < DIO_NUMBER_OF_PORTS) && (PinID < DIO_NUMBER_OF_PINS)){
		if(Direction == DIO_OUTPUT){
			switch(PortID){
				case DIO_PORTA: SET_BIT(DDRA_REG, PinID); break;
				case DIO_PORTB: SET_BIT(DDRB_REG, PinID); break;
				case DIO_PORTC: SET_BIT(DDRC_REG, PinID); break;
				case DIO_PORTD: SET_BIT(DDRD_REG, PinID); break;
			}
		}
		else if(Direction == DIO_INPUT){
			switch(PortID){
				case DIO_PORTA: CLR_BIT(DDRA_REG, PinID); break;
				case DIO_PORTB: CLR_BIT(DDRB_REG, PinID); break;
				case DIO_PORTC: CLR_BIT(DDRC_REG, PinID); break;
				case DIO_PORTD: CLR_BIT(DDRD_REG, PinID); break;
			}
		}
		else{ /* Invalid Direction */ }
	}
	else{ /* Invalid Port ID or Pin ID */}
}


/*========================================================
 * Function: DIO_voidSetPortDirection
 * Purpose : Set the direction of an entire DIO port
 *========================================================*/
void DIO_voidSetPortDirection(u8 PortID, u8 Direction){

	if(PortID < DIO_NUMBER_OF_PORTS){
		switch(PortID){
			case DIO_PORTA: DDRA_REG = Direction; break;
			case DIO_PORTB: DDRB_REG = Direction; break;
			case DIO_PORTC: DDRC_REG = Direction; break;
			case DIO_PORTD: DDRD_REG = Direction; break;
		}
	}
	else{ /* Invalid Port ID */}
}


/*========================================================
 * Function: DIO_voidSetPinValue
 * Purpose : Set the output value of a specific DIO pin
 *========================================================*/
void DIO_voidSetPinValue(u8 PortID, u8 PinID, u8 Value){

	if((PortID < DIO_NUMBER_OF_PORTS) && (PinID < DIO_NUMBER_OF_PINS)){
		if(Value == DIO_HIGH){
			switch(PortID){
				case DIO_PORTA: SET_BIT(PORTA_REG, PinID); break;
				case DIO_PORTB: SET_BIT(PORTB_REG, PinID); break;
				case DIO_PORTC: SET_BIT(PORTC_REG, PinID); break;
				case DIO_PORTD: SET_BIT(PORTD_REG, PinID); break;
			}
		}
		else if(Value == DIO_LOW){
			switch(PortID){
				case DIO_PORTA: CLR_BIT(PORTA_REG, PinID); break;
				case DIO_PORTB: CLR_BIT(PORTB_REG, PinID); break;
				case DIO_PORTC: CLR_BIT(PORTC_REG, PinID); break;
				case DIO_PORTD: CLR_BIT(PORTD_REG, PinID); break;
			}
		}
		else{ /* Invalid Value */ }
	}
	else{ /* Invalid Port ID or Pin ID */}
}


/*========================================================
 * Function: DIO_voidTogglePin
 * Purpose : Toggle the output value of a specific DIO pin
 *========================================================*/
void DIO_voidTogglePin(u8 PortID, u8 PinID){

	if((PortID < DIO_NUMBER_OF_PORTS) && (PinID < DIO_NUMBER_OF_PINS)){
		switch(PortID){
			case DIO_PORTA: TOG_BIT(PORTA_REG, PinID); break;
			case DIO_PORTB: TOG_BIT(PORTB_REG, PinID); break;
			case DIO_PORTC: TOG_BIT(PORTC_REG, PinID); break;
			case DIO_PORTD: TOG_BIT(PORTD_REG, PinID); break;
		}
	}
	else{ /* Invalid Port ID or Pin ID */}
}


/*========================================================
 * Function: DIO_voidSetPortValue
 * Purpose : Set the output value of an entire DIO port
 *========================================================*/
void DIO_voidSetPortValue(u8 PortID, u8 Value){

	if(PortID < DIO_NUMBER_OF_PORTS){
		switch(PortID){
			case DIO_PORTA: PORTA_REG = Value; break;
			case DIO_PORTB: PORTB_REG = Value; break;
			case DIO_PORTC: PORTC_REG = Value; break;
			case DIO_PORTD: PORTD_REG = Value; break;
		}
	}
	else{ /* Invalid Port ID */}
}


/*========================================================
 * Function: DIO_u8GetPinValue
 * Purpose : Read and return the value of a specific DIO pin
 *========================================================*/
u8 DIO_u8GetPinValue(u8 PortID, u8 PinID){

	u8 Local_u8PinValue = 0;

	if((PortID < DIO_NUMBER_OF_PORTS) && (PinID < DIO_NUMBER_OF_PINS)){
		switch(PortID){
			case DIO_PORTA: Local_u8PinValue = GET_BIT(PINA_REG, PinID); break;
			case DIO_PORTB: Local_u8PinValue = GET_BIT(PINB_REG, PinID); break;
			case DIO_PORTC: Local_u8PinValue = GET_BIT(PINC_REG, PinID); break;
			case DIO_PORTD: Local_u8PinValue = GET_BIT(PIND_REG, PinID); break;
		}
	}
	else{ /* Invalid Port ID or Pin ID */}

	return Local_u8PinValue;
}
