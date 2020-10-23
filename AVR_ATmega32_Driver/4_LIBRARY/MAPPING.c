/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: LIBRARY						************/
/************		SWC: MAPPING						************/
/************		Date: 4-10-2020					************/
/************		Version: 1.00					************/
/***************************************************************/
/***************************************************************/
#include "STD_TYPE.h"
#include "MAPPING.h"

int32 MAPPING_int32GetOutput (MAPPING_CONFIG * mapping_config)
{
	int32 Local_int32OutputValue ;
	Local_int32OutputValue = ((((mapping_config->Copy_int32InputValue - mapping_config->Copy_int32InputMin) * (mapping_config->Copy_int32OutputMax - mapping_config->Copy_int32OutputMin)) / (mapping_config->Copy_int32InputMax - mapping_config->Copy_int32InputMin)) + mapping_config->Copy_int32OutputMin) ;
	return Local_int32OutputValue  ;
}
