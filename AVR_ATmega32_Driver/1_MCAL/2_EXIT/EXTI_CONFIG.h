/***************************************************************/
/***************************************************************/
/************		Author: A. S. Eldesouky			************/
/************		Layer: MCAL						************/
/************		SWC: EXTI						************/
/************		Date: 25-10-2020				************/
/************		Version: 2.00					************/
/***************************************************************/
/***************************************************************/

/*File Gard*/
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

	/*
	 * Choose INT0 Sense Control
	 * 1. LOW_LEVEL
	 * 2. ON_CHANGE
	 * 3. FALLING_EDGE
	 * 4. RISING_EDGE
	 */
	#define EXTI_INT0_SENSE		FALLING_EDGE
	/*
	 * Choose INT1 Sense Control
	 * 1. LOW_LEVEL
	 * 2. ON_CHANGE
	 * 3. FALLING_EDGE
	 * 4. RISING_EDGE
	 */
	#define EXTI_INT1_SENSE		FALLING_EDGE
	/*
	 * Choose INT2 Sense Control
	 * 1. FALLING_EDGE
	 * 2. RISING_EDGE
	 */
	#define EXTI_INT2_SENSE		FALLING_EDGE

	/*
	 * Choose INT0 Initial State
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define EXTI_INT0_INITIAL_STATE		ENABLE
	/*
	 * Choose INT1 Initial State
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define EXTI_INT1_INITIAL_STATE		ENABLE
	/*
	 * Choose INT2 Initial State
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define EXTI_INT2_INITIAL_STATE		ENABLE

#endif /* EXTI_CONFIG_H_ */
