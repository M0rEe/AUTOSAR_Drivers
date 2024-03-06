#include "DIO_interface.h"
#include "DIO_register.h"
#include "STD_types.h"
#include "Bit_Math.h"

#define PORTB_OFFSET 1
#define PORTD_OFFSET 14
#define PORTC_OFFSET 22
#define PORTA_OFFSET 40
#define PORT_SIZE 7
/*
 *   Service ID [hex] 0x00
 *   Sync/Async Synchronous
 *   Reentrancy Reentrant
 *   Parameters (in) ChannelId ID of DIO channel
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    u8 tempPinValue = 0;
    if ((ChannelId >= PORTB_OFFSET) && ChannelId <= (PORTB_OFFSET + PORT_SIZE)) // PORTB
    {
        tempPinValue = Get_Bit(PINB, (ChannelId - PORTB_OFFSET));
    }
    else if ((ChannelId >= PORTD_OFFSET) && ChannelId <= (PORTD_OFFSET + PORT_SIZE)) // PORTD
    {
        tempPinValue = Get_Bit(PIND, (ChannelId - PORTD_OFFSET));
    }

    else if ((ChannelId >= PORTC_OFFSET) && ChannelId <= (PORTC_OFFSET + PORT_SIZE)) // PORTC
    {
        tempPinValue = Get_Bit(PINC, (ChannelId - PORTC_OFFSET));
    }
    else if ((ChannelId >= (PORTA_OFFSET - PORT_SIZE)) && (ChannelId <= PORTA_OFFSET)) // PORTA
    {
        tempPinValue = Get_Bit(PINA, (PORTA_OFFSET - ChannelId));
    }
    return tempPinValue ? STD_HIGH : STD_LOW;
}

/*
 * Service ID [hex] 0x01
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in)
 * ChannelId ID of DIO channel
 * Level Value to be written
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    if ((ChannelId >= PORTB_OFFSET) && ChannelId <= (PORTB_OFFSET + PORT_SIZE)) // PORTB
    {
        if (Level == STD_HIGH)
        {
            Set_Bit(PORTB, (ChannelId - PORTB_OFFSET));
        }
        else
        {
            Clr_Bit(PORTB, (ChannelId - PORTB_OFFSET));
        }
    }
    else if ((ChannelId >= PORTD_OFFSET) && ChannelId <= (PORTD_OFFSET + PORT_SIZE)) // PORTD
    {
        if (Level == STD_HIGH)
        {
            Set_Bit(PORTD, (ChannelId - PORTD_OFFSET));
        }
        else
        {
            Clr_Bit(PORTD, (ChannelId - PORTD_OFFSET));
        }
    }
    else if ((ChannelId >= PORTC_OFFSET) && ChannelId <= (PORTC_OFFSET + PORT_SIZE)) // PORTC
    {
        if (Level == STD_HIGH)
        {
            Set_Bit(PORTC, (ChannelId - PORTC_OFFSET));
        }
        else
        {
            Clr_Bit(PORTC, (ChannelId - PORTC_OFFSET));
        }
    }
    else if ((ChannelId >= (PORTA_OFFSET - PORT_SIZE)) && (ChannelId <= PORTA_OFFSET)) // PORTA
    {
        if (Level == STD_HIGH)
        {
            Set_Bit(PORTA, (PORTA_OFFSET - ChannelId));
        }
        else
        {
            Clr_Bit(PORTA, (PORTA_OFFSET - ChannelId));
        }
    }
}

/*
 * Service ID [hex] 0x11
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in) ChannelId ID of DIO channel
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    u8 tempPinValue = 0;
    if ((ChannelId >= PORTB_OFFSET) && ChannelId <= (PORTB_OFFSET + PORT_SIZE)) // PORTB
    {
        Tog_Bit(PORTB, (ChannelId - PORTB_OFFSET));
        tempPinValue = Get_Bit(PINB, (ChannelId - PORTB_OFFSET));
    }
    else if ((ChannelId >= PORTD_OFFSET) && ChannelId <= (PORTD_OFFSET + PORT_SIZE)) // PORTD
    {
        Tog_Bit(PORTD, (ChannelId - PORTD_OFFSET));
        tempPinValue = Get_Bit(PIND, (ChannelId - PORTD_OFFSET));
    }
    else if ((ChannelId >= PORTC_OFFSET) && ChannelId <= (PORTC_OFFSET + PORT_SIZE)) // PORTC
    {
        Tog_Bit(PORTC, (ChannelId - PORTC_OFFSET));
        tempPinValue = Get_Bit(PINC, (ChannelId - PORTC_OFFSET));
    }
    else if ((ChannelId >= (PORTA_OFFSET - PORT_SIZE)) && (ChannelId <= PORTA_OFFSET)) // PORTA
    {
        Tog_Bit(PORTA, (PORTA_OFFSET - ChannelId));
        tempPinValue = Get_Bit(PINA, (PORTA_OFFSET - ChannelId));
    }
    else
    {
        // DIO_E_PARAM_INVALID_CHANNEL_ID
    }
    return tempPinValue ? STD_HIGH : STD_LOW;
}

/*-------------------------------------------------------------------*/
/*
 * Service ID [hex] 0x02
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in) PortId ID of DIO Port
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    Dio_PortLevelType ret = 0x00;
    switch (PortId)
    {
    case DIO_PORTA:
        ret = PORTA;
        break;
    case DIO_PORTB:
        ret = PORTB;

        break;
    case DIO_PORTC:
        ret = PORTC;

        break;
    case DIO_PORTD:
        ret = PORTD;

        break;
    default:
        // DIO_E_PARAM_INVALID_PORT_ID
        break;
    }
    return ret;
}

/*
 * Service ID [hex] 0x03
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in)
 * PortId ID of DIO Port
 * Level Value to be written
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    switch (PortId)
    {
    case DIO_PORTA:
        PORTA = Level;
        break;

    case DIO_PORTB:
        PORTB = Level;
        break;

    case DIO_PORTC:
        PORTC = Level;
        break;

    case DIO_PORTD:
        PORTD = Level;
        break;
    default:
        // DIO_E_PARAM_INVALID_PORT_ID
        break;
    }
}

/*
 * Service ID [hex] 0x13
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in)
 * PortId ID of DIO Port
 * Level Value to be written
 * Mask Channels to be masked in the port
 */
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
{
    switch (PortId)
    {
    case DIO_PORTA:
        PORTA = (Level | Mask);
        break;

    case DIO_PORTB:
        PORTB = (Level | Mask);
        break;

    case DIO_PORTC:
        PORTC = (Level | Mask);
        break;

    case DIO_PORTD:
        PORTD = (Level | Mask);
        break;
    default:
        // DIO_E_PARAM_INVALID_PORT_ID
        break;
    }
}
