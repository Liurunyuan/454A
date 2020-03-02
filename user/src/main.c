#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "main.h"
/**
 * main.c
 */
int gtest = 0;
int arinc429[11] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11};

void setCtlReg(void)
{
    Uint16 data = 0;
    int i = 0;
    GpioDataRegs.GPBCLEAR.bit.GPIO61 = 1;
    while(GpioDataRegs.GPBDAT.bit.GPIO61 != 0);
    for(i = 0; i < 20000; ++i){
        asm (" NOP");
    }
    data = 0x0010;
    SpiaRegs.SPITXBUF = (data)<< 8;
    data = 0x1234;
    SpiaRegs.SPITXBUF = (data << 8);
    data = 0x4312;
    SpiaRegs.SPITXBUF = (data << 8);

    while(SpiaRegs.SPIFFRX.bit.RXFFST < 3);
    arinc429[2] = SpiaRegs.SPIRXBUF;
    arinc429[3] = SpiaRegs.SPIRXBUF;
    arinc429[4] = SpiaRegs.SPIRXBUF;
    GpioDataRegs.GPBSET.bit.GPIO61 = 1;
    for(i = 0; i < 20000; ++i){
        asm (" NOP");
    }

}

void readStatusReg(void)
{
    Uint16 data = 0;
    int i = 0;
    for(i = 0; i < 20000; ++i){
        asm (" NOP");
    }
    GpioDataRegs.GPBCLEAR.bit.GPIO61 = 1;
    while(GpioDataRegs.GPBDAT.bit.GPIO61 != 0);
    for(i = 0; i < 20000; ++i){
        asm (" NOP");
    }
    data = 0x000a;
    SpiaRegs.SPITXBUF = (data << 8);
    data = 0x1234;
    SpiaRegs.SPITXBUF = (data << 8);
    while(SpiaRegs.SPIFFRX.bit.RXFFST < 2);
    arinc429[0] = SpiaRegs.SPIRXBUF;
    arinc429[1] = SpiaRegs.SPIRXBUF;
    GpioDataRegs.GPBSET.bit.GPIO61 = 1;
    for(i = 0; i < 20000; ++i){
        asm (" NOP");
    }

}

void readCtlReg(void)
{
    int i = 0;
    for(i = 0; i < 20000; ++i){
        asm (" NOP");
    }
    Uint16 data = 0;

    GpioDataRegs.GPBCLEAR.bit.GPIO61 = 1;
    while(GpioDataRegs.GPBDAT.bit.GPIO61 != 0);
    for(i = 0; i < 20000; ++i){
        asm (" NOP");
    }
    data = 0x000d;
    SpiaRegs.SPITXBUF = (data << 8);
    data = 0x0001;
    SpiaRegs.SPITXBUF = (data << 8);
    data = 0x0001;
    SpiaRegs.SPITXBUF = (data << 8);
    while(SpiaRegs.SPIFFRX.bit.RXFFST < 3) {
    }
    arinc429[5] = SpiaRegs.SPIRXBUF;
    arinc429[6] = SpiaRegs.SPIRXBUF;
    arinc429[7] = SpiaRegs.SPIRXBUF;
	arinc429[8] = SpiaRegs.SPIRXBUF;
    GpioDataRegs.GPBDAT.bit.GPIO61 = 1;
    for(i = 0; i < 20000; ++i){
        asm (" NOP");
    }

}
int gpio60state = -1;
int gpio61state = -1;
void main(void)
{
	int i = 0;

	InitSysCtrl();
	PFAL_ADC_CFG(CfgAdcTbl_User,sizeof(CfgAdcTbl_User)/sizeof(CfgAdcTbl_User[0]));		//pass the test
	PFAL_GPIO_CFG(CfgGpioTbl_User,sizeof(CfgGpioTbl_User)/sizeof(CfgGpioTbl_User[0]));	//pass the test
	PFAL_PWM_CFG(CfgPwmTbl_User,sizeof(CfgPwmTbl_User)/sizeof(CfgPwmTbl_User[0]));		//pass the test
	PFAL_SCI_CFG(CfgSciTbl_User,sizeof(CfgSciTbl_User)/sizeof(CfgSciTbl_User[0]));		//pass the test
	PFAL_SPI_CFG(CfgSpiTbl_User,sizeof(CfgSpiTbl_User)/sizeof(CfgSpiTbl_User[0]));
	PFAL_XINTF_CFG(CfgXintfTbl_User,sizeof(CfgXintfTbl_User)/sizeof(CfgXintfTbl_User[0]));
	PFAL_TIMER_CFG(CfgTimerTbl_User,sizeof(CfgTimerTbl_User)/sizeof(CfgTimerTbl_User[0]));//pass the test
	PFAL_INTERRUPT_CFG(CfgInterruptTbl_User,sizeof(CfgInterruptTbl_User)/sizeof(CfgInterruptTbl_User[0]));

    GpioDataRegs.GPBDAT.bit.GPIO60 = 1;
    for(i = 0; i < 20; ++i){
        asm (" NOP");
    }
	GpioDataRegs.GPBDAT.bit.GPIO60 = 0;


    setCtlReg();
    readStatusReg();
    readCtlReg();






	while(1)
	{
	    ++i;
	    if(i > 1000){
	        gpio60state = GpioDataRegs.GPBDAT.bit.GPIO60;
	        gpio61state = GpioDataRegs.GPBDAT.bit.GPIO61;

	        gtest++;
	        i = 0;
	    }
	}
}
