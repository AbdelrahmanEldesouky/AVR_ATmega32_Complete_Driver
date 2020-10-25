/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: EXTI						************/
/************		Date: 20-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

	/* Macros to choose EXTI */
	#define EXTI_INT0		0
	#define EXTI_INT1		1
	#define EXTI_INT2		2

	/* Macros to choose Sense */
	#define LOW_LEVEL		0
	#define ON_CHANGE		1
	#define FALLING_EDGE	2
	#define RISING_EDGE		3

	/*
	 * @breif:	EXTI_VoidINT0Init() is a function that used to initialize External Interrupt 0
	 * @para:	void
	 * @return: void
	 * @note:	you must edit your require configuration from CONFIG.h before call it
	 */
	void EXTI_VoidINT0Init (void) ;

	/*
	 * @breif:	EXTI_VoidINT1Init() is a function that used to initialize External Interrupt 1
	 * @para:	void
	 * @return: void
	 * @note:	you must edit your require configuration from CONFIG.h before call it
	 */
	void EXTI_VoidINT1Init (void) ;

	/*
	 * @breif:	EXTI_VoidINT2Init() is a function that used to initialize External Interrupt 2
	 * @para:	void
	 * @return: void
	 * @note:	you must edit your require configuration from CONFIG.h before call it
	 */
	void EXTI_VoidINT2Init (void) ;

	/*
	 * @breif:	EXTI_uint8SetSenseCotrol() is a function that used to Control the sense
	 * @para:	Copy_uint8INT_Number -> INT Number [INT0 - INT1 - INT2]
	 * @para:	Copy_uint8Sense -> Sense state [LOW_LEVEL - ON_CHANGE - FALLING_EDGE - RISING_EDGE]
	 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
	 * @example: To make the sense of the INT0 is FALLING_EDGE --> EXTI_uint8SetSenseCotrol(INT0, FALLING_EDGE);
	 */
	uint8 EXTI_uint8SetSenseCotrol (uint8 Copy_uint8INT_Number , uint8 Copy_uint8Sense) ;

	/*
	 * @breif:	EXTI_uint8EnableInterrupt() is a function that used to enable PIE
	 * @para:	Copy_uint8INT_Number -> INT Number [EXTI_INT0 - EXTI_INT1 - EXTI_INT2]
	 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
	 * @example: To enable PIE of INT0 --> EXTI_uint8EnableInterrupt(INT0);
	 */
	uint8 EXTI_uint8EnableInterrupt (uint8 Copy_uint8INT_Number) ;

	/*
	 * @breif:	EXTI_uint8EnableInterrupt() is a function that used to disable PIE
	 * @para:	Copy_uint8INT_Number -> INT Number [EXTI_INT0 - EXTI_INT1 - EXTI_INT2]
	 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
	 * @example: To disable PIE of INT2 --> EXTI_uint8DisableInterrupt(INT2);
	 */
	uint8 EXTI_uint8DisableInterrupt (uint8 Copy_uint8INT_Number) ;
	
	/*
	 * @breif:	EXTI_uint8INTSetCallBack() is a function that used to call back the ISR function when the EXTI happened
	 * @para:	Copy_pvoidCallBackFunc() -> call back function -> take address of the ISR function
	 * @para:	Copy_uint8INT_Number -> INT Number [EXTI_INT0 - EXTI_INT1 - EXTI_INT2]
	 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK - NULL_POINTER]
	 */
	uint8 EXTI_uint8INTSetCallBack (void (*Copy_pvoidCallBackFunc)(void) , uint8 Copy_uint8INT_Number) ;

#endif /* EXTI_INTERFACE_H_ */
