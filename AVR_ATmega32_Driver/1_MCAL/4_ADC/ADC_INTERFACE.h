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
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

	/* Macros choose ADC perscaler division factor */
	#define ADC_DIVISION_FACTOR_2	 	0
	#define ADC_DIVISION_FACTOR_4	 	2
	#define ADC_DIVISION_FACTOR_8	 	3
	#define ADC_DIVISION_FACTOR_16	 	4
	#define ADC_DIVISION_FACTOR_32		5
	#define ADC_DIVISION_FACTOR_64	 	6
	#define ADC_DIVISION_FACTOR_128	 	7
	
	/* Macros choose ADC channel */
	#define ADC_CHANNEL_SINGLE_ADC0							0
	#define ADC_CHANNEL_SINGLE_ADC1							1
	#define ADC_CHANNEL_SINGLE_ADC2							2
	#define ADC_CHANNEL_SINGLE_ADC3							3
	#define ADC_CHANNEL_SINGLE_ADC4							4
	#define ADC_CHANNEL_SINGLE_ADC5							5
	#define ADC_CHANNEL_SINGLE_ADC6							6
	#define ADC_CHANNEL_SINGLE_ADC7							7
	#define ADC_CHANNEL_DIFF_ADC0_P_ADC0_N_GAIN_10			8
	#define ADC_CHANNEL_DIFF_ADC1_P_ADC0_N_GAIN_10			9
	#define ADC_CHANNEL_DIFF_ADC0_P_ADC0_N_GAIN_200			10
	#define ADC_CHANNEL_DIFF_ADC1_P_ADC0_N_GAIN_200			11
	#define ADC_CHANNEL_DIFF_ADC2_P_ADC2_N_GAIN_10			12
	#define ADC_CHANNEL_DIFF_ADC3_P_ADC2_N_GAIN_10			13
	#define ADC_CHANNEL_DIFF_ADC2_P_ADC2_N_GAIN_200			14
	#define ADC_CHANNEL_DIFF_ADC3_P_ADC2_N_GAIN_200			15
	#define ADC_CHANNEL_DIFF_ADC0_P_ADC1_N_GAIN_1			16
	#define ADC_CHANNEL_DIFF_ADC1_P_ADC1_N_GAIN_1			17
	#define ADC_CHANNEL_DIFF_ADC2_P_ADC1_N_GAIN_1			18
	#define ADC_CHANNEL_DIFF_ADC3_P_ADC1_N_GAIN_1			19
	#define ADC_CHANNEL_DIFF_ADC4_P_ADC1_N_GAIN_1			20
	#define ADC_CHANNEL_DIFF_ADC5_P_ADC1_N_GAIN_1			21
	#define ADC_CHANNEL_DIFF_ADC6_P_ADC1_N_GAIN_1			22
	#define ADC_CHANNEL_DIFF_ADC7_P_ADC2_N_GAIN_1			23
	#define ADC_CHANNEL_DIFF_ADC0_P_ADC2_N_GAIN_1			24
	#define ADC_CHANNEL_DIFF_ADC1_P_ADC2_N_GAIN_1			25
	#define ADC_CHANNEL_DIFF_ADC2_P_ADC2_N_GAIN_1			26
	#define ADC_CHANNEL_DIFF_ADC3_P_ADC2_N_GAIN_1			27
	#define ADC_CHANNEL_DIFF_ADC4_P_ADC2_N_GAIN_1			28
	#define ADC_CHANNEL_DIFF_ADC5_P_AD2C_N_GAIN_1			29
	#define ADC_CHANNEL_1220m_VOLT							30
	#define ADC_CHANNEL_GND									31

	/*
	* ***********************************************@dataType***********************************************************
	* @name: 			ADC_Chain
	* @initialization: 	ADC_Chain variable_name = {&ADC_Channel , ChainSize , &ADC_Result , &NotificationFunc};
	* @Notes: 			ADC_Channel[ADC_CHANNEL_...1 , ADC_CHANNEL_...2 , ADC_CHANNEL_...n]
	* @Notes: 			ChainSize {0 to 255}
	* @Notes: 			ADC_Result[ADC_Result...1 , ADC_Result...2 , ADC_Result...n]
	* @Notes: 			NotificationFunc -> your notification function in upper layers
	* @example : 		ADC_Chain adc_chain1 = {&ADC_Channel , 2 , &ADC_Result , &NotificationFunc};
	*/
	typedef struct
	{
		uint8 * ADC_Channel ;
		uint8 ChainSize ;
		uint16 * ADC_Result ;
		void (*NotificationFunc)(void) ;
	}ADC_Chain;

	/*
	 * @breif:	ADC_VoidInit() is a function that used to initialize ADC Peripheral
	 * @para:	void
	 * @return: void
	 * @note:	you must edit your require configuration from CONFIG.h before call it
	 */
	void ADC_VoidInit(void) ;

	/*
	 * @breif:	ADC_VoidEnable() is a function that used to enable ADC
	 * @para:	void
	 * @return: void
	 * @example: To enable ADC ->  ADC_VoidEnable();
	 */
	void ADC_VoidEnable (void) ;

	/*
	 * @breif:	ADC_VoidDisable() is a function that used to disable ADC
	 * @para:	void
	 * @return: void
	 * @example: To disable ADC ->  ADC_VoidDisable();
	 */
	void ADC_VoidDisable (void) ;

	/*
	 * @breif:	ADC_VoidInterruptEnable() is a function that used to enable ADC PIE
	 * @para:	void
	 * @return: void
	 * @example: To enable ADC PIE ->  ADC_VoidInterruptEnable();
	 */
	void ADC_VoidInterruptEnable (void) ;

	/*
	 * @breif:	ADC_VoidInterruptEnable() is a function that used to disable ADC PIE
	 * @para:	void
	 * @return: void
	 * @example: To disable ADC PIE ->  ADC_VoidInterruptDisable();
	 */
	void ADC_VoidInterruptDisable (void) ;

	/*
	 * @breif:	ADC_uint8SetPrescaler() is a function that used to set the ADC division factor
	 * @para:	Copy_uint8Prescaler -> ADC_DIVISION_FACTOR_number
	 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
	 * @example: To set prescaler for ADC divided by 8 --> ADC_uint8SetPrescaler(ADC_DIVISION_FACTOR_8);
	 */
	uint8 ADC_uint8SetPrescaler (uint8 Copy_uint8Prescaler) ;

	/*
	 * @breif:	ADC_uint8StartSingleConversionSynch() is a function that used to start single conversion synchronous
	 * @para:	Copy_uint8Channel -> ADC_CHANNEL_...n
	 * @para:	* Copy_puint16Result -> pointer to hold the conversion result
	 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK - NULL_POINTER - TIMEOUT_STATE]
	 */
	uint8 ADC_uint8StartSingleConversionSynch (uint8 Copy_uint8Channel , uint16 * Copy_puint16Result) ;

	/*
	 * @breif:	ADC_uint8StartSingleConversionAsynch() is a function that used to start single conversion asynchronous
	 * @para:	Copy_uint8Channel -> ADC_CHANNEL_...n
	 * @para:	Copy_puint16Result -> pointer to hold the conversion result
	 * @para:	Copy_pvNotificationFunc -> notification function execute in ISR
	 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK - NULL_POINTER - TIMEOUT_STATE]
	 */
	uint8 ADC_uint8StartSingleConversionAsynch (uint8 Copy_uint8Channel , uint16 * Copy_puint16Result , void (*Copy_pvNotificationFunc)(void)) ;

	/*
	 * @breif:	ADC_uint8StartChainConversionAsynch() is a function that used to start chain conversion asynchronous
	 * @para:	ADC_Chain -> {&ADC_Channel , ChainSize , &ADC_Result , &NotificationFunc}
	 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK - NULL_POINTER - TIMEOUT_STATE]
	 */
	uint8 ADC_uint8StartChainConversionAsynch (ADC_Chain * Copy_Chain) ;

#endif /* ADC_INTERFACE_H_ */
