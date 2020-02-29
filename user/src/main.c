#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "main.h"
/**
 * main.c
 */
int gtest = 0;
int length = -1;

void main(void)
{
	int i = 0;
	InitSysCtrl();

	Init_GPIO_CFG(CfgGpioTbl_User,sizeof(CfgGpioTbl_User)/sizeof(CfgGpioTbl_User[0]));
	Init_PWM_CFG(CfgPwmTbl_User,sizeof(CfgPwmTbl_User)/sizeof(CfgPwmTbl_User[0]));
	Init_SCI_CFG(CfgSciTbl_User,sizeof(CfgSciTbl_User)/sizeof(CfgSciTbl_User[0]));
	Init_SPI_CFG(CfgSpiTbl_User,sizeof(CfgSpiTbl_User)/sizeof(CfgSpiTbl_User[0]));
	Init_XINTF_CFG(CfgXintfTbl_User,sizeof(CfgXintfTbl_User)/sizeof(CfgXintfTbl_User[0]));
	Init_TIMER_CFG(CfgTimerTbl_User,sizeof(CfgTimerTbl_User)/sizeof(CfgTimerTbl_User[0]));
	Init_INTERRUPT_CFG(CfgInterruptTbl_User,sizeof(CfgInterruptTbl_User)/sizeof(CfgInterruptTbl_User[0]));


    //TODO init globalvar




	while(1)
	{
	    ++i;
	    if(i > 1000){
	        gtest++;
	        i = 0;
	    }
	}
}
