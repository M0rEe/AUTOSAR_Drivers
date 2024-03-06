#include "PORT_interface.h"
#include "PORT_register.h"
#include "Bit_Math.h"

#define PORTB_OFFSET 1
#define PORTD_OFFSET 14
#define PORTC_OFFSET 22
#define PORTA_OFFSET 40
#define PORT_SIZE 7

/*
 * Service ID [hex] 0x00
 * Sync/Async Synchronous
 * Reentrancy Non Reentrant
 * Parameters (in) ConfigPtr Pointer to configuration set.
 */
void Port_Init(const Port_ConfigType *ConfigPtr)
{
    if (NULL != ConfigPtr)
    {
        for (u8 pinCounter = 0; pinCounter < ConfigPtr->PortNumberOfPins; pinCounter++)
        {
            Port_SetPinDirection((ConfigPtr->Pins[pinCounter]).PinId, (ConfigPtr->Pins[pinCounter]).PinDirection);
            //Port_SetPinMode((ConfigPtr->Pins[pinCounter]).PinId, (ConfigPtr->Pins[pinCounter]).PinMode);
        }
    }
    else
    {
        // Error
    }
}

/*
 * Service ID [hex] 0x01
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in) Pin Port Pin ID number
 * Direction Port Pin Direction
 */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
    if ((Pin >= PortBPin0) && (Pin <= PortBPin7))
    {
        switch (Direction)
        {
        case PORT_PIN_IN:
            Clr_Bit(DDRB, (Pin - PORTB_OFFSET));
            break;

        case PORT_PIN_OUT:
            Set_Bit(DDRB, (Pin - PORTB_OFFSET));
            break;

        default:
            // Error
            break;
        }
    }
    else if ((Pin >= PortDPin0) && (Pin <= PortDPin7))
    {
        switch (Direction)
        {
        case PORT_PIN_IN:
            Clr_Bit(DDRD, (Pin - PORTD_OFFSET));
            break;

        case PORT_PIN_OUT:
            Set_Bit(DDRD, (Pin - PORTD_OFFSET));
            break;

        default:
            // Error
            break;
        }
    }
    else if ((Pin >= PortCPin0) && (Pin <= PortCPin7))
    {
        switch (Direction)
        {
        case PORT_PIN_IN:
            Clr_Bit(DDRC, (Pin - PORTC_OFFSET));
            break;

        case PORT_PIN_OUT:
            Set_Bit(DDRC, (Pin - PORTC_OFFSET));
            break;

        default:
            // Error
            break;
        }
    }
    else if ((Pin <= PortAPin0) && (Pin >= PortAPin7))
    {
        switch (Direction)
        {
        case PORT_PIN_IN:
            Clr_Bit(DDRA, (PORTA_OFFSET - Pin));
            break;

        case PORT_PIN_OUT:
            Set_Bit(DDRA, (PORTA_OFFSET - Pin));
            break;

        default:
            // Error
            break;
        }
    }
    else
    {
        // Error
    }
}

/*
 * Service ID [hex] 0x02
 * Sync/Async Synchronous
 * Reentrancy Non Reentrant
 * Parameters (in) None
 */
void Port_RefreshPortDirection(void);

/*
 * Service ID [hex] 0x04
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in) Pin Port Pin ID number
 * Mode New Port Pin mode to be set on port pin.
 */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);