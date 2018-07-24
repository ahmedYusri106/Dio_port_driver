/*
 * Det.h
 *
 *  Created on: Apr 14, 2018
 *      Author: Ahmed Yusri Mohammed
 */

#ifndef MYHWDRIV_AUTOSARCOMP_DET_H_
#define MYHWDRIV_AUTOSARCOMP_DET_H_

#define DIO_E_PARAM_INVALID_CHANNEL_ID  0X0A
#define DIO_E_PARAM_CONFIG 				0X10
#define DIO_E_PARAM_INVALID_PORT_ID		0X14
#define DIO_E_PARAM_INVALID_GROUP		0X1F
#define DIO_E_PARAM_POINTER				0X20
#define PORT_E_PARAM_PIN				0X0A
#define PORT_E_DIRECTION_UNCHANGEABLE	0X0B
#define PORT_E_INIT_FAILED				0X0C // API Port_Init service called with wrong parameter.
#define PORT_E_PARAM_INVALID_MODE       0X0D
#define PORT_E_MODE_UNCHANGEABLE	    0X0E
#define PORT_E_UNINIT					0X0F //API service called without module initialization
#define PORT_E_PARAM_POINTER			0X10 // APIs called with a Null Pointer


#endif /* MYHWDRIV_AUTOSARCOMP_DET_H_ */
