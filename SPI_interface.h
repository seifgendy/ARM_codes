
/****************************************************************************************
* Author:				seif gendy
* Creation Data:		06 Apr, 2024
* Version:				v1.0
* Compiler:				GNU ARM-GCC
* Controller:			STM32F401CCU6
* Layer:				MCAL
****************************************************************************************/
/***************************************************************************************
* Version	  Date				  	Author				  			Description
* v1.0		  20 Apr, 2024			seif gendy      		  	Initial Creation
***************************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H



////////functions prototypes/////////////////////////////
void SPI1_voidInit(void);
void SPI2_voidInit(void);
void SPI3_voidInit(void);
void SPI4_voidInit(void);

void SPI1_voidSetCallBack(void (*pFunc)(void));
void SPI2_voidSetCallBack(void (*pFunc)(void));
void SPI3_voidSetCallBack(void (*pFunc)(void));
void SPI4_voidSetCallBack(void (*pFunc)(void));

u16 SPI1_voidTranciever(u16 Trans_Data);
u16 SPI2_voidTranciever(u16 Trans_Data);
u16 SPI3_voidTranciever(u16 Trans_Data);
u16 SPI4_voidTranciever(u16 Trans_Data);


u8 MSPI1_u8TrancieveSynchronous(u8 Copy_u8Data);
u8 MSPI2_u8TrancieveSynchronous(u8 Copy_u8Data);
u8 MSPI3_u8TrancieveSynchronous(u8 Copy_u8Data);
u8 MSPI4_u8TrancieveSynchronous(u8 Copy_u8Data);



typedef enum{
	SPI_1=1,
	SPI_2,
	SPI_3,
	SPI_4
}SPI_NO;



#endif
