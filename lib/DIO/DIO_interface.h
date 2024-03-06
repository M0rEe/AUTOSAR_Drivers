#ifndef __DIO_INTERFACE_H__
#define __DIO_INTERFACE_H__

#define PDIP 0
#define TQFP_MLF 1

#define DIO_E_PARAM_INVALID_CHANNEL_ID 0x0A
#define DIO_E_PARAM_INVALID_PORT_ID 0x14
// not used
#define DIO_E_PARAM_INVALID_GROUP 0x1F
#define DIO_E_PARAM_POINTER 0x20

#define MCU_PACKAGE PDIP

typedef enum
{
    STD_LOW,
    STD_HIGH
} Dio_LevelType;

typedef unsigned char Dio_PortLevelType;

#if MCU_PACKAGE == PDIP

typedef enum
{
    MCU_PIN1 = 1,
    MCU_PIN2,
    MCU_PIN3,
    MCU_PIN4,
    MCU_PIN5,
    MCU_PIN6,
    MCU_PIN7,
    MCU_PIN8,

    MCU_PIN14 = 14,
    MCU_PIN15,
    MCU_PIN16,
    MCU_PIN17,
    MCU_PIN18,
    MCU_PIN19,
    MCU_PIN20,
    MCU_PIN21,

    MCU_PIN33 = 33,
    MCU_PIN34,
    MCU_PIN35,
    MCU_PIN36,
    MCU_PIN37,
    MCU_PIN38,
    MCU_PIN39,
    MCU_PIN40,

    MCU_PIN22 = 22,
    MCU_PIN23,
    MCU_PIN24,
    MCU_PIN25,
    MCU_PIN26,
    MCU_PIN27,
    MCU_PIN28,
    MCU_PIN29
} Dio_ChannelType;

typedef enum
{
    DIO_PORTA,
    DIO_PORTB,
    DIO_PORTC,
    DIO_PORTD
} Dio_PortType;

#elif MCU_PACKAGE == TQFP_MLF
#endif

/*
 *   Service ID [hex] 0x00
 *   Sync/Async Synchronous
 *   Reentrancy Reentrant
 *   Parameters (in) ChannelId ID of DIO channel
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/*
 * Service ID [hex] 0x01
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in)
 * ChannelId ID of DIO channel
 * Level Value to be written
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/*
 * Service ID [hex] 0x11
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in) ChannelId ID of DIO channel
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

/*-------------------------------------------------------------------*/
/*
 * Service ID [hex] 0x02
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in) PortId ID of DIO Port
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/*
 * Service ID [hex] 0x03
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in)
 * PortId ID of DIO Port
 * Level Value to be written
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/*
 * Service ID [hex] 0x13
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in)
 * PortId ID of DIO Port
 * Level Value to be written
 * Mask Channels to be masked in the port
 */
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);

#endif //__DIO_INTERFACE_H__