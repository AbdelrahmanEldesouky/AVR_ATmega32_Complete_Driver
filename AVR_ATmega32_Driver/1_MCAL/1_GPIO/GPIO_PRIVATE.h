/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: DIO						************/
/************		Date: 22-10-2020				************/
/************		Version: 2.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

	/* Macros used in CONFIG.h to determine pins direction */
	#define INPUT 	0
	#define OUTPUT	1

	/* Macros used in CONFIG.h to determine initial value of pins */
	#define LOW		0
	#define HIGH	1

	/* Concatenation with function like macro to aggregate values of PORTx State and Initial Value */
	#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
	#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)	0b##b7##b6##b5##b4##b3##b2##b1##b0

	/* aggregate values of PORTA State using function like macro */
	#define PORTA_DIR	CONC(PORTA_PIN7_DIR , PORTA_PIN6_DIR , PORTA_PIN5_DIR , PORTA_PIN4_DIR , PORTA_PIN3_DIR , PORTA_PIN2_DIR , PORTA_PIN1_DIR , PORTA_PIN0_DIR)
	/* aggregate values of PORTB State using function like macro */
	#define PORTB_DIR	CONC(PORTB_PIN7_DIR , PORTB_PIN6_DIR , PORTB_PIN5_DIR , PORTB_PIN4_DIR , PORTB_PIN3_DIR , PORTB_PIN2_DIR , PORTB_PIN1_DIR , PORTB_PIN0_DIR)
	/* aggregate values of PORTC State using function like macro */
	#define PORTC_DIR	CONC(PORTC_PIN7_DIR , PORTC_PIN6_DIR , PORTC_PIN5_DIR , PORTC_PIN4_DIR , PORTC_PIN3_DIR , PORTC_PIN2_DIR , PORTC_PIN1_DIR , PORTC_PIN0_DIR)
	/* aggregate values of PORTD State using function like macro */
	#define PORTD_DIR	CONC(PORTD_PIN7_DIR , PORTD_PIN6_DIR , PORTD_PIN5_DIR , PORTD_PIN4_DIR , PORTD_PIN3_DIR , PORTD_PIN2_DIR , PORTD_PIN1_DIR , PORTD_PIN0_DIR)

	/*aggregate values of PORTA Initial Value */
	#define PORTA_INITIAl_VALUE	CONC(PORTA_PIN7_INITIAl_VALUE , PORTA_PIN6_INITIAl_VALUE ,	PORTA_PIN5_INITIAl_VALUE , PORTA_PIN4_INITIAl_VALUE , PORTA_PIN3_INITIAl_VALUE , PORTA_PIN2_INITIAl_VALUE ,PORTA_PIN1_INITIAl_VALUE , PORTA_PIN0_INITIAl_VALUE)
	/*aggregate values of PORTB Initial Value */
	#define PORTB_INITIAl_VALUE	CONC(PORTB_PIN7_INITIAl_VALUE , PORTB_PIN6_INITIAl_VALUE ,	PORTB_PIN5_INITIAl_VALUE , PORTB_PIN4_INITIAl_VALUE , PORTB_PIN3_INITIAl_VALUE , PORTB_PIN2_INITIAl_VALUE ,PORTB_PIN1_INITIAl_VALUE , PORTB_PIN0_INITIAl_VALUE)
	/*aggregate values of PORTC Initial Value */
	#define PORTC_INITIAl_VALUE	CONC(PORTC_PIN7_INITIAl_VALUE , PORTC_PIN6_INITIAl_VALUE , PORTC_PIN5_INITIAl_VALUE , PORTC_PIN4_INITIAl_VALUE ,  PORTC_PIN3_INITIAl_VALUE , PORTC_PIN2_INITIAl_VALUE ,PORTC_PIN1_INITIAl_VALUE , PORTC_PIN0_INITIAl_VALUE)
	/*aggregate values of PORTA Initial Value */
	#define PORTD_INITIAl_VALUE	CONC(PORTD_PIN7_INITIAl_VALUE , PORTD_PIN6_INITIAl_VALUE ,	PORTD_PIN5_INITIAl_VALUE , PORTD_PIN4_INITIAl_VALUE , PORTD_PIN3_INITIAl_VALUE , PORTD_PIN2_INITIAl_VALUE ,PORTD_PIN1_INITIAl_VALUE , PORTD_PIN0_INITIAl_VALUE)

#endif /* DIO_PRIVATE_H_ */
