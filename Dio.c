/*
 * Dio.c
 *
 *  Created on: Apr 14, 2018
 *      Author: Ahmed Yusri Mohammed
 */

#include <myHWDRIV/AUTOSARCOMP/Det.h>
#include "Dio.h"
#include "Dio_MemMap.h"
#include "SchM_Dio.h"
#include "myHWDRIV/hw_types.h"
#include "myHWDRIV/Poard.h"

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<**/

static void WriteHWMaskedPins(Dio_PortType Portid, uint8 Val, uint16 Mask){
	uint32 B[6] = {BASE_A,BASE_B,BASE_C,BASE_D,BASE_E,BASE_F};
	uint32 Base = B[Portid];
	WRITE_REG_32BIT(Base + GPIODATA + (Mask << 2), Val);
}

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<**/

static void ReadHWMaskedPins(Dio_PortType Portid, uint8 *Val, uint16 Mask){
	uint32 B[6] = {BASE_A,BASE_B,BASE_C,BASE_D,BASE_E,BASE_F};
	uint32 Base = B[Portid];
	*Val  = READ_REG_32BIT(Base + GPIODATA + (Mask << 2));
}

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<**/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId){
	Dio_LevelType ret;
	uint32 B[6] = {BASE_A,BASE_B,BASE_C,BASE_D,BASE_E,BASE_F};
	uint32 Base;
	ChannelId--;
	Base = B[ChannelId/PORT_PIN_NUMBER];
	ChannelId  = ChannelId % PORT_PIN_NUMBER;
	ret = ((READ_REG_32BIT((Base + GPIODATA)|0X3FC) & (1 << ChannelId)) >> ChannelId);
	return ret;
}

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<**/

void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level){
	uint32 Val2;
	uint32 B[6] = {BASE_A,BASE_B,BASE_C,BASE_D,BASE_E,BASE_F};
	uint32 Base;
	ChannelId--;
	Base = B[ChannelId/PORT_PIN_NUMBER];
	ChannelId  %= PORT_PIN_NUMBER;
	if(Level == STD_HIGH){
		Val2 = (Level << ChannelId) | READ_REG_32BIT((Base + GPIODATA) | 0X3FC);
	}else{
		Val2 = (~(1 << ChannelId)) & READ_REG_32BIT((Base + GPIODATA) | 0X3FC);
	}
	WRITE_REG_32BIT((Base + GPIODATA) | 0X3FC,Val2);
}

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<**/

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){
	Dio_PortLevelType Val;
	ReadHWMaskedPins(PortId,&Val,0xFF);
	return Val;
}

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<**/

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level){
	WriteHWMaskedPins(PortId,Level,0xFF);
}

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<**/

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr){
	Dio_PortLevelType Val;
	ReadHWMaskedPins(ChannelGroupIdPtr->port,(uint8*)&Val,ChannelGroupIdPtr->mask);
	return (Val >> ChannelGroupIdPtr->offset);
}

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<**/

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level){
	WriteHWMaskedPins(ChannelGroupIdPtr->port,Level,(ChannelGroupIdPtr->mask << ChannelGroupIdPtr->offset));
}

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<**/

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId){
	Dio_LevelType ret = Dio_ReadChannel(ChannelId);
	if(ret == STD_HIGH){
		Dio_WriteChannel(ChannelId,STD_LOW);
		ret = STD_LOW;
	}else{
		Dio_WriteChannel(ChannelId,STD_HIGH);
		ret =  STD_HIGH;
	}
	return ret;
}

/**>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<**/

#ifdef DIOVERSIONINFOAPI
static Std_VersionInfoType aux_versioninfo = {
		 106,//Vendor Id
		 20, // Module Id
		 10, //sw_major_version;
		 20, //sw_minor_version;
		 30, //uint8 sw_patch_version;
};
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo){
	versioninfo = &aux_versioninfo;
}
#endif

