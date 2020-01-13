#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "main.h"
/**
 * main.c
 */
int main(void)
{
	InitSysCtrl_M();

    //TODO init globalvar

	Init_GPIO();

	Init_ADC();

	Init_XINTF();

	Init_SCI();

	Init_SPI();
	
	Init_PWM();

	//init timer

	//init interrupt

	//main loop

	return 0;
}
