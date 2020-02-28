#include "pf_pwm_pin_cfg.h"


const CFG_PWM_TBL CfgPwmTbl[] =
{
     PWM1A,
     PWM1B,
     PWM2A,
     PWM2B,
     PWM3A,
     PWM3B,
     PWM4A,
     PWM4B,
     PWM5A,
     PWM5B,
     PWM6A,
     PWM6B
};

void CFG_PWM_1A(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;    // Enable pull-up on GPIO0 (EPWM1A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A

    EDIS;

}
void CFG_PWM_1B(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;    // Enable pull-up on GPIO1 (EPWM1B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B
    EDIS;

}
void CFG_PWM_2A(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;    // Enable pull-up on GPIO2 (EPWM2A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
    EDIS;
}
void CFG_PWM_2B(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;    // Enable pull-up on GPIO3 (EPWM3B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B
    EDIS;
}
void CFG_PWM_3A(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;    // Enable pull-up on GPIO4 (EPWM3A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
    EDIS;
}
void CFG_PWM_3B(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;    // Enable pull-up on GPIO5 (EPWM3B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B
    EDIS;
}
void CFG_PWM_4A(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWM4A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;   // Configure GPIO6 as EPWM4A
    EDIS;
}
void CFG_PWM_4B(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;
    EDIS;
}
void CFG_PWM_5A(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 0;    // Enable pull-up on GPIO8 (EPWM5A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;   // Configure GPIO8 as EPWM5A
    EDIS;
}
void CFG_PWM_5B(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;    // Enable pull-up on GPIO9 (EPWM5B)
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;   // Configure GPIO9 as EPWM5B
    EDIS;
}
void CFG_PWM_6A(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0;    // Enable pull-up on GPIO10 (EPWM6A)
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;   // Configure GPIO10 as EPWM6A
    EDIS;
}
void CFG_PWM_6B(void)
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


void Init_PWM_CFG(CFG_PWM_TBL* cfgPwmTbl)
{
    int i = 0;
    EALLOW;
    for(i = 0; i < sizeof(cfgPwmTbl)/sizeof(cfgPwmTbl[0]); ++i)
    {
        SDB_CfgPwmHdlTbl[cfgPwmTbl[i].pwmModule]();
    }
    EDIS;
}
