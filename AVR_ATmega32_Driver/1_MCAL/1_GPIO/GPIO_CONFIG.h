/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: GPIO						************/
/************		Date: 22-10-2020				************/
/************		Version: 2.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

	/* Configuration Options of GPIO Pins Direction for GPIO_voidPortInit() function
	 * Choose between:
	 * 1. INPUT
	 * 2. OUTPUT
	 */

	/* PORTA Direction */
	#define PORTA_PIN0_DIR				OUTPUT
	#define PORTA_PIN1_DIR				OUTPUT
	#define PORTA_PIN2_DIR				OUTPUT
	#define PORTA_PIN3_DIR				OUTPUT
	#define PORTA_PIN4_DIR				OUTPUT
	#define PORTA_PIN5_DIR				OUTPUT
	#define PORTA_PIN6_DIR				OUTPUT
	#define PORTA_PIN7_DIR			    OUTPUT

	/* PORTB Direction */
	#define PORTB_PIN0_DIR				INPUT
	#define PORTB_PIN1_DIR				INPUT
	#define PORTB_PIN2_DIR				INPUT
	#define PORTB_PIN3_DIR				INPUT
	#define PORTB_PIN4_DIR				INPUT
	#define PORTB_PIN5_DIR				INPUT
	#define PORTB_PIN6_DIR				INPUT
	#define PORTB_PIN7_DIR  		    INPUT

	/* PORTC Direction */
	#define PORTC_PIN0_DIR				OUTPUT
	#define PORTC_PIN1_DIR				OUTPUT
	#define PORTC_PIN2_DIR				OUTPUT
	#define PORTC_PIN3_DIR				OUTPUT
	#define PORTC_PIN4_DIR				OUTPUT
	#define PORTC_PIN5_DIR				OUTPUT
	#define PORTC_PIN6_DIR				OUTPUT
	#define PORTC_PIN7_DIR			    OUTPUT

	/* PORTD Direction */
	#define PORTD_PIN0_DIR				INPUT
	#define PORTD_PIN1_DIR				INPUT
	#define PORTD_PIN2_DIR				INPUT
	#define PORTD_PIN3_DIR				INPUT
	#define PORTD_PIN4_DIR				INPUT
	#define PORTD_PIN5_DIR				INPUT
	#define PORTD_PIN6_DIR				INPUT
	#define PORTD_PIN7_DIR  		    INPUT

	/* Configuration Options of GPIO Pins Initial value for GPIO_voidPortInit() function
	 * Choose between:
	 * 1. LOW for: floating input or low output
	 * 2. HIGH for:pullup input	or high output
	*/

	/* PORTA Initial Value */
	#define PORTA_PIN0_INITIAl_VALUE		HIGH
	#define PORTA_PIN1_INITIAl_VALUE		HIGH
	#define PORTA_PIN2_INITIAl_VALUE		HIGH
	#define PORTA_PIN3_INITIAl_VALUE		HIGH
	#define PORTA_PIN4_INITIAl_VALUE		HIGH
	#define PORTA_PIN5_INITIAl_VALUE		HIGH
	#define PORTA_PIN6_INITIAl_VALUE		HIGH
	#define PORTA_PIN7_INITIAl_VALUE	    HIGH

	/* PORTB Initial Value */
	#define PORTB_PIN0_INITIAl_VALUE		LOW
	#define PORTB_PIN1_INITIAl_VALUE		LOW
	#define PORTB_PIN2_INITIAl_VALUE		LOW
	#define PORTB_PIN3_INITIAl_VALUE		LOW
	#define PORTB_PIN4_INITIAl_VALUE		LOW
	#define PORTB_PIN5_INITIAl_VALUE		LOW
	#define PORTB_PIN6_INITIAl_VALUE		LOW
	#define PORTB_PIN7_INITIAl_VALUE	    LOW

	/* PORTC Initial Value */
	#define PORTC_PIN0_INITIAl_VALUE		HIGH
	#define PORTC_PIN1_INITIAl_VALUE		HIGH
	#define PORTC_PIN2_INITIAl_VALUE		HIGH
	#define PORTC_PIN3_INITIAl_VALUE		HIGH
	#define PORTC_PIN4_INITIAl_VALUE		HIGH
	#define PORTC_PIN5_INITIAl_VALUE		HIGH
	#define PORTC_PIN6_INITIAl_VALUE		HIGH
	#define PORTC_PIN7_INITIAl_VALUE	    HIGH

	/* PORTD Initial Value */
	#define PORTD_PIN0_INITIAl_VALUE		LOW
	#define PORTD_PIN1_INITIAl_VALUE		LOW
	#define PORTD_PIN2_INITIAl_VALUE		LOW
	#define PORTD_PIN3_INITIAl_VALUE		LOW
	#define PORTD_PIN4_INITIAl_VALUE		LOW
	#define PORTD_PIN5_INITIAl_VALUE		LOW
	#define PORTD_PIN6_INITIAl_VALUE		LOW
	#define PORTD_PIN7_INITIAl_VALUE	    LOW

#endif /* GPIO_CONFIG_H_ */
