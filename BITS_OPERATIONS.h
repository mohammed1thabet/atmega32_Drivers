


#ifndef _BITS_OPERATIONS_H__
#define _BITS_OPERATIONS_H__


#define CLEAR_BIT(REG,OFSET)     REG&=~(1<<OFSET)
#define SET_BIT(REG,OFSET)       REG|= 1<<OFSET
#define TOGGLE_BIT(REG,OFSET)    REG^= 1<<OFSET
#define GET_BIT(REG,OFSET)       ((REG>>OFSET)&0x1)
#endif
