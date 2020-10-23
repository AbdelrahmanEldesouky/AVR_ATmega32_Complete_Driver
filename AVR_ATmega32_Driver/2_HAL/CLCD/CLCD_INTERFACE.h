/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: HAL						************/
/************		SWC: CLCD						************/
/************		Date: 25-8-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

	void CLCD_VoidInit (void) ;
	void CLCD_VoidSendCommand (uint8 Copy_Command) ;
	void CLCD_VoidSendData (uint8 Copy_Data) ;
	void CLCD_VoidSendString (const char *Copy_pChString) ;
	void CLCD_VoidSendString_XY (const char *Copy_pChString , uint8 Copy_XPos , uint8 Copy_YPos) ;
	void CLCD_VoidSendNumber (uint32 Copy_uint32Number) ;
	void CLCD_VoidSendNumber_XY (uint32 Copy_uint32Number , uint8 Copy_XPos , uint8 Copy_YPos) ;
	void CLCD_VoidGoToXY (uint8 Copy_uint8XPos , uint8 Copy_uint8YPos) ;
	void CLCD_VoidWriteSpecialChar (uint8 * Copy_uint8Pattern , uint8 Copy_uint8PatternNumber , uint8 Copy_uint8XPos , uint8 Copy_uint8YPos);

#endif
