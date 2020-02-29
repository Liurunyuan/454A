#include "pf_interrupt_cfg.h"

const CFG_INTERRUPT_TBL CfgInterruptTbl_Default[] =
{
    TIMER0_ISR,
    TIMER1_ISR,
};
void CFG_INTERRUPT(CFG_ISR_ENABLE isrEnable)
{

    switch (isrEnable)
    {
    case TIMER0_ISR:
        /* code */
        PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
        break;
    case TIMER1_ISR:
        IER |= M_INT13;//timer1
        /* code */
        break;
    case EPWM1:
        /* code */
        break;
    case ECAP1:
        /* code */
        break;
    case SCIARX:
        /* code */
        break;
    case SCIATX:
        /* code */
        break;
    
    default:
        break;
    }

}

const CFG_INTERRUPT_HDL_TBL SDB_CfgInterruptHdlTbl[TOTAL_INTERRUPT] =
{
    CFG_INTERRUPT
};


void Init_INTERRUPT_CFG(CFG_INTERRUPT_TBL* cfgInterruptTbl, int len)
{
    int i;
    DINT;
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();
    IER |= M_INT1;
    IER |= M_INT2;
    IER |= M_INT3;
    IER |= M_INT4;
    IER |= M_INT7;
    IER |= M_INT8;//SCIc
    IER |= M_INT9;//SCIa//ECAN//scib

    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;
    PieCtrlRegs.PIEACK.all = 0xFFFF;

    for(i = 0; i < len; ++i)
	{
	    SDB_CfgInterruptHdlTbl[0](cfgInterruptTbl[i].cfgIsrEnable);
	}

    EINT;   // Enable Global interrupt INTM
    ERTM;

}

