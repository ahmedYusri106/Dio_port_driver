/*
 * System_init.c
 *
 *  Created on: 3 /11 /2018
 *      Author: Ahmed Yusri Mohammed
 *      	To: Graduation Project.
 */
#include <myHWDRIV/AUTOSARCOMP/AUTOSAR_SWS_PortDriver/System_init.h>

extern Port_ConfigType  PortConfig;

void Init_Sys(void)
{
	Port_Init(&PortConfig);
}

