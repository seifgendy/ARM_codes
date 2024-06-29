/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		29 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  6 abril, 2024	    seif gendy		  Initial Creation
*********************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H



//exti registers 
// 0x40013C00
typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

#define     EXTI                     ((volatile EXTI_t *)0x40013C00)
//the register that is not in the EXTI section in the data sheet 
//that help me choosing the port of the chhosed pin wether a or b or c
#define     SYSCFG_EXTICR1          *((volatile u32 *)(0x40013800+0x08))
#define     SYSCFG_EXTICR2          *((volatile u32 *)(0x40013800+0x0C))
#define     SYSCFG_EXTICR3          *((volatile u32 *)(0x40013800+0x10))
#define     SYSCFG_EXTICR4          *((volatile u32 *)(0x40013800+0x14))




#endif
