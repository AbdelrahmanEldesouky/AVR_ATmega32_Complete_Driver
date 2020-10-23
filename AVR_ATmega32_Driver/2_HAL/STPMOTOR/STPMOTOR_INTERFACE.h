/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: STPMOTOR					************/
/************		Date: 27-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#ifndef STPMOTOR_INTERFACE_H_
#define STPMOTOR_INTERFACE_H_

	#define STPMOTOR_CW		0
	#define STPMOTOR_CCW	1
	#define STPMOTOR_STOP	2
	
	typedef struct 
	{
		uint8 Copy_uint8STPMOTORPort ;
		uint8 Copy_uint8STPMOTORPin1 ;
		uint8 Copy_uint8STPMOTORPin2 ;
		uint8 Copy_uint8STPMOTORPin3 ;
		uint8 Copy_uint8STPMOTORPin4 ;
	} STPMOTOR_CONFIG ;
	
	uint8 STPMOTOR_uint8StepControl (STPMOTOR_CONFIG * STPMOTOR , uint8 Copy_uint8State) ;
	uint8 STPMOTOR_uint8AngleControl (STPMOTOR_CONFIG * STPMOTOR , uint8 Copy_uint8State , uint16 Copy_uint16Angle) ;
#endif
