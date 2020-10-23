/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: KPD						************/
/************		Date: 1-9-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#include "../../1_MCAL/1_GPIO/GPIO_INTERFACE.h"
#include "STD_TYPE.h"

#include "PORT_INTERFACE.h"

#include "KPD_CONFIG.h"
#include "KPD_INTERFACE.h"
#include "KPD_PRIVET.h"

uint8 KPD_uint8GetPressedKey (void)
{
	uint8 Local_uint8ROWi , Local_uint8COLi , Local_uint8PressedKey = NOT_PRESSED_KEY , Local_uint8PinState ;
	uint8 Local_uint8KPD_ARR[ROW_NUMBER][COL_NUMBER] = KPD_BUTTONS_VAL ;
	uint8 Local_uint8COL_ARR[COL_NUMBER] = COL_PINS ;
	uint8 Local_uint8ROW_ARR[ROW_NUMBER] = ROW_PINS ;

	for (Local_uint8COLi = 0 ; Local_uint8COLi < COL_NUMBER ; Local_uint8COLi++)
	{
		/* Activate current column */
		DIO_uint8SetPinValue(KPD_PORT , Local_uint8COL_ARR[Local_uint8COLi] , DIO_uint8_LOW) ;

		for (Local_uint8ROWi = 0 ; Local_uint8ROWi < ROW_NUMBER ; Local_uint8ROWi++)
		{
			/* Read current row */
			DIO_uint8GetPinValue(KPD_PORT , Local_uint8ROW_ARR[Local_uint8ROWi] , &Local_uint8PinState) ;

			if (Local_uint8PinState == DIO_uint8_LOW)
			{
				Local_uint8PressedKey = Local_uint8KPD_ARR[Local_uint8ROWi][Local_uint8COLi] ;

				/* Polling until the key is released */
				while (Local_uint8PinState == DIO_uint8_LOW)
				{
					DIO_uint8GetPinValue(KPD_PORT , Local_uint8ROW_ARR[Local_uint8ROWi] , &Local_uint8PinState) ;
				}
				return Local_uint8PressedKey ;
			}
		}
		/* Deactivate current column */
		DIO_uint8SetPinValue(KPD_PORT , Local_uint8COL_ARR[Local_uint8COLi] , DIO_uint8_HIGH) ;
	}

	return NOT_PRESSED_KEY ;
}
