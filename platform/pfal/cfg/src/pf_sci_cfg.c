#include "pf_sci_cfg.h"

const CFG_SCI_TBL CFG_SCI_INFO[] =
{
    {
        {
            SCIA,       //sci moudule, A, B, C
            28,         //sci rx gpio index
            29          //sci tx gpio index
        },
        {
            BAUD_RATE_115200    //sci baud rate
        }
    },
    {
        {
            SCIB, 
            11,
            9
        },
        {
            BAUD_RATE_115200
        }
    },
    {
        {
            SCIC, 
            62,
            63
        },
        {
            BAUD_RATE_115200
        }
    }
};


void CFG_SCI_A(CFG_SCI_TBL cfgSciTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up for GPIO28 (SCIRXDA)
    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;    // Enable pull-up for GPIO29 (SCITXDA)

    GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (SCIRXDA)

    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;   // Configure GPIO28 for SCIRXDA operation
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1;   // Configure GPIO29 for SCITXDA operation
    EDIS;
}
void CFG_SCI_B(CFG_SCI_TBL cfgSciTblElement)
{
    EALLOW;
    switch(cfgSciTblElement.cfgSciGpio.rxNum)
    {
        case 11:
            GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;
            GpioCtrlRegs.GPAQSEL1.bit.GPIO11 = 3;
            GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 2;
            break;
        case 15:
            GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;
            GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 3;
            GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 2;


            break;
        case 19:
            GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;
            GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 3;
            GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 2;
            break;
        case 23:
            GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;
            GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 3;
            GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 3;
            break;
        default:
            //TODO generate warning
            break;
    }

    switch(cfgSciTblElement.cfgSciGpio.txNum)
    {
        case 9:
            GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;
            GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 2;
            break;
        case 14:
            GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;
            GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 2;
            break;
        case 18:
            GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;
            GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 2;
            break;
        case 22:
            GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;
            GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 3;
            break;
        default:
            //TODO generate warning
            break;
    }

    EDIS;
}
void CFG_SCI_C(CFG_SCI_TBL cfgSciTblElement)
{
    EALLOW;
    GpioCtrlRegs.GPBPUD.bit.GPIO62 = 0;    // Enable pull-up for GPIO62 (SCIRXDC)
    GpioCtrlRegs.GPBPUD.bit.GPIO63 = 0;    // Enable pull-up for GPIO63 (SCITXDC)

    GpioCtrlRegs.GPBQSEL2.bit.GPIO62 = 3;  // Asynch input GPIO62 (SCIRXDC)

    GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 1;   // Configure GPIO62 for SCIRXDC operation
    GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 1;   // Configure GPIO63 for SCITXDC operation
    EDIS;
}

const CFG_SCI_HDL_TBL SDB_CfgSCIHdlTbl[TOTAL_SCI] =
{
     CFG_SCI_A,
     CFG_SCI_B,
     CFG_SCI_C
};


void Init_SCI_CFG(CFG_SCI_TBL* cfgSciTbl)
{
    int i = 0;
    EALLOW;
    for(i = 0; i < sizeof(cfgSciTbl)/sizeof(cfgSciTbl[0]); ++i)
    {
        SDB_CfgSCIHdlTbl[cfgSciTbl[i].cfgSciGpio.sciModule](cfgSciTbl[i]);
    }
    EDIS;
}
