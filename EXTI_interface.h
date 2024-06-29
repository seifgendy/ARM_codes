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
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


//options to select the number of the bit that will be used to recieve the interrupt
//the enums substitute there members with a number = to there order
//to use it after defining it you write that this func is going to take this data type 
//and write the member name 
typedef enum
{
    MEXTI_EXTI0 = 0,
    MEXTI_EXTI1,
    MEXTI_EXTI2,
    MEXTI_EXTI3,
    MEXTI_EXTI4,
    MEXTI_EXTI5,
    MEXTI_EXTI6,
    MEXTI_EXTI7,
    MEXTI_EXTI8,
    MEXTI_EXTI9,
    MEXTI_EXTI10,
    MEXTI_EXTI11,
    MEXTI_EXTI12,
    MEXTI_EXTI13,
    MEXTI_EXTI14,
    MEXTI_EXTI15,
}MEXTI_INTERRUPT_LINE_t;



//options for the signal that enable the interrupt
typedef enum
{
    MEXTI_RISING = 0,
    MEXTI_FALLING,
    MEXTI_ONCHANGE
}MEXTI_INTERRUPT_SENSE_SIGNAL_t;


#define EXTI_PIN0           0
#define EXTI_PIN1           1
#define EXTI_PIN2           2

#define EXTI_PIN3           3
#define EXTI_PIN4           4
#define EXTI_PIN5           5

#define EXTI_PIN6           6
#define EXTI_PIN7           7
#define EXTI_PIN8           8

#define EXTI_PIN9            9
#define EXTI_PIN10           10

#define EXTI_PIN11           11
#define EXTI_PIN12           12

#define EXTI_PIN13           13
#define EXTI_PIN14           14
#define EXTI_PIN15           15


#define     EXTI_PORTA              1
#define     EXTI_PORTB              2
#define     EXTI_PORTC              3




void MEXTI_voidInit(u8 EXTI_PORT_NAME  , u8 EXTI_pin_number);
void MEXTI_voidEnableInterrupt(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine);
void MEXTI_voidDisableInterrupt(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine);
void MEXTI_voidChangeSenseMode(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, MEXTI_INTERRUPT_SENSE_SIGNAL_t Copy_tSenseSignal);
void MEXTI_voidSetCallBack(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, void (*pCallBackFunction)(void));

#endif
