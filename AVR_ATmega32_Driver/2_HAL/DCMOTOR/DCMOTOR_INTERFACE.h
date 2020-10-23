/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: DCMOTOR						************/
/************		Date: 3-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

	#define DCMOTOR_CW		0
	#define DCMOTOR_CCW		1
	#define DCMOTOR_STOP	2
	
	typedef struct 
	{
		uint8 Copy_uint8DcMotorPort ;
		uint8 Copy_uint8DcMotorPinA ;
		uint8 Copy_uint8DcMotorPinB ;
	} DCMOTOR_CONFIG ;

	uint8 DCMOTOR_uint8Control (DCMOTOR_CONFIG * DcMotor , uint8 Copy_uint8State) ;

#endif
