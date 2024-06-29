
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
* v1.0		  20 Apr, 2024			seif gendy       		  	Initial Creation
***************************************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

//regesters of the prephiral are consecutive so i did it using struct
typedef struct{
volatile	u32 SPI_CR1;
volatile	u32 SPI_CR2;
volatile	u32 SPI_SR;
volatile	u32 SPI_DR;
volatile	u32 SPI_CRCPR;
volatile	u32 SPI_RXCRCR;
volatile	u32 SPI_TXCRCR;
volatile	u32 SPI_I2SCFGR;
volatile	u32 SPI_I2SPR;
}SPI_t;

//base addresses of the 4 spi prephirals in my mc
#define  SPI1  ((volatile SPI_t*)0x40013000)
#define  SPI2  ((volatile SPI_t*)0x40003800)
#define  SPI3  ((volatile SPI_t*)0x40003C00)
#define  SPI4  ((volatile SPI_t*)0x40013400)


#define  SPI_Disable  0
#define  SPI_Enable   1

#define  SPI_8bit   0
#define  SPI_16bit  1

#define  SPI_INT_DISABLE  0
#define  SPI_INT_ENABLE   1

#define  SPI_Slave   0
#define  SPI_Master  1

#define  SPI_LEADING   0
#define  SPI_TRAILING  1

#define  IDLE_IN0  0
#define  IDLE_IN1  1

#define  SPI_FREQ2    0
#define  SPI_FREQ4    1
#define  SPI_FREQ8    3
#define  SPI_FREQ16   4
#define  SPI_FREQ32   5
#define  SPI_FREQ64   6
#define  SPI_FREQ128  7
#define  SPI_FREQ256  8

#define  SPI_MostBit   0
#define  SPI_LeastBit  1


 
#endif  

