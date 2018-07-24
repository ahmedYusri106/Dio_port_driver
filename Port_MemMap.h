/*
 * Port_MemMap.h
 *
 *  Created on: 3 /11 /2018
 *      Author: Ahmed Yusri Mohammed
 *      	To: Graduation Project.
 */

#ifndef PORT_MEMMAP_H_
#define PORT_MEMMAP_H_
/*=============================================================
 *>>>>>>>>>>>>>>>>>>>>>>>For AHB<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
=============================================================*/

#ifdef AHB_t
#define BASE_A   0X40058000UL
#define BASE_B   0X40059000UL
#define BASE_C   0X4005A000UL
#define BASE_D   0X4005B000UL
#define BASE_E   0X4005C000UL
#define BASE_F   0X4005D000UL
#endif
#ifndef AHB_t
#define BASE_A   0X40004000UL
#define BASE_B   0X40005000UL
#define BASE_C   0X40006000UL
#define BASE_D   0X40007000UL
#define BASE_E   0X40024000UL
#define BASE_F   0X40025000UL
#endif
/*=========================================================*/
#define GPIODATA 0X00UL
#define GPIODIR  0X400UL
/*=========================================================*/
#define GPIOIS     0X404UL       /* GPIO Interrupt sense*/
#define GPIOIBE    0X408UL      /* GPIO both edges*/
#define GPIOIEV    0X40CUL      /* GPIO interrupt event*/
#define GPIOIM     0X410UL     /* GPIO Interrupt mask En/dis*/
#define GPIORIS    0X414UL     /* GPIO Raw Interrupt Status*/
#define GPIOMIS    0X418UL     /*GPIO Masked Interrupt Status*/
#define GPIOICR    0X41CUL
#define GPIOAFSEL  0X420UL
#define GPIODE2R   0X500UL
#define GPIODE4R   0X504UL
#define GPIODE8R   0X508UL
#define GPIOODR    0X50CUL
#define GPIOPUR    0X510UL
#define GPIOPDR    0X514UL
#define GPIOSLR    0X518UL
#define GPIODEN    0X51CUL
#define GPIOLOCK   0X520UL
#define GPIOCR     0X524UL
#define GPIOAMSEL  0X528UL
#define GPIOPCTL   0X52CUL
#define GPIOADCCTL 0X530UL
#define GPIODMACTL 0X534UL


#endif /* PORT_MEMMAP_H_ */
