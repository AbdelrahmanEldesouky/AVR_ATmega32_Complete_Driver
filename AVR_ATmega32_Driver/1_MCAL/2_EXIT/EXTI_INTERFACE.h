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

	#define EXTI_INT0		0
	#define EXTI_INT1		1
	#define EXTI_INT2		2

	#define LOW_LEVEL		0
	#define ON_CHANGE		1
	#define FALLING_EDGE	2
	#define RISING_EDGE		3

	void EXTI_VoidINT0Init (void) ;
	void EXTI_VoidINT1Init (void) ;
	void EXTI_VoidINT2Init (void) ;

	uint8 EXTI_uint8SetSenseCotrol (uint8 Copy_uint8INT_Number , uint8 Copy_uint8Sense) ;

	uint8 EXTI_uint8EnableInterrupt (uint8 Copy_uint8INT_Number) ;
	uint8 EXTI_uint8DisableInterrupt (uint8 Copy_uint8INT_Number) ;
	
	uint8 EXTI_uint8INTSetCallBack (void (*Copy_pvoidCallBackFunc)(void) , uint8 Copy_uint8INT_Number) ;

#endif
