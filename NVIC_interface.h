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
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

//used in prehiral interrupt control function
#define     MNVIC_INT_DISABLE       0
#define     MNVIC_INT_ENABLE        1



//initialize the group and sub priority for each interrupt
//user choose from table 51 4.4.5   
void MNVIC_voidInit(void);

void MNVIC_voidPeripheralInterruptControl(u8 Copy_u8PeripheralID, u8 Copy_u8InterruptState);

void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID);

void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority);

#endif