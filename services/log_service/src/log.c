#include "log.h"


SYS_LOG gSysLog = {0};

void Log_Init()
{

#if(SYS_LOG_WARN == INCLUDE_FEATURE)
	gSysLog.logLvStatus.warning = 1;
#else
	gSysLog.logLvStatus.warning = 0;
#endif

#if(SYS_LOG_ALARM == INCLUDE_FEATURE)
	gSysLog.logLvStatus.alarm = 1;
#else
	gSysLog.logLvStatus.alarm = 0;
#endif

#if(SYS_LOG_INFO == INCLUDE_FEATURE)
	gSysLog.logLvStatus.info = 1;
#else
	gSysLog.logLvStatus.info = 0;
#endif

//#if(SYS_LOG DEBUG == INCLUDE_FEATURE)
//	gSysLog.logLvStatus.debug = 1;
//#else
//	gSysLog.logLvStatus.debug = 0;
//#endif

}

void SetLogLevel(SYS_LOG_LV logLv)
{
	gSysLog.logLvStatus = logLv;
}

void LogDebug()
{

	//TODO
	//need to pack the coming data as sci protcol request
	//send the data to the host

}

void LogWarn()
{

}

void LogAlarm()
{

}

void LogInfo()
{

}

void LOG(Uint16 logLv)
{
	switch(logLv)
	{
		case LOG_DBG:
		    LogDebug();
			break;
		case LOG_WARN:
		    LogWarn();
			break;
		case LOG_ALARM:
		    LogAlarm();
			break;
		case LOG_INFO:
			LogInfo();
			break;
		default:
			break;
	}
}
