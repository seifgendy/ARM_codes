/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		16 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  31 Mar, 2024	    seif gendy		       Initial Creation
*********************************************/
#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

/*
options:
    GRP_4_SUB_0_BITS
    GRP_3_SUB_1_BITS
    GRP_2_SUB_2_BITS
    GRP_1_SUB_3_BITS
    GRP_0_SUB_4_BITS
*/


//this register is used to chose how many bits we 
//will use to  represent the sub priority and group priority

#define     MNVIC_GRP_SUB_DISTRIBUTION       GRP_4_SUB_0_BITS


#endif