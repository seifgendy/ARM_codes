#ifndef RCC_config_H
#define RCC_config_H
 
 
 
 
 
 
 /*
 
 OPTIONS:
 
 RCC_CLK_HSE
 RCC_CLK_HSI
 RCC_CLK_PLL
 
 
 */
 
 #define RCC_CLOCK_SOURCE   RCC_CLK_HSI
 
 
 
 
 
 
 
 
 /*
  
 OPTIONS:
 
 RCC_CLK_HSE
 RCC_CLK_HSI
 
*/
  
 #define RCC_CLK_PLL_SRC     RCC_CLK_HSI
 
 
 
 
 
 
 
 
 ////////////////////////////////////////////////////
  /*                                               //
                                                   //
 OPTIONS:                                          //
                                                   //
 RCC_AHB_DIV_1                                     //
 RCC_AHB_DIV_2     or APB1 or APB2                 //
 RCC_AHB_DIV_4                                     //
                                                   //
                                                   //
                                                   //
*/                                                 //
                                                   //
                                                   //  
 #define   RCC_AHB_PRESCALER     RCC_AHB_DIV_2     //
 #define   RCC_APB1_PRESCALER    RCC_APB1_DIV_1    //
 #define   RCC_APB2_PRESCALER    RCC_APB1_DIV_1    //
 ////////////////////////////////////////////////////
 
 
 #endif 
 
