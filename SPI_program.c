
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
* v1.0		  20  Apr, 2024			seif gendy       		  	Initial Creation
***************************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/SPI_interface.h"
#include "../include/SPI_private.h"
#include "../include/SPI_config.h"



/*
static void (*SPI1_CallBackFunction)(void)=0;
static void (*SPI2_CallBackFunction)(void)=0;
static void (*SPI3_CallBackFunction)(void)=0;
static void (*SPI4_CallBackFunction)(void)=0;

u16 SPI1_RecievedData = 0;
u16 SPI2_RecievedData = 0;
u16 SPI3_RecievedData = 0;
u16 SPI4_RecievedData = 0;

u16 SPI1_TransmissionData = 0;
u16 SPI2_TransmissionData = 0;
u16 SPI3_TransmissionData = 0;
u16 SPI4_TransmissionData = 0;
*/

//////////the 4 spi void initiation functions//////////////////////////


void SPI1_voidInit(void)
{
SPI1->SPI_CR1  = 0x0047 ;


/*
//ENABLE/DISABLE SPI
	SPI1->SPI_CR1 &= ~(1<<6);
	SPI1->SPI_CR1 |= (SPI1_Status<<6);



	//SPI CLK PHASE SELECTION
	SPI1->SPI_CR1 &= ~(1<<0);
	SPI1->SPI_CR1 |= (SPI1_ClkPhase<<0);

	//SPI CLK POLARITY SELECTION
	SPI1->SPI_CR1 &= ~(1<<1);
	SPI1->SPI_CR1 |= (SPI1_ClkPolarity<<1);

	//SPI Master Slave Selection
	SPI1->SPI_CR1 &= ~(1<<2);
	SPI1->SPI_CR1 |= (SPI1_MasterSelection<<2);

	//SPI BAUD RATE SELECTION
	SPI1->SPI_CR1 &= ~(0b111<<3);
	SPI1->SPI_CR1 |= (SPI1_BaudRate<<3);

	//SPI FIRST MOST BIT FIRST LEAST BIT SELECTION
	SPI1->SPI_CR1 &= ~(1<<7);
	SPI1->SPI_CR1 |= (SPI1_MostLeastBitSelection<<7);

	//SPI Software Slave Management Selection
	SPI1->SPI_CR1 &= ~(1<<9);
	SPI1->SPI_CR1 |= (SPI1_SoftwareSlaveManagement<<9);

	//SPI NUMBER OF FRAME BITS SELECTION
	SPI1->SPI_CR1 &= ~(1<<11);
	SPI1->SPI_CR1 |= (SPI1_NoOfFrameBits<<11);
	*/
}

//////////////////////////////////////////////////////////////////////////////

void SPI2_voidInit(void)
{


	//ENABLE/DISABLE SPI
	SPI2->SPI_CR1 &= ~(1<<6);
	SPI2->SPI_CR1 |= (SPI2_Status<<6);

	/*ENABLE/DISABLE INTERRUPT SELECTION

	#if (SPI2_INTStatus == SPI_INT_ENABLE)
		SET_BIT(SPI2->SPI_CR2 , 7);
	    NVIC_voidPeripheralInterruptControl(36,NVIC_INT_ENABLE);
	#endif
	*/

	//SPI CLK PHASE SELECTION
	SPI1->SPI_CR1 &= ~(1<<0);
	SPI1->SPI_CR1 |= (SPI2_ClkPhase<<0);

	//SPI CLK POLARITY SELECTION
	SPI2->SPI_CR1 &= ~(1<<1);
	SPI2->SPI_CR1 |= (SPI2_ClkPolarity<<1);

	//SPI Master Slave Selection
	SPI2->SPI_CR1 &= ~(1<<2);
	SPI2->SPI_CR1 |= (SPI2_MasterSelection<<2);

	//SPI BAUD RATE SELECTION
	SPI2->SPI_CR1 &= ~(0b111<<3);
	SPI2->SPI_CR1 |= (SPI2_BaudRate<<3);

	//SPI FIRST MOST BIT FIRST LEAST BIT SELECTION
	SPI1->SPI_CR1 &= ~(1<<7);
	SPI1->SPI_CR1 |= (SPI2_MostLeastBitSelection<<7);

	//SPI Software Slave Management Selection
	SPI2->SPI_CR1 &= ~(1<<9);
	SPI2->SPI_CR1 |= (SPI2_SoftwareSlaveManagement<<9);

	//SPI NUMBER OF FRAME BITS SELECTION
	SPI2->SPI_CR1 &= ~(1<<11);
	SPI2->SPI_CR1 |= (SPI2_NoOfFrameBits<<11);
}

/////////////////////////////////////////////////////////////////////////////

void SPI3_voidInit(void)
{


	/*ENABLE/DISABLE SPI*/
	SPI3->SPI_CR1 &= ~(1<<6);
	SPI3->SPI_CR1 |= (SPI3_Status<<6);

	/*ENABLE/DISABLE INTERRUPT SELECTION
	#if (SPI3_INTStatus == SPI_INT_ENABLE)
		SET_BIT(SPI3->SPI_CR2 , 7);
	    NVIC_voidPeripheralInterruptControl(51,NVIC_INT_ENABLE);
	#endif
	*/

	/*SPI CLK PHASE SELECTION*/
	SPI1->SPI_CR1 &= ~(1<<0);
	SPI1->SPI_CR1 |= (SPI3_ClkPhase<<0);

	/*SPI CLK POLARITY SELECTION*/
	SPI3->SPI_CR1 &= ~(1<<1);
	SPI3->SPI_CR1 |= (SPI3_ClkPolarity<<1);

	/*SPI Master Slave Selection*/
	SPI3->SPI_CR1 &= ~(1<<2);
	SPI3->SPI_CR1 |= (SPI1_MasterSelection<<2);

	/*SPI BAUD RATE SELECTION*/
	SPI3->SPI_CR1 &= ~(0b111<<3);
	SPI3->SPI_CR1 |= (SPI3_BaudRate<<3);

	/*SPI FIRST MOST BIT FIRST LEAST BIT SELECTION*/
	SPI3->SPI_CR1 &= ~(1<<7);
	SPI3->SPI_CR1 |= (SPI3_MostLeastBitSelection<<7);

	/*SPI Software Slave Management Selection*/
	SPI3->SPI_CR1 &= ~(1<<9);
	SPI3->SPI_CR1 |= (SPI3_SoftwareSlaveManagement<<9);

	/*SPI NUMBER OF FRAME BITS SELECTION*/
	SPI3->SPI_CR1 &= ~(1<<11);
	SPI3->SPI_CR1 |= (SPI3_NoOfFrameBits<<11);
}

////////////////////////////////////////////////////////////////////////////////


void SPI4_voidInit(void)
{


	/*ENABLE/DISABLE SPI*/
	SPI4->SPI_CR1 &= ~(1<<6);
	SPI4->SPI_CR1 |= (SPI4_Status<<6);

	/*ENABLE/DISABLE INTERRUPT SELECTION
	#if (SPI4_INTStatus == SPI_INT_ENABLE)
		SET_BIT(SPI4->SPI_CR2 , 7);
	    NVIC_voidPeripheralInterruptControl(84,NVIC_INT_ENABLE);
	#endif
	*/

	/*SPI CLK PHASE SELECTION*/
	SPI4->SPI_CR1 &= ~(1<<0);
	SPI4->SPI_CR1 |= (SPI4_ClkPhase<<0);

	/*SPI CLK POLARITY SELECTION*/
	SPI4->SPI_CR1 &= ~(1<<1);
	SPI4->SPI_CR1 |= (SPI4_ClkPolarity<<1);

	/*SPI Master Slave Selection*/
	SPI4->SPI_CR1 &= ~(1<<2);
	SPI4->SPI_CR1 |= (SPI4_MasterSelection<<2);

	/*SPI BAUD RATE SELECTION*/
	SPI4->SPI_CR1 &= ~(0b111<<3);
	SPI4->SPI_CR1 |= (SPI4_BaudRate<<3);

	/*SPI FIRST MOST BIT FIRST LEAST BIT SELECTION*/
	SPI4->SPI_CR1 &= ~(1<<7);
	SPI4->SPI_CR1 |= (SPI4_MostLeastBitSelection<<7);

	/*SPI Software Slave Management Selection*/
	SPI4->SPI_CR1 &= ~(1<<9);
	SPI4->SPI_CR1 |= (SPI4_SoftwareSlaveManagement<<9);

	/*SPI NUMBER OF FRAME BITS SELECTION*/
	SPI4->SPI_CR1 &= ~(1<<11);
	SPI4->SPI_CR1 |= (SPI4_NoOfFrameBits<<11);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////call back functions that takes the name of function of what to do written in main .c file////////////////////////////
/*
void SPI1_voidSetCallBack(void (*pFunc)(void))
{
	SPI1_CallBackFunction = pFunc;
}

///////////////////////////////////////////////////////////////////////////////////

void SPI2_voidSetCallBack(void (*pFunc)(void))
{
	SPI2_CallBackFunction = pFunc;
}

///////////////////////////////////////////////////////////////////////////////////

void SPI3_voidSetCallBack(void (*pFunc)(void))
{
	SPI3_CallBackFunction = pFunc;
}

///////////////////////////////////////////////////////////////////////////////////


void SPI4_voidSetCallBack(void (*pFunc)(void))
{
	SPI4_CallBackFunction = pFunc;
}
*/

///////////////////the 4 tranciever functions////////////
////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
/*
u16 SPI1_voidTranciever(u16 Trans_Data)
{
	u16 Recieved_Data = 0;
	#if (SPI1_INTStatus == SPI_INT_DISABLE)
		SPI1->SPI_DR = Trans_Data;
	    while(GIT_BIT(SPI1->SPI_DR , 7));
		Recieved_Data = SPI1->SPI_DR;
		return Recieved_Data;
	#elif (SPI1_INTStatus == SPI_INT_ENABLE)
		SPI1_RecievedData = SPI1->SPI_DR;
	    SPI1->SPI_DR = Trans_Data;
		#endif
}

///////////////////////////////////////////////////////

u16 SPI2_voidTranciever(u16 Trans_Data)
{
	u16 SPI_RecievedData = 0;
	#if (SPI2_INTStatus == SPI_INT_DISABLE)
		SPI2->SPI_DR = Trans_Data;
	    while(GIT_BIT(SPI2->SPI_DR , 7));
		Recieved_Data = SPI2->SPI_DR;
		return Recieved_Data;
	#elif (SPI2_INTStatus == SPI_INT_ENABLE)
		SPI_RecievedData = SPI2->SPI_DR;
	    SPI2->SPI_DR = Trans_Data;
		#endif
}

//////////////////////////////////////////////////////////

u16 SPI3_voidTranciever(u16 Trans_Data)
{
	u16 Recieved_Data = 0;
	#if (SPI3_INTStatus == SPI_INT_DISABLE)
		SPI3->SPI_DR = Trans_Data;
	    while(GIT_BIT(SPI3->SPI_DR , 7));
		Recieved_Data = SPI3->SPI_DR;
		return Recieved_Data;
	#elif (SPI3_INTStatus == SPI_INT_ENABLE)
		SPI3_RecievedData = SPI3->SPI_DR;
	    SPI3->SPI_DR = Trans_Data;
		#endif
}

////////////////////////////////////////////////////////////

u16 SPI4_voidTranciever(u16 Trans_Data)
{
	u16 Recieved_Data = 0;
	#if (SPI4_INTStatus == SPI_INT_DISABLE)
		SPI4->SPI_DR = Trans_Data;
	    while(GIT_BIT(SPI4->SPI_DR , 7));
		Recieved_Data = SPI4->SPI_DR;
		return Recieved_Data;
	#elif (SPI4_INTStatus == SPI_INT_ENABLE)
		SPI4_RecievedData = SPI4->SPI_DR;
	    SPI4->SPI_DR = Trans_Data;
		#endif
}
*/



////////////like above but for 8bit signal//////////////////////


u8 MSPI1_u8TrancieveSynchronous(u8 Copy_u8Data)
{
    u8 Local_u8ReceivedData;
    SPI1 -> SPI_DR = Copy_u8Data;
    while(GET_BIT(SPI1 -> SPI_SR, 7));        // while(GET_BIT(MSPI1 -> SR, 7) == 1);
    Local_u8ReceivedData = SPI1 ->SPI_DR;
    return Local_u8ReceivedData;
}


u8 MSPI2_u8TrancieveSynchronous(u8 Copy_u8Data)
{
    u8 Local_u8ReceivedData;
    SPI2 -> SPI_DR = Copy_u8Data;
    while(GET_BIT(SPI2 -> SPI_SR, 7));        // while(GET_BIT(MSPI1 -> SR, 7) == 1);
    Local_u8ReceivedData = SPI2 -> SPI_DR;
    return Local_u8ReceivedData;
}

u8 MSPI3_u8TrancieveSynchronous(u8 Copy_u8Data)
{
    u8 Local_u8ReceivedData;
    SPI3 -> SPI_DR = Copy_u8Data;
    while(GET_BIT(SPI3 -> SPI_SR, 7));        // while(GET_BIT(MSPI1 -> SR, 7) == 1);
    Local_u8ReceivedData = SPI3 -> SPI_DR;
    return Local_u8ReceivedData;
}

u8 MSPI4_u8TrancieveSynchronous(u8 Copy_u8Data)
{
    u8 Local_u8ReceivedData;
    SPI4 -> SPI_DR = Copy_u8Data;
    while(GET_BIT(SPI4 -> SPI_SR, 7));        // while(GET_BIT(MSPI1 -> SR, 7) == 1);
    Local_u8ReceivedData = SPI4 -> SPI_DR;
    return Local_u8ReceivedData;
}


/////////////////////////////////////////////////////////////////////////////////////








////////////////the 4 isr /////////////////////////////////////
//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
/*
void SPI1_IRQHandler(void)
{
	SPI1_voidTranciever(SPI1_TransmissionData);
	if(SPI1_CallBackFunction != 0)
	{
		SPI1_CallBackFunction();
	}
}
///////////////////////////////////////////////////////
void SPI2_IRQHandler(void)
{
	SPI2_voidTranciever(SPI2_TransmissionData);
	if(SPI2_CallBackFunction != 0)
	{
		SPI2_CallBackFunction();
	}
}
///////////////////////////////////////////////////////
void SPI3_IRQHandler(void)
{
	SPI3_voidTranciever(SPI3_TransmissionData);
	if(SPI3_CallBackFunction != 0)
	{
		SPI3_CallBackFunction();
	}
}
//////////////////////////////////////////////////////
void SPI4_IRQHandler(void)
{
	SPI4_voidTranciever(SPI4_TransmissionData);
	if(SPI4_CallBackFunction != 0)
	{
		SPI4_CallBackFunction();
	}
}

*/




