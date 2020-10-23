/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: GPIO						************/
/************		Date: 22-10-2020				************/
/************		Version: 2.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

	/* Macros to choose ports */
	#define GPIO_uint8PORTA 			0
	#define GPIO_uint8PORTB 			1
	#define GPIO_uint8PORTC 			2
	#define GPIO_uint8PORTD 			3

	/* Macros to choose pins */
	#define GPIO_uint8PIN0  			0
	#define GPIO_uint8PIN1  			1
	#define GPIO_uint8PIN2  			2
	#define GPIO_uint8PIN3  			3
	#define GPIO_uint8PIN4  			4
	#define GPIO_uint8PIN5  			5
	#define GPIO_uint8PIN6  			6
	#define GPIO_uint8PIN7  			7

	/* Macros to choose pin value */
	#define GPIO_uint8_LOW 				0
	#define GPIO_uint8_HIGH 			1

	/* Macros to choose port value */
	#define GPIO_uint8PORT_LOW 			0X00
	#define GPIO_uint8PORT_HIGH 		0XFF

	/*
	 * @breif:	GPIO_voidPortInit() is a function that used to initialize the direction and the initial state of the all ports
	 * @para:	void
	 * @return: void
	 * @note:	you must edit your require configuration from CONFIG.h before call it
	 * @note:	it's better to call it at the beginning of the program
	 */
	void GPIO_voidPortInit 			(void) ;
	
	/*
	 * @breif:	GPIO_uint8SetPinValue() is a function that used to change the pin state [HIGH - LOW]
	 * @para:	Copy_uint8Port -> Port Name [GPIO_uint8PORTA - GPIO_uint8PORTB - GPIO_uint8PORTC - GPIO_uint8PORTD]
	 * @para:	Copy_uint8Pin -> Pin Number [GPIO_uint8PIN0 - GPIO_uint8PIN1 - ... - GPIO_uint8PIN7]
	 * @para:	Copy_uint8Value -> pin state value [GPIO_uint8_HIGH - GPIO_uint8_LOW]
	 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
	 * @example: To make the output of the PINC0 is high --> GPIO_uint8SetPinValue(GPIO_uint8PORTC, GPIO_uint8PIN0 , GPIO_uint8_HIGH);
	 */
	uint8 GPIO_uint8SetPinValue		(uint8 Copy_uint8Port , uint8 Copy_uint8Pin , uint8 Copy_uint8Value) ;

	/*
	 * @breif:	GPIO_uint8SetPinValue() is a function that used to change the port state [HIGH - LOW]
	 * @para:	Copy_uint8Port -> Port Name [GPIO_uint8PORTA - GPIO_uint8PORTB - GPIO_uint8PORTC - GPIO_uint8PORTD]
	 * @para:	Copy_uint8Value -> port state value [GPIO_uint8PORT_HIGH - GPIO_uint8PORT_LOW]
	 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
	 * @example: To make the output of the PINC is low --> GPIO_uint8PortValue(GPIO_uint8PORTC , GPIO_uint8PORT_LOW);
	 */
	uint8 GPIO_uint8PortValue		(uint8 Copy_uint8Port , uint8 Copy_uint8Value) ;

	/*
	 * @GPIO_uint8GetPinValue() is a function that used to read the digital signal at pin
	 * @para:	Copy_uint8Port -> Port Name [GPIO_uint8PORTA - GPIO_uint8PORTB - GPIO_uint8PORTC - GPIO_uint8PORTD]
	 * @para:	Copy_uint8Pin -> Pin Number [GPIO_uint8PIN0 - GPIO_uint8PIN1 - ... - GPIO_uint8PIN7]
	 * @para:	Copy_puint8Value -> pointer to hold the pin value
	 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
	 * @example: To get the value of input signal at PINCO --> GPIO_uint8GetPinValue(GPIO_uint8PORTC, GPIO_uint8PIN0 , &Local_uint8Value);
	 */
	uint8 GPIO_uint8GetPinValue		(uint8 Copy_uint8Port , uint8 Copy_uint8Pin , uint8 * Copy_puint8Value) ;
	
	/*
	 * @GPIO_uint8GetPinValue() is a function that used to toggle pin value
	 * @para:	Copy_uint8Port -> Port Name [GPIO_uint8PORTA - GPIO_uint8PORTB - GPIO_uint8PORTC - GPIO_uint8PORTD]
	 * @para:	Copy_uint8Pin -> Pin Number [GPIO_uint8PIN0 - GPIO_uint8PIN1 - ... - GPIO_uint8PIN7]
	 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
	 * @example: To toggle the value of PINCO --> GPIO_uint8ToggelPinValue(GPIO_uint8PORTC, GPIO_uint8PIN0);
	 */
	uint8 GPIO_uint8ToggelPinValue	(uint8 Copy_uint8Port , uint8 Copy_uint8Pin) ;
	
#endif /* GPIO_INTERFACE_H_ */
