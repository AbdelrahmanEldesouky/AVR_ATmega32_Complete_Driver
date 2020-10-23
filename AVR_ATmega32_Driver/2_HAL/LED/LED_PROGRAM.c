/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: LED						************/
/************		Date: 2-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "../../1_MCAL/1_GPIO/GPIO_INTERFACE.h"
#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "PORT_INTERFACE.h"

#include "LED_INTERFACE.h"
#include "LED_PRIVET.h"

uint8 LED_uint8Control (LED_CONFIG * led , uint8 Copy_uint8State)
{
	uint8 Local_uint8ErrorState = OK ;
	if (Copy_uint8State == LED_ON)
	{
		if (led->Copy_ConnectionType == ACTIVE_HIGH)
		{
			DIO_uint8SetPinValue(led->Copy_LedPort , led->Copy_LedPin , DIO_uint8_HIGH) ;
		}
		else if (led->Copy_ConnectionType == ACTIVE_LOW)
		{
			DIO_uint8SetPinValue(led->Copy_LedPort , led->Copy_LedPin , DIO_uint8_LOW) ;
		}
		else
		{
			Local_uint8ErrorState = NOK ;
		}
	}
	else if (Copy_uint8State == LED_OFF)
	{
		if (led->Copy_ConnectionType == ACTIVE_HIGH)
		{
			DIO_uint8SetPinValue(led->Copy_LedPort , led->Copy_LedPin , DIO_uint8_LOW) ;
		}
		else if (led->Copy_ConnectionType == ACTIVE_LOW)
		{
			DIO_uint8SetPinValue(led->Copy_LedPort , led->Copy_LedPin , DIO_uint8_HIGH) ;
		}
		else
		{
			Local_uint8ErrorState = NOK ;
		}
	}
	else
	{
		Local_uint8ErrorState = NOK ;
	}
	return Local_uint8ErrorState ;
}
void LED_VoidToggel (LED_CONFIG * led)
{
	DIO_uint8ToggelPinValue(led->Copy_LedPort , led->Copy_LedPin) ;
}
