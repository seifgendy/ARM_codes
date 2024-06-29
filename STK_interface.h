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
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

// STK Functions Prototypes
void MSTK_voidInit(void);    /* This Functiontion used to Control Systick (NOTE: This is Pre-Build).
                               And it can be controlled by "STK_config.h".             */

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
u32 MSTK_voidGetRemainingTime(void);
u32 MSTK_voidGetElapsedTime(void);
void MSTK_voidResetTimer(void);
void MSTK_voidSTKEnable(void);
void MSTK_voidSTKDisable(void);
void MSTK_voidSetPreloadValue(u32 Copy_u32PreloadValue);
void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*CallBackFunction) (void));
void MSTK_voidSetPeriodicInterval(void (*CallBackFunction) (void));
void SysTick_Handler(void);

void MSTK_voidSetSingleInterval2(void (*CallBackFunction) (void));



#endif
