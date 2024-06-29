/*

 * main.c
 *
 *  Created on: Apr 7, 2024
 *      Author: A&G Computer World
 */




#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"


void led1 (void);
void led2 (void);



void main(void)
{
	    RCC_voidInit();
	    RCC_voidEnablePrephiralClock( RCC_AHB , RCC_AHB_GPIOAEN);
	    RCC_voidEnablePrephiralClock( RCC_AHB , RCC_AHB_GPIOBEN);
	    RCC_voidEnablePrephiralClock( RCC_APB2 ,RCC_APB2_SYSCF);

	    MGPIO_voidSetPinMode( GPIO_PORTA ,       GPIO_PIN0 ,  GPIO_INPUT );
	    GPIO_voidSetInputPinState(GPIO_PORTA, GPIO_PIN0, PULL_DOWN);

	    MGPIO_voidSetPinMode( GPIO_PORTB ,       GPIO_PIN3 ,  GPIO_INPUT );
	    GPIO_voidSetInputPinState(GPIO_PORTB, GPIO_PIN3, PULL_DOWN);



	    MGPIO_voidSetPinMode( GPIO_PORTA ,       GPIO_PIN1 ,  GPIO_OUTPUT );
	    MGPIO_voidSetPinOutputSpeed( GPIO_PORTA ,GPIO_PIN1 , GPIO_LOW_SPEED  );
	    MGPIO_voidSetPinOutputType( GPIO_PORTA , GPIO_PIN1 ,  GPIO_OUTPUT_PP );

	    MGPIO_voidSetPinMode( GPIO_PORTB ,       GPIO_PIN7 ,  GPIO_OUTPUT );
	    MGPIO_voidSetPinOutputSpeed( GPIO_PORTB ,GPIO_PIN7 , GPIO_LOW_SPEED  );
	    MGPIO_voidSetPinOutputType( GPIO_PORTB , GPIO_PIN7 ,  GPIO_OUTPUT_PP );




	    MNVIC_voidInit();
	    MNVIC_voidPeripheralInterruptControl(6, MNVIC_INT_ENABLE);
	    MNVIC_voidPeripheralInterruptControl(9, MNVIC_INT_ENABLE);



	    MEXTI_voidInit(EXTI_PORTA   , EXTI_PIN0);
	//  MEXTI_voidInit(EXTI_PORTA   , EXTI_PIN1);
	//  MEXTI_voidInit(EXTI_PORTB   , EXTI_PIN0);
	    MEXTI_voidInit(EXTI_PORTB   , EXTI_PIN3);
	    MEXTI_voidEnableInterrupt(MEXTI_EXTI0 );
	    MEXTI_voidEnableInterrupt(MEXTI_EXTI3 );
	    MEXTI_voidChangeSenseMode(MEXTI_EXTI0, MEXTI_RISING);
	    MEXTI_voidChangeSenseMode(MEXTI_EXTI3, MEXTI_RISING);

	    MEXTI_voidSetCallBack(MEXTI_EXTI0, &led1);
	    MEXTI_voidSetCallBack(MEXTI_EXTI3, &led2);





while(1)
{

}

}


void led1 (void)
{
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_PIN_TOGGLE);
}

void led2 (void)
{
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN7, GPIO_PIN_TOGGLE);
}



