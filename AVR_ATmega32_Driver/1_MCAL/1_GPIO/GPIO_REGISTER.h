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
#ifndef GPIO_REGISTER_H_
#define GPIO_REGISTER_H_
	
	#define PORTA		*((volatile uint8 *) 0X3B)		/* Port A Data Register */
	#define DDRA		*((volatile uint8 *) 0X3A)		/* Port A Data Direction Register */
	#define PINA		*((volatile uint8 *) 0X39)		/* Port A Input Pins Address */
	
	#define PORTB		*((volatile uint8 *) 0X38)      /* Port B Data Register */
	#define DDRB		*((volatile uint8 *) 0X37)      /* Port B Data Direction Register */
	#define PINB		*((volatile uint8 *) 0X36)      /* Port B Input Pins Address */
	
	#define PORTC		*((volatile uint8 *) 0X35)      /* Port C Data Register */
	#define DDRC		*((volatile uint8 *) 0X34)      /* Port C Data Direction Register */
	#define PINC		*((volatile uint8 *) 0X33)      /* Port C Input Pins Address */
	
	#define PORTD		*((volatile uint8 *) 0X32)      /* Port D Data Register */
	#define DDRD		*((volatile uint8 *) 0X31)      /* Port D Data Direction Register */
	#define PIND		*((volatile uint8 *) 0X30)      /* Port D Input Pins Address */
	
#endif /* GPIO_REGISTER_H_ */
