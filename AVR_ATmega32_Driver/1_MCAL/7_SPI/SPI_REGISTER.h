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
#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_
	
#define SPCR				* ((volatile uint8 *)0X2D)
#define SPCR_SPIE			7
#define SPCR_SPE			6
#define SPCR_DORD			5
#define SPCR_MSTR			4
#define SPCR_CPOL			3
#define SPCR_CPHA			2
#define SPCR_SPR1			1
#define SPCR_SPR0			0

#define SPSR		    	* ((volatile uint8 *)0X2E)
#define SPSR_SPIF			7
#define SPSR_WCOL			6
#define SPSR_SPI2X			0

#define SPDR			    * ((volatile uint8 *)0X2F)

#endif
