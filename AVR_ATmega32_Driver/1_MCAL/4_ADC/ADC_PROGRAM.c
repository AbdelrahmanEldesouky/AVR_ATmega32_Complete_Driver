/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: ADC						************/
/************		Date: 28-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "../4_ADC/ADC_CONFIG.h"
#include "../4_ADC/ADC_INTERFACE.h"
#include "../4_ADC/ADC_PRIVATE.h"
#include "../4_ADC/ADC_REGISTER.h"
#include "STD_TYPE.h"
#include "BIT_MATH.h"

/*Must include ADC_CONFIG before ADC_PRIVATE*/

/*Global pointer to carry the conversion result in the Asynchronous execution*/
static uint16 * ADC_puint16AsynchConversionResult = NULL;

/*Global pointer to function to carry the notification function called by ISR*/
static void (* ADC_pvNotificationFunc)(void)= NULL;

/*Global flag for the ADC ISR State*/
static uint8 ADC_uint8ISRState ;

/*Global pointer to carry the chain Channel*/
static uint8 * ADC_puint8ChainChannel ;

/*Global variable to carry the chain size*/
static uint8 ADC_uint8ChainSize ;

/*Global variable to indicate for the current ADC Chain*/
static uint8 ADC_uint8Index ;

/*Global flag for the ADC Busy State*/
static uint8 ADC_uint8State= ACTIVE ;

/*
 * @breif:	ADC_VoidInit() is a function that used to initialize ADC Peripheral
 * @para:	void
 * @return: void
 * @note:	you must edit your require configuration from CONFIG.h before call it
 */
void ADC_VoidInit(void)
{
	/*Select the voltage reference*/
	#if ADC_VOLTAGE_REFERENCE == ADC_AREF_REFERENCE
		CLR_BIT(ADMUX , ADMUX_REFS0) ;
		CLR_BIT(ADMUX , ADMUX_REFS1) ;

	#elif ADC_VOLTAGE_REFERENCE == ADC_AVCC_REFERENCR
		SET_BIT(ADMUX , ADMUX_REFS0) ;
		CLR_BIT(ADMUX , ADMUX_REFS1) ;

	#elif ADC_VOLTAGE_REFERENCE == ADC_INTERNAL_VOLTAGE
		SET_BIT(ADMUX , ADMUX_REFS0) ;
		SET_BIT(ADMUX , ADMUX_REFS1) ;

	#else
		#error "Wrong ADC_VOLTAGE_REFERENCE config"

	#endif /* ADC_VOLTAGE_REFERENCE */

	/*Set Left Adjust Result*/
	#if ADC_RESOLUTION == ADC_RESOLUTION_10_BIT
			CLR_BIT(ADMUX , ADMUX_ADLAR) ;

	#elif ADC_RESOLUTION == ADC_RESOLUTION_8_BIT
			SET_BIT(ADMUX , ADMUX_ADLAR) ;

	#else
		#error "Wrong ADC_RESOLUTION_8_BIT config"

	#endif /* ADC_RESOLUTION */

	/*Set Prescaler Value*/
	ADSAR &= ADC_PRESCALER_MASK ;
	ADSAR |= ADC_PRESCALER_SELECTION ;

	/*Enable ADC Peripheral*/
	#if ADC_PERIPHERAL_CONTROL == DISABLE
		CLR_BIT(ADSAR , ADSAR_ADEN) ;
	#elif ADC_PERIPHERAL_CONTROL == ENABLE
		SET_BIT(ADSAR , ADSAR_ADEN) ;
	#else
	#error "Wrong ADC_PERIPHERAL_CONTROL config"
	#endif /* ADC_PERIPHERAL_CONTROL */

	/*Enable ADC Interrupt*/
	#if ADC_INTERRUPT_CONTROL == DISABLE
		CLR_BIT(ADSAR , ADSAR_ADIE) ;
	#elif ADC_INTERRUPT_CONTROL == ENABLE
		SET_BIT(ADSAR , ADSAR_ADIE) ;
	#else
	#error "Wrong ADC_INTERRUPT_CONTROL config"
	#endif /* ADC_INTERRUPT_CONTROL */

}

/*
 * @breif:	ADC_VoidEnable() is a function that used to enable ADC
 * @para:	void
 * @return: void
 * @example: To enable ADC ->  ADC_VoidEnable();
 */
void ADC_VoidEnable (void)
{
	SET_BIT(ADSAR , ADSAR_ADEN) ;
}

/*
 * @breif:	ADC_VoidDisable() is a function that used to disable ADC
 * @para:	void
 * @return: void
 * @example: To disable ADC ->  ADC_VoidDisable();
 */
void ADC_VoidDisable (void)
{
	CLR_BIT(ADSAR , ADSAR_ADEN) ;
}

/*
 * @breif:	ADC_VoidInterruptEnable() is a function that used to enable ADC PIE
 * @para:	void
 * @return: void
 * @example: To enable ADC PIE ->  ADC_VoidInterruptEnable();
 */
void ADC_VoidInterruptEnable (void)
{
	SET_BIT(ADSAR , ADSAR_ADIE) ;
}

/*
 * @breif:	ADC_VoidInterruptEnable() is a function that used to disable ADC PIE
 * @para:	void
 * @return: void
 * @example: To disable ADC PIE ->  ADC_VoidInterruptDisable();
 */
void ADC_VoidInterruptDisable (void)
{
	CLR_BIT(ADSAR , ADSAR_ADIE) ;
}

/*
 * @breif:	ADC_uint8SetPrescaler() is a function that used to set the ADC division factor
 * @para:	Copy_uint8Prescaler -> ADC_DIVISION_FACTOR_number
 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
 * @example: To set prescaler for ADC divided by 8 --> ADC_uint8SetPrescaler(ADC_DIVISION_FACTOR_8);
 */
uint8 ADC_uint8SetPrescaler (uint8 Copy_uint8Prescaler)
{
	uint8 Local_uint8ErrorState = OK ;

	if (Copy_uint8Prescaler < 8)
	{
		/*Set Prescaler Value*/
		ADSAR &= ADC_PRESCALER_MASK ;
		ADSAR |= Copy_uint8Prescaler ;
	}

	return Local_uint8ErrorState ;
}

/*
 * @breif:	ADC_uint8StartSingleConversionSynch() is a function that used to start single conversion synchronous
 * @para:	Copy_uint8Channel -> ADC_CHANNEL_...n
 * @para:	* Copy_puint16Result -> pointer to hold the conversion result
 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK - NULL_POINTER - TIMEOUT_STATE]
 */
uint8 ADC_uint8StartSingleConversionSynch (uint8 Copy_uint8Channel , uint16 * Copy_puint16Result)
{
	uint8 Local_uint8ErrorState = OK ;
	uint32 Local_uint32TimeoutCounter = 0 ;
	if (Copy_puint16Result != NULL)
	{
		if (ADC_uint8State == ACTIVE)
		{
			/*ADC is now Busy*/
			ADC_uint8State = BUSY ;

			/*Set required channel*/
			ADMUX &= ADC_CHANNEL_MASK ;
			ADMUX |= Copy_uint8Channel ;

			/*Start Conversion*/
			SET_BIT(ADSAR , ADSAR_ADSC) ;

			/*Waiting until the conversion is complete*/
			while (((GET_BIT(ADSAR , ADSAR_ADIF)) == 0) && (Local_uint32TimeoutCounter < ADC_uint32TIMEOUT))
			{
				Local_uint32TimeoutCounter++ ;
			}
			if (Local_uint32TimeoutCounter == ADC_uint32TIMEOUT)
			{
				Local_uint8ErrorState = TIMEOUT_STATE ;
			}
			else
			{
				/*Clear the interrupt flag*/
				SET_BIT(ADSAR , ADSAR_ADIF) ;

				/*Return Conversion Result*/
				#if ADC_RESOLUTION == ADC_RESOLUTION_10_BIT
					Copy_puint16Result = &ADCL | (&ADCH << 8)  ;

				#elif ADC_RESOLUTION == ADC_RESOLUTION_8_BIT
					*Copy_puint16Result = ADCH ;
				#else
					#error "Wrong ADC_LEFT_ADJUST_RESULT config"

				#endif
			}

			/*ADC is ACTIVE*/
			ADC_uint8State = ACTIVE ;
		}
		else
		{
			Local_uint8ErrorState = BUSY_STATE ;
		}


	}
	else
	{
		Local_uint8ErrorState = NULL_POINTER ;
	}
	return Local_uint8ErrorState ;
}

/*
 * @breif:	ADC_uint8StartSingleConversionAsynch() is a function that used to start single conversion asynchronous
 * @para:	Copy_uint8Channel -> ADC_CHANNEL_...n
 * @para:	Copy_puint16Result -> pointer to hold the conversion result
 * @para:	Copy_pvNotificationFunc -> notification function execute in ISR
 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK - NULL_POINTER - TIMEOUT_STATE]
 */
uint8 ADC_uint8StartSingleConversionAsynch (uint8 Copy_uint8Channel , uint16 * Copy_puint16Result , void (*Copy_pvNotificationFunc)(void))
{
	uint8 Local_uint8ErrorState = OK ;

	if ((Copy_puint16Result != NULL) && (Copy_pvNotificationFunc != NULL))
	{
		if (ADC_uint8State == ACTIVE)
		{
			/*ADC is now Busy*/
			ADC_uint8State = BUSY ;

			/*Set ISR State*/
			ADC_uint8ISRState = SINGLE ;

			/*Initialize the global result pointer*/
			ADC_puint16AsynchConversionResult = Copy_puint16Result;

			/*Initialize the global notification function pointer*/
			ADC_pvNotificationFunc= Copy_pvNotificationFunc;

			/*Set required channel*/
			ADMUX &= ADC_CHANNEL_MASK ;
			ADMUX |= Copy_uint8Channel ;

			/*Start Conversion*/
			SET_BIT(ADSAR , ADSAR_ADSC) ;

			/*ADC Conversion Complete Interrupt Enable*/
			SET_BIT(ADSAR , ADSAR_ADIE) ;
		}
		else
		{
			Local_uint8ErrorState = BUSY_STATE ;
		}
	}
	else
	{
		Local_uint8ErrorState = NULL_POINTER ;
	}

	return Local_uint8ErrorState ;
}

/*
 * @breif:	ADC_uint8StartChainConversionAsynch() is a function that used to start chain conversion asynchronous
 * @para:	ADC_Chain -> {&ADC_Channel , ChainSize , &ADC_Result , &NotificationFunc}
 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK - NULL_POINTER - TIMEOUT_STATE]
 */
uint8 ADC_uint8StartChainConversionAsynch (ADC_Chain * Copy_Chain)
{
	uint8 Local_uint8ErrorState = OK ;

	if ((Copy_Chain != NULL) && (Copy_Chain->ADC_Channel != NULL) && (Copy_Chain->NotificationFunc != NULL) && (Copy_Chain->ADC_Result))
	{
		if (ADC_uint8State == ACTIVE)
		{
			/*ADC is now Busy*/
			ADC_uint8State = BUSY ;

			/*Set ISR State*/
			ADC_uint8ISRState = CHAIN ;

			/*Assign the ADC data globally*/
			ADC_puint16AsynchConversionResult = Copy_Chain->ADC_Result ;
			ADC_puint8ChainChannel = Copy_Chain->ADC_Channel ;
			ADC_uint8ChainSize = Copy_Chain->ChainSize ;
			ADC_pvNotificationFunc = Copy_Chain->NotificationFunc ;

			/*Set Index to first element*/
			ADC_uint8Index = 0 ;

			/*Set required channel*/
			ADMUX &= ADC_CHANNEL_MASK ;
			ADMUX |= ADC_puint8ChainChannel[ADC_uint8Index] ;

			/*Start Conversion*/
			SET_BIT(ADSAR , ADSAR_ADSC) ;

			/*ADC Conversion Complete Interrupt Enable*/
			SET_BIT(ADSAR , ADSAR_ADIE) ;
		}
		else
		{
			Local_uint8ErrorState = BUSY_STATE ;
		}

	}
	else
	{
		Local_uint8ErrorState = NULL_POINTER ;
	}
	return Local_uint8ErrorState ;
}

/* ISR for ADC conversion complete */
void __vector_16 (void)  __attribute__((signal)) ;
void __vector_16 (void)
{
	if (ADC_uint8ISRState == SINGLE)
	{
		/*Return Conversion Result*/
		#if ADC_RESOLUTION == ADC_RESOLUTION_10_BIT
			* ADC_puint16AsynchConversionResult = &ADCL | (&ADCH << 8)  ;

		#elif ADC_RESOLUTION == ADC_RESOLUTION_8_BIT
			* ADC_puint16AsynchConversionResult = ADCH ;
		#else
			#error "Wrong ADC_LEFT_ADJUST_RESULT config"

		#endif

		/*ADC is ACTIVE*/
		ADC_uint8State = ACTIVE ;

		/*Call Notification Function*/
		ADC_pvNotificationFunc() ;

		/*Disable the Conversion Complete Interrupt*/
		CLR_BIT(ADSAR , ADSAR_ADIE) ;
	}
	else
	{
		#if ADC_RESOLUTION == ADC_RESOLUTION_10_BIT
			ADC_puint16AsynchConversionResult = &ADCL | (&ADCH << 8)  ;

		#elif ADC_RESOLUTION == ADC_RESOLUTION_8_BIT
			ADC_puint16AsynchConversionResult[ADC_uint8Index] = ADCH ;
		#else
			#error "Wrong ADC_LEFT_ADJUST_RESULT config"

		#endif

		/*Increment Data index of the chain*/
		ADC_uint8Index++ ;

		if (ADC_uint8Index == ADC_uint8ChainSize)
		{
			/*ADC is ACTIVE*/
			ADC_uint8State = ACTIVE ;

			/*Call Notification Function*/
			ADC_pvNotificationFunc() ;

			/*Disable the Conversion Complete Interrupt*/
			CLR_BIT(ADSAR , ADSAR_ADIE) ;
		}
		else
		{
			/*Set required channel*/
			ADMUX &= ADC_CHANNEL_MASK ;
			ADMUX |= ADC_puint8ChainChannel[ADC_uint8Index] ;

			/*Start Conversion*/
			SET_BIT(ADSAR , ADSAR_ADSC) ;
		}
	}
}
