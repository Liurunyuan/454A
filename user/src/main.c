#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "main.h"
/**
 * main.c
 */
int gtest = 0;

void main(void)
{
	InitSysCtrl();
	int i = 0;


	Init_GPIO_CFG(CfgGpioTbl_User);
	Init_PWM_CFG(CfgPwmTbl_User);
	Init_SCI_CFG(CfgSciTbl_User);
	Init_SPI_CFG(CfgSpiTbl_User);
	Init_XINTF_CFG(CfgXintfTbl_User);


    //TODO init globalvar

//
//	Init_ADC();
//
//	Init_XINTF();
//
//	Init_SCI();
//
//	Init_SPI();
//
//	Init_PWM();

	//init timer

	//init interrupt

	//main loop


	while(1)
	{
	    ++i;
	    if(i > 1000){
	        gtest++;
	        i = 0;
	    }
	}
}
