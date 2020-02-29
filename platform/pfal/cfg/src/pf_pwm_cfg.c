#include "pf_pwm_cfg.h"


const CFG_PWM_TBL CfgPwmTbl[] =
{
    {
        PWM1A,          //pwm module selected
        40000           //pwm frequency
    },
    {
        PWM1B,
        40000
    },
    {
        PWM2A,
        40000
    },
    {
        PWM2B,
        40000
    },
    {
        PWM3A,
        40000
    },
    {
        PWM3B,
        40000
    },
    {
        PWM4A,
        40000
    },
    {
        PWM4B,
        40000
    },
    {
        PWM5A,
        40000
    },
    {
        PWM5B,
        40000
    },
    {
        PWM6A,
        40000
    },
    {
        PWM6B,
        40000
    }
};

void CFG_PWM_1A(CFG_PWM_TBL cfgPwmTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;    // Enable pull-up on GPIO0 (EPWM1A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A

    EDIS;

}
void CFG_PWM_1B(CFG_PWM_TBL cfgPwmTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;    // Enable pull-up on GPIO1 (EPWM1B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B
    EDIS;

}
void CFG_PWM_2A(CFG_PWM_TBL cfgPwmTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;    // Enable pull-up on GPIO2 (EPWM2A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
    EDIS;
}
void CFG_PWM_2B(CFG_PWM_TBL cfgPwmTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;    // Enable pull-up on GPIO3 (EPWM3B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B
    EDIS;
}
void CFG_PWM_3A(CFG_PWM_TBL cfgPwmTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;    // Enable pull-up on GPIO4 (EPWM3A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
    EDIS;
}
void CFG_PWM_3B(CFG_PWM_TBL cfgPwmTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;    // Enable pull-up on GPIO5 (EPWM3B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B
    EDIS;
}
void CFG_PWM_4A(CFG_PWM_TBL cfgPwmTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWM4A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;   // Configure GPIO6 as EPWM4A
    EDIS;
}
void CFG_PWM_4B(CFG_PWM_TBL cfgPwmTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;
    EDIS;
}
void CFG_PWM_5A(CFG_PWM_TBL cfgPwmTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 0;    // Enable pull-up on GPIO8 (EPWM5A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;   // Configure GPIO8 as EPWM5A
    EDIS;
}
void CFG_PWM_5B(CFG_PWM_TBL cfgPwmTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;    // Enable pull-up on GPIO9 (EPWM5B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;   // Configure GPIO9 as EPWM5B
    EDIS;
}
void CFG_PWM_6A(CFG_PWM_TBL cfgPwmTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0;    // Enable pull-up on GPIO10 (EPWM6A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;   // Configure GPIO10 as EPWM6A
    EDIS;
}
void CFG_PWM_6B(CFG_PWM_TBL cfgPwmTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;    // Enable pull-up on GPIO11 (EPWM6B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;   // Configure GPIO11 as EPWM6B
    EDIS;
}


const CFG_PWM_HDL_TBL SDB_CfgPwmHdlTbl[TOTAL_PWM] =
{
     CFG_PWM_1A,
     CFG_PWM_1B,
     CFG_PWM_2A,
     CFG_PWM_2B,
     CFG_PWM_3A,
     CFG_PWM_3B,
     CFG_PWM_4A,
     CFG_PWM_4B,
     CFG_PWM_5A,
     CFG_PWM_5B,
     CFG_PWM_6A,
     CFG_PWM_6B
};


void Init_PWM_CFG(CFG_PWM_TBL* cfgPwmTbl, int len)
{
    int i = 0;
    EALLOW;
    for(i = 0; i < len; ++i)
    {
        SDB_CfgPwmHdlTbl[cfgPwmTbl[i].cfgPwmModule.pwmModule](cfgPwmTbl[i]);
    }
    EDIS;
}
