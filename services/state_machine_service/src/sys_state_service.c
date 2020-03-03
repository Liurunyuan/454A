#include "sys_state_service.h"


SYS_STATE_FLAG gSysStateFlag = 
{
    STOP,
    0,
    0
};

void (*Sys_hlstPtr)(void);

void Sys_hlstInit(void);
void Sys_hlsStop(void);
void Sys_hlstForwardRotate(void);
void Sys_hlstBackwardRotate(void);
void Sys_hlsWarning(void);
void Sys_hlsAlarm(void);

#define Sys_chstInit()                  Sys_hlstPtr = Sys_hlstInit; SET_SYS_RUNNING_STATE_INIT;
#define Sys_chstStop()                  Sys_hlstPtr = Sys_hlsStop; SET_SYS_RUNNING_STATE_STOP;
#define Sys_chstForwardRotate()         Sys_hlstPtr = Sys_hlstForwardRotate; SET_SYS_RUNNING_STATE_FORWARD_RUN;
#define Sys_chstBackwardRotate()        Sys_hlstPtr = Sys_hlstBackwardRotate; SET_SYS_RUNNING_STATE_BACKWARD_RUN;
#define Sys_chstWarning()               Sys_hlstPtr = Sys_hlsWarning; SET_SYS_RUNNING_STATE_WARNING;
#define Sys_chstAlarm()                 Sys_hlstPtr = Sys_hlsAlarm; SET_SYS_RUNNING_STATE_ALARM;



void Sys_hlstInit(void)
{
    if(IS_SYS_ALARM)
    {
        Sys_chstAlarm();
        return;
    }

    if(IS_SYS_WARNING)
    {
        Sys_chstWarning();
        return;
    }

    Sys_chstStop();
}

void Sys_hlsStop(void)
{
    if(IS_SYS_ALARM)
    {
        Sys_chstAlarm();
        return;
    }

    if(IS_SYS_WARNING)
    {
        Sys_chstWarning();
        return;
    }

    if(IS_SYS_ENABLE_FORWARD_ROTATE)
    {
        Sys_chstForwardRotate();
        return;
    }

    if(IS_SYS_ENABLE_BACKWARD_ROTATE)
    {
        Sys_chstBackwardRotate();
        return;
    }
}

void Sys_hlstForwardRotate(void)
{
    if(IS_SYS_ALARM)
    {
        Sys_chstAlarm();
        return;
    }

    if(IS_SYS_WARNING)
    {
        Sys_chstWarning();
        return;
    }
}

void Sys_hlsBackwardRotate(void)
{
    if(IS_SYS_ALARM)
    {
        Sys_chstAlarm();
        return;
    }

    if(IS_SYS_WARNING)
    {
        Sys_chstWarning();
        return;
    }
}



void Sys_hlsWarning(void)
{
    if(IS_SYS_ALARM)
    {
        Sys_chstAlarm();
        return;
    }

    if(IS_SYS_WARNING)
    {
        Sys_chstWarning();
        return;
    }

    Sys_chstStop();
}

void Sys_hlsAlarm(void)
{
    if(IS_SYS_ALARM)
    {
        Sys_chstAlarm();
        return;
    }

    if(IS_SYS_WARNING)
    {
        Sys_chstWarning();
        return;
    }

    Sys_chstStop();
}



