#ifndef     __PORT_REGISTER_H__
#define     __PORT_REGISTER_H__

#define ACCESS_REG(reg)      (*((volatile u8*)reg))

#define PINA                ACCESS_REG(0x39)       
#define DDRA                ACCESS_REG(0x3A)       
#define PORTA               ACCESS_REG(0x3B)      

#define PINB                ACCESS_REG(0x36)       
#define DDRB                ACCESS_REG(0x37)       
#define PORTB               ACCESS_REG(0x38)      

#define PINC                ACCESS_REG(0x33)       
#define DDRC                ACCESS_REG(0x34)       
#define PORTC               ACCESS_REG(0x35)      

#define PIND                ACCESS_REG(0x30)       
#define DDRD                ACCESS_REG(0x31)       
#define PORTD               ACCESS_REG(0x32)      

#endif      //__PORT_REGISTER_H__