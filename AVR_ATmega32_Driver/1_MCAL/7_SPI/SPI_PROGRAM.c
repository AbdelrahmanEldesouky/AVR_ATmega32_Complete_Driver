/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: SPI						************/
/************		Date: 8-10-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "../7_SPI/SPI_CONFIG.h"
#include "../7_SPI/SPI_INTERFACE.h"
#include "../7_SPI/SPI_PRIVATE.h"
#include "../7_SPI/SPI_REGISTER.h"
#include "STD_TYPE.h"
#include "BIT_MATH.h"


/*Global variable to carry the Transmit Data*/
static uint8 * SPI_puint8TData = NULL ;

/*Global variable to carry the Receive Data*/
static uint8 * SPI_puint8RData = NULL ;

/*Global variable to carry the buffer size*/
static uint8 SPI_uint8BufferSize;

/*Global variable to indicate for the current Data index of the buffer*/
static uint8 SPI_uint8Index;

/*Global pointer to function to carry the notification function called by ISR*/
static void (* SPI_pvNotificationFunc)(void)= NULL;

/*Global flag for the SPI Busy State*/
static uint8 SPI_uint8State= ACTIVE ;

void SPI_VoidInit(void)
{
	/*Data Order*/
	#if SPI_DATA_ORDER == SPI_DATA_LSB_FIRST
		SET_BIT(SPCR , SPCR_DORD) ;
	#elif SPI_DATA_ORDER == SPI_DATA_MSP_FIRST
		CLR_BIT(SPCR , SPCR_DORD) ;
	#else
		#error "wrong SPI_DATA_ORDER config"
	#endif

	/*Master Select*/
	#if SPI_MASTER_SLAVE_SELECT == SPI_MASTER
		SET_BIT(SPCR , SPCR_MSTR) ;
	#elif SPI_MASTER_SLAVE_SELECT == SPI_SLAVE
		CLR_BIT(SPCR , SPCR_MSTR) ;
	#else
		#error "wrong SPI_MASTER_SLAVE_SELECT config"
	#endif

	/*Clock Polarity*/
	#if SPI_CLOCK_POLARITY == SPI_RISING_LEADING_FALLING_TRAILING
		CLR_BIT(SPCR , SPCR_CPOL) ;
	#elif SPI_CLOCK_POLARITY == SPI_FALLING_LEADING_RISING_TRAILING
		SET_BIT(SPCR , SPCR_CPOL) ;
	#else
		#error "wrong SPI_CLOCK_POLARITY config"
	#endif

	/*Clock Phase*/
	#if SPI_CLOCK_PHASE == SPI_SAMPLE_LEADING_SETUP_TRAILING
		CLR_BIT(SPCR , SPCR_CPHA) ;

	#elif SPI_CLOCK_PHASE == SPI_SETUP_LEADING_SAMPLE_TRAILING
		SET_BIT(SPCR , SPCR_CPHA) ;
	#else
		#error "wrong SPI_CLOCK_PHASE config"
	#endif

	/*Clock Rate*/
	#if SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_2
		CLR_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;

	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_4
		CLR_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_8
		SET_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_16
		SET_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_32
		CLR_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_64
		CLR_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_128
		SET_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#else
		#error "wrong SPI_CLOCK_RATE config"
	#endif

	/*SPI Interrupt Enable*/
	#if SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_DISABLE
		CLR_BIT(SPCR , SPCR_SPIE) ;
	#elif SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_ENABLE
		SET_BIT(SPCR , SPCR_SPIE) ;
	#else
		#error "wrong SPI_INTERRUPT_ENABLE_MODE config"
	#endif

	/*SPI Enable*/
	#if SPI_ENABLE_MODE == SPI_DISABLE
		CLR_BIT(SPCR , SPCR_SPE) ;
	#elif SPI_ENABLE_MODE == SPI_ENABLE
		SET_BIT(SPCR , SPCR_SPE) ;
	#else
		#error "wrong SPI_ENABLE_MODE config"
	#endif

}

uint8 SPI_uint8InitConfig (SPI_CONFIG * spi)
{
	uint8 Local_uint8ErrorState = OK ;

	if ((spi != NULL) && (spi->SPI_uint8ClockPhase != NULL) && (spi->SPI_uint8ClockPolarity != NULL) && (spi->SPI_uint8ClockRate != NULL) && (spi->SPI_uint8DataOrder != NULL) && (spi->SPI_uint8InterruptEnable != NULL) && (spi->SPI_uint8MasterSlaveSelect != NULL) && (spi->SPI_uint8SPIEnable != NULL))
	{
		switch (spi->SPI_uint8ClockPhase)
		{
		case SPI_SAMPLE_LEADING_SETUP_TRAILING: CLR_BIT(SPCR , SPCR_CPHA) ; break ;
		case SPI_SETUP_LEADING_SAMPLE_TRAILING: SET_BIT(SPCR , SPCR_CPHA) ; break ;
		default: 								Local_uint8ErrorState = NOK ; break ;
		}
		switch (spi->SPI_uint8ClockPolarity)
		{
		case SPI_RISING_LEADING_FALLING_TRAILING: CLR_BIT(SPCR , SPCR_CPOL) ; break ;
		case SPI_FALLING_LEADING_RISING_TRAILING: SET_BIT(SPCR , SPCR_CPOL) ; break ;
		default:								  Local_uint8ErrorState = NOK ; break ;
		}
		switch (spi->SPI_uint8ClockRate)
		{
		case SPI_FREQ_DIVIDED_BY_2:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_4:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_8:
			SET_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_16:
			SET_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_32:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			SET_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_64:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			SET_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_128:
			SET_BIT(SPCR , SPCR_SPR0) ;
			SET_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		default:
			Local_uint8ErrorState = NOK ;
			break ;
		}
		switch (spi->SPI_uint8DataOrder)
		{
		case SPI_DATA_MSP_FIRST: CLR_BIT(SPCR , SPCR_DORD) ; break ;
		case SPI_DATA_LSB_FIRST: SET_BIT(SPCR , SPCR_DORD) ; break ;
		default:				 Local_uint8ErrorState = NOK ; break ;
		}
		switch (spi->SPI_uint8MasterSlaveSelect)
		{
		case SPI_MASTER: SET_BIT(SPCR , SPCR_MSTR) ; break ;
		case SPI_SLAVE:  CLR_BIT(SPCR , SPCR_MSTR) ; break ;
		default:		 Local_uint8ErrorState = NOK ; break ;
		}
		switch (spi->SPI_uint8InterruptEnable)
		{
		case SPI_INTERRUPT_DISABLE: CLR_BIT(SPCR , SPCR_SPIE) ; break ;
		case SPI_INTERRUPT_ENABLE:  SET_BIT(SPCR , SPCR_SPIE) ; break ;
		default:		 			Local_uint8ErrorState = NOK ; break ;
		}
		switch (spi->SPI_uint8SPIEnable)
		{
		case SPI_DISABLE: CLR_BIT(SPCR , SPCR_SPE) ; break ;
		case SPI_ENABLE:  SET_BIT(SPCR , SPCR_SPE) ; break ;
		default:		  Local_uint8ErrorState = NOK ; break ;
		}
	}
	else
	{
		Local_uint8ErrorState = NULL_POINTER ;
	}
	return Local_uint8ErrorState ;
}

uint8 SPI_uint8Tranceive (uint8 Copy_uint8TData , uint8 * Copy_uint8RData)
{
	uint8 Local_uint8ErrorState = OK ;
	uint32 Local_uint32TimeoutCounter = 0 ;

	if (SPI_uint8State == ACTIVE)
	{
		SPI_uint8State = BUSY ;

		SPDR = Copy_uint8TData ;

		while (((GET_BIT(SPSR , SPSR_SPIF)) == 0) && (Local_uint32TimeoutCounter < SPI_uint32TIMEOUT))
		{
			Local_uint32TimeoutCounter++ ;
		}
		if (Local_uint32TimeoutCounter == SPI_uint32TIMEOUT)
		{
			Local_uint8ErrorState = TIMEOUT_STATE ;
		}
		else
		{
			* Copy_uint8RData = SPDR ;
		}
		SPI_uint8State = ACTIVE ;
	}
	else
	{
		Local_uint8ErrorState = BUSY_STATE ;
	}

	return Local_uint8ErrorState ;
}

uint8 SPI_uint8BufferTranceiverSynch (uint8 * Copy_uint8TData , uint8 * Copy_uint8RData , uint8 Copy_uint8BufferSize)
{
	uint8 Local_uint8ErrorState = OK ;
	uint8 Local_uint8Counter = 0 ;
	if ((Copy_uint8TData != NULL) && (Copy_uint8RData != NULL))
	{
		while (Local_uint8Counter < Copy_uint8BufferSize)
		{
			SPI_uint8Tranceive(Copy_uint8TData[Local_uint8Counter] , &Copy_uint8RData[Local_uint8Counter]) ;
			Local_uint8Counter++ ;
		}
	}
	else
	{
		Local_uint8ErrorState = NULL_POINTER ;
	}
	return Local_uint8ErrorState ;
}
uint8 SPI_uint8BufferTranceiverAsynch (SPI_BUFFER * spi_buffer)
{
	uint8 Local_uint8ErrorState = OK ;

	if (SPI_uint8State == ACTIVE)
	{
		if ((spi_buffer != NULL) && (spi_buffer->Copy_uint8TData != NULL) && (spi_buffer->Copy_uint8RData != NULL) && (spi_buffer->NotificationFuncn != NULL))
		{
			/*SPI is now Busy*/
			SPI_uint8State = BUSY ;

			/*Assign the SPI data globally*/
			SPI_puint8TData = spi_buffer->Copy_uint8TData ;
			SPI_puint8RData = spi_buffer->Copy_uint8RData ;
			SPI_uint8BufferSize = spi_buffer->Copy_uint8BufferSize ;
			SPI_pvNotificationFunc = spi_buffer->NotificationFuncn ;

			/*Set Index to first element*/
			SPI_uint8Index = 0 ;

			/*Transmit first Data */
			SPDR = SPI_puint8TData[SPI_uint8Index] ;

			/*SPI Interrupt Enable*/
			SET_BIT(SPCR , SPCR_SPIE) ;
		}
		else
		{
			Local_uint8ErrorState = NULL_POINTER ;
		}
	}
	else
	{
		Local_uint8ErrorState = BUSY_STATE ;
	}
	return Local_uint8ErrorState ;
}

void __vector_12 (void)		__attribute__ ((signal)) ;
void __vector_12 (void)
{
	/*Receive Data*/
	SPI_puint8RData[SPI_uint8Index] = SPDR ;

	/*Increment Data index of the buffer*/
	SPI_uint8Index++ ;

	if (SPI_uint8Index == SPI_uint8BufferSize)
	{
		/*Buffer Complete*/

		/*SPI is now ACTIVE*/
		SPI_uint8State = ACTIVE ;

		/*SPI Interrupt Disable*/
		CLR_BIT(SPCR , SPCR_SPIE) ;

		/*Call Notification Function*/
		SPI_pvNotificationFunc() ;
	}
	else
	{
		/*Buffer not Complete*/

		/*Transmit next Data*/
		SPDR = SPI_puint8TData[SPI_uint8Index] ;
	}
}
