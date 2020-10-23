/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: CLCD						************/
/************		Date: 25-8-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

	/* Choose 8 for 8_bit connection, 4 for 4_bit connection */
	#define CLCD_CONNECTION_TYPE	4

	#if CLCD_CONNECTION_TYPE == 8

		#define CLCD_DATA_PORT			DIO_uint8PORTA

		#define CLCD_CTRL_PORT			DIO_uint8PORTB
		#define CLCD_RS_PIN				DIO_uint8PIN5
		#define CLCD_RW_PIN				DIO_uint8PIN6
		#define CLCD_E_PIN				DIO_uint8PIN7
		/*
		 * Choose:
		 * 0b00111000 for font 5 x 7 , 2 lines
		 * 0b00111100 for font 5 x 11 , 2 lines
		 * 0b00110000 for font 5 x 7 , 1 lines
		 * 0b00110100 for font 5 x 11 , 1 lines
		*/
		#define FUNCSETCOMMAND			0b00111000
		/*
		 * Always start with 0b00001ABC then choose:
		 * For A -> 1 to Display On , 0 to Display Off
		 * For B -> 1 to Cursor On , 0 to Cursor Off
		 * For C -> 1 to Cursor blink On , 0 to Cursor blink Off
		*/
		#define DISPLAYCONTROLCOMMAND	0b00001100

		/* Clear Display */
		#define DISPLAYCLEARCOMMAND		0b00000001

	#elif CLCD_CONNECTION_TYPE == 4

		#define CLCD_DATA_PORT			DIO_uint8PORTC
		#define CLCD_D7_PIN				DIO_uint8PIN7
		#define CLCD_D6_PIN				DIO_uint8PIN6
		#define CLCD_D5_PIN				DIO_uint8PIN5
		#define CLCD_D4_PIN				DIO_uint8PIN4

		#define CLCD_CTRL_PORT			DIO_uint8PORTC
		#define CLCD_RS_PIN				DIO_uint8PIN1
		#define CLCD_RW_PIN				DIO_uint8PIN2
		#define CLCD_E_PIN				DIO_uint8PIN3

		/* Choose 0 for one line , 1 for two lines */
		#define DISPLAY_LINES		1

		/* Choose 0 for 5 x 7 , 1 for 5 x 10 */
		#define DISPLAY_SIZE		0

		/*
		 * Always start with 0b00001ABC then choose:
		 * For A -> 1 to Display On , 0 to Display Off
		 * For B -> 1 to Cursor On , 0 to Cursor Off
		 * For C -> 1 to Cursor blink On , 0 to Cursor blink Off
		*/
		#define DISPLAYCONTROLCOMMAND	0b00001100

		/* Clear Display */
		#define DISPLAYCLEARCOMMAND		0b00000001
	#endif
#endif
