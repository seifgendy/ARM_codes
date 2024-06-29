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
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/EXTI_interface.h"
#include "../include/EXTI_private.h"
#include "../include/EXTI_config.h"

// static void (*EXTI0_pNotificationFunction)(void) = NULLPTR;
// static void (*EXTI1_pNotificationFunction)(void) = NULLPTR;

// Array Of Pointers to Function
//array of 16 func to the 16 interrupt (max number of interrupts at the same time)
//this array carryies the global functions that the setcallback func
//put in it the address of the function recieved from the main.c
static void (*EXTI_pNotificationFunction[16])(void) = {NULLPTR};




// Task
//the initiate function choose port of the pin that we choosed 
//this is the register that is out of the EXTI sec in the data sheet 
void MEXTI_voidInit(u8 EXTI_PORT_NAME  , u8 EXTI_pin_number)
{
    switch (EXTI_pin_number)
    {


    case EXTI_PIN0:
        
if  ( EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR1,0);
CLR_BIT (SYSCFG_EXTICR1,1);
CLR_BIT (SYSCFG_EXTICR1,2);
CLR_BIT (SYSCFG_EXTICR1,3);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR1,0);
CLR_BIT (SYSCFG_EXTICR1,1);
CLR_BIT (SYSCFG_EXTICR1,2);
CLR_BIT (SYSCFG_EXTICR1,3);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{

CLR_BIT (SYSCFG_EXTICR1,0);
SET_BIT (SYSCFG_EXTICR1,1);
CLR_BIT (SYSCFG_EXTICR1,2);
CLR_BIT (SYSCFG_EXTICR1,3);
}

 break;
    
    case EXTI_PIN1:
        
if  ( EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR1,4);
CLR_BIT (SYSCFG_EXTICR1,5);
CLR_BIT (SYSCFG_EXTICR1,6);
CLR_BIT (SYSCFG_EXTICR1,7);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR1,4);
CLR_BIT (SYSCFG_EXTICR1,5);
CLR_BIT (SYSCFG_EXTICR1,6);
CLR_BIT (SYSCFG_EXTICR1,7);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{

CLR_BIT (SYSCFG_EXTICR1,4);
SET_BIT (SYSCFG_EXTICR1,5);
CLR_BIT (SYSCFG_EXTICR1,6);
CLR_BIT (SYSCFG_EXTICR1,7);
}
 break;

    case EXTI_PIN2:
        
if  ( EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR1,8);
CLR_BIT (SYSCFG_EXTICR1,9);
CLR_BIT (SYSCFG_EXTICR1,10);
CLR_BIT (SYSCFG_EXTICR1,11);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR1,8);
CLR_BIT (SYSCFG_EXTICR1,9);
CLR_BIT (SYSCFG_EXTICR1,10);
CLR_BIT (SYSCFG_EXTICR1,11);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{
CLR_BIT (SYSCFG_EXTICR1,8);
SET_BIT (SYSCFG_EXTICR1,9);
CLR_BIT (SYSCFG_EXTICR1,10);
CLR_BIT (SYSCFG_EXTICR1,11);
}
 break;


    case EXTI_PIN3:
        
if  ( EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR1,12);
CLR_BIT (SYSCFG_EXTICR1,13);
CLR_BIT (SYSCFG_EXTICR1,14);
CLR_BIT (SYSCFG_EXTICR1,15);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR1,12);
CLR_BIT (SYSCFG_EXTICR1,13);
CLR_BIT (SYSCFG_EXTICR1,14);
CLR_BIT (SYSCFG_EXTICR1,15);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
	{
CLR_BIT (SYSCFG_EXTICR1,12);
SET_BIT (SYSCFG_EXTICR1,13);
CLR_BIT (SYSCFG_EXTICR1,14);
CLR_BIT (SYSCFG_EXTICR1,15);
	}
 break;

    case EXTI_PIN4:
        
if   (EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR2,0);
CLR_BIT (SYSCFG_EXTICR2,1);
CLR_BIT (SYSCFG_EXTICR2,2);
CLR_BIT (SYSCFG_EXTICR2,3);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR2,0);
CLR_BIT (SYSCFG_EXTICR2,1);
CLR_BIT (SYSCFG_EXTICR2,2);
CLR_BIT (SYSCFG_EXTICR2,3);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{

CLR_BIT (SYSCFG_EXTICR2,0);
SET_BIT (SYSCFG_EXTICR2,1);
CLR_BIT (SYSCFG_EXTICR2,2);
CLR_BIT (SYSCFG_EXTICR2,3);
}
 break;


     case EXTI_PIN5:
        
if   (EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR2,4);
CLR_BIT (SYSCFG_EXTICR2,5);
CLR_BIT (SYSCFG_EXTICR2,6);
CLR_BIT (SYSCFG_EXTICR2,7);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR2,4);
CLR_BIT (SYSCFG_EXTICR2,5);
CLR_BIT (SYSCFG_EXTICR2,6);
CLR_BIT (SYSCFG_EXTICR2,7);
}

else if (EXTI_PORT_NAME == EXTI_PORTC)
{

CLR_BIT (SYSCFG_EXTICR2,4);
SET_BIT (SYSCFG_EXTICR2,5);
CLR_BIT (SYSCFG_EXTICR2,6);
CLR_BIT (SYSCFG_EXTICR2,7);
}
 break;

    case EXTI_PIN6:
        
if   (EXTI_PORT_NAME == EXTI_PORTA)
		{
CLR_BIT (SYSCFG_EXTICR2,8);
CLR_BIT (SYSCFG_EXTICR2,9);
CLR_BIT (SYSCFG_EXTICR2,10);
CLR_BIT (SYSCFG_EXTICR2,11);
		}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR2,8);
CLR_BIT (SYSCFG_EXTICR2,9);
CLR_BIT (SYSCFG_EXTICR2,10);
CLR_BIT (SYSCFG_EXTICR2,11);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{

CLR_BIT (SYSCFG_EXTICR2,8);
SET_BIT (SYSCFG_EXTICR2,9);
CLR_BIT (SYSCFG_EXTICR2,10);
CLR_BIT (SYSCFG_EXTICR2,11);
}
 break;

    case EXTI_PIN7:
        
if   (EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR2,12);
CLR_BIT (SYSCFG_EXTICR2,13);
CLR_BIT (SYSCFG_EXTICR2,14);
CLR_BIT (SYSCFG_EXTICR2,15);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR2,12);
CLR_BIT (SYSCFG_EXTICR2,13);
CLR_BIT (SYSCFG_EXTICR2,14);
CLR_BIT (SYSCFG_EXTICR2,15);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{

CLR_BIT (SYSCFG_EXTICR2,12);
SET_BIT (SYSCFG_EXTICR2,13);
CLR_BIT (SYSCFG_EXTICR2,14);
CLR_BIT (SYSCFG_EXTICR2,15);
}
 break;

    case EXTI_PIN8:
        
if   (EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR3,0);
CLR_BIT (SYSCFG_EXTICR3,1);
CLR_BIT (SYSCFG_EXTICR3,2);
CLR_BIT (SYSCFG_EXTICR3,3);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR3,0);
CLR_BIT (SYSCFG_EXTICR3,1);
CLR_BIT (SYSCFG_EXTICR3,2);
CLR_BIT (SYSCFG_EXTICR3,3);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{

CLR_BIT (SYSCFG_EXTICR3,0);
SET_BIT (SYSCFG_EXTICR3,1);
CLR_BIT (SYSCFG_EXTICR3,2);
CLR_BIT (SYSCFG_EXTICR3,3);
}
 break;


     case EXTI_PIN9:
        
if   (EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR3,4);
CLR_BIT (SYSCFG_EXTICR3,5);
CLR_BIT (SYSCFG_EXTICR3,6);
CLR_BIT (SYSCFG_EXTICR3,7);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR3,4);
CLR_BIT (SYSCFG_EXTICR3,5);
CLR_BIT (SYSCFG_EXTICR3,6);
CLR_BIT (SYSCFG_EXTICR3,7);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{

CLR_BIT (SYSCFG_EXTICR3,4);
SET_BIT (SYSCFG_EXTICR3,5);
CLR_BIT (SYSCFG_EXTICR3,6);
CLR_BIT (SYSCFG_EXTICR3,7);
}
 break;

    case EXTI_PIN10:
        
if   (EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR3,8);
CLR_BIT (SYSCFG_EXTICR3,9);
CLR_BIT (SYSCFG_EXTICR3,10);
CLR_BIT (SYSCFG_EXTICR3,11);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR3,8);
CLR_BIT (SYSCFG_EXTICR3,9);
CLR_BIT (SYSCFG_EXTICR3,10);
CLR_BIT (SYSCFG_EXTICR3,11);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)

{
CLR_BIT (SYSCFG_EXTICR3,8);
SET_BIT (SYSCFG_EXTICR3,9);
CLR_BIT (SYSCFG_EXTICR3,10);
CLR_BIT (SYSCFG_EXTICR3,11);
}
 break;


    case EXTI_PIN11:
        
if  ( EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR3,12);
CLR_BIT (SYSCFG_EXTICR3,13);
CLR_BIT (SYSCFG_EXTICR3,14);
CLR_BIT (SYSCFG_EXTICR3,15);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR3,12);
CLR_BIT (SYSCFG_EXTICR3,13);
CLR_BIT (SYSCFG_EXTICR3,14);
CLR_BIT (SYSCFG_EXTICR3,15);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{

CLR_BIT (SYSCFG_EXTICR3,12);
SET_BIT (SYSCFG_EXTICR3,13);
CLR_BIT (SYSCFG_EXTICR3,14);
CLR_BIT (SYSCFG_EXTICR3,15);
}
 break;

    case EXTI_PIN12:
        
if   (EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR4,0);
CLR_BIT (SYSCFG_EXTICR4,1);
CLR_BIT (SYSCFG_EXTICR4,2);
CLR_BIT (SYSCFG_EXTICR4,3);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR4,0);
CLR_BIT (SYSCFG_EXTICR4,1);
CLR_BIT (SYSCFG_EXTICR4,2);
CLR_BIT (SYSCFG_EXTICR4,3);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{

CLR_BIT (SYSCFG_EXTICR4,0);
SET_BIT (SYSCFG_EXTICR4,1);
CLR_BIT (SYSCFG_EXTICR4,2);
CLR_BIT (SYSCFG_EXTICR4,3);
}
 break;


     case EXTI_PIN13:
        
if   (EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR4,4);
CLR_BIT (SYSCFG_EXTICR4,5);
CLR_BIT (SYSCFG_EXTICR4,6);
CLR_BIT (SYSCFG_EXTICR4,7);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR4,4);
CLR_BIT (SYSCFG_EXTICR4,5);
CLR_BIT (SYSCFG_EXTICR4,6);
CLR_BIT (SYSCFG_EXTICR4,7);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{

CLR_BIT (SYSCFG_EXTICR4,4);
SET_BIT (SYSCFG_EXTICR4,5);
CLR_BIT (SYSCFG_EXTICR4,6);
CLR_BIT (SYSCFG_EXTICR4,7);
}
 break;

    case EXTI_PIN14:
        
if  ( EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR4,8);
CLR_BIT (SYSCFG_EXTICR4,9);
CLR_BIT (SYSCFG_EXTICR4,10);
CLR_BIT (SYSCFG_EXTICR4,11);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR4,8);
CLR_BIT (SYSCFG_EXTICR4,9);
CLR_BIT (SYSCFG_EXTICR4,10);
CLR_BIT (SYSCFG_EXTICR4,11);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{

CLR_BIT (SYSCFG_EXTICR4,8);
SET_BIT (SYSCFG_EXTICR4,9);
CLR_BIT (SYSCFG_EXTICR4,10);
CLR_BIT (SYSCFG_EXTICR4,11);
}
 break;

    case EXTI_PIN15:
        
if  ( EXTI_PORT_NAME == EXTI_PORTA)
{
CLR_BIT (SYSCFG_EXTICR4,12);
CLR_BIT (SYSCFG_EXTICR4,13);
CLR_BIT (SYSCFG_EXTICR4,14);
CLR_BIT (SYSCFG_EXTICR4,15);
}
else if (EXTI_PORT_NAME == EXTI_PORTB)
{
SET_BIT (SYSCFG_EXTICR4,12);
CLR_BIT (SYSCFG_EXTICR4,13);
CLR_BIT (SYSCFG_EXTICR4,14);
CLR_BIT (SYSCFG_EXTICR4,15);
}
else if (EXTI_PORT_NAME == EXTI_PORTC)
{
CLR_BIT (SYSCFG_EXTICR4,12);
SET_BIT (SYSCFG_EXTICR4,13);
CLR_BIT (SYSCFG_EXTICR4,14);
CLR_BIT (SYSCFG_EXTICR4,15);
}
 break;



    default:
        break;
    }


}



//the data type is MEXTI_INTERRUPT_LINE_t and the var name Copy_tInterrupLine 
//i will send MEXTI_EXTI0 or MEXTI_EXTI1 or MEXTI_EXTI2  and so on  
void MEXTI_voidEnableInterrupt(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine)
{
    SET_BIT(EXTI->IMR, Copy_tInterrupLine);
}



void MEXTI_voidDisableInterrupt(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine)
{
    CLR_BIT(EXTI->IMR, Copy_tInterrupLine);
}


//set the interrupt enabling signal type 
//sec 10.3.3 10.3.4 
//the clr is just to make sure that the another mode is not set
//this function take the mode and the pin number 
void MEXTI_voidChangeSenseMode(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, MEXTI_INTERRUPT_SENSE_SIGNAL_t Copy_tSenseSignal)
{
    switch(Copy_tSenseSignal)
    {
        case MEXTI_RISING:
            CLR_BIT(EXTI->FTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->RTSR, Copy_tInterrupLine);
        break;

        case MEXTI_FALLING:
            CLR_BIT(EXTI->RTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->FTSR, Copy_tInterrupLine);
        break;

        case MEXTI_ONCHANGE:
            SET_BIT(EXTI->RTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->FTSR, Copy_tInterrupLine);
        break;

        default:
        break;
    }
}


//take the address of the isr function that the user just written in the main.c function
//and put the code of this function that he has its address 
//in the EXTI0_TRQHANDLER (example)  function to create an interrupt 

//all what this func do is to recieve the address of written function in
//main.c and put it in a global variable for this file to enable 
//the handler function to call it 
void MEXTI_voidSetCallBack(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, void (*pCallBackFunction)(void))
{
    switch(Copy_tInterrupLine)
    {
        case MEXTI_EXTI0:
            // EXTI0_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case MEXTI_EXTI1:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;


        case MEXTI_EXTI2:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;

        case MEXTI_EXTI3:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;

        case MEXTI_EXTI4:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;

        case MEXTI_EXTI5:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;

        case MEXTI_EXTI6:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;

        case MEXTI_EXTI7:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;

        case MEXTI_EXTI8:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;


        case MEXTI_EXTI9:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;


        case MEXTI_EXTI10:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;


        case MEXTI_EXTI11:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;


        case MEXTI_EXTI12:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;


        case MEXTI_EXTI13:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;


        case MEXTI_EXTI14:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;


        case MEXTI_EXTI15:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;








    }
}

// ISR For EXTI0
//this is the syntax of the isr of this interrupt but it  lacks 
//the code itself that we implement when the interrupt happen 
//so we give it the address of this function
void EXTI0_IRQHandler(void)
{
    // if(EXTI0_pNotificationFunction != NULLPTR)
    //to avoid segmenttation fault
    if(EXTI_pNotificationFunction[0] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[0]();
    }
    else
    {
        // Do Nothing
    }
    SET_BIT(EXTI->PR, 0);
}

// ISR For EXTI1
void EXTI1_IRQHandler(void)
{

  if(EXTI_pNotificationFunction[1] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[1]();
    }
    else
    {
        // Do Nothing
    }
  SET_BIT(EXTI->PR, 0);

}



// ISR For EXTI1
void EXTI2_IRQHandler(void)
{

  if(EXTI_pNotificationFunction[2] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[2]();
    }
    else
    {
        // Do Nothing
    }
  SET_BIT(EXTI->PR, 0);

}


// ISR For EXTI1
void EXTI3_IRQHandler(void)
{

  if(EXTI_pNotificationFunction[3] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[3]();
    }
    else
    {
        // Do Nothing
    }
  SET_BIT(EXTI->PR, 0);

}




// ISR For EXTI1
void EXTI4_IRQHandler(void)
{

  if(EXTI_pNotificationFunction[4] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[4]();
    }
    else
    {
        // Do Nothing
    }
  SET_BIT(EXTI->PR, 0);

}



// ISR For EXTI1
void EXTI9_5_IRQHandler(void)
{

  if(EXTI_pNotificationFunction[5] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[5]();
    }


    else if(EXTI_pNotificationFunction[6] != NULLPTR)
    {
        EXTI_pNotificationFunction[6]();
    }

  else if(EXTI_pNotificationFunction[7] != NULLPTR)
    {
        EXTI_pNotificationFunction[7]();
    }

      else if(EXTI_pNotificationFunction[8] != NULLPTR)
    {
        EXTI_pNotificationFunction[8]();
    }

  else if(EXTI_pNotificationFunction[9] != NULLPTR)
    {
        EXTI_pNotificationFunction[9]();
    }

}

void EXTI10_IRQHandler(void)
{

  if(EXTI_pNotificationFunction[10] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[10]();
    }
    else
    {
        // Do Nothing
    }
  SET_BIT(EXTI->PR, 0);

}


void EXTI11_IRQHandler(void)
{

  if(EXTI_pNotificationFunction[11] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[11]();
    }
    else
    {
        // Do Nothing
    }
  SET_BIT(EXTI->PR, 0);

}

void EXTI12_IRQHandler(void)
{

  if(EXTI_pNotificationFunction[12] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[12]();
    }
    else
    {
        // Do Nothing
    }
  SET_BIT(EXTI->PR, 0);

}

void EXTI13_IRQHandler(void)
{

  if(EXTI_pNotificationFunction[13] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[13]();
    }
    else
    {
        // Do Nothing
    }
  SET_BIT(EXTI->PR, 0);

}


void EXTI14_IRQHandler(void)
{

  if(EXTI_pNotificationFunction[14] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[14]();
    }
    else
    {
        // Do Nothing
    }
  SET_BIT(EXTI->PR, 0);

}


void EXTI15_IRQHandler(void)
{

  if(EXTI_pNotificationFunction[15] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[15]();
    }
    else
    {
        // Do Nothing
    }
  SET_BIT(EXTI->PR, 0);

}
