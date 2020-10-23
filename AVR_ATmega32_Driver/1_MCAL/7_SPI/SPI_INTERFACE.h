/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: SPI						************/
/************		Date: 8-10-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

	#define SPI_INTERRUPT_DISABLE					0
	#define SPI_INTERRUPT_ENABLE 					1

	#define SPI_DISABLE								0
	#define SPI_ENABLE 								1

	#define SPI_DATA_LSB_FIRST 						0
	#define SPI_DATA_MSP_FIRST 						1

	#define SPI_MASTER								0
	#define SPI_SLAVE 								1

	#define SPI_RISING_LEADING_FALLING_TRAILING 	0
	#define SPI_FALLING_LEADING_RISING_TRAILING		1

	#define SPI_SAMPLE_LEADING_SETUP_TRAILING 		0
	#define SPI_SETUP_LEADING_SAMPLE_TRAILING		1

	#define SPI_FREQ_DIVIDED_BY_2					0
	#define SPI_FREQ_DIVIDED_BY_4					1
	#define SPI_FREQ_DIVIDED_BY_8					2
	#define SPI_FREQ_DIVIDED_BY_16					3
	#define SPI_FREQ_DIVIDED_BY_32					4
	#define SPI_FREQ_DIVIDED_BY_64					5
	#define SPI_FREQ_DIVIDED_BY_128					6

	typedef struct
	{
		uint8 SPI_uint8InterruptEnable ;
		uint8 SPI_uint8SPIEnable ;
		uint8 SPI_uint8DataOrder ;
		uint8 SPI_uint8MasterSlaveSelect ;
		uint8 SPI_uint8ClockPolarity ;
		uint8 SPI_uint8ClockPhase ;
		uint8 SPI_uint8ClockRate ;
	}SPI_CONFIG;

	typedef struct
	{
		uint8 * Copy_uint8TData ;
		uint8 * Copy_uint8RData ;
		uint8 Copy_uint8BufferSize ;
		void(* NotificationFuncn)(void) ;
	}SPI_BUFFER;

	void SPI_VoidInit(void) ;

	uint8 SPI_uint8InitConfig (SPI_CONFIG * spi) ;
	
	uint8 SPI_uint8Tranceive (uint8 Copy_uint8TData , uint8 * Copy_uint8RData) ;
	
	uint8 SPI_uint8BufferTranceiverSynch (uint8 * Copy_uint8TData , uint8 * Copy_uint8RData , uint8 Copy_uint8BufferSize) ;

	uint8 SPI_uint8BufferTranceiverAsynch (SPI_BUFFER * spi_buffer) ;

#endif
