
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(var,BitNum) ((var) |= (1 << (BitNum)))
#define CLR_BIT(var,BitNum) ((var) &= ~(1 << (BitNum)))
#define TOG_BIT(var,BitNum) ((var) ^= (1 << (BitNum)))
#define GET_BIT(var,BitNum) (((var) >> (BitNum)) & 1)
#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) \
( \
    ((b7) << 7) | ((b6) << 6) | ((b5) << 5) | \
    ((b4) << 4) | ((b3) << 3) | ((b2) << 2) | \
    ((b1) << 1) | (b0) \
)

#endif
