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
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{   
    //here i defined a register from outside the NVIC which violates the layered 
    //architecture principle but it is needed for the bits 8 9 10 
    //that set priority configurations (sub and group)
    #define SCB_AIRCR       *((volatile u32 *)0xE000ED00+0x0C)
    //Set The Group And Sub Priorities Distribution
    //we first must write password value in [16 31 bits] 
    //then we can change the bits [8 9 10 ] 
    SCB_AIRCR |= (AIRCR_PRIVKEY << 16) | (MNVIC_GRP_SUB_DISTRIBUTION << 8);
}


//enable and disable the and gate of the NVIC (active flag) 
//sec 4.3.2  ISER register for enable and ICER for disable 
void MNVIC_voidPeripheralInterruptControl(u8 Copy_u8PeripheralID, u8 Copy_u8InterruptState)
{
    u8 Local_u8RegisterIndex = 0;                     //A value from 0 to 7 
    Local_u8RegisterIndex = Copy_u8PeripheralID / 32; // i make two register index values one for the division out of 8 divisions and one for the division out of 32 division to select the bit of external prephiral required from the large NVIC_ICSR or ICER 240 bit register 
    switch(Copy_u8InterruptState)                     //example if i send 35 so local will be 35/32 =  1 which is the first division and the 1 will be shifted 35%32 = 3bits since 35 is the third in the second 32 bits
    {
        case MNVIC_INT_ENABLE:
            NVIC -> ISER[Local_u8RegisterIndex] = (1 << (Copy_u8PeripheralID % 32));
        break;
      // the enable register is differnt from the disable register 
        case MNVIC_INT_DISABLE:
            NVIC -> ICER[Local_u8RegisterIndex] = (1 << (Copy_u8PeripheralID % 32));
        break;
        
        default:
            // Error
        break;
    }
}



//4.3.4 
void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID)
{
    if(Copy_u8PeripheralID <= 239)
    {
        u8 Local_u8RegisterIndex = 0;
        Local_u8RegisterIndex = Copy_u8PeripheralID / 32;
        NVIC -> ISPR[Local_u8RegisterIndex] = (1 << ((Copy_u8PeripheralID % 32)));
    }
}



/*Task*/ 
void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID)
{


        u8 Local_u8RegisterIndex = 0;
        Local_u8RegisterIndex = Copy_u8PeripheralID / 32;
        NVIC -> ICPR[Local_u8RegisterIndex] = (1 << ((Copy_u8PeripheralID % 32)));


}




/*Task*/ 
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID)
{

        u8 Local_u8RegisterIndex = 0;
        Local_u8RegisterIndex = Copy_u8PeripheralID / 32;
        u8 bit_value = Copy_u8PeripheralID % 32;
        u8 register_value = NVIC -> IABR[Local_u8RegisterIndex];
        u32 returnedvalue = GET_BIT(  register_value ,bit_value);
        return returnedvalue ;
}


//60->32->8
//4.3.7 interrupt priority register to arrange priorities from 0 to 239 it has 60 register each one is 32bit each 32 is divided to 8 bits register in which i write the priority
//priority value is from 0 to 255 (since i have 4bits to write in )
void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority)
{
	NVIC -> IP[Copy_u8PeripheralID] = (Copy_u8Priority << 4); //four since first four are reserved 
}
