
#ifndef GIE_PRIVATE_H_
#define GIE_PRIVATE_H_


/*==================== REGISTERS ====================*/

/* Status Register */
#define SREG_REG        *((volatile u8*)0x5F)


/*==================== SREG BITS ====================*/

/* Global Interrupt Enable Bit */
#define SREG_I          7


#endif
