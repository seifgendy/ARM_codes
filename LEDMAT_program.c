/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		22 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				HAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  2  april, 2024	seif gendy		       Initial Creation
*********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h" //my timer module for the delay func neccessary for controlling the fps


#include "LEDMAT_interface.h"
#include "LEDMAT_private.h"
#include "LEDMAT_config.h"


//(HLEDMAT_COL0_PORT_PIN) this indicates the pin in microcontroller that is 
//connected to the first coulmn pin of the led matrix 
//note that this function takes originally two inpunts the port register and the pin no. but 
//now i have made a macro that makes text replacment with the two req input info 
void HLEDMAT_voidInit(void)
{
    //Set 8 Columns Pins To Be Output 
    MGPIO_voidSetPinMode(HLEDMAT_COL0_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL1_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL2_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL3_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL4_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL5_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL6_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL7_PORT_PIN, GPIO_OUTPUT);

    //Set 8 Columns Pins To Be Output Push pull
    MGPIO_voidSetPinOutputType(HLEDMAT_COL0_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL1_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL2_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL3_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL4_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL5_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL6_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL7_PORT_PIN, GPIO_OUTPUT_PP);

    //Set 8 Columns Pin To Be Output Low Speed
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL0_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL1_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL2_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL3_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL4_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL5_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL6_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL7_PORT_PIN, GPIO_LOW_SPEED);


    //Set 8 Rows Pins To Be Output
    MGPIO_voidSetPinMode(HLEDMAT_ROW0_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW1_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW2_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW3_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW4_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW5_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW6_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW7_PORT_PIN, GPIO_OUTPUT);
    
    //Set 8 Rows Pins To Be Output PP
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW0_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW1_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW2_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW3_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW4_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW5_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW6_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW7_PORT_PIN, GPIO_OUTPUT_PP);

    //Set 8 Rows Pin To Be Output Low Speed
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW0_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW1_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW2_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW3_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW4_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW5_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW6_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW7_PORT_PIN, GPIO_LOW_SPEED);
}


//the pointer is for the data to display

void HLED_voidDisplay(u8 * Copy_pu8Data)
{
    while(1)
    {
        /*Disable All Columns*/
        voidDisableAllColumns(); //private function to ease deactivation 
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[0]);
        /*Activate Column 0*/
        MGPIO_voidSetPinValue(HLEDMAT_COL0_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);


        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[1]);
        /*Activate Column 1*/
        MGPIO_voidSetPinValue(HLEDMAT_COL1_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);

        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[2]);
        /*Activate Column 2*/
        MGPIO_voidSetPinValue(HLEDMAT_COL2_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);

        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[3]);
        /*Activate Column 3*/
        MGPIO_voidSetPinValue(HLEDMAT_COL3_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);
    
        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[4]);
        /*Activate Column 4*/
        MGPIO_voidSetPinValue(HLEDMAT_COL4_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);

        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[5]);
        /*Activate Column 5*/
        MGPIO_voidSetPinValue(HLEDMAT_COL5_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);

        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[6]);
        /*Activate Column 6*/
        MGPIO_voidSetPinValue(HLEDMAT_COL6_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);


        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[7]);
        /*Activate Column 7*/
        MGPIO_voidSetPinValue(HLEDMAT_COL7_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);
    }
}


//since coulmns are the cathods of the leds
//thats why the high value deactivate them
static void voidDisableAllColumns(void) //static to make it private and the user cannot call it any where else
{
    MGPIO_voidSetPinValue(HLEDMAT_COL0_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL1_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL2_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL3_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL4_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL5_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL6_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL7_PORT_PIN, GPIO_PIN_HIGH);
}

//we are coulmn controled
//we must use the tool that i downloaded from imt led matrix studio
//the copy_u8Value i get it mainly from the tool i installed (it carry 8 decimal values one for each row)
//that i draw in it the shape that i want  to show and then i take its decimal numbers
//and put it in the pointer to array that i send it  to the function SetRowValue
//where the size of the array is 8 bits = to nomber of  rows in my case=8
//correction i recieve only one decimal value from the array every time the function is called and it is called 8 times 
static void voidSetRowsValue(u8 Copy_u8Value)
{
    u8 Local_u8Bit;
    /*Set Rows Value*/
    Local_u8Bit = GET_BIT(Copy_u8Value, 0);
    MGPIO_voidSetPinValue(HLEDMAT_ROW0_PORT_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 1);
    MGPIO_voidSetPinValue(HLEDMAT_ROW1_PORT_PIN, Local_u8Bit);   //if the u8 * Copy_pu8Data was (126,28,16,126,0,0,0)
    Local_u8Bit = GET_BIT(Copy_u8Value, 2);                      //so copy_u8Value will be only one u8 element from the array   
    MGPIO_voidSetPinValue(HLEDMAT_ROW2_PORT_PIN, Local_u8Bit);   //then it will put 126(decimal) in a variable  named Local_u8Bit 
    Local_u8Bit = GET_BIT(Copy_u8Value, 3);                      //and put the 8 elements of the variable value in the corresponding raw pin      
    MGPIO_voidSetPinValue(HLEDMAT_ROW3_PORT_PIN, Local_u8Bit);   //using the set pin value function then move to next row and put in it the next element value  
    Local_u8Bit = GET_BIT(Copy_u8Value, 4);
    MGPIO_voidSetPinValue(HLEDMAT_ROW4_PORT_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 5);
    MGPIO_voidSetPinValue(HLEDMAT_ROW5_PORT_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 6);
    MGPIO_voidSetPinValue(HLEDMAT_ROW6_PORT_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 7);
    MGPIO_voidSetPinValue(HLEDMAT_ROW7_PORT_PIN, Local_u8Bit);
}