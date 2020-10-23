/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: CLCD						************/
/************		Date: 25-8-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "../../1_MCAL/1_GPIO/GPIO_INTERFACE.h"
#include "STRINGFUNC.h"

#include "CLCD_INTERFACE.h"
#include "CLCD_PRIVET.h"
#include "CLCD_CONFIG.h"

#define ROW1_ADDRESS		0X40
uint8 Global_uint8i , Global_uint8RowPos ;


void CLCD_VoidSendCommand (uint8 Copy_uint8Command)
{
	/* 8_bit mode */
	#if CLCD_CONNECTION_TYPE == 8
		/* Set pin RS to low for command */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_uint8_LOW) ;
		/* Set pin RW to low for write */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_uint8_LOW) ;
		/* Send command to the CLCD */
		DIO_uint8PortValue(CLCD_DATA_PORT , Copy_uint8Command) ;
		/* Send the Enable pulse to the CLCD */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_HIGH) ;
		_delay_ms(2) ;
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_LOW) ;
	/* 4_bit mode */
	#elif CLCD_CONNECTION_TYPE == 4
		/* Set pin RS to low for command */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_uint8_LOW) ;
		/* Set pin RW to low for write */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_uint8_LOW) ;
		/* Send the higher part command to the CLCD */
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D7_PIN , GET_BIT(Copy_uint8Command , 7)) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D6_PIN , GET_BIT(Copy_uint8Command , 6)) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D5_PIN , GET_BIT(Copy_uint8Command , 5)) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D4_PIN , GET_BIT(Copy_uint8Command , 4)) ;
		/* Send the Enable pulse to the CLCD */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_HIGH) ;
		_delay_ms(2) ;
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_LOW) ;
		/* Delay before send the lower part */
		_delay_ms(2) ;
		/* Send the lower part command to the CLCD */
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D7_PIN , GET_BIT(Copy_uint8Command , 3)) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D6_PIN , GET_BIT(Copy_uint8Command , 2)) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D5_PIN , GET_BIT(Copy_uint8Command , 1)) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D4_PIN , GET_BIT(Copy_uint8Command , 0)) ;
		/* Send the Enable pulse to the CLCD */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_HIGH) ;
		_delay_ms(2) ;
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_LOW) ;
		_delay_ms(2) ;
	#endif
}
void CLCD_VoidSendData (uint8 Copy_uint8Data)
{
	/* 8_bit mode */
	#if CLCD_CONNECTION_TYPE == 8
		/* Set pin RS to high for data */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_uint8_HIGH) ;
		/* Set pin RW to low for write */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_uint8_LOW) ;
		/* Send data to the CLCD */
		DIO_uint8PortValue(CLCD_DATA_PORT , Copy_uint8Data) ;
		/* Send the Enable pulse to the CLCD */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_HIGH) ;
		_delay_ms(2) ;
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_LOW) ;
	/* 4_bit mode */
	#elif CLCD_CONNECTION_TYPE == 4
		/* Set pin RS to low for command */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_uint8_HIGH) ;
		/* Set pin RW to low for write */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_uint8_LOW) ;
		/* Send the higher part command to the CLCD */
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D7_PIN , GET_BIT(Copy_uint8Data , 7)) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D6_PIN , GET_BIT(Copy_uint8Data , 6)) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D5_PIN , GET_BIT(Copy_uint8Data , 5)) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D4_PIN , GET_BIT(Copy_uint8Data , 4)) ;
		/* Send the Enable pulse to the CLCD */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_HIGH) ;
		_delay_ms(2) ;
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_LOW) ;
		/* Send the lower part command to the CLCD */
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D7_PIN , GET_BIT(Copy_uint8Data , 3)) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D6_PIN , GET_BIT(Copy_uint8Data , 2)) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D5_PIN , GET_BIT(Copy_uint8Data , 1)) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D4_PIN , GET_BIT(Copy_uint8Data , 0)) ;
		/* Send the Enable pulse to the CLCD */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_HIGH) ;
		_delay_ms(2) ;
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_LOW) ;
		_delay_ms(2) ;
	#endif
}
void CLCD_VoidInit (void)
{
	#if CLCD_CONNECTION_TYPE == 8
		/* wait for more than 30 ms */
		_delay_ms(35) ;
		/* function set */
		CLCD_VoidSendCommand(FUNCSETCOMMAND) ;
		/* Display control on / off */
		CLCD_VoidSendCommand(DISPLAYCONTROLCOMMAND) ;
		/* Display clear */
		CLCD_VoidSendCommand(DISPLAYCLEARCOMMAND) ;
	#elif CLCD_CONNECTION_TYPE == 4
		/* wait for more than 30 ms */
		_delay_ms(35) ;
		/* function set */
		CLCD_VoidSendCommand(FUNCSETCOMMAND1) ;
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_uint8_LOW) ;
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_uint8_LOW) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D7_PIN , DISPLAY_LINES) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D6_PIN , DISPLAY_SIZE) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D5_PIN , DIO_uint8_LOW) ;
		DIO_uint8SetPinValue(CLCD_DATA_PORT , CLCD_D4_PIN , DIO_uint8_LOW) ;
		/* Send the Enable pulse to the CLCD */
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_HIGH) ;
		_delay_ms(2) ;
		DIO_uint8SetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_uint8_LOW) ;
		_delay_ms(2) ;
		/* Display control on\off */
		CLCD_VoidSendCommand(DISPLAYCONTROLCOMMAND) ;
		/* Display clear */
		CLCD_VoidSendCommand(DISPLAYCLEARCOMMAND) ;
		_delay_ms(2) ;
	#endif
}
void CLCD_VoidSendString (const char *Copy_pChString)
{
	uint8 Local_uint8Counter ;
	for (Local_uint8Counter = 0 ; Copy_pChString[Local_uint8Counter] != '\0' ; Local_uint8Counter++)
	{
		if (Global_uint8i < 16 && Global_uint8RowPos == 0)
		{
			CLCD_VoidGoToXY(Global_uint8i , Global_uint8RowPos) ;
			CLCD_VoidSendData (Copy_pChString[Local_uint8Counter]) ;
			Global_uint8i++ ;
			if (Global_uint8i == 16)
			{
				Global_uint8i = 0 , Global_uint8RowPos = 1 ;
			}
		}
		else if (Global_uint8i < 16 && Global_uint8RowPos == 1)
		{
			CLCD_VoidGoToXY(Global_uint8i , Global_uint8RowPos) ;
			CLCD_VoidSendData (Copy_pChString[Local_uint8Counter]) ;
			Global_uint8i++ ;
			if (Global_uint8i == 16)
			{
				Global_uint8i = 0 , Global_uint8RowPos = 0 ;
			}
		}
	}
	Global_uint8i = 0 ; Global_uint8RowPos = 0 ;
}
void CLCD_VoidSendString_XY (const char *Copy_pChString , uint8 Copy_XPos , uint8 Copy_YPos)
{
	uint8 Local_uint8Counter ;
	Global_uint8i = Copy_XPos , Global_uint8RowPos = Copy_YPos ;
	for (Local_uint8Counter = 0 ; Copy_pChString[Local_uint8Counter] != '\0' ; Local_uint8Counter++)
	{
		if (Global_uint8i < 16 && Global_uint8RowPos == 0)
		{
			CLCD_VoidGoToXY(Global_uint8i , Global_uint8RowPos) ;
			CLCD_VoidSendData (Copy_pChString[Local_uint8Counter]) ;
			Global_uint8i++ ;
			if (Global_uint8i == 16)
			{
				Global_uint8i = 0 , Global_uint8RowPos = 1 ;
			}
		}
		else if (Global_uint8i < 16 && Global_uint8RowPos == 1)
		{
			CLCD_VoidGoToXY(Global_uint8i , Global_uint8RowPos) ;
			CLCD_VoidSendData (Copy_pChString[Local_uint8Counter]) ;
			Global_uint8i++ ;
			if (Global_uint8i == 16)
			{
				Global_uint8i = 0 , Global_uint8RowPos = 0 ;
			}
		}
	}
	Global_uint8i = 0 ; Global_uint8RowPos = 0 ;
}
void CLCD_VoidSendNumber (uint32 Copy_uint32Number)
{
	char str[10] ;
	inttostring(str , Copy_uint32Number) ;
	CLCD_VoidSendString(str) ;
}
void CLCD_VoidSendNumber_XY (uint32 Copy_uint32Number , uint8 Copy_XPos , uint8 Copy_YPos)
{
	char str[10] ;
	inttostring(str , Copy_uint32Number) ;
	CLCD_VoidSendString_XY(str , Copy_XPos , Copy_YPos) ;
}
void CLCD_VoidGoToXY (uint8 Copy_uint8XPos , uint8 Copy_uint8YPos)
{
	/* Calculate DDRAM address */
	uint8 Local_uint8DDRAM_Adrress = Copy_uint8XPos + ROW1_ADDRESS * Copy_uint8YPos ;
	/* Set bit 7 for setDDRAM Address command */
	CLCD_VoidSendCommand(SET_BIT(Local_uint8DDRAM_Adrress , 7)) ;
}
void CLCD_VoidWriteSpecialChar (uint8 * Copy_uint8Pattern , uint8 Copy_uint8PatternNumber , uint8 Copy_uint8XPos , uint8 Copy_uint8YPos)
{
	uint8 Local_uint8Counter ;
	/* Calculate CGRAM address */
	uint8 Local_uint8CGRAM_Adrress = Copy_uint8PatternNumber * 8 ;
	/* Set bit 6 for setCGRAM Address command */
	CLCD_VoidSendCommand(SET_BIT(Local_uint8CGRAM_Adrress , 6)) ;
	/* Write the pattern on CGRAM */
	for (Local_uint8Counter = 0 ; Local_uint8Counter < 8 ; Local_uint8Counter++)
	{
		CLCD_VoidSendData(Copy_uint8Pattern[Local_uint8Counter]) ;
	}
	/* Back to DDRAM to display */
	CLCD_VoidGoToXY(Copy_uint8XPos , Copy_uint8YPos) ;
	/* Display special char */
	CLCD_VoidSendData(Copy_uint8PatternNumber) ;
}
