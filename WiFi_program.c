/****************************************************************************************
* Author:             seif gendy
* Creation Data:      12 June, 2024
* Version:            v1.0
* Compiler:           GNU ARM-GCC
* Controller:         STM32F401CCU6
* Layer:              HAL
****************************************************************************************/
/***************************************************************************************
* Version    Date              Author                Description
* v1.0       12 June, 2024     seif gendy            Initial Creation
***************************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
#include "../include/STK_interface.h"
#include "../include/UART_interface.h"
#include "../include/WiFi_interface.h"
#include "../include/WiFi_private.h"
#include "../include/WiFi_config.h"

u8 Local_u8Response[100];
u8 Temp_char[20];

void WiFi_voidInit(void)
{
    u8 Local_u8CMDValid = 0;
    while(Local_u8CMDValid == 0)
    {
        MUSART1_voidSendStringSynchronous(WIFI_ECHO_STATE);
        Local_u8CMDValid = u8ValidateCmd(ECHO_TIMEOUT);
    }
    
    Local_u8CMDValid = 0;
    while(Local_u8CMDValid == 0)
    {
        MUSART1_voidSendStringSynchronous(WIFI_NODE_MODE);
        Local_u8CMDValid = u8ValidateCmd(NODE_MODE_TIMEOUT);
    }
}

static u8 u8ValidateCmd(u32 Copy_u32TimeOut)
{
    u8 Local_u8ValidFlag = 0;
    u8 Counter = 0;
    u8 Temp_char = 0;
    for(u8 i = 0; i < 100; i++)
    {
        Local_u8Response[i] = 0;
    }
    
    while (Temp_char != 255)
    {
        Temp_char = MUSART1_u8ReceiveDataIfReceived(&Copy_u32TimeOut);
        Local_u8Response[Counter] = Temp_char;
        Counter++;
    }

    Local_u8Response[Counter - 1] = 0;
 
    for(u8 i = 0; i < Counter - 2; i++)
    {
        if(Local_u8Response[i] == 'O' && Local_u8Response[i + 1] == 'K')
        {
            Local_u8ValidFlag = 1;
            break;
        }
    }
    return Local_u8ValidFlag;
}

void WiFi_voidRouterConnect(void)
{
    u8 Local_u8CMDValid = 0;
    while(Local_u8CMDValid == 0)
    {
        MUSART1_voidSendStringSynchronous(INTERNET_CONNECT);
        MUSART1_voidSendStringSynchronous(USERNAME);
        MUSART1_voidSendStringSynchronous("\",\"");
        MUSART1_voidSendStringSynchronous(PASSWORD);
        MUSART1_voidSendStringSynchronous(ENTER_COMMAND);
        Local_u8CMDValid = u8ValidateCmd(ROUTER_TIMEOUT);
    }
    Local_u8CMDValid = 0;
}

void WiFi_voidServerConnect(void)
{
    u8 Local_u8CMDValid = 0;
    while(Local_u8CMDValid == 0)
    {
        MUSART1_voidSendStringSynchronous(SERVER_CONNECT);
        MUSART1_voidSendStringSynchronous(WIFI_PROTOCOL);
        MUSART1_voidSendStringSynchronous("\",\"");
        MUSART1_voidSendStringSynchronous(WIFI_IP);
        MUSART1_voidSendStringSynchronous(",");
        MUSART1_voidSendStringSynchronous(WIFI_PORT);
        MUSART1_voidSendStringSynchronous(ENTER_COMMAND);
        Local_u8CMDValid = u8ValidateCmd(SERVER_TIMEOUT);
    }
    Local_u8CMDValid = 0;
}

void WiFi_voidServerSendRecordRequest(void)
{
    u16 result = WiFi_voidRecieve();
    u8 arr[4] = {0};
    u8 value = 0;
    u8 RecievedRecordArray[100];

    for(u8 i = 0; i < result; i++)
    {
        WiFi_voidServerConnect();
        MUSART1_voidSendStringSynchronous(CHAR_NUM);
        MUSART1_voidSendStringSynchronous("36");
        MUSART1_voidSendStringSynchronous(ENTER_COMMAND);
        MSTK_voidSetBusyWait(1000000);
        MUSART1_voidSendStringSynchronous(GET);

        value = i;
        arr[0] = value / 100 + '0';
        value %= 100;
        arr[1] = value / 10 + '0';
        value %= 10;
        arr[2] = value + '0';
        arr[3] = '\0';
        MUSART1_voidSendStringSynchronous("http://3.218.11.219/Block");
        MUSART1_voidSendStringSynchronous(arr);
        MUSART1_voidSendStringSynchronous(ENTER_COMMAND);
    }
}

u16 WiFi_voidRecieve(void)
{
    u8 Local_u8Flag = 0;
    u8 Local_u8j = 0;
    u16 Local_u8sum = 0;

    for(u8 i = 0; i < 99; i++)
    {
        Temp_char[i] = 0;
    }

    for(u8 i = 0; i < 98; i++)
    {
        if(Local_u8Flag == 1 && Local_u8Response[i] != 'c')
        {
            if(Local_u8Response[i + 1] == 'C')
            {
                continue;
            }

            Temp_char[Local_u8j] = Local_u8Response[i + 1];
            Local_u8j++;
        }

        if(Local_u8Response[i] == ':')
        {
            Local_u8Flag = 1;
            Temp_char[Local_u8j] = Local_u8Response[i + 1];
            Local_u8j++;
        }

        if(Local_u8Response[i] == 'C')
        {
            break;
        }
    }

    Local_u8Flag = 0;
    Local_u8sum = ((AsciToHex(Temp_char[0]) * 10) + AsciToHex(Temp_char[1]));
    return Local_u8sum;
}

u8 AsciToHex(u8 Copy_u8Ascii)
{
    if(Copy_u8Ascii >= '0' && Copy_u8Ascii <= '9')
    {
        return Copy_u8Ascii - '0';
    }
    else if(Copy_u8Ascii >= 'A' && Copy_u8Ascii <= 'F')
    {
        return Copy_u8Ascii - 'A' + 10;
    }
    else if(Copy_u8Ascii >= 'a' && Copy_u8Ascii <= 'f')
    {
        return Copy_u8Ascii - 'a' + 10;
    }
    return 0;
}
