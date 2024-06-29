#ifndef RCC_interface_H
#define RCC_interface_H
   
                        // read only 
                        // in the interface.h we write the function prototypes and any thing that the user will use in his main.c (interface.h is the only  file externed out of the module)
 

/////clock sources///////
#define RCC_HSI      0///
#define RCC_HSE      1///
#define RCC_PLL      2///
/////////////////////////

/////BUS SELECTION///////
#define RCC_AHB       0///
#define RCC_APB1      1///
#define RCC_APB2      2///
/////////////////////////

////prephirals pins for GPIOS//////////
                                     //  
   #define RCC_GPIOAEN            0  //
   #define RCC_GPIOBEN            1  // 
   #define RCC_GPIOCEN            2  //
   #define RCC_DMA1EN             21 //
   #define RCC_DMA2EN             22 //
///////////////////////////////////////


////////////////PREPHIRALS FOR AHB//
#define 	RCC_AHB_GPIOAEN		0   //
#define 	RCC_AHB_GPIOBEN		1   //
#define 	RCC_AHB_GPIOCEN		2   //
#define 	RCC_AHB_DMA1EN		21     //
#define 	RCC_AHB_DMA2EN		22     //
////////////////////////////////////




/////////prephirals pins for APB2//////                                     
   #define RCC_APB2_TIM1EN        0  //
   #define RCC_APB2_USART1        4  //
   #define RCC_APB2_SPI1EN        12 //
   #define RCC_APB2_TIM9          16 //
   #define RCC_APB2_TIM10         17 //
   #define RCC_APB2_TIM11         18 //
   #define RCC_APB2_USART1        4  //
   #define RCC_APB2_USART6        5  //
   #define RCC_APB2_ADC1          8  //
   #define RCC_APB2_SDIO          11 //
   #define RCC_APB2_SPI1          12 //
   #define RCC_APB2_SPI4EN        13 //
   #define RCC_APB2_SYSCF         14 //
///////////////////////////////////////                          


//////////prephirals pins for APB1/////  
   #define RCC_APB1_TIM2EN        0  //
   #define RCC_APB1_TIM3EN        1  //
   #define RCC_APB1_TIM4EN        2  //
   #define RCC_APB1_TIM5EN        3  //
   #define RCC_APB1_WWDG          11 //
   #define RCC_APB1_SPI2          14 //
   #define RCC_APB1_SPI3          15 //
   #define RCC_APB1_USART2        17 //
   #define RCC_APB1_I2C1          21 //
   #define RCC_APB1_I2C2          22 //
   #define RCC_APB1_I2C3          23 //
   #define RCC_APB1_PWR           28 //
                                     //
///////////////////////////////////////



 ///////////////////////////functions prototypes/////////////////////////////////////// 
 void RCC_voidEnableClockSpource(u8 copy_u8ClockSource);                            ///
 void RCC_voidDisableClockSpource(u8 copy_u8ClockSource);                           ///
 void RCC_voidEnablePrephiralClock( u8 Copy_u8BusName , u8 Copy_u8PeripheralName);  ///  
 void RCC_voidDisablePrephiralClock( u8 Copy_u8BusName , u8 Copy_u8PeripheralName); ///
 void RCC_voidInit(void);                                                           ///
 //////////////////////////////////////////////////////////////////////////////////////
 
 #endif 
 