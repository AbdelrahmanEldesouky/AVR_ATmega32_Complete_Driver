#include "STD_TYPE.h"

uint8 Global_uint8i ;
#define ZERO		0
#define ONE			1
void inttostring (char * str, uint32 Copy_Number)
{
	uint8 Local_uint8rem, Local_uint8len = 0 ;
	uint32 Local_CopyNum ;

	Local_CopyNum = Copy_Number ;
	while (Local_CopyNum != 0)
	{
		Local_uint8len++ ;
		Local_CopyNum /= 10 ;
	}
	for (Global_uint8i = 0 ; Global_uint8i < Local_uint8len ; Global_uint8i++)
	{
		Local_uint8rem = Copy_Number % 10 ;
		Copy_Number = Copy_Number / 10 ;
		str[Local_uint8len - (Global_uint8i + 1)] = Local_uint8rem + '0';
	}
	if(Local_uint8len == ZERO)
	{
		str[ZERO] = '0' ;
		str[ONE] = '\0' ;
	}
	else
	{
		str[Local_uint8len] = '\0';
	}
}
void stringtoint (char * str, int num)
{

}
