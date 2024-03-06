#include "PORT_interface.h"
#include "DIO_interface.h"
#include "STD_types.h"
#include <util/delay.h>

int main()
{

  Port_PinConfigType led;
  led.PinId = PortAPin5;
  led.PinDirection = PORT_PIN_IN;

  Port_PinConfigType led2;
  led2.PinId = PortCPin5;
  led2.PinDirection = PORT_PIN_OUT;

  Port_SetPinDirection(led.PinId, led.PinDirection);
  Port_SetPinDirection(led2.PinId, led2.PinDirection);

  // Dio_WriteChannel(MCU_PIN35, STD_HIGH);

  while (1)
  {
    Dio_LevelType ch = Dio_ReadChannel(MCU_PIN35);

    if (ch == STD_HIGH)
    {
      Dio_FlipChannel(MCU_PIN27);
    }
    _delay_ms(150);
  }
  return 0;
}