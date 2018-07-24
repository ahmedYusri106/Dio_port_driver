/*
 * Port.c
 *
 *  Created on: 3 /11 /2018
 *      Author: Ahmed Yusri Mohammed
 *      	To: Graduation Project.
 */

/*
 * The PORT Driver module shall allow the configuration of different functionality
 * for each port and port pin, e.g. ADC, SPI, DIO etc.
 */

#include <myHWDRIV/AUTOSARCOMP/AUTOSAR_SWS_PortDriver/Port.h>
#include <myHWDRIV/AUTOSARCOMP/AUTOSAR_SWS_PortDriver/Port_MemMap.h>
#include "myHWDRIV/hw_types.h"

#ifdef PORTSETPINDIRECTIONAPI
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction)
{
	uint32 B[6] = {BASE_A,BASE_B,BASE_C,BASE_D,BASE_E,BASE_F};
	uint32 Base;
	Pin--;
	Base = B[Pin/PORT_PIN_NUMBER];
	Pin  %= PORT_PIN_NUMBER;
	if(Direction == PORT_PIN_OUT){
		SET_BIT(Base + GPIODIR,Pin);
	}else{
		CLEAR_BIT(Base + GPIODIR,Pin);
	}
}
#endif
#ifdef PORTSETPINMODEAPI
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode)
{
	uint32 B[6] = {BASE_A,BASE_B,BASE_C,BASE_D,BASE_E,BASE_F};
	uint32 Base;
	Pin--;
	Base = B[Pin/PORT_PIN_NUMBER];
	Pin  %= PORT_PIN_NUMBER;
	if(Mode == PORT_PIN_MODE_ADC){
		SET_BIT(Base + GPIOAMSEL,Pin);
	}else if(Mode == PORT_PIN_MODE_TRIGGER_ADC){
		SET_BIT(Base + GPIOADCCTL,Pin);
	}else if(Mode == PORT_PIN_MODE_DIO){
		CLEAR_BIT(Base + GPIOADCCTL,Pin);
		CLEAR_BIT(Base + GPIOAMSEL,Pin);
		SET_BIT(Base + GPIODEN,Pin);
	}else{
		SET_BIT(Base + GPIOAFSEL,Pin);
		SET_BIT(Base + GPIODEN,Pin);
		WRITE_REG_32BIT(Base + GPIOPCTL,READ_REG_32BIT(Base + GPIOPCTL) | ( (uint32) Mode << (Pin << 2) ) );
	}
}
#endif

void Port_Init(const Port_ConfigType* ConfigPtr)
{
	uint32 B[6] = {BASE_A,BASE_B,BASE_C,BASE_D,BASE_E,BASE_F};
	uint32 i = 0,j,Pin,Base;
	Port_PinDirectionType Dir;
	Port_PinModeType Mode;
	for(j = 0;j < PORT_NUMBER;j++){
		Base = B[j];
		for(Pin = 0;Pin < PORT_PIN_NUMBER;Pin++){
			Mode = ConfigPtr->PortPin[i].PortPinInitialMode;
			Dir  = ConfigPtr->PortPin[i].PortPinDirection;
			if(Mode == PORT_PIN_NOT_USED){
				//continue;
			}else if(Mode == PORT_PIN_MODE_DIO){
				//Config Pin as Digital Input || Output.
		    	if(Dir == PORT_PIN_OUT){
		    		SET_BIT(Base + GPIODIR,Pin);
		    	}else{
		    		CLEAR_BIT(Base + GPIODIR,Pin);
		    	}
				CLEAR_BIT(Base + GPIOADCCTL,Pin);
				CLEAR_BIT(Base + GPIOAMSEL,Pin);
				SET_BIT(Base + GPIODEN,Pin);
			}else{
				//Set Pin to Specs Alternative Function .
		    	if(Dir == PORT_PIN_OUT){
		    		SET_BIT(Base + GPIODIR,Pin);
		    	}else{
		    		CLEAR_BIT(Base + GPIODIR,Pin);
		    	}
				if(Mode == PORT_PIN_MODE_ADC){
					SET_BIT(Base + GPIOAMSEL,Pin);
				}else if(Mode == PORT_PIN_MODE_TRIGGER_ADC){
					SET_BIT(Base + GPIOADCCTL,Pin);
				}else{
					SET_BIT(Base + GPIOAFSEL,Pin);
					SET_BIT(Base + GPIODEN,Pin);
					WRITE_REG_32BIT(Base + GPIOPCTL,READ_REG_32BIT(Base + GPIOPCTL) | ( (uint32) Mode << (Pin << 2) ) );
				}
			}
			i++;
		}
	}
}

extern Port_ConfigType  PortConfig;

void Port_RefreshPortDirection(void)
{
	uint32 B[6] = {BASE_A,BASE_B,BASE_C,BASE_D,BASE_E,BASE_F};
	uint32 i = 0,j,Pin,Base;
	for(j = 0;j < PORT_NUMBER;j++){
		Base = B[j];
		for(Pin = 0;Pin < PORT_PIN_NUMBER;Pin++){
			if(PortConfig.PortPin[i].PortPinInitialMode == PORT_PIN_NOT_USED){

			}else if(PortConfig.PortPin[i].PortPinDirection == PORT_PIN_OUT){
	    		SET_BIT(Base + GPIODIR,Pin);
	    	}else{
	    		CLEAR_BIT(Base + GPIODIR,Pin);
	    	}
			i++;
		}
	}
}
#ifdef PORTVERSIONINFOAPI
static Std_VersionInfoType aux_versioninfo = {
		 106,//Vendor Id
		 40, // Module Id
		 10, //sw_major_version;
		 20, //sw_minor_version;
		 30, //uint8 sw_patch_version;
};
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
	versioninfo = &aux_versioninfo;
}
#endif
