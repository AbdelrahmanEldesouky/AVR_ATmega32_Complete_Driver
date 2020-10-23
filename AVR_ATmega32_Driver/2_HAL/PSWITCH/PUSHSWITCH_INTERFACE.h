/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: PSWITCH					************/
/************		Date: 2-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#ifndef PSWITCH_INTERFACE_H_
#define PSWITCH_INTERFACE_H_

	#define NOT_PRESSED		0
	#define PRESSED			1

	#define PULLUP			0
	#define PULLDOWN		1

	#define PSWITCH_DELAY	10

	typedef struct
	{
		uint8 Copy_uint8PswitchPort ;
		uint8 Copy_uint8PswitchPin ;
		uint8 Copy_uint8PswitchPullType ;
	} PSWITCH_CONFIG ;

	uint8 PSWITCH_uint8CONTROL_DEBOUNCING (PSWITCH_CONFIG * Pswitch , uint8 * Copy_uint8State) ;
	uint8 PSWITCH_uint8CONTROL_BOUNCING (PSWITCH_CONFIG * Pswitch , uint8 * Copy_uint8State) ;

#endif
