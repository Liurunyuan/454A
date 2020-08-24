#ifndef LOG_H_
#define LOG_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define LOG_DBG		0
#define LOG_WARN	1
#define LOG_ALARM	2	
#define LOG_INFO	3

#define SCIA_TRANSPORT	0
#define SCIB_TRANSPORT	1
#define SCIC_TRANSPORT	2
#define SPI_TRANSPORT	3
#define CAN_TRANSPORT	4

typedef struct _SYS_LOG_LV
{
	Uint16 debug	:1;
	Uint16 warning	:1;
	Uint16 alarm	:1;
	Uint16 info		:1;

}SYS_LOG_LV;
typedef struct _SYS_LOG
{
	SYS_LOG_LV	logLvStatus;
	Uint8		tranportType;

}SYS_LOG;

#endif

