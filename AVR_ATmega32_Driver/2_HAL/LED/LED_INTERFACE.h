/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: LED						************/
/************		Date: 2-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

	#define ACTIVE_HIGH		1
	#define ACTIVE_LOW		0

	#define LED_OFF			0
	#define LED_ON			1
	
	typedef struct
	{
		uint8 Copy_LedPort ;
		uint8 Copy_LedPin ;
		uint8 Copy_ConnectionType ;
	} LED_CONFIG ;
	
	uint8 LED_uint8Control (LED_CONFIG * led , uint8 Copy_uint8State) ;
	void LED_VoidToggel (LED_CONFIG * led) ;

#endif
