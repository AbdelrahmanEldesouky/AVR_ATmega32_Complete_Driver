/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: GIE						************/
/************		Date: 25-10-2020				************/
/************		Version: 2.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

	/*
	 * @breif:	GIE_VoidEnable() is a function that used to enable General Interrupt Enable (GIE)
	 * @para:	void
	 * @return: void
	 */
	void GIE_VoidEnable (void) ;

	/*
	 * @breif:	GIE_VoidDisable() is a function that used to disable General Interrupt Enable (GIE)
	 * @para:	void
	 * @return: void
	 */
	void GIE_VoidDisable (void) ;
	
#endif /*  GIE_INTERFACE_H_ */
