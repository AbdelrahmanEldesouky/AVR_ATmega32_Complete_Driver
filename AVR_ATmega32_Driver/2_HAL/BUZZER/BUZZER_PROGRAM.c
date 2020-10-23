/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: BUZZER						************/
/************		Date: 3-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "../../1_MCAL/1_GPIO/GPIO_INTERFACE.h"
#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "PORT_INTERFACE.h"

#include "BUZZER_INTERFACE.h"
#include "BUZZER_PRIVET.h"

uint8 BUZZER_uint8Control (BUZZER_CONFIG * buzzer , uint8 Copy_uint8State)
{
	uint8 Local_uint8ErrorState = OK ;
	if (Copy_uint8State == BUZZER_ON)
	{
		DIO_uint8SetPinValue(buzzer->Copy_uint8BuzzerPort , buzzer->Copy_uint8BuzzerPin , buzzer->Copy_uint8ConnectionType) ;
	}
	else if (Copy_uint8State == BUZZER_OFF)
	{
		DIO_uint8SetPinValue(buzzer->Copy_uint8BuzzerPort , buzzer->Copy_uint8BuzzerPin , !buzzer->Copy_uint8ConnectionType) ;
	}
	else
	{
		Local_uint8ErrorState = NOK ;
	}
	return Local_uint8ErrorState ;
}
