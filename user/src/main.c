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
