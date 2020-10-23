/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: BUZZER						************/
/************		Date: 3-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

	#define BUZZER_OFF		0
	#define BUZZER_ON		1
	
	#define ACTIVE_LOW		0
	#define ACTIVE_HIGH		1
	
	typedef struct
	{
		uint8 Copy_uint8BuzzerPort ;
		uint8 Copy_uint8BuzzerPin ;
		uint8 Copy_uint8ConnectionType ;
	} BUZZER_CONFIG ;
	
	uint8 BUZZER_uint8Control (BUZZER_CONFIG * buzzer , uint8 Copy_uint8State) ;

#endif
