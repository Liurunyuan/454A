#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "main.h"
#include <stdlib.h>

/**
 * main.c
 */
#if(SYS_DEBUG == INCLUDE_FEATURE	)
int gtest = 0;
int i = 0;
#endif

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

	while(1)
	{
	    TOOGLE_CTL_BOARD_WATCHDOG;

		TOOGLE_DRIVE_BOARD_WATCHDOG;

		DIGIT_SIG_ROUTING_INSPECTION();
#if(SYS_DEBUG == INCLUDE_FEATURE)
		PF_ProcessSciRxPacket(gScibRxQue);
#elif
        ProcessSciRxPacket(gScibRxQue);
#endif
		SYS_STATE_MACHINE;
		++i;
		if(i > 1000)
		{
        	PackSciTxPacket(gScibTxQue,gSciTxVar);
			i = 0;
		}
        CheckEnableScibTx(gScibTxQue);
	}
}
