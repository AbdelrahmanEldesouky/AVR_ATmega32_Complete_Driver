/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: EXTI						************/
/************		Date: 20-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "../../4_LIBRARY/STD_TYPE.h"
#include "../../4_LIBRARY/BIT_MATH.h"

#include "EXTI_CONFIG.h"
#include "EXTI_INTERFACE.h"
#include "EXTI_PRIVATE.h"
#include "EXTI_REGISTER.h"


/* Array of Global Pointers to Function to carry ISRs Applications Addresses */
static void (*EXTI_pvINTCallBackFunc[3]) (void) = {NULL} ;

/*
 * @breif:	EXTI_VoidINT0Init() is a function that used to initialize External Interrupt 0
 * @para:	void
 * @return: void
 * @note:	you must edit your require configuration from CONFIG.h before call it
 */
void EXTI_VoidINT0Init (void)
{
	/* Set INT0 Sense Control */
	#if EXTI_INT0_SENSE == LOW_LEVEL
		CLR_BIT(MCUCR , MCUCR_ISC00) ;
		CLR_BIT(MCUCR , MCUCR_ISC01) ;

	#elif EXTI_INT0_SENSE == ON_CHANGE
		SET_BIT(MCUCR , MCUCR_ISC00) ;
		CLR_BIT(MCUCR , MCUCR_ISC01) ;

	#elif EXTI_INT0_SENSE == FALLING_EDGE
		CLR_BIT(MCUCR , MCUCR_ISC00) ;
		SET_BIT(MCUCR , MCUCR_ISC01) ;

	#elif EXTI_INT0_SENSE == RISING_EDGE
		SET_BIT(MCUCR , MCUCR_ISC00) ;
		SET_BIT(MCUCR , MCUCR_ISC01) ;

	#else
		#error "Wrong EXTI_INT0_SENSE Config"

	#endif /* EXTI_INT0_SENSE */

	#if EXTI_INT0_INITIAL_STATE == DISABLE
			CLR_BIT(GICR , GICR_INT0) ;

	#elif EXTI_INT0_INITIAL_STATE == ENABLE
			SET_BIT(GICR , GICR_INT0) ;

	#else
		#error "Wrong EXTI_INT0_INITIAL_STATE Config"

	#endif /* EXTI_INT0_INITIAL_STATE */
}

/*
 * @breif:	EXTI_VoidINT1Init() is a function that used to initialize External Interrupt 1
 * @para:	void
 * @return: void
 * @note:	you must edit your require configuration from CONFIG.h before call it
 */
void EXTI_VoidINT1Init (void)
{
	/* Set INT1 Sense Control */
	#if EXTI_INT1_SENSE == LOW_LEVEL
		CLR_BIT(MCUCR , MCUCR_ISC10) ;
		CLR_BIT(MCUCR , MCUCR_ISC11) ;

	#elif EXTI_INT1_SENSE == ON_CHANGE
		SET_BIT(MCUCR , MCUCR_ISC10) ;
		CLR_BIT(MCUCR , MCUCR_ISC11) ;

	#elif EXTI_INT1_SENSE == FALLING_EDGE
		CLR_BIT(MCUCR , MCUCR_ISC10) ;
		SET_BIT(MCUCR , MCUCR_ISC11) ;

	#elif EXTI_INT1_SENSE == RISING_EDGE
		SET_BIT(MCUCR , MCUCR_ISC10) ;
		SET_BIT(MCUCR , MCUCR_ISC11) ;

	#else
		#error "Wrong EXTI_INT1_SENSE Config"

	#endif /* EXTI_INT1_SENSE */

	#if EXTI_INT1_INITIAL_STATE == DISABLE
			CLR_BIT(GICR , GICR_INT0) ;

	#elif EXTI_INT1_INITIAL_STATE == ENABLE
			SET_BIT(GICR , GICR_INT1) ;

	#else
		#error "Wrong EXTI_INT1_INITIAL_STATE Config"

	#endif /* EXTI_INT1_INITIAL_STATE */
}

/*
 * @breif:	EXTI_VoidINT2Init() is a function that used to initialize External Interrupt 2
 * @para:	void
 * @return: void
 * @note:	you must edit your require configuration from CONFIG.h before call it
 */
void EXTI_VoidINT2Init (void)
{
	/* Set INT2 Sense Control */
	#if EXTI_INT2_SENSE == FALLING_EDGE
		CLR_BIT(MCUCSR , MCUCSR_ISC2) ;

	#elif EXTI_INT2_SENSE == RISING_EDGE
		SET_BIT(MCUCSR , MCUCSR_ISC2) ;

	#else
		#error "Wrong EXTI_INT2_SENSE Config"

	#endif /* EXTI_INT2_SENSE */

	#if EXTI_INT2_INITIAL_STATE == DISABLE
			CLR_BIT(GICR , GICR_INT0) ;

	#elif EXTI_INT2_INITIAL_STATE == ENABLE
			SET_BIT(GICR , GICR_INT2) ;

	#else
		#error "Wrong EXTI_INT2_INITIAL_STATE Config"

	#endif /* EXTI_INT2_INITIAL_STATE */
}

/*
 * @breif:	EXTI_uint8EnableInterrupt() is a function that used to enable PIE
 * @para:	Copy_uint8INT_Number -> INT Number [INT0 - INT1 - INT2]
 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
 * @example: To enable PIE of INT0 --> EXTI_uint8EnableInterrupt(INT0);
 */
uint8 EXTI_uint8SetSenseCotrol (uint8 Copy_uint8INT_Number , uint8 Copy_uint8Sense)
{
	uint8 Local_uint8ErrorState = OK ;

	switch (Copy_uint8INT_Number)
	{
		case EXTI_INT0 :
			switch (Copy_uint8Sense)
			{
				case LOW_LEVEL 		: CLR_BIT(MCUCR , MCUCR_ISC00) ; CLR_BIT(MCUCR , MCUCR_ISC01) ; break ;
				case ON_CHANGE 		: SET_BIT(MCUCR , MCUCR_ISC00) ; CLR_BIT(MCUCR , MCUCR_ISC01) ; break ;
				case FALLING_EDGE 	: CLR_BIT(MCUCR , MCUCR_ISC00) ; SET_BIT(MCUCR , MCUCR_ISC01) ; break ;
				case RISING_EDGE 	: SET_BIT(MCUCR , MCUCR_ISC00) ; SET_BIT(MCUCR , MCUCR_ISC01) ; break ;
				default				: Local_uint8ErrorState = NOK ; break ;
			}
		break ;
		case EXTI_INT1 :
			switch (Copy_uint8Sense)
			{
				case LOW_LEVEL 		: CLR_BIT(MCUCR , MCUCR_ISC10) ; CLR_BIT(MCUCR , MCUCR_ISC11) ; break ;
				case ON_CHANGE 		: SET_BIT(MCUCR , MCUCR_ISC10) ; CLR_BIT(MCUCR , MCUCR_ISC11) ; break ;
				case FALLING_EDGE 	: CLR_BIT(MCUCR , MCUCR_ISC10) ; SET_BIT(MCUCR , MCUCR_ISC11) ; break ;
				case RISING_EDGE 	: SET_BIT(MCUCR , MCUCR_ISC10) ; SET_BIT(MCUCR , MCUCR_ISC11) ; break ;
				default				: Local_uint8ErrorState = NOK ; break ;
			}
		break ;
		case EXTI_INT2 :
			switch (Copy_uint8Sense)
			{
				case FALLING_EDGE 	: CLR_BIT(MCUCSR , MCUCSR_ISC2) ; break ;
				case RISING_EDGE 	: SET_BIT(MCUCSR , MCUCSR_ISC2) ;  break ;
				default				: Local_uint8ErrorState = NOK ; break ;
			}
		break ;
		default :
			Local_uint8ErrorState = NOK ;
		break ;
	}

	return Local_uint8ErrorState ;
}

/*
 * @breif:	EXTI_uint8EnableInterrupt() is a function that used to enable PIE
 * @para:	Copy_uint8INT_Number -> INT Number [EXTI_INT0 - EXTI_INT1 - EXTI_INT2]
 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
 * @example: To enable PIE of INT0 --> EXTI_uint8EnableInterrupt(INT0);
 */
uint8 EXTI_uint8EnableInterrupt (uint8 Copy_uint8INT_Number)
{
	uint8 Local_uint8ErrorState = OK ;

	switch (Copy_uint8INT_Number)
	{
	case EXTI_INT0 : SET_BIT(GICR , GICR_INT0) ; break ;
	case EXTI_INT1 : SET_BIT(GICR , GICR_INT1) ; break ;
	case EXTI_INT2 : SET_BIT(GICR , GICR_INT2) ; break ;
	default: Local_uint8ErrorState = NOK ;
	}

	return Local_uint8ErrorState ;
}

/*
 * @breif:	EXTI_uint8EnableInterrupt() is a function that used to disable PIE
 * @para:	Copy_uint8INT_Number -> INT Number [INT0 - INT1 - INT2]
 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK]
 * @example: To disable PIE of INT2 --> EXTI_uint8DisableInterrupt(INT2);
 */
uint8 EXTI_uint8DisableInterrupt (uint8 Copy_uint8INT_Number)
{
	uint8 Local_uint8ErrorState = OK ;

	switch (Copy_uint8INT_Number)
	{
	case EXTI_INT0 : CLR_BIT(GICR , GICR_INT0) ; break ;
	case EXTI_INT1 : CLR_BIT(GICR , GICR_INT1) ; break ;
	case EXTI_INT2 : CLR_BIT(GICR , GICR_INT2) ; break ;
	default: Local_uint8ErrorState = NOK ;
	}

	return Local_uint8ErrorState ;
}

/*
 * @breif:	EXTI_uint8INTSetCallBack() is a function that used to call back the ISR function when the EXTI happened
 * @para:	Copy_pvoidCallBackFunc() -> call back function -> take address of the ISR function
 * @para:	Copy_uint8INT_Number -> INT Number [INT0 - INT1 - INT2]
 * @return: Copy_uint8ErrorState -> Error Type -> [OK - NOK - NULL_POINTER]
 */
uint8 EXTI_uint8INTSetCallBack (void (*Copy_pvCallBackFunc)(void) , uint8 Copy_uint8INT_Number)
{
	uint8 Local_uint8ErrorState = OK ;

	if (Copy_pvCallBackFunc != NULL)
	{
		EXTI_pvINTCallBackFunc[Copy_uint8INT_Number] = Copy_pvCallBackFunc ;
	}
	else
	{
		Local_uint8ErrorState = NULL_POINTER ;
	}
	return Local_uint8ErrorState ;
}

/* ISR for INT0 */
void __vector_1 (void) 		__attribute__((signal)) ;
void __vector_1 (void)
{
	if (EXTI_pvINTCallBackFunc[EXTI_INT0] != NULL)
	{
		EXTI_pvINTCallBackFunc[EXTI_INT0]() ;
	}
}
/* ISR for INT1 */
void __vector_2 (void) 		__attribute__((signal)) ;
void __vector_2 (void)
{
	if (EXTI_pvINTCallBackFunc[EXTI_INT1] != NULL)
	{
		EXTI_pvINTCallBackFunc[EXTI_INT1] () ;
	}
}
/* ISR for INT2 */
void __vector_3 (void) 		__attribute__((signal)) ;
void __vector_3 (void)
{
	if (EXTI_pvINTCallBackFunc[EXTI_INT2] != NULL)
	{
		EXTI_pvINTCallBackFunc[EXTI_INT2] () ;
	}
}
