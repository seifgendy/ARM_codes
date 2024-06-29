/*********************************************
 * Author:				SEIF GENDY
 * Creation Data:		09 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  09 Mar, 2024	     SEIF GENDY		        Initial Creation
*********************************************/

#ifndef STK_config_H
#define STK_config_H

// Control STK Power.
// There Are Two Options: [STK_ENABLE, STK_DISABLE].

  #define STK_POWER  STK_ENABLE


// Select STK Clock Source.
// There Are Two Options: [STK_AHB_DIV_1, STK_AHB_DIV_8].

  #define STK_SRC_CLK  STK_AHB_DIV_8


// Control STK Interrupt.
// There Are Two Options: [STK_ENABLE, STK_DISABLE].

  #define STK_INTERRUPT  STK_DISABLE

#endif
