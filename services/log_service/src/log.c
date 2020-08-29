#include "log.h"
#include "prod_defs.h"


SYS_LOG gSysLog = {0};

void Log_Init()
{

#if(SYS_LOG_WARN == INCLUDE_FEATURE)
	gSysLog.logLvStatus.warning = ENABLE;
#else
	gSysLog.logLvStatus.warning = DISABLE;
#endif

#if(SYS_LOG_ALARM == INCLUDE_FEATURE)
	gSysLog.logLvStatus.alarm = ENABLE;
#else
	gSysLog.logLvStatus.alarm = DISABLE;
#endif

#if(SYS_LOG_INFO == INCLUDE_FEATURE)
	gSysLog.logLvStatus.info = ENABLE;
#else
	gSysLog.logLvStatus.info = DISABLE;
#endif

#if(SYS_LOG_DEBUG == INCLUDE_FEATURE)
	gSysLog.logLvStatus.debug = ENABLE;
#else
	gSysLog.logLvStatus.debug = DISABLE;
#endif

	switch(gSysLog.transportType)
	{
		case SCIA_TRANSPORT:
			break;
		case SCIB_TRANSPORT:
			break;
		case SCIC_TRANSPORT:
			break;
		default:
			break;
	}
}

void SetLogLevel(SYS_LOG_LV logLv)
{
	gSysLog.logLvStatus = logLv;
}

void LogDebug(Uint16 logid, void* data, Uint16 len)
{
    int i;
	int totalLength;

	if(gSysLog.logLvStatus.debug == DISABLE)
	{
		return;
	}

	totalLength = len + EXTRA_LEN;

	if(totalLength < GetSciTxQueLength(gScibTxQue))
	{
		return;
	}

	char* tmp = (char*)malloc(totalLength);

	if(tmp == NULL)
	{
	    return;
	}
	tmp[0] = 0x5a;
	tmp[1] = 0x5a;

	tmp[2] = 0x5a;

	tmp[3] = 0xff;
	tmp[4] = 0xff;

	tmp[totalLength - 4] = 0xbb;
	tmp[totalLength - 3] = 0xcc;
	tmp[totalLength - 2] = 0xa5;
	tmp[totalLength - 1] = 0xa5;

	memcpy(tmp + OFFSET, data, len);

	for(i = 0; i < totalLength; ++i)
	{
 		if(SciTxEnQueue(tmp[i],gScibTxQue) == 0)
		{
			//TODO, generate alarm, queue is full
		}
	}

	free(tmp);
}

void LogWarn(Uint16 logid, void* data, Uint16 len)
{
	if(gSysLog.logLvStatus.warning == DISABLE)
	{
		return;
	}

}

void LogAlarm(Uint16 logid, void* data, Uint16 len)
{
	if(gSysLog.logLvStatus.alarm == DISABLE)
	{
		return;
	}

}

void LogInfo(Uint16 logid, void* data, Uint16 len)
{
	if(gSysLog.logLvStatus.info == DISABLE)
	{
		return;
	}

}

void Log(Uint16 logLv, Uint16 logid, void* data, Uint16 len)
{
	switch(logLv)
	{
		case LOG_DBG:
		    LogDebug(logid, data, len);
			break;
		case LOG_WARN:
		    LogWarn(logid, data, len);
			break;
		case LOG_ALARM:
		    LogAlarm(logid, data, len);
			break;
		case LOG_INFO:
			LogInfo(logid, data, len);
			break;
		default:
			break;
	}
}
