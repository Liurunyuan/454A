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

#define Sys_chstInit()                  Sys_hlstPtr = Sys_hlstInit;
#define Sys_chstStop()                  Sys_hlstPtr = Sys_hlsStop;
#define Sys_chstForwardRotate()         Sys_hlstPtr = Sys_hlstForwardRotate;
#define Sys_chstBackwardRotate()        Sys_hlstPtr = Sys_hlstBackwardRotate;
#define Sys_chstWarning()               Sys_hlstPtr = Sys_hlsWarning;
#define Sys_chstAlarm()                 Sys_hlstPtr = Sys_hlsAlarm;



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



