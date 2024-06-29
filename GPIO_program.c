/*********************************************
 * Author:				seif gendy
 * Creation Data:		28 Feb, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  1 MARCH, 2024	      seif gendy		  ADDING APIS (APPLICATION PUBLIC/PROGRAM INTERFACE)
*********************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"
#include "../include/GPIO_private.h"
#include "../include/GPIO_config.h"

void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode)
{
	/* Check For The Port Name*/
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			// Bit Masking
			GPIOA_MODER &= ~(MODER_MASK << (Copy_u8PinNumber * PIN_OFFSET));
			GPIOA_MODER |= (Copy_u8PinMode << ((Copy_u8PinNumber * PIN_OFFSET)));
		break;
		
		case GPIO_PORTB:
			GPIOB_MODER &= ~(MODER_MASK << (Copy_u8PinNumber * PIN_OFFSET));
			GPIOB_MODER |= (Copy_u8PinMode << ((Copy_u8PinNumber * PIN_OFFSET)));

		break;
		
		case GPIO_PORTC:
		GPIOC_MODER &= ~(MODER_MASK << (Copy_u8PinNumber * PIN_OFFSET));
		GPIOC_MODER |= (Copy_u8PinMode << ((Copy_u8PinNumber * PIN_OFFSET)));
		break;
		
		default:
			// Error
		break;
	}
}

void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinSpeed)
{
	/* Check For The Port Name*/
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			// Bit Masking
			GPIOA_OSPEEDR &= ~(OSPEEDR_MASK << (Copy_u8PinNumber * PIN_OFFSET));
			GPIOA_OSPEEDR |= (Copy_u8PinSpeed << ((Copy_u8PinNumber * PIN_OFFSET)));
		break;
		
		case GPIO_PORTB:

		GPIOB_OSPEEDR &= ~(OSPEEDR_MASK << (Copy_u8PinNumber * PIN_OFFSET));
		GPIOB_OSPEEDR |= (Copy_u8PinSpeed << ((Copy_u8PinNumber * PIN_OFFSET)));
		break;
		
		case GPIO_PORTC:
		GPIOC_OSPEEDR &= ~(OSPEEDR_MASK << (Copy_u8PinNumber * PIN_OFFSET));
		GPIOC_OSPEEDR |= (Copy_u8PinSpeed << ((Copy_u8PinNumber * PIN_OFFSET)));
		break;
		
		default:
			// Error
		break;
	}
}



void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinOutputType)
{
	/* Check For The Port Name*/
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			// Bit Masking
			GPIOA_OTYPER &= ~(OTYPE_MASK << Copy_u8PinNumber);
			GPIOA_OTYPER |= (Copy_u8PinOutputType << Copy_u8PinNumber);
		break;
		
		case GPIO_PORTB:
		GPIOB_OTYPER &= ~(OTYPE_MASK << Copy_u8PinNumber);
		GPIOB_OTYPER |= (Copy_u8PinOutputType << Copy_u8PinNumber);
		break;
		
		case GPIO_PORTC:
		GPIOC_OTYPER &= ~(OTYPE_MASK << Copy_u8PinNumber);
		GPIOC_OTYPER |= (Copy_u8PinOutputType << Copy_u8PinNumber);
		break;
		
		default:
			// Error
		break;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
/* Check For The Port Name*/
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			switch(Copy_u8PinValue)
			{
				case GPIO_PIN_LOW:
					//SET_BIT(GPIOA_BSRR, (Copy_u8PinNumber+16));
					GPIOA_BSRR = 1 << (Copy_u8PinNumber+16);
				break;
				
				case GPIO_PIN_HIGH:
					//SET_BIT(GPIOA_BSRR, Copy_u8PinNumber);
					GPIOA_BSRR = 1 << Copy_u8PinNumber;
				break;
				
				case GPIO_PIN_TOGGLE:
					TOG_BIT(GPIOA_ODR, Copy_u8PinNumber);
				break;

				default:
					// Error
				break;
			}
		break;
		
		case GPIO_PORTB:
               switch(Copy_u8PinValue)
			{
				case GPIO_PIN_LOW:
					//SET_BIT(GPIOA_BSRR, (Copy_u8PinNumber+16));
					GPIOB_BSRR = 1 << (Copy_u8PinNumber+16);
				break;
				
				case GPIO_PIN_HIGH:
					//SET_BIT(GPIOA_BSRR, Copy_u8PinNumber);
					GPIOB_BSRR = 1 << Copy_u8PinNumber;
				break;
				case GPIO_PIN_TOGGLE:
						TOG_BIT(GPIOB_ODR, Copy_u8PinNumber);
					break;
				default:
					// Error
				break;
			}




		break;
		
		case GPIO_PORTC:

switch(Copy_u8PinValue)
			{
				case GPIO_PIN_LOW:
					//SET_BIT(GPIOA_BSRR, (Copy_u8PinNumber+16));
					GPIOC_BSRR = 1 << (Copy_u8PinNumber+16);
				break;
				
				case GPIO_PIN_HIGH:
					//SET_BIT(GPIOA_BSRR, Copy_u8PinNumber);
					GPIOC_BSRR = 1 << Copy_u8PinNumber;
				break;
				case GPIO_PIN_TOGGLE:
						TOG_BIT(GPIOC_ODR, Copy_u8PinNumber);
					break;
				default:
					// Error
				break;
			}

		break;
		
		default:
			// Error
		break;
	}
}











void GPIO_voidSetInputPinState(u8 Copy_u8Port, u8 Copy_u8InputPin, u8 Copy_u8State)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && Copy_u8InputPin>=GPIO_PIN0 && Copy_u8InputPin<=GPIO_PIN15 && (Copy_u8State==No_PULL_UP_PULL_DOWN || Copy_u8State==PULL_UP || Copy_u8State==PULL_DOWN))
  {
    if(Copy_u8Port == GPIO_PORTA)
    {
       GPIOA_PUPDR &= ~ (INPUT_PIN_STATE_MASK << (Copy_u8InputPin*PIN_OFFSET));
       GPIOA_PUPDR |= (Copy_u8State << (Copy_u8InputPin*PIN_OFFSET));
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
       GPIOB_PUPDR &= ~ (INPUT_PIN_STATE_MASK << (Copy_u8InputPin*PIN_OFFSET));
       GPIOB_PUPDR |= (Copy_u8State << (Copy_u8InputPin*PIN_OFFSET));
    }

    else if(Copy_u8Port == GPIO_PORTC && Copy_u8InputPin>=GPIO_PIN13 && Copy_u8InputPin<=GPIO_PIN15)
    {
       GPIOC_PUPDR &= ~ (INPUT_PIN_STATE_MASK << (Copy_u8InputPin*PIN_OFFSET));
       GPIOC_PUPDR |= (Copy_u8State << (Copy_u8InputPin*PIN_OFFSET));
    }
  }

  else
  {
    // error
  }
}


u8 GPIO_u8GetInputPinValue(u8 Copy_u8Port, u8 Copy_u8InputPin)
{
  if(Copy_u8Port>=GPIO_PORTA && Copy_u8Port<=GPIO_PORTC && Copy_u8InputPin>=GPIO_PIN0 && Copy_u8InputPin<=GPIO_PIN15)
  {
    u8 LOC_u8PinValue;
    if(Copy_u8Port == GPIO_PORTA)
    {
       LOC_u8PinValue = GET_BIT(GPIOA_IDR, Copy_u8InputPin);
    }

    else if(Copy_u8Port == GPIO_PORTB)
    {
       LOC_u8PinValue = GET_BIT(GPIOB_IDR, Copy_u8InputPin);
    }

    else if(Copy_u8Port == GPIO_PORTC && Copy_u8InputPin>=GPIO_PIN13 && Copy_u8InputPin<=GPIO_PIN15)
    {
       LOC_u8PinValue = GET_BIT(GPIOC_IDR, Copy_u8InputPin);
    }
    return LOC_u8PinValue;
  }

  else
  {
    // error
  }
}

/**
 * @brief A Function to set the alternative function for a pin
 * 
 * @param Copy_u8PortName: GPIO_PORTA, GPIO_PORTB, GPIO_PORTC
 * @param Copy_u8PinNumber: GPIO_PIN0, GPIO_PIN1, ..., GPIO_PIN15 
 * @param Copy_u8AlternativeFunction: GPIO_AF00, GPIO_AF01, ..., GPIO_AF15
 */
//i will recieve in the third argument smth like 1101 , 1110 ,...

/*
#define     AF_MASK					0b1111
#define     AF_BITS_OFFSET			4
#define     AF_HIGH_BITS_OFFSET		8
*/

void MGPIO_voidSetAlternativeFunction(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8AlternativeFunction)
{
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			// Check for the pin part
			if(Copy_u8PinNumber <= GPIO_PIN7 && Copy_u8PinNumber >= GPIO_PIN0)
			{
				// Clear the 4 bits associated for that pin (Bit Masking)
				GPIOA_AFRL &= ~(AF_MASK << (Copy_u8PinNumber * AF_BITS_OFFSET));
				// Set the Alternative function number in the bits
				GPIOA_AFRL |= (Copy_u8AlternativeFunction << (Copy_u8PinNumber * AF_BITS_OFFSET));
			}//second 8 pins
			else if(Copy_u8PinNumber <= GPIO_PIN15 && Copy_u8PinNumber >= GPIO_PIN8)
			{
				// Clear the 4 bits associated for that pin (Bit Masking)
				GPIOA_AFRH &= ~(AF_MASK << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) * AF_BITS_OFFSET));
				// Set the Alternative function number in the bits
				GPIOA_AFRH |= (Copy_u8AlternativeFunction << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) * AF_BITS_OFFSET));
			}
			else
			{
				// Error
			}
		break;
		
		case GPIO_PORTB:

			// Check for the pin part
			if(Copy_u8PinNumber <= GPIO_PIN7 && Copy_u8PinNumber >= GPIO_PIN0)
			{
				// Clear the 4 bits associated for that pin (Bit Masking)
				GPIOB_AFRL &= ~(AF_MASK << (Copy_u8PinNumber * AF_BITS_OFFSET));
				// Set the Alternative function number in the bits
				GPIOB_AFRL |= (Copy_u8AlternativeFunction << (Copy_u8PinNumber * AF_BITS_OFFSET));
			}//second 8 pins
			else if(Copy_u8PinNumber <= GPIO_PIN15 && Copy_u8PinNumber >= GPIO_PIN8)
			{
				// Clear the 4 bits associated for that pin (Bit Masking)
				GPIOB_AFRH &= ~(AF_MASK << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) * AF_BITS_OFFSET));
				// Set the Alternative function number in the bits
				GPIOB_AFRH |= (Copy_u8AlternativeFunction << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) * AF_BITS_OFFSET));
			}
			else
			{
				// Error
			}



		break;

		case GPIO_PORTC:
			// Check for the pin part
			if(Copy_u8PinNumber <= GPIO_PIN7 && Copy_u8PinNumber >= GPIO_PIN0)
			{
				// Clear the 4 bits associated for that pin (Bit Masking)
				GPIOC_AFRL &= ~(AF_MASK << (Copy_u8PinNumber * AF_BITS_OFFSET));
				// Set the Alternative function number in the bits
				GPIOC_AFRL |= (Copy_u8AlternativeFunction << (Copy_u8PinNumber * AF_BITS_OFFSET));
			}//second 8 pins
			else if(Copy_u8PinNumber <= GPIO_PIN15 && Copy_u8PinNumber >= GPIO_PIN8)
			{
				// Clear the 4 bits associated for that pin (Bit Masking)
				GPIOC_AFRH &= ~(AF_MASK << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) * AF_BITS_OFFSET));
				// Set the Alternative function number in the bits
				GPIOC_AFRH |= (Copy_u8AlternativeFunction << ((Copy_u8PinNumber-AF_HIGH_BITS_OFFSET) * AF_BITS_OFFSET));
			}
			else
			{
				// Error
			}


		break;

		default:
			// Error
		break;
	}
}


















/*

 MGPIO_voidSetPinInputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinInputType)
 {
	      u8 first_pin =  2*Copy_u8PinNumber    ;
	      u8 second_pin = first_pin + 1      ;


	 	 switch (Copy_u8PortName)
	 	 {


	 		 case GPIO_PORTA :

	 	 if (Copy_u8PinInputType == GPIO_INPUT_PULLDOWN)
	 	 {
	 		 CLR_BIT(GPIOA_PUPDR , first_pin);
	 		 SET_BIT(GPIOA_PUPDR , second_pin);
	 	}

	 	 if ( Copy_u8PinInputType == GPIO_INPUT_PULLUP)
	 	 {
	 		 SET_BIT(GPIOA_PUPDR , first_pin);
	 		 CLR_BIT(GPIOA_PUPDR , second_pin);
	 	}



	 	break ;


	 	 case GPIO_PORTB :
		 	 if (Copy_u8PinInputType == GPIO_INPUT_PULLDOWN)
		 	 {
		 		 CLR_BIT(GPIOB_PUPDR , first_pin);
		 		 SET_BIT(GPIOB_PUPDR , second_pin);
		 	}

		 	 if ( Copy_u8PinInputType == GPIO_INPUT_PULLUP)
		 	 {
		 		 SET_BIT(GPIOB_PUPDR , first_pin);
		 		 CLR_BIT(GPIOB_PUPDR , second_pin);
		 	}



	 	break ;

	 	 case GPIO_PORTC :

		 	 if (Copy_u8PinInputType == GPIO_INPUT_PULLDOWN)
		 	 {
		 		 CLR_BIT(GPIOC_PUPDR , first_pin);
		 		 SET_BIT(GPIOC_PUPDR , second_pin);
		 	}

		 	 if ( Copy_u8PinInputType == GPIO_INPUT_PULLUP)
		 	 {
		 		 SET_BIT(GPIOC_PUPDR , first_pin);
		 		 CLR_BIT(GPIOC_PUPDR , second_pin);
		 	}


	 	break ;




	 	 }

 }



 u8 MGPIO_voidReadPinInputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber)

 {

	u8 return_value = 0 ;


	 switch (Copy_u8PortName)
	 {


	 case GPIO_PORTA :

return_value = GET_BIT(GPIOA_IDR,Copy_u8PinNumber);
if (return_value == 0)
{
	return 0 ;
}
else if (return_value == 1)
{

	return 1 ;
}
 break;


	 case GPIO_PORTB :
			return_value = GET_BIT(GPIOB_IDR,Copy_u8PinNumber);
	if (return_value == 0)
	{
		return 0 ;
	}
	else if (return_value == 1)
	{

		return 1 ;
	}


		 break;

	 case GPIO_PORTC :
			return_value = GET_BIT(GPIOC_IDR,Copy_u8PinNumber);
	if (return_value == 0)
	{
		return 0 ;
	}
	else if (return_value == 1)
	{

		return 1 ;
	}

	 break;
 }
 }

*/


