/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: KPD						************/
/************		Date: 1-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

	#define NOT_PRESSED_KEY 0XFF
	#define ROW_NUMBER		4
	#define COL_NUMBER		4
								/* 	  ROW1			   ROW2			   ROW3					ROW4	*/
	#define KPD_BUTTONS_VAL		{{1 , 2 , 3 , 4},{5 , 6 , 7 , 8},{9 , 10 , 11 , 12},{13 , 14 , 15 , 16}}

	#define KPD_PORT		DIO_uint8PORTD

	#define COL_PIN0		DIO_uint8PIN3
	#define COL_PIN1		DIO_uint8PIN2
	#define COL_PIN2		DIO_uint8PIN1
	#define COL_PIN3		DIO_uint8PIN0

	#define ROW_PIN0		DIO_uint8PIN4
	#define ROW_PIN1		DIO_uint8PIN5
	#define ROW_PIN2		DIO_uint8PIN6
	#define ROW_PIN3		DIO_uint8PIN7

	#define ROW_PINS 		{ROW_PIN0 , ROW_PIN1 , ROW_PIN2 , ROW_PIN3}
	#define COL_PINS 		{COL_PIN0 , COL_PIN1 , COL_PIN2 , COL_PIN3}
	
#endif
