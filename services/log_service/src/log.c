#include "log.h"


SYS_LOG gSysLog = {0};

void Log_Init()
{
#if(SYS_LOG_WARN == INCLUDE_FEATURE)
	gSysLog.logLvStatus.warning = 1;
#else

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

#if(SYS_LOG DEBUG == INCLUDE_FEATURE)
	gSysLog.logLvStatus.debug = 1;
#else
	gSysLog.logLvStatus.debug = 0;
#endif
}

inline void SetLogLevel(SYS_LOG_LV logLv)
{
	gSysLog.logLvStatus = logLv;
}

void LOG_DEBUG()
{

	//TODO
	//need to pack the coming data as sci protcol request
	//send the data to the host

}

void LOG_WARN()
{

}

void LOG_ALARM()
{

}

void LOG_INFO()
{

}

void LOG(UINT8 logLv)
{
	switch(logLv)
	{
		case LOG_DBG:
			LOG_DEBUG();
			break;
		case LOG_WARN:
			LOG_WARN();
			break;
		case LOG_ALARM:
			LOG_ALARM();
			break;
		case LOG_INFO:
			LOG_INFO();
			break;
		defalut:
			break;
	}
}
