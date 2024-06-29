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
 * v2.0    09 april, 2024	     SEIF GENDY		    adding more APIs
*********************************************/





# include "../include/STD_TYPES.h"
# include "../include/BIT_MATH.h"




# include "../include/STK_interface.h"
# include "../include/STK_private.h"
# include "../include/STK_config.h"

/*
#define SINGLE_INTERVAL   0
#define PERIODIC_INTERVAL 1
*/

//a function i just created to carry the address of the recieved functio
//from set interval function and i initiate it with null to avoid pointing to wrong address
static void (*pNotificationFunction)(void) = NULLPTR;
//this flag is used in case of single interrupt and i donot want to fire the 
//interrupt multiple times so i check on it in the isr before execution 
static u8 u8IntervalTypeFlag = SINGLE_INTERVAL;

void MSTK_voidInit(void)
{
  // Select STK Clock Source (STK_AHB_DIV_1 or STK_AHB_DIV_8)
  #if STK_SRC_CLK == STK_AHB_DIV_1
     SET_BIT(STK->CTRL, STK_BIT_2);
  #elif STK_SRC_CLK == STK_AHB_DIV_8
     CLR_BIT(STK->CTRL, STK_BIT_2);
  #else
     #error "STK_CLOCK_SOURCE Configuration Error"
  #endif

  // Control STK Interrupt (Enable or Disable)
  #if STK_INTERRUPT == STK_ENABLE
     SET_BIT(STK->CTRL, STK_BIT_1);
  #elif STK_INTERRUPT == STK_DISABLE
     CLR_BIT(STK->CTRL, STK_BIT_1);
  #else
     #error "STK_Interrupt Configuration Error"
  #endif

  // Control STK Power (Enable or Disable)
  #if STK_POWER == STK_ENABLE
     SET_BIT(STK->CTRL, STK_BIT_0);
  #elif STK_POWER == STK_DISABLE
     CLR_BIT(STK->CTRL, STK_BIT_0);
  #else
     #error "STK_Power Configuration Error"
  #endif
}

//alternative of delay function
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	//load ticks values in the load register
   STK->LOAD =  Copy_u32Ticks;
   //wait for tick interrupt
   while(GET_BIT(STK->CTRL, STK_BIT_16) == ZERO);
   STK->VAL= 0;
}

//remaining time to be zero again
u32 MSTK_voidGetRemainingTime(void)
{
  return STK->VAL;
}

//elapsed time since timer started counting
u32 MSTK_voidGetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = STK->LOAD - STK->VAL;
    return Local_u32ElapsedTime;
}

// sec 4.5.3
void MSTK_voidResetTimer(void)
{
    STK -> VAL = ZERO;
}


void MSTK_voidSTKEnable(void)
{
	SET_BIT(STK->CTRL, STK_BIT_0);
}


void MSTK_voidSTKDisable(void)
{
	CLR_BIT(STK->CTRL, STK_BIT_0);
}

//4.5.2
//put the value of starting the decrement then give it to val 
//and decrement in val then see the value again from load to recount again 


void MSTK_voidSetPreloadValue(u32 Copy_u32PreloadValue)
{
    STK -> LOAD = Copy_u32PreloadValue;
}


//one shot timer
//it will recieve a pointer to function that it will put inside the isr
void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*CallBackFunction) (void))
{
	STK -> VAL = 0;
	CLR_BIT(STK->CTRL, 0);
	u8IntervalTypeFlag = SINGLE_INTERVAL;
	STK -> LOAD = Copy_u32Ticks;

	SET_BIT(STK->CTRL, 1);
	SET_BIT(STK->CTRL, 0);

	pNotificationFunction = CallBackFunction;
}


void MSTK_voidSetSingleInterval2(void (*CallBackFunction) (void))
{
    pNotificationFunction = CallBackFunction;
    u8IntervalTypeFlag = SINGLE_INTERVAL;
    SET_BIT(STK->CTRL, STK_BIT_0);
}


//multiple periodic timer to infinity
void MSTK_voidSetPeriodicInterval(void (*CallBackFunction) (void))
{
    pNotificationFunction = CallBackFunction;
	//setting the flag to distinguish it in isr
    u8IntervalTypeFlag = PERIODIC_INTERVAL;
}




// the isr that the systick will carry after finishing counting
//the isr will be called automaticly bec of MSTK_voidInit(void)
//that initiate the timerand this flag is fired by hardware i am just 
//putting in it the function to do after firing this interrupt 
//by calling either the single or periodic interval function 
//and in both cases i must clear the flag  
void SysTick_Handler(void)
{
    u8 LocalTempVar = ZERO;
	//if the called function was single then disable the timer 
    if(u8IntervalTypeFlag == SINGLE_INTERVAL)
    {
        // Disable Timer
        STK -> LOAD = ZERO;
        STK -> VAL = ZERO;
        CLR_BIT(STK->CTRL, STK_BIT_0);
    }
    if(pNotificationFunction != NULLPTR)
    {
        pNotificationFunction();
    }
    // Flag Clearance
	//a bit inside the 4.5.1 register that if read 
    //it clears the flag
    LocalTempVar = GET_BIT(STK -> CTRL, STK_BIT_16);
}
