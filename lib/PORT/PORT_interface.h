#ifndef __PORT_INTERFACE_H__
#define __PORT_INTERFACE_H__

#include "STD_types.h"

#define PORT_MAX_PIN_NUM 8

typedef enum
{
    // 1
    PortBPin0 = 1,
    PortBPin1,
    PortBPin2,
    PortBPin3,
    PortBPin4,
    PortBPin5,
    PortBPin6,
    PortBPin7,
    // 14
    PortDPin0 = 14,
    PortDPin1,
    PortDPin2,
    PortDPin3,
    PortDPin4,
    PortDPin5,
    PortDPin6,
    PortDPin7,
    // 22
    PortCPin0 = 22,
    PortCPin1,
    PortCPin2,
    PortCPin3,
    PortCPin4,
    PortCPin5,
    PortCPin6,
    PortCPin7,
    // 33
    PortAPin7 = 33,
    PortAPin6,
    PortAPin5,
    PortAPin4,
    PortAPin3,
    PortAPin2,
    PortAPin1,
    PortAPin0,

} Port_PinType;

/*
typedef struct
{
    Port_PinType Pin0 : 1;
    Port_PinType Pin1 : 1;
    Port_PinType Pin2 : 1;
    Port_PinType Pin3 : 1;
    Port_PinType Pin4 : 1;
    Port_PinType Pin5 : 1;
    Port_PinType Pin6 : 1;
    Port_PinType Pin7 : 1;

} Port_ConfigType;
*/
typedef enum
{
    PORT_PIN_IN,
    PORT_PIN_OUT
} Port_PinDirectionType;

typedef enum
{
    PORT_PIN_MODE_GPIO,
    PORT_PIN_MODE_PWM,
    PORT_PIN_MODE_ADC
} Port_PinModeType;

typedef struct
{
    Port_PinType PinId;                 // Identifier for the pin
    Port_PinModeType PinMode;           // Mode of the pin (e.g., GPIO, PWM, ADC)
    Port_PinDirectionType PinDirection; // Direction of the pin (Input or Output)
                                        // Other pin-specific configuration parameters can be added here
} Port_PinConfigType;

typedef struct
{
    u8 PortNumberOfPins;                       // Total number of pins in the Port
    Port_PinConfigType Pins[PORT_MAX_PIN_NUM]; // Array to store individual pin configurations
                                               // Additional configuration parameters can be added as needed
} Port_ConfigType;




/*
 * Service ID [hex] 0x00
 * Sync/Async Synchronous
 * Reentrancy Non Reentrant
 * Parameters (in) ConfigPtr Pointer to configuration set.
 */
void Port_Init(const Port_ConfigType *ConfigPtr);

/*
 * Service ID [hex] 0x01
 * Sync/Async Synchronous
 * Reentrancy Reentrant
 * Parameters (in) Pin Port Pin ID number
 * Direction Port Pin Direction
 */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);

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

#endif //__PORT_INTERFACE_H__