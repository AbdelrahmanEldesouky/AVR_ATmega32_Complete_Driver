/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: GIE						************/
/************		Date: 25-10-2020				************/
/************		Version: 2.00					************/
/***************************************************************/
/***************************************************************/

#include "../../4_LIBRARY/STD_TYPE.h"
#include "../../4_LIBRARY/BIT_MATH.h"

#include "GIE_INTERFACE.h"
#include "GIE_REGISTER.h"

/*
 * @breif:	GIE_VoidEnable() is a function that used to enable General Interrupt Enable (GIE)
 * @para:	void
 * @return: void
 */
void GIE_VoidEnable (void)
{
	SET_BIT (SREG , SREG_I) ;
}

/*
 * @breif:	GIE_VoidDisable() is a function that used to disable General Interrupt Enable (GIE)
 * @para:	void
 * @return: void
 */
void GIE_VoidDisable (void)
{
	CLR_BIT (SREG , SREG_I) ;
}
