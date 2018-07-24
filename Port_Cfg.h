/*
 * Port_Cfg.h
 *
 *  Created on: 3 /11 /2018
 *      Author: Ahmed Yusri Mohammed
 *      	To: Graduation Project.
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_
/*
 * Edit in this file using SW tool.
 */
#define PORT_NUMBER     6
#define PIN_NUMBER      48
#define PORT_PIN_NUMBER 8
/*
 * Switches the development error detection and notification on or off.
 * UnComment: detection and notification is enabled.
 * Comment  : detection and notification is disabled.
 */
//#define PORTDEVERRORDETECT
/*
 * Pre-processor switch to enable / disable the use of the function Port_SetPinDirection().
 * UnComment: Enabled - Function Port_SetPinDirection() is available.
 * Comment  : Disabled - Function Port_SetPinDirection() is not available.
 */
#define PORTSETPINDIRECTIONAPI
/*
 * Pre-processor switch to enable / disable the use of the function Port_SetPinMode().
 * UnComment: Enabled - Function Port_SetPinMode() is available.
 * Comment  : Disabled - Function Port_SetPinMode() is not available.
 */
#define PORTSETPINMODEAPI
/*
 * Pre-processor switch to enable / disable the API to read out the modules version information.
 * UnComment: Version info API enabled.
 * Comment  : Version info API disabled.
 */
//#define PORTVERSIONINFOAPI

/*
 * mode & The Value = Mux Value .
 */


#endif /* PORT_CFG_H_ */
