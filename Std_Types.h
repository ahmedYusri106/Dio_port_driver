/*
 * Std_Types.h
 *
 *  Created on: 3 /11 /2018
 *      Author: Ahmed Yusri Mohammed
 *      	To: Graduation Project.
 */


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "myHWDRIV/Types_t.h"
#include "myHWDRIV/Poard.h"

#ifndef STATUSTYPEDEFINED
 #define STATUSTYPEDEFINED
 #define E_OK 0x00
 typedef unsigned char StatusType; /* OSEK compliance */
#endif

#define E_NOT_OK 0X01

#define STD_HIGH 0x01 /* Physical state 5V or 3.3V */
#define STD_LOW 0x00 /* Physical state 0V */

#define STD_ACTIVE 0x01 /* Logical state active */
#define STD_IDLE 0x00 /* Logical state idle */

#define STD_ON 0x01
#define STD_OFF 0x00

typedef struct
{
 myUint16 vendorID;
 myUint16 moduleID;
 myUint8 sw_major_version;
 myUint8 sw_minor_version;
 myUint8 sw_patch_version;
}Std_VersionInfoType;

typedef myUint8  EcucBooleanParamDef;
typedef myUint32 EcucIntegerParamDef;


#endif /* STD_TYPES_H_ */
