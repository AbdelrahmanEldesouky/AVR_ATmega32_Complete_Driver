/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: EXTI						************/
/************		Date: 20-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/


#include "../2_EXIT/EXTI_CONFIG.h"
#include "../2_EXIT/EXTI_INTERFACE.h"
#include "../2_EXIT/EXTI_PRIVATE.h"
#include "../2_EXIT/EXTI_REGISTER.h"
#include "STD_TYPE.h"
#include "BIT_MATH.h"


/* Define Array of Global Pointers to Function to carry ISRs Applications Addresses */
static void (*EXTI_pvINT0CallBackFunc[3]) (void) = {NULL} ;

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

	#endif

	#if EXTI_INT0_INITIAL_STATE == DISABLE
			CLR_BIT(GICR , GICR_INT0) ;

	#elif EXTI_INT0_INITIAL_STATE == ENABLE
			SET_BIT(GICR , GICR_INT0) ;

	#else
		#error "Wrong EXTI_INT0_INITIAL_STATE Config"

	#endif
}

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

	#endif

	#if EXTI_INT1_INITIAL_STATE == DISABLE
			CLR_BIT(GICR , GICR_INT0) ;

	#elif EXTI_INT1_INITIAL_STATE == ENABLE
			SET_BIT(GICR , GICR_INT1) ;

	#else
		#error "Wrong EXTI_INT1_INITIAL_STATE Config"

	#endif
}
void EXTI_VoidINT2Init (void)
{
	/* Set INT2 Sense Control */
	#if EXTI_INT2_SENSE == FALLING_EDGE
		CLR_BIT(MCUCSR , MCUCSR_ISC2) ;

	#elif EXTI_INT2_SENSE == RISING_EDGE
		SET_BIT(MCUCSR , MCUCSR_ISC2) ;

	#else
		#error "Wrong EXTI_INT2_SENSE Config"

	#endif

	#if EXTI_INT2_INITIAL_STATE == DISABLE
			CLR_BIT(GICR , GICR_INT0) ;

	#elif EXTI_INT2_INITIAL_STATE == ENABLE
			SET_BIT(GICR , GICR_INT2) ;

	#else
		#error "Wrong EXTI_INT2_INITIAL_STATE Config"

	#endif
}

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

uint8 EXTI_uint8INTSetCallBack (void (*Copy_pvCallBackFunc)(void) , uint8 Copy_uint8INT_Number)
{
	uint8 Local_uint8ErrorState = OK ;

	if (Copy_pvCallBackFunc != NULL)
	{
		EXTI_pvINT0CallBackFunc[Copy_uint8INT_Number] = Copy_pvCallBackFunc ;
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
	if (EXTI_pvINT0CallBackFunc[EXTI_INT0] != NULL)
	{
		EXTI_pvINT0CallBackFunc[EXTI_INT0]() ;
	}
}
/* ISR for INT1 */
void __vector_2 (void) 		__attribute__((signal)) ;
void __vector_2 (void)
{
	if (EXTI_pvINT0CallBackFunc[EXTI_INT1] != NULL)
	{
		EXTI_pvINT0CallBackFunc[EXTI_INT1] () ;
	}
}
/* ISR for INT2 */
void __vector_3 (void) 		__attribute__((signal)) ;
void __vector_3 (void)
{
	if (EXTI_pvINT0CallBackFunc[EXTI_INT2] != NULL)
	{
		EXTI_pvINT0CallBackFunc[EXTI_INT2] () ;
	}
}
