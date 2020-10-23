/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: STPMOTOR					************/
/************		Date: 27-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "../../1_MCAL/1_GPIO/GPIO_INTERFACE.h"
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "util/delay.h"

#include "PORT_INTERFACE.h"

#include "STPMOTOR_INTERFACE.h"
#include "STPMOTOR_PRIVET.h"

uint8 STPMOTOR_uint8StepControl (STPMOTOR_CONFIG * STPMOTOR , uint8 Copy_uint8State)
{
	uint8 Local_uint8ErrorState = OK ;

	switch (Copy_uint8State)
	{
	case STPMOTOR_CW :
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN0 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN1 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN2 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN3 , DIO_uint8_LOW) ;
		_delay_ms(2) ;

		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN0 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN1 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN2 , DIO_uint8_LOW) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN3 , DIO_uint8_HIGH) ;
		_delay_ms(2) ;

		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN0 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN1 , DIO_uint8_LOW) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN2 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN3 , DIO_uint8_HIGH) ;
		_delay_ms(2) ;

		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN0 , DIO_uint8_LOW) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN1 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN2 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN3 , DIO_uint8_HIGH) ;
		_delay_ms(2) ;
		break ;
	case STPMOTOR_CCW :
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN0 , DIO_uint8_LOW) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN1 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN2 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN3 , DIO_uint8_HIGH) ;
		_delay_ms(2) ;

		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN0 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN1 , DIO_uint8_LOW) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN2 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN3 , DIO_uint8_HIGH) ;
		_delay_ms(2) ;

		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN0 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN1 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN2 , DIO_uint8_LOW) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN3 , DIO_uint8_HIGH) ;
		_delay_ms(2) ;

		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN0 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN1 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN2 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN3 , DIO_uint8_LOW) ;
		_delay_ms(2) ;
		break ;
	case STPMOTOR_STOP :
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN0 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN1 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN2 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN3 , DIO_uint8_HIGH) ;
		_delay_ms(2) ;

		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN0 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN1 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN2 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN3 , DIO_uint8_HIGH) ;
		_delay_ms(2) ;

		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN0 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN1 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN2 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN3 , DIO_uint8_HIGH) ;
		_delay_ms(2) ;

		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN0 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN1 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN2 , DIO_uint8_HIGH) ;
		DIO_uint8SetPinValue(DIO_uint8PORTA , DIO_uint8PIN3 , DIO_uint8_HIGH) ;
		break ;
	default : Local_uint8ErrorState = NOK ;
	}

	return Local_uint8ErrorState ;
}
uint8 STPMOTOR_uint8AngleControl (STPMOTOR_CONFIG * STPMOTOR , uint8 Copy_uint8State , uint16 Copy_uint16Angle)
{
	uint8 Local_uint8ErrorState = OK ;
	uint32 Local_uint32StepNumber , Local_uint32Counter ;
	if (Copy_uint16Angle <= 360)
	{
		Local_uint32StepNumber = (uint32)((2048UL * (uint32)Copy_uint16Angle) / (360UL * 4UL)) ;
		switch (Copy_uint8State)
		{
		case STPMOTOR_CW :
			for (Local_uint32Counter = 0 ; Local_uint32Counter < Local_uint32StepNumber ; Local_uint32Counter++)
			{
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin1 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin2 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin3 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin4 , DIO_uint8_LOW) ;
				_delay_ms(2) ;

				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin1 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin2 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin3 , DIO_uint8_LOW) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin4 , DIO_uint8_HIGH) ;
				_delay_ms(2) ;

				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin1 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin2 , DIO_uint8_LOW) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin3 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin4 , DIO_uint8_HIGH) ;
				_delay_ms(2) ;

				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin1 , DIO_uint8_LOW) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin2 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin3 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin4 , DIO_uint8_HIGH) ;
				_delay_ms(2) ;
			}
			break ;
		case STPMOTOR_CCW :
			for (Local_uint32Counter = 0 ; Local_uint32Counter < Local_uint32StepNumber ; Local_uint32Counter++)
			{
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin1 , DIO_uint8_LOW) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin2 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin3 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin4 , DIO_uint8_HIGH) ;
				_delay_ms(2) ;

				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin1 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin2 , DIO_uint8_LOW) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin3 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin4 , DIO_uint8_HIGH) ;
				_delay_ms(2) ;

				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin1 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin2 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin3 , DIO_uint8_LOW) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin4 , DIO_uint8_HIGH) ;
				_delay_ms(2) ;

				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin1 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin2 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin3 , DIO_uint8_HIGH) ;
				DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin4 , DIO_uint8_LOW) ;
				_delay_ms(2) ;
			}
			break ;
		case STPMOTOR_STOP :
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin1 , DIO_uint8_HIGH) ;
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin2 , DIO_uint8_HIGH) ;
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin3 , DIO_uint8_HIGH) ;
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin4 , DIO_uint8_HIGH) ;
			_delay_ms(2) ;

			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin1 , DIO_uint8_HIGH) ;
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin2 , DIO_uint8_HIGH) ;
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin3 , DIO_uint8_HIGH) ;
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin4 , DIO_uint8_HIGH) ;
			_delay_ms(2) ;

			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin1 , DIO_uint8_HIGH) ;
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin2 , DIO_uint8_HIGH) ;
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin3 , DIO_uint8_HIGH) ;
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin4 , DIO_uint8_HIGH) ;
			_delay_ms(2) ;

			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin1 , DIO_uint8_HIGH) ;
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin2 , DIO_uint8_HIGH) ;
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin3 , DIO_uint8_HIGH) ;
			DIO_uint8SetPinValue(STPMOTOR->Copy_uint8STPMOTORPort , STPMOTOR->Copy_uint8STPMOTORPin4 , DIO_uint8_HIGH) ;
			break ;
		default : Local_uint8ErrorState = NOK ;
		}
	}
	else
	{
		Local_uint8ErrorState = NOK ;
	}

	return Local_uint8ErrorState ;
}
