#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


/*==================== REGISTERS ====================*/

/* ADC Data Register Low */
#define ADCL_REG         *((volatile u8*)0x24)

/* ADC Data Register High */
#define ADCH_REG         *((volatile u8*)0x25)

/* ADC Control and Status Register A */
#define ADCSRA_REG       *((volatile u8*)0x26)

/* ADC Multiplexer Selection Register */
#define ADMUX_REG        *((volatile u8*)0x27)

/* Special Function IO Register */
#define SFIOR_REG        *((volatile u8*)0x50)


/*==================== ADCSRA BITS ====================*/

/* ADC Enable Bit */
#define ADEN_BIT         7

/* ADC Start Conversion Bit */
#define ADSC_BIT         6

/* ADC Auto Trigger Enable Bit */
#define ADATE_BIT        5

/* ADC Interrupt Flag Bit */
#define ADIF_BIT         4

/* ADC Interrupt Enable Bit */
#define ADIE_BIT         3

/* ADC Prescaler Select Bits */
#define ADPS0_BIT        0
#define ADPS1_BIT        1
#define ADPS2_BIT        2


/*==================== SFIOR BITS ====================*/

/* ADC Auto Trigger Source Bits */
#define ADTS0_BIT        5
#define ADTS1_BIT        6
#define ADTS2_BIT        7


/*==================== ADMUX BITS ====================*/

/* ADC Multiplexer Channel Selection Bits */
#define MUX0_BIT         0
#define MUX1_BIT         1
#define MUX2_BIT         2
#define MUX3_BIT         3
#define MUX4_BIT         4

/* ADC Left Adjust Result Bit */
#define ADLAR_BIT        5

/* ADC Reference Selection Bits */
#define REFS0_BIT        6
#define REFS1_BIT        7


#endif
