/****************************************************************************************
* Author:				seif gendy
* Creation Data:		19 Apr, 2024
* Version:				v1.0
* Compiler:				GNU ARM-GCC
* Controller:			STM32F401CCU6
* Layer:				HAL
****************************************************************************************/
/***************************************************************************************
* Version	  Date				  	Author				  			Description
* v1.0		  26 Apr, 2024			seif gendy		            	Initial Creation
***************************************************************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"
#include "../include/SPI_interface.h"

#include "../include/TFT_interfae.h"
#include "../include/TFT_private.h"
#include "../include/TFT_config.h"



void HTFT_voidInit(void)
{
    // Set A0 Of TFT To be Output Pin//Ao is command or data selection pin
    MGPIO_voidSetPinMode(HTFT_A0_PORT_PIN, GPIO_OUTPUT);
    // Set RST Of TFT To be Output Pin
    MGPIO_voidSetPinMode(HTFT_RST_PORT_PIN, GPIO_OUTPUT);

    // Initialization Sequence
    // Rest Pulses  these values are not in data sheet trial and error
    MGPIO_voidSetPinValue(HTFT_RST_PORT_PIN, GPIO_PIN_HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_voidSetPinValue(HTFT_RST_PORT_PIN, GPIO_PIN_LOW);
    MSTK_voidSetBusyWait(1);
    MGPIO_voidSetPinValue(HTFT_RST_PORT_PIN, GPIO_PIN_HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_voidSetPinValue(HTFT_RST_PORT_PIN, GPIO_PIN_LOW);
    MSTK_voidSetBusyWait(100);
    MGPIO_voidSetPinValue(HTFT_RST_PORT_PIN, GPIO_PIN_HIGH);
    MSTK_voidSetBusyWait(120000);
    // el command ely ba2olo feh esha mn el noom
    voidSendCommand(SLPOUT_CMD);
    MSTK_voidSetBusyWait(150000);
    // el command ely ba5tar beh ana mashy 3la anhy color code
    voidSendCommand(COLMOD_CMD);
    HTFT_voidSendData(TFT_COLOR_MODE);
    // display command 
    voidSendCommand(DISPON_CMD);
}




static void voidSendCommand(u8 Copy_u8Command)
{
    u8 Local_u8Dummy;
    // Set A0 Pin To Be Low For Command option
    MGPIO_voidSetPinValue(HTFT_A0_PORT_PIN, GPIO_PIN_LOW);
    //send command over spi protocol
    Local_u8Dummy = MSPI1_u8TrancieveSynchronous(Copy_u8Command);
}



void HTFT_voidSendData(u8 Copy_u8Data)
{
    u8 Local_u8Dummy;
    // Set A0 Pin To Be Low For Command option
    MGPIO_voidSetPinValue(HTFT_A0_PORT_PIN, GPIO_PIN_HIGH);
     //send command over spi protocol
    Local_u8Dummy = MSPI1_u8TrancieveSynchronous(Copy_u8Data);
}



void HTFT_voidSetWindow(u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1)
{
    // Send Set X Addresses Command 0x2A so that it know i will choose now my x boundries
    voidSendCommand(X_ADD_CMD);
    // the first byte of the first x boundry
    HTFT_voidSendData(0);
    // the second byte of the first x boundry
    HTFT_voidSendData(Copy_u8X0);
    // the first byte of the second x boundry
    HTFT_voidSendData(0);
    // the second byte of the second x boundry
    HTFT_voidSendData(Copy_u8X1);


    // Send Set y Addresses Command 0x28 so that it know i will choose now my y boundries
    voidSendCommand(Y_ADD_CMD);
    // the first byte of the first y boundry
    HTFT_voidSendData(0);
    // the second byte of the first y boundry
    HTFT_voidSendData(Copy_u8Y0);
    // the first byte of the second y boundry
    HTFT_voidSendData(0);
    // the second byte of the second y boundry
    HTFT_voidSendData(Copy_u8Y1);
}



// 16 bit element array
void HTFT_voidDisplayImage(u16 * Copy_pu16Image)
{
    u16 Local_u16LoopCounter = 0;
    u8 Local_u8Data;

    // choose to display full screen
    HTFT_voidSetWindow(0, 127, 0, 159);

    // Send Write RAM Command (a command in data sheet that tell tft controller that any thing i send after this command will by my image data so store it to view it )
    voidSendCommand(RAM_WR_CMD);

    //iterate over my image array to send it by spi protocol (20480 pixel screen)
    for(Local_u16LoopCounter = 0; Local_u16LoopCounter < 20480; Local_u16LoopCounter++)
    {
        //since my spi register is 8 bit register and my array 
        //elements are 16 bit so i send the most then the least

        // Send MSB First by right shifting
        Local_u8Data = (u8)(Copy_pu16Image[Local_u16LoopCounter] >> 8);
        HTFT_voidSendData(Local_u8Data);

        // Send LSB Then by casting 16bits in 8bits
        Local_u8Data = (u8)Copy_pu16Image[Local_u16LoopCounter];
        HTFT_voidSendData(Local_u8Data);

    }
}
