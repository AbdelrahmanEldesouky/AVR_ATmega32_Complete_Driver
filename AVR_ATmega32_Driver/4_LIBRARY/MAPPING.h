/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: LIBRARY						************/
/************		SWC: MAPPING						************/
/************		Date: 4-10-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/

#ifndef MAPPING_H_
#define MAPPING_H_

	typedef struct
	{
		int32 Copy_int32InputMin ;
		int32 Copy_int32InputMax ;
		int32 Copy_int32OutputMin ;
		int32 Copy_int32OutputMax ;
		int32 Copy_int32InputValue ;
	}MAPPING_CONFIG ;

	int32 MAPPING_int32GetOutput (MAPPING_CONFIG * mapping_config) ;
	
#endif
