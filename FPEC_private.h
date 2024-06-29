
/*****************************************************************************************
* Author:				seif gendy
* Creation Data:		5 may, 2024
* Version:				v1.0
* Compiler:				GNU ARM-GCC
* Controller:			STM32F401CCU6 (32-bit Architecture)
* Processor:			Cortex M4 (32-bit Architecture)
* Layer:				MCAL Layer
*****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  5 may, 2024	      seif gendy		  Initial Creation
*****************************************************************************************/
#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H


typedef struct
{
	volatile u32 ACR;
    volatile u32 KEYR;
    volatile u32 OPTKEYR;
    volatile u32 SR;
    volatile u32 CR;
    volatile u32 OPTCR;
}FPEC_t;

#define     FPEC    ((volatile FPEC_t *) 0x40023C00)

#define KEY1    0x45670123
#define KEY2    0xCDEF89AB

#endif