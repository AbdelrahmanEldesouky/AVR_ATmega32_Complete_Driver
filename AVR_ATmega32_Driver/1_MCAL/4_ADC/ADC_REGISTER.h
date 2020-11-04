/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: ADC						************/
/************		Date: 28-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_
	
	#define ADMUX			*((volatile uint8*)0X27)		/* ADC Multiplexer Selection Register */
	#define ADMUX_REFS1		7								/* Reference Selection Bit 1 */
	#define ADMUX_REFS0		6								/* Reference Selection Bit 0 */
	#define ADMUX_ADLAR		5								/* ADC Left Adjust Result */
	
	#define ADSAR			*((volatile uint8*)0X26)		/* ADC Control and Status Register */
	#define ADSAR_ADEN		7								/* ADC Enable */
	#define ADSAR_ADSC		6								/* ADC Start Conversion */
	#define ADSAR_ADATE		5								/* ADC Auto Trigger Enable */
	#define ADSAR_ADIF		4								/* ADC Interrupt Flag */
	#define ADSAR_ADIE		3								/* ADC Interrupt Enable */

	#define ADCH			*((volatile uint8*)0X25)		/* ADC Data Register High Byte */
	#define ADCL			*((volatile uint8*)0X24)		/* ADC Data Register Low Byte */

	#define SFIOR			*((volatile uint8*)0X30)		/* Special Function IO Register */

#endif /* ADC_REGISTER_H_ */
