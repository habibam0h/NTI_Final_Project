
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


/*==================== REGISTERS ====================*/

/* INT0 & INT1 Sense Control Register */
#define MCUCR_REG        *((volatile u8*)0x55)

/* INT2 Sense Control Register */
#define MCUCSR_REG       *((volatile u8*)0x54)

/* Interrupt Enable Register */
#define GICR_REG         *((volatile u8*)0x5B)

/* External Interrupt Flag Register */
#define GIFR_REG         *((volatile u8*)0x5A)


/*==================== MCUCR BITS ====================*/

/* INT0 Sense Control Bits */
#define MCUCR_ISC00      0
#define MCUCR_ISC01      1

/* INT1 Sense Control Bits */
#define MCUCR_ISC10      2
#define MCUCR_ISC11      3


/*==================== MCUCSR BITS ====================*/

/* INT2 Sense Control Bit */
#define MCUCSR_ISC2      6


/*===================== GICR BITS =====================*/

/* INT0 Enable Bit */
#define GICR_INT0        6

/* INT1 Enable Bit */
#define GICR_INT1        7

/* INT2 Enable Bit */
#define GICR_INT2        5


/*===================== GIFR BITS =====================*/

/* INT0 Interrupt Flag Bit */
#define GIFR_INTF0     6

/* INT1 Interrupt Flag Bit */
#define GIFR_INTF1     7

/* INT2 Interrupt Flag Bit */
#define GIFR_INTF2     5


#endif
