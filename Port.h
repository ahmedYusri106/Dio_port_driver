/*
 * Port.h
 *
 *  Created on: 3 /11 /2018
 *      Author: Ahmed Yusri Mohammed
 *      	To: Graduation Project.
 */

#ifndef PORT_H_
#define PORT_H_

#include "../Std_Types.h"
#include "Port_Cfg.h"


typedef uint32 Port_PinType;

typedef enum{
	PORT_PIN_IN,
	PORT_PIN_OUT,
}Port_PinDirectionType;
typedef enum{
	PORT_PIN_LEVEL_HIGH,
	PORT_PIN_LEVEL_LOW,
}Pot_PinLevelType;

typedef uint32 Port_PinModeType;

/*
 * Container -> Def.
 */
typedef struct{
	Port_PinDirectionType PortPinDirection;
	EcucBooleanParamDef PortPinDirectionChangeable;
	EcucIntegerParamDef PortPinId;
	Port_PinModeType   PortPinInitialMode;
	Pot_PinLevelType   PortPinLevelValue;
	EcucBooleanParamDef PortPinModeChangeable;
}PortPinType;
/*
 * The Main Containar.
 */
typedef struct{
	PortPinType* PortPin;
	EcucIntegerParamDef PortNumberOfPortPins;
}Port_ConfigType;


/*
 * Functions prototypes
 */
#ifdef PORTDEVERRORDETECT
#endif

#ifdef PORTVERSIONINFOAPI
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif
#ifdef PORTSETPINDIRECTIONAPI
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction);
#endif
#ifdef PORTSETPINMODEAPI
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode);
#endif
void Port_Init(const Port_ConfigType* ConfigPtr);

void Port_RefreshPortDirection(void);


#endif /* PORT_H_ */
