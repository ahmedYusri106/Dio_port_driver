/*
 * Dio_Lcfg.c
 *
 *  Created on: Apr 14, 2018
 *      Author: Ahmed Yusri Mohammed
 */
#include "Dio.h"
#include "Dio_MemMap.h"

/*
 * Example :
 *
	const Dio_ChannelGroupType DioConfigData[2] =
	{
		{
			port = MOTOR_CTL_PORT,
			offset = 5,
			mask = 0x60,
		},
		{
			port = MUX_SEL_PORT,
			offset = 1,
			mask = 0x1E,
		}
	};
 *
 */

