/*****************************************************
 *Author :Moatasem
 *Date:   12/10/2018
 *Version: v02
 *Brief: Macros module
 *******************************************************/
#ifndef UTILS_H_
#define UTILS_H_

/*        MACROS FOR PIN         */
#define WRITE_BIT(REG, PIN, DATA) (REG) = (REG & (~(1 << PIN))) | (DATA << PIN)
#define GET_BIT(REG, INDEX) ((REG >> INDEX) & 0x01)
#define TOG_BIT(REG, PIN) REG ^= (1 << (PIN))
#define SET_BIT(REG, BIT) REG |= (1 << BIT)
#define CLEAR_BIT(REG, BIT) REG = (REG & (~(1 << BIT)))

/*         MACROS TO PORT        */
#define InitPort(CONTROL, DIRECTION) ((CONTROL) = (DIRECTION) ? (~GPIO_LOW) : (GPIO_LOW))
#define WRITE_PORT(PORT, DATA) ((PORT) = (DATA))
#define PORT_SET_MASK(REG, VAL) (REG) |= (VAL)
#define PORT_CLEAR_MASK(REG, VAL) (REG) &= ~(VAL)
#define PORT_MASK(REG, SET_INDEX, CLEAR_INDEX) REG = (REG & ~(CLEAR_INDEX)) | (SET_INDEX);
#define ReadPort(PORT) (PORT)
#define SET_REG(REG) REG = 0xFF
#define CLEAR_REG(REG) REG = 0x00
#define TOOGLE_REG(REG) REG ^= 0xFF

/*        LOWER NIBBLE 0-3        */

#define GET_LOWER(REG) (REG) & 0x0f
#define LOWER_NIBBLE_HIGH(REG) REG = ((REG & 0xf0) | 0x0f)
#define LOWER_NIBBLE_VALUE(REG, DATA) REG = (REG & 0xF0) | DATA & 0X0F

/*        HIGHER NIBBLE 4-8        */

#define GET_HIGHER(REG) (REG) & (0xF0)
#define HIGHER_NIBBLE_HIGH(REG) (REG) = ((REG & 0x0f) | (0xf0))
#define HIGHER_NIBBLE_VALUE(REG, DATA) (REG) = (REG & 0x0f) | (DATA & 0XF0)

#endif
