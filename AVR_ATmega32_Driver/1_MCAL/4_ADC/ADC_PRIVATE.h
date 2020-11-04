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
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

	/* Macros used in ADC ISR to differentiate between single conversion and chain conversion */
	#define SINGLE						0
	#define CHAIN						1

	/* Macros used in CONFIG.h to control ADEN & ADIE */
	#define DISABLE						0
	#define ENABLE						1

	/* Macros used in CONFIG.h to choose ADC reference voltage */
	#define ADC_AREF_REFERENCE		 	0
	#define ADC_AVCC_REFERENCR		 	1
	#define ADC_INTERNAL_VOLTAGE	 	3

	/* Macros choose ADC resolution */
	#define ADC_RESOLUTION_10_BIT		0
	#define ADC_RESOLUTION_8_BIT		1

	/* Macros used to make sure the last 3 bits in ADCSRA are 0 */
	#define ADC_PRESCALER_MASK			0b11111000

	/* Macros used to make sure the last 5 bits in ADCMUX are 0 */
	#define ADC_CHANNEL_MASK			0b11100000

	/* Macros used to make sure the first 3 bits in SFIOR are 0 */
	#define ADC_AUTO_TRIGGER_SOURCE		0b00011111

#endif /* ADC_PRIVATE_H_ */
