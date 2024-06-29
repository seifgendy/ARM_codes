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
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

//the registers for NVIC prephiral sec 4.3.11 in arm data sheet
//from register map
//since the registers are not succesive so i do this reserved thing
//to not waste the bits inbetween them     
// reserve value = 0x304 - 0x31c /32 for example 
// 8 registers each of 32 bit to control the 32 position in vector table where it carry a bit for each prephiral
// ISER[2] means i am now accessing the second 32 external prephiral
// in the vector table and according to the 32bit value that i 
//write in hexa decimal form i will set a value (and gate interrupt in this example)
//for each external prephiral
typedef struct
{
    volatile u32 ISER[8];
    volatile u32 Reserved0[24];
    volatile u32 ICER[8];        
    volatile u32 Reserved1[24];
    volatile u32 ISPR[8];
    volatile u32 Reserved2[24];
    volatile u32 ICPR[8];
    volatile u32 Reserved3[24];
    volatile u32 IABR[8];
    volatile u32 Reserved4[56];
    volatile u8 IP[240];
    volatile u32 Reserved5[580];
    volatile u32 STIR;
}NVIC_t;


//NVIC defined with its base address sec 4.1  
#define     NVIC                    ((volatile NVIC_t *)0xE000E100)
#define     AIRCR_PRIVKEY           0x05FA  //password value  for write access to AIRCR

// values for selecting which bits for group priority and which for sub priority
//get it from the priority grouping table 
#define     GRP_4_SUB_0_BITS        0b000
#define     GRP_3_SUB_1_BITS        0b100
#define     GRP_2_SUB_2_BITS        0b101
#define     GRP_1_SUB_3_BITS        0b110
#define     GRP_0_SUB_4_BITS        0b111

#endif
