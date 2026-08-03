
#ifndef TIM0_PRIVATE_H_
#define TIM0_PRIVATE_H_


/*==================== REGISTERS ====================*/

/* Timer/Counter0 Register */
#define TCNT0_REG      *((volatile u8*)0x52)

/* Timer/Counter Control Register */
#define TCCR0_REG      *((volatile u8*)0x53)

/* Timer/Counter Interrupt Flag Register */
#define TIFR_REG       *((volatile u8*)0x58)

/* Timer/Counter Interrupt Mask Register */
#define TIMSK_REG      *((volatile u8*)0x59)

/* Output Compare Register 0 */
#define OCR0_REG       *((volatile u8*)0x5C)


/*==================== TCCR0 BITS ====================*/

/* Clock Select Bits */
#define CS00_BIT	  0
#define CS01_BIT      1
#define CS02_BIT      2

/* Waveform Generation Mode Bits */
#define WGM00_BIT      6
#define WGM01_BIT      3

/* Compare Match Output Mode Bits */
#define COM00_BIT       4
#define COM01_BIT       5


/*==================== TIMSK BITS ====================*/

/* Timer0 Overflow Interrupt Enable Bit */
#define TOIE0_BIT      0

/* Timer0 Output Compare Match Interrupt Enable Bit */
#define OCIE0_BIT      1


/*==================== TIFR BITS ====================*/

/* Timer0 Overflow Flag Bit */
#define TOV0_BIT      0

/* Timer0 Output Compare Flag Bit */
#define OCF0_BIT      1

#endif
