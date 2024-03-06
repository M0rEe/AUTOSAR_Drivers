#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__

#define NULL (void *)0

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long s64;

typedef float f32;

//6 bits for return types 2 reserved 
typedef enum
{
    E_OK,
    E_NOT_OK
    /*0x02 - 0x03F user errors*/
} Std_Return_type;

#endif //__STD_TYPES_H__