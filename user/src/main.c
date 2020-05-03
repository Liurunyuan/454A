#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "main.h"
#include <stdlib.h>
#include "pf_isr.h"
#include "flash_hal.h"

/**
 * main.c
 */
#if(SYS_DEBUG == INCLUDE_FEATURE)
int gtest = 0;
Uint16 flashArrayW[4] = {0x0802, 0x1991, 0x1234, 0x5678};
Uint16 flashArrayR[4] = {0, 0, 0, 0};
int i = 0;
Uint16 *Resolver_read=(Uint16 *)0x100000;
Uint16 Resolver_result=0;
#endif

Uint16 gtArinc429RegStatus = 0;
Uint16 gtArinc429CtlReg = 0;


void main(void)
{
	InitSysCtrl();

	Init_Sys_State_Service();
	Init_Spwm_Service();
    Init_Sci_Service();
	Init_Adc_Service();

	PFAL_ADC_CFG(CfgAdcTbl_User,sizeof(CfgAdcTbl_User)/sizeof(CfgAdcTbl_User[0]));		        //pass the test
	PFAL_GPIO_CFG(CfgGpioTbl_User,sizeof(CfgGpioTbl_User)/sizeof(CfgGpioTbl_User[0]));	        //pass the test
	PFAL_PWM_CFG(CfgPwmTbl_User,sizeof(CfgPwmTbl_User)/sizeof(CfgPwmTbl_User[0]));		        //pass the test
	PFAL_SCI_CFG(CfgSciTbl_User,sizeof(CfgSciTbl_User)/sizeof(CfgSciTbl_User[0]));		        //pass the test
	PFAL_SPI_CFG(CfgSpiTbl_User,sizeof(CfgSpiTbl_User)/sizeof(CfgSpiTbl_User[0]));              //pass the test
	PFAL_XINTF_CFG(CfgXintfTbl_User,sizeof(CfgXintfTbl_User)/sizeof(CfgXintfTbl_User[0]));  
	PFAL_TIMER_CFG(CfgTimerTbl_User,sizeof(CfgTimerTbl_User)/sizeof(CfgTimerTbl_User[0]));      //pass the test
	PFAL_INTERRUPT_CFG(CfgInterruptTbl_User,sizeof(CfgInterruptTbl_User)/sizeof(CfgInterruptTbl_User[0]));

	ENABLE_DRIVE_BOARD_PWM_OUTPUT();
	TURN_ON_PWM_VALVE;

	Arinc429_MR_DEASSERT;
	int i;
	for(i = 0; i < 20; ++i)
	{
		asm (" NOP");
	}

	Arinc429_MR_ASSERT;
	for(i = 0; i < 20; ++i)
	{
		asm (" NOP");
	}

	Arinc429_MR_DEASSERT;
	for(i = 0; i < 20; ++i)
	{
		asm (" NOP");
	}

#if(SYS_DEBUG == INCLUDE_FEATURE)
	DISABLE_GLOBAL_INTERRUPT;
	if(Flash_WR(0x330000, flashArrayW, sizeof(flashArrayW)) == STATUS_SUCCESS)
	{
		gtest |= 0x01;

	}
	else
	{
		gtest |= 0x02; /* code */
	}
	if(Flash_RD(0x330000,flashArrayR, sizeof(flashArrayR)) == STATUS_SUCCESS)
	{
		gtest |= 0x04;
	}
	else
	{
		gtest |= 0x08;
	}
	ENABLE_GLOBAL_INTERRUPT;
#endif

	ARINC429_CTL_REG tmp;
	tmp.all = 0x2800;

	while(1)
	{
	    TOOGLE_CTL_BOARD_WATCHDOG;

		TOOGLE_DRIVE_BOARD_WATCHDOG;

		DIGIT_SIG_ROUTING_INSPECTION();
#if(SYS_DEBUG == INCLUDE_FEATURE)
		PF_ProcessSciRxPacket(gScibRxQue);
		Resolver_result =(*Resolver_read) >> 6;
#else
        ProcessSciRxPacket(gScibRxQue);
#endif
		SYS_STATE_MACHINE;

        PackSciTxPacket(gScibTxQue,gSciTxVar);

        Arinc429_SetCtlReg(tmp);

        gtArinc429RegStatus = Arinc429_ReadStatusReg();

        gtArinc429CtlReg = Arinc429_ReadCtlReg();

		// GpioDataRegs.GPBTOGGLE.bit.GPIO54 = 1;
        CheckEnableScibTx(gScibTxQue);
	}
}
