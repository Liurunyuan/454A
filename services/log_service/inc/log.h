#ifndef LOG_H_
#define LOG_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define LOG_DBG		0
#define LOG_WARN	1
#define LOG_ALARM	2	
#define LOG_INFO	3

typedef struct _SYS_LOG_LV
{
	UINT16 debug	:1;
	UINT16 warning	:1;
	UINT16 alarm	:1;
	UINT16 info		:1;

}SYS_LOG_LV;
typedef struct _SYS_LOG
{
	SYS_LOG_LV logLvStatus;

}SYS_LOG;

#endif

