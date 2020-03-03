#include "sys_state_service.h"


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
    //system is in the init state;

    // check the init success flag
}

void Sys_hlstForwardRotate(void)
{
    //system is in the init state;
}

void Sys_hlsBackwardRotate(void)
{
    //system is in the init state;
}

void Sys_hlsStop(void)
{
    //system is in the init state;
}

void Sys_hlsWarning(void)
{
    //system is in the init state;
}

void Sys_hlsAlarm(void)
{
    //system is in the init state;
}



