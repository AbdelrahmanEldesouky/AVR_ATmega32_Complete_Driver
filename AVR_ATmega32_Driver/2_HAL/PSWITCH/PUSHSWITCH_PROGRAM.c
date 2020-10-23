/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: PSWITCH					************/
/************		Date: 2-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "../../1_MCAL/1_GPIO/GPIO_INTERFACE.h"
#include "PORT_INTERFACE.h"

#include "PUSHSWITCH_INTERFACE.h"
#include "PUSHSWITCH_PRIVET.h"

uint8 PSWITCH_uint8CONTROL_DEBOUNCING (PSWITCH_CONFIG * Pswitch , uint8 * Copy_uint8State)
{
	uint8 Local_uint8ErrorState = OK , Local_uint8Value ;
	_delay_ms(PSWITCH_DELAY) ;
	DIO_uint8GetPinValue(Pswitch->Copy_uint8PswitchPort , Pswitch->Copy_uint8PswitchPin , &Local_uint8Value) ;
	if (Pswitch->Copy_uint8PswitchPullType == PULLUP)
	{
		if (Local_uint8Value == DIO_uint8_HIGH)
		{
			*Copy_uint8State = NOT_PRESSED ;

		}
		else
		{
			*Copy_uint8State = PRESSED ;
		}
	}
	else if (Pswitch->Copy_uint8PswitchPullType == PULLDOWN)
	{
		if (Local_uint8Value == DIO_uint8_HIGH)
		{
			*Copy_uint8State = PRESSED ;
		}
		else
		{
			*Copy_uint8State = NOT_PRESSED ;
		}
	}
	else
	{
		Local_uint8ErrorState = NOK ;
	}
	return Local_uint8ErrorState ;
}
uint8 PSWITCH_uint8CONTROL_BOUNCING (PSWITCH_CONFIG * Pswitch , uint8 * Copy_uint8State)
{
	uint8 Local_uint8ErrorState = OK , Local_uint8Value ;
	DIO_uint8GetPinValue(Pswitch->Copy_uint8PswitchPort , Pswitch->Copy_uint8PswitchPin , &Local_uint8Value) ;
	if (Pswitch->Copy_uint8PswitchPullType == PULLUP)
	{
		if (Local_uint8Value == DIO_uint8_HIGH)
		{
			* Copy_uint8State = NOT_PRESSED ;

		}
		else
		{
			* Copy_uint8State = PRESSED ;
		}
	}
	else if (Pswitch->Copy_uint8PswitchPullType == PULLDOWN)
	{
		if (Local_uint8Value == DIO_uint8_HIGH)
		{
			* Copy_uint8State = PRESSED ;
		}
		else
		{
			* Copy_uint8State = NOT_PRESSED ;
		}
	}
	else
	{
		Local_uint8ErrorState = NOK ;
	}
	return Local_uint8ErrorState ;
}
