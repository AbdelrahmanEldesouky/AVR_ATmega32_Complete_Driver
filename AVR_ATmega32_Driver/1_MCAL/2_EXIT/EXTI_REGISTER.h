/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: EXTI						************/
/************		Date: 20-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

	#define MCUCR			*((volatile uint8*) 0X55)	/* MCU Control Register */
	#define MCUCR_ISC11		3							/* INT1 Sense Control Bit1 */
	#define MCUCR_ISC10		2							/* INT1 Sense Control Bit0 */
	#define MCUCR_ISC01		1							/* INT0 Sense Control Bit1 */
	#define MCUCR_ISC00		0							/* INT0 Sense Control Bit0 */
	
	#define MCUCSR			*((volatile uint8*) 0X54)	/* MCU Control & State Register */
	#define MCUCSR_ISC2		6							/* INT2 Sense Control */
	
	#define GICR			*((volatile uint8*) 0X5B)	/* General Interrupt Control Register */
	#define GICR_INT1		7							/* INT1 PIE */
	#define GICR_INT0		6							/* INT0 PIE */
	#define GICR_INT2		5							/* INT2 PIE */

#endif
