/*
 * Dio.h
 *
 *  Created on: Apr 14, 2018
 *      Author: Ahmed Yusri Mohammed
 */


#ifndef MYHWDRIV_AUTOSARCOMP_AUTOSAR_SWS_DIODRIVER_DIO_H_
#define MYHWDRIV_AUTOSARCOMP_AUTOSAR_SWS_DIODRIVER_DIO_H_

#include "../Std_Types.h"
#include "Dio_Cfg.h"

typedef uint32 Dio_ChannelType;
typedef uint32 Dio_PortType;

typedef struct dcgt{
	uint8 mask;
	uint8 offset;
	Dio_PortType port;
}Dio_ChannelGroupType;

typedef uint32 Dio_LevelType;
typedef uint32 Dio_PortLevelType;
typedef uint32 Dio_ErrorType;

typedef struct{
/*
 * This structure contains all post-build configurable parameters of the DIO driver. A
 * pointer to this structure is passed to the DIO driver initialization function for
 * configuration.
 */

}Dio_ConfigType;

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);
#ifdef DIOVERSIONINFOAPI
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);


#endif /* MYHWDRIV_AUTOSARCOMP_AUTOSAR_SWS_DIODRIVER_DIO_H_ */
