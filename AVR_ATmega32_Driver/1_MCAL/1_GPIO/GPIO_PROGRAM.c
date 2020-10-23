/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: GPIO						************/
/************		Date: 22-10-2020				************/
/************		Version: 2.00					************/
/***************************************************************/
/***************************************************************/

#include "../../4_LIBRARY/STD_TYPE.h"
#include "../../4_LIBRARY/BIT_MATH.h"

#include "GPIO_CONFIG.h"
#include "GPIO_INTERFACE.h"
#include "GPIO_PRIVATE.h"
#include "GPIO_REGISTER.h"


/*
 * @breif:	GPIO_voidPortInit() is a function that used to initialize the direction and the initial state of the all ports
 * @para:	void
 * @return: void
 * @note:	you must edit your require configuration from CONFIG.h before call it
 * @note:	it's better to call it at the beginning of the program
 */
void GPIO_voidPortInit (void)
{
	DDRA = PORTA_DIR ;
	DDRB = PORTB_DIR ;
	DDRC = PORTC_DIR ;
	DDRD = PORTD_DIR ;
	
	PORTA = PORTA_INITIAl_VALUE ;
	PORTB = PORTB_INITIAl_VALUE ;
	PORTC = PORTC_INITIAl_VALUE ;
	PORTD = PORTD_INITIAl_VALUE ;
}

/*
 * @breif:	GPIO_uint8SetPinValue() is a function that used to change the pin state [HIGH - LOW]
 * @para:	Copy_uint8Port -> Port Name [GPIO_uint8PORTA - GPIO_uint8PORTB - GPIO_uint8PORTC - GPIO_uint8PORTD]
 * @para:	Copy_uint8Pin -> Pin Number [GPIO_uint8PIN0 - GPIO_uint8PIN1 - ... - GPIO_uint8PIN7]
 * @para:	Copy_uint8Value -> pin state value [GPIO_uint8_HIGH - GPIO_uint8_LOW]
 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
 * @example: To make the output of the PINC0 is high --> GPIO_uint8SetPinValue(GPIO_uint8PORTC, GPIO_uint8PIN0 , GPIO_uint8_HIGH);
 */
uint8 GPIO_uint8SetPinValue(uint8 Copy_uint8Port , uint8 Copy_uint8Pin , uint8 Copy_uint8Value)
{
	uint8 Local_uint8ErrorState = OK ;
	if ((Copy_uint8Pin <= GPIO_uint8PIN7))
	{
		if (Copy_uint8Value == GPIO_uint8_LOW)
		{
			switch (Copy_uint8Port)
			{
			case GPIO_uint8PORTA: CLR_BIT(PORTA , Copy_uint8Pin) ; break ;
			case GPIO_uint8PORTB: CLR_BIT(PORTB , Copy_uint8Pin) ; break ;
			case GPIO_uint8PORTC: CLR_BIT(PORTC , Copy_uint8Pin) ; break ;
			case GPIO_uint8PORTD: CLR_BIT(PORTD , Copy_uint8Pin) ; break ;
			default: Local_uint8ErrorState = NOK ;
			}
		}
		else if (Copy_uint8Value == GPIO_uint8_HIGH)
		{
			switch (Copy_uint8Port)
			{
			case GPIO_uint8PORTA: SET_BIT(PORTA , Copy_uint8Pin) ; break ;
			case GPIO_uint8PORTB: SET_BIT(PORTB , Copy_uint8Pin) ; break ;
			case GPIO_uint8PORTC: SET_BIT(PORTC , Copy_uint8Pin) ; break ;
			case GPIO_uint8PORTD: SET_BIT(PORTD , Copy_uint8Pin) ; break ;
			default: Local_uint8ErrorState = NOK ;
			}
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

/*
 * @breif:	GPIO_uint8SetPinValue() is a function that used to change the port state [HIGH - LOW]
 * @para:	Copy_uint8Port -> Port Name [GPIO_uint8PORTA - GPIO_uint8PORTB - GPIO_uint8PORTC - GPIO_uint8PORTD]
 * @para:	Copy_uint8Value -> port state value [GPIO_uint8PORT_HIGH - GPIO_uint8PORT_LOW]
 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
 * @example: To make the output of the PINC is low --> GPIO_uint8PortValue(GPIO_uint8PORTC , GPIO_uint8PORT_LOW);
 */
uint8 GPIO_uint8PortValue(uint8 Copy_uint8Port , uint8 Copy_uint8Value)
{
	uint8 Local_uint8ErrorState = OK ;
	switch (Copy_uint8Port)
	{
	case GPIO_uint8PORTA: PORTA = Copy_uint8Value; break ;
	case GPIO_uint8PORTB: PORTB = Copy_uint8Value; break ;
	case GPIO_uint8PORTC: PORTC = Copy_uint8Value; break ;
	case GPIO_uint8PORTD: PORTD = Copy_uint8Value; break ;
	default: Local_uint8ErrorState = NOK ; 		  break ;
	}
	return Local_uint8ErrorState ;
}

/*
 * @GPIO_uint8GetPinValue() is a function that used to read the digital signal at pin
 * @para:	Copy_uint8Port -> Port Name [GPIO_uint8PORTA - GPIO_uint8PORTB - GPIO_uint8PORTC - GPIO_uint8PORTD]
 * @para:	Copy_uint8Pin -> Pin Number [GPIO_uint8PIN0 - GPIO_uint8PIN1 - ... - GPIO_uint8PIN7]
 * @para:	Copy_puint8Value -> pointer to hold the pin value
 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
 * @example: To get the value of input signal at PINCO --> GPIO_uint8GetPinValue(GPIO_uint8PORTC, GPIO_uint8PIN0 , &Local_uint8Value);
 */
uint8 GPIO_uint8GetPinValue(uint8 Copy_uint8Port , uint8 Copy_uint8Pin , uint8 * Copy_puint8Value)
{
	uint8 Local_uint8ErrorState = OK ;
	if ((Copy_puint8Value != NULL) && (Copy_uint8Pin <= GPIO_uint8PIN7))
	{
		switch (Copy_uint8Port)
		{
		case GPIO_uint8PORTA: *Copy_puint8Value = GET_BIT(PINA , Copy_uint8Pin) ; break ;
		case GPIO_uint8PORTB: *Copy_puint8Value = GET_BIT(PINB , Copy_uint8Pin) ; break ;
		case GPIO_uint8PORTC: *Copy_puint8Value = GET_BIT(PINC , Copy_uint8Pin) ; break ;
		case GPIO_uint8PORTD: *Copy_puint8Value = GET_BIT(PIND , Copy_uint8Pin) ; break ;
		default: Local_uint8ErrorState = NOK ; 									 break ;
		}
	}
	else
	{
		Local_uint8ErrorState = NOK ;
	}
	return Local_uint8ErrorState ;
}

/*
 * @GPIO_uint8GetPinValue() is a function that used to toggle pin value
 * @para:	Copy_uint8Port -> Port Name [GPIO_uint8PORTA - GPIO_uint8PORTB - GPIO_uint8PORTC - GPIO_uint8PORTD]
 * @para:	Copy_uint8Pin -> Pin Number [GPIO_uint8PIN0 - GPIO_uint8PIN1 - ... - GPIO_uint8PIN7]
 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
 * @example: To toggle the value of PINCO --> GPIO_uint8ToggelPinValue(GPIO_uint8PORTC, GPIO_uint8PIN0);
 */
uint8 GPIO_uint8ToggelPinValue	(uint8 Copy_uint8Port , uint8 Copy_uint8Pin)
{
	uint8 Local_uint8ErrorState = OK ;
	if (Copy_uint8Pin <= GPIO_uint8PIN7)
	{
		switch (Copy_uint8Port)
		{
		case	GPIO_uint8PORTA:
				GPIO_uint8SetPinValue(PORTA , Copy_uint8Pin , TOGGLE_BIT(PORTA, Copy_uint8Pin)) ;
				break ;
		case 	GPIO_uint8PORTB: GPIO_uint8SetPinValue(PORTB , Copy_uint8Pin , TOGGLE_BIT(PORTB, Copy_uint8Pin)) ;
				break ;
		case 	GPIO_uint8PORTC: GPIO_uint8SetPinValue(PORTC , Copy_uint8Pin , TOGGLE_BIT(PORTC, Copy_uint8Pin)) ;
				break ;
		case 	GPIO_uint8PORTD: GPIO_uint8SetPinValue(PORTD , Copy_uint8Pin , TOGGLE_BIT(PORTD, Copy_uint8Pin)) ;
				break ;
		default:
				Local_uint8ErrorState = NOK ;
				break ;
		}
	}
	else
	{
		Local_uint8ErrorState = NOK ;
	}
	return Local_uint8ErrorState ;
}
