// TI File $Revision: /main/1 $
// Checkin $Date: August 18, 2006   13:46:25 $
//###########################################################################
//
// FILE:	DSP2833x_Gpio.c
//
// TITLE:	DSP2833x General Purpose I/O Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x Header Files V1.20 $
// $Release Date: August 1, 2008 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define GPIO 0
#define INPUT 0
#define OUTPUT 1

//---------------------------------------------------------------------------
// InitGpio: 
//---------------------------------------------------------------------------
// This function initializes the Gpio to a known (default) state.
//
// For more details on configuring GPIO's as peripheral functions,
// refer to the individual peripheral examples and/or GPIO setup example. 
void InitGpio(void)
{
   EALLOW;
   
   // Each GPIO pin can be: 
   // a) a GPIO input/output
   // b) peripheral function 1
   // c) peripheral function 2
   // d) peripheral function 3
   // By default, all are GPIO Inputs 
   GpioCtrlRegs.GPAMUX1.all = 0x0000;     // GPIO functionality GPIO0-GPIO15
   GpioCtrlRegs.GPAMUX2.all = 0x0000;     // GPIO functionality GPIO16-GPIO31
   GpioCtrlRegs.GPBMUX1.all = 0x0000;     // GPIO functionality GPIO32-GPIO39
   GpioCtrlRegs.GPBMUX2.all = 0x0000;     // GPIO functionality GPIO48-GPIO63
   GpioCtrlRegs.GPCMUX1.all = 0x0000;     // GPIO functionality GPIO64-GPIO79
   GpioCtrlRegs.GPCMUX2.all = 0x0000;     // GPIO functionality GPIO80-GPIO95

   GpioCtrlRegs.GPADIR.all = 0x0000;      // GPIO0-GPIO31 are inputs
   GpioCtrlRegs.GPBDIR.all = 0x0000;      // GPIO32-GPIO63 are inputs   
   GpioCtrlRegs.GPCDIR.all = 0x0000;      // GPI064-GPIO95 are inputs

   // Each input can have different qualification
   // a) input synchronized to SYSCLKOUT
   // b) input qualified by a sampling window
   // c) input sent asynchronously (valid for peripheral inputs only)
   GpioCtrlRegs.GPAQSEL1.all = 0x0000;    // GPIO0-GPIO15 Synch to SYSCLKOUT 
   GpioCtrlRegs.GPAQSEL2.all = 0x0000;    // GPIO16-GPIO31 Synch to SYSCLKOUT
   GpioCtrlRegs.GPBQSEL1.all = 0x0000;    // GPIO32-GPIO39 Synch to SYSCLKOUT 
   GpioCtrlRegs.GPBQSEL2.all = 0x0000;    // GPIO48-GPIO63 Synch to SYSCLKOUT 

   // Pull-ups can be enabled or disabled. 
   GpioCtrlRegs.GPAPUD.all = 0x0000;      // Pullup's enabled GPIO0-GPIO31
   GpioCtrlRegs.GPBPUD.all = 0x0000;      // Pullup's enabled GPIO32-GPIO63
   GpioCtrlRegs.GPCPUD.all = 0x0000;      // Pullup's enabled GPIO64-GPIO79

   //GpioCtrlRegs.GPAPUD.all = 0xFFFF;    // Pullup's disabled GPIO0-GPIO31
   //GpioCtrlRegs.GPBPUD.all = 0xFFFF;    // Pullup's disabled GPIO32-GPIO34
   //GpioCtrlRegs.GPCPUD.all = 0xFFFF     // Pullup's disabled GPIO64-GPIO79

   EDIS;

}	

void InitOutputPin(void)
{
	/*Read the circuit diagram and find which Pin need to init as Output GPIO, finsish the code here*/
	/*
	 * GPIO30
	 * Pin index:			1
	 * Name in circuit:		AD1K
	 */
	EALLOW;
	GpioCtrlRegs.GPAMUX2.bit.GPIO30	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO30	= OUTPUT;
	/*
	 * GPIO29
	 * Pin index:			2
	 * Name in circuit:		AD2K
	 */
	GpioCtrlRegs.GPAMUX2.bit.GPIO29	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO29	= OUTPUT;
	/*
	 * GPIO7
	 * Pin index:			16
	 * Name in circuit:		KZ_WDI_DSP
	 */
	GpioCtrlRegs.GPAMUX1.bit.GPIO7	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO7	= OUTPUT;

	/*
	 * GPIO9
	 * Pin index:			18
	 * Name in circuit 		CLR_OC_DSP
	 */
	GpioCtrlRegs.GPAMUX1.bit.GPIO9	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO9	= OUTPUT;
	/*GPIO51(pin index:91) is used to feed watch dog,so GPIO51 is output*/
	/*
	 * GPIO51
	 * Pin index:			91
	 * Name in circuit:		WDI
	 */
	GpioCtrlRegs.GPBMUX2.bit.GPIO51	= GPIO;
	GpioCtrlRegs.GPBDIR.bit.GPIO51	= OUTPUT;
	/*
	 *GPIO52
	 *Pin index:			94
	 *Name in circuit:		BIT_SER_CLK
	 */
	GpioCtrlRegs.GPBMUX2.bit.GPIO52	= GPIO;
	GpioCtrlRegs.GPBDIR.bit.GPIO52	= OUTPUT;
	/*
	 *GPIO53
	 *Pin index:			95
	 *Name in circuit:		BIT_SER_LOAD
	 */
	GpioCtrlRegs.GPBMUX2.bit.GPIO53	= GPIO;
	GpioCtrlRegs.GPBDIR.bit.GPIO53	= OUTPUT;
	/*
	 *GPIO85
	 *Pin index:			172
	 *Name in circuit:		AD4K
	 */
	GpioCtrlRegs.GPCMUX2.bit.GPIO85	= GPIO;
	GpioCtrlRegs.GPCDIR.bit.GPIO85	= OUTPUT;
	/*
	 *GPIO86
	 *Pin index:			173
	 *Name in circuit:		KZ_N_DSP
	 */
	GpioCtrlRegs.GPCMUX2.bit.GPIO86	= GPIO;
	GpioCtrlRegs.GPCDIR.bit.GPIO86	= OUTPUT;
	/*
	 *GPIO87
	 *Pin index:			174
	 *Name in circuit:		EN_OUT_BUF
	 */
	GpioCtrlRegs.GPCMUX2.bit.GPIO87	= GPIO;
	GpioCtrlRegs.GPCDIR.bit.GPIO87	= OUTPUT;
	/*
	 *GPIO39
	 *Pin index:			175
	 *Name in circuit:		AD3K
	 */
	GpioCtrlRegs.GPBMUX1.bit.GPIO39	= GPIO;
	GpioCtrlRegs.GPBDIR.bit.GPIO39	= OUTPUT;
	/*
	 *GPIO31
	 *Pin index:			176
	 *Name in circuit:		KZ_P_DSP
	 */
	GpioCtrlRegs.GPAMUX2.bit.GPIO31	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO31	= OUTPUT;


	/*
	 *GPIO82
	 *Pin index:			165
	 *Name in circuit:		GPIO82, just for test to calculate the function running time
	 */
	GpioCtrlRegs.GPCMUX2.bit.GPIO82	= GPIO;
	GpioCtrlRegs.GPCDIR.bit.GPIO82	= OUTPUT;

	/*
	 *GPIO84
	 *Pin index:			169
	 *Name in circuit:		GPIO84, just for test��GPIO84-------->CNV_AD;
	 */
	GpioCtrlRegs.GPCMUX2.bit.GPIO84	= GPIO;
	GpioCtrlRegs.GPCDIR.bit.GPIO84	= OUTPUT;


	/*
	 *GPIO6
	 *Pin index:			13
	 *Name in circuit:		GPIO6;
	 */
	GpioCtrlRegs.GPAMUX1.bit.GPIO6	= GPIO;
	GpioDataRegs.GPASET.bit.GPIO6 = 1;
	GpioCtrlRegs.GPADIR.bit.GPIO6	= OUTPUT;

	//GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;

	EDIS;
}

void InitInputPin(void)
{
	/*Read the circuit diagram and find which Pin need to init as Output GPIO, finsish the code here*/
	/*
	 * GPIO10
	 * Pin index:			19
	 * Name in circuit:		DIS_DSP
	 */
	GpioCtrlRegs.GPAMUX1.bit.GPIO10	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO10	= INPUT;
	/*
	 * GPIO11
	 * Pin index:			20
	 * Name in circuit:		EN_PWM_DSP
	 */
	GpioCtrlRegs.GPAMUX1.bit.GPIO11	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO11	= INPUT;
	/*
	 * GPIO12
	 * Pin index:			21
	 * Name in circuit:		P_SD_DSP
	 */
	GpioCtrlRegs.GPAMUX1.bit.GPIO12	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO12	= INPUT;
	/*
	 * GPIO13
	 * Pin index:			24
	 * Name in circuit:		PG_DSP
	 */
	GpioCtrlRegs.GPAMUX1.bit.GPIO13	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO13	= INPUT;
	/*
	 * GPIO14
	 * Pin index:			25
	 * Name in circuit:		DC_FLT_DSP
	 */
	GpioCtrlRegs.GPAMUX1.bit.GPIO14	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO14	= INPUT;
	/*
	 * GPIO15
	 * Pin index:			26
	 * Name in circuit:		DC_EN_DSP
	 */
	GpioCtrlRegs.GPAMUX1.bit.GPIO15	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO15	= INPUT;
	/*
	 * GPIO16
	 * Pin index:			27
	 * Name in circuit:		X_OC_F_DSP
	 */
	GpioCtrlRegs.GPAMUX2.bit.GPIO16	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO16	= INPUT;
	/*
	 * GPIO17
	 * Pin index:			28
	 * Name in circuit:		Q_OC_F_DSP
	 */
	GpioCtrlRegs.GPAMUX2.bit.GPIO17	= GPIO;
	GpioCtrlRegs.GPADIR.bit.GPIO17	= INPUT;
    /*
     * GPIO35
     * Pin index:           148
     * Name in circuit:     GPIO35 ROLL
     */
    GpioCtrlRegs.GPBMUX1.bit.GPIO35 = GPIO;
    GpioCtrlRegs.GPBDIR.bit.GPIO35  = INPUT;
	/*
	 * GPIO59
	 * Pin index:			110
	 * Name in circuit:		BIT_SER_DIN_P
	 */
	GpioCtrlRegs.GPBMUX2.bit.GPIO59	= GPIO;
	GpioCtrlRegs.GPBDIR.bit.GPIO59	= INPUT;
	/*
	 * GPIO60
	 * Pin index:			111
	 * Name in circuit:		BIT_SER_DIN_N
	 */
	GpioCtrlRegs.GPBMUX2.bit.GPIO60	= GPIO;
	GpioCtrlRegs.GPBDIR.bit.GPIO60	= INPUT;
    /*
     * GPIO61
     * Pin index:           112
     * Name in circuit:     GPIO61 PITCH
     */
    GpioCtrlRegs.GPBMUX2.bit.GPIO61 = GPIO;
    GpioCtrlRegs.GPBDIR.bit.GPIO61  = INPUT;
}
/*
 * Initialize the GPIO
 */
void Init_GPIO()
{
	InitOutputPin();
	InitInputPin();
}

typedef enum
{
    GPIO_INTPUT,
    GPIO_OUTPUT
}GPIO_DIRECTION;
void CFG_GPIO_0(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = GPIO;
	 GpioCtrlRegs.GPADIR.bit.GPIO0  = direction;
}
void CFG_GPIO_1(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO1  = direction;
}
void CFG_GPIO_2(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO2  = direction;
}
void CFG_GPIO_3(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO3  = direction;
}
void CFG_GPIO_4(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO4 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO4  = direction;
}
void CFG_GPIO_5(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO5 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO5  = direction;
}
void CFG_GPIO_6(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO6 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO6  = direction;
}
void CFG_GPIO_7(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO7 = GPIO;
    GpioCtrlRegs.GPADIR.bit.GPIO7  = direction;
}
void CFG_GPIO_8(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO8 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO8  = direction;
}
void CFG_GPIO_9(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO9 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO9  = direction;
}
void CFG_GPIO_10(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO10 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO10  = direction;
}
void CFG_GPIO_11(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO11 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO11  = direction;
}
void CFG_GPIO_12(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO12 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO12  = direction;
}
void CFG_GPIO_13(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO13 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO13  = direction;
}
void CFG_GPIO_14(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO14 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO14  = direction;
}
void CFG_GPIO_15(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX1.bit.GPIO15 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO15  = direction;
}
void CFG_GPIO_16(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO16 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO16  = direction;
}
void CFG_GPIO_17(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO17 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO17  = direction;
}
void CFG_GPIO_18(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO18 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO18  = direction;
}
void CFG_GPIO_19(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO19 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO19  = direction;
}
void CFG_GPIO_20(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO20 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO20  = direction;
}
void CFG_GPIO_21(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO21 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO21  = direction;
}
void CFG_GPIO_22(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO22 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO22  = direction;
}
void CFG_GPIO_23(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO23 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO23  = direction;
}
void CFG_GPIO_24(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO24 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO24  = direction;
}
void CFG_GPIO_25(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO25 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO25  = direction;
}
void CFG_GPIO_26(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO26 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO26  = direction;
}
void CFG_GPIO_27(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO27 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO27  = direction;
}
void CFG_GPIO_28(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO28  = direction;
}
void CFG_GPIO_29(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO29  = direction;
}
void CFG_GPIO_30(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO30 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO30  = direction;
}
void CFG_GPIO_31(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPAMUX2.bit.GPIO31 = GPIO;
     GpioCtrlRegs.GPADIR.bit.GPIO31  = direction;
}
void CFG_GPIO_32(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO32 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO32  = direction;
}
void CFG_GPIO_33(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO33 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO33  = direction;
}
void CFG_GPIO_34(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO34 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO34  = direction;
}
void CFG_GPIO_35(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO35 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO35  = direction;
}
void CFG_GPIO_36(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO36 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO36  = direction;
}
void CFG_GPIO_37(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO37 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO37  = direction;
}
void CFG_GPIO_38(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO38 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO38  = direction;
}
void CFG_GPIO_39(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO39 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO39  = direction;
}
void CFG_GPIO_40(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO40 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO40  = direction;
}
void CFG_GPIO_41(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO41 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO41  = direction;
}
void CFG_GPIO_42(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO42 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO42  = direction;
}
void CFG_GPIO_43(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO43 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO43  = direction;
}
void CFG_GPIO_44(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO44 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO44  = direction;
}
void CFG_GPIO_45(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO45 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO45  = direction;
}
void CFG_GPIO_46(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO46 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO46  = direction;
}
void CFG_GPIO_47(GPIO_DIRECTION direction)
{
	GpioCtrlRegs.GPBMUX1.bit.GPIO47 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO47  = direction;
}
void CFG_GPIO_48(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO48 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO48  = direction;
}
void CFG_GPIO_49(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO49 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO49  = direction;
}
void CFG_GPIO_50(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO50 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO50  = direction;
}
void CFG_GPIO_51(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO51 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO51  = direction;
}
void CFG_GPIO_52(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO52 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO52  = direction;
}
void CFG_GPIO_53(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO53 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO53  = direction;
}
void CFG_GPIO_54(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO54 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO54  = direction;
}
void CFG_GPIO_55(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO55 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO55  = direction;
}
void CFG_GPIO_56(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO56 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO56  = direction;
}
void CFG_GPIO_57(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO57 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO57  = direction;
}
void CFG_GPIO_58(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO58 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO58  = direction;
}
void CFG_GPIO_59(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO59 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO59  = direction;
}
void CFG_GPIO_60(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO60 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO60  = direction;
}
void CFG_GPIO_61(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO61 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO61  = direction;
}
void CFG_GPIO_62(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO62 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO62  = direction;
}
void CFG_GPIO_63(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPBMUX2.bit.GPIO63 = GPIO;
     GpioCtrlRegs.GPBDIR.bit.GPIO63  = direction;
}
void CFG_GPIO_64(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO64 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO64 = direction;
}
void CFG_GPIO_65(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO65 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO65 = direction;
}
void CFG_GPIO_66(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO66 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO66 = direction;
}
void CFG_GPIO_67(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO67 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO67 = direction;
}
void CFG_GPIO_68(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO68 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO68 = direction;
}
void CFG_GPIO_69(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO69 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO69 = direction;
}
void CFG_GPIO_70(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO70 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO70 = direction;
}
void CFG_GPIO_71(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO71 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO71 = direction;
}
void CFG_GPIO_72(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO72 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO72 = direction;
}
void CFG_GPIO_73(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO73 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO73 = direction;
}
void CFG_GPIO_74(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO74 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO74 = direction;
}
void CFG_GPIO_75(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO75 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO75 = direction;
}
void CFG_GPIO_76(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO76 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO76 = direction;
}
void CFG_GPIO_77(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO77 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO77 = direction;
}
void CFG_GPIO_78(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO78 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO78 = direction;
}
void CFG_GPIO_79(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX1.bit.GPIO79 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO79 = direction;
}
void CFG_GPIO_80(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX2.bit.GPIO80 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO80 = direction;
}
void CFG_GPIO_81(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX2.bit.GPIO81 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO81 = direction;
}
void CFG_GPIO_82(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX2.bit.GPIO82 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO82 = direction;
}
void CFG_GPIO_83(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX2.bit.GPIO83 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO83 = direction;
}
void CFG_GPIO_84(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX2.bit.GPIO84 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO84 = direction;
}
void CFG_GPIO_85(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX2.bit.GPIO85 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO85 = direction;
}
void CFG_GPIO_86(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX2.bit.GPIO86 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO86 = direction;
}
void CFG_GPIO_87(GPIO_DIRECTION direction)
{
    GpioCtrlRegs.GPCMUX2.bit.GPIO87 = GPIO;
     GpioCtrlRegs.GPCDIR.bit.GPIO87 = direction;
}

typedef void (*CFG_GPIO_HDL_TBL)(GPIO_DIRECTION direction);
#define TOTAL_GPIO 88
const CFG_GPIO_HDL_TBL CfgGPIOHdlTbl[TOTAL_GPIO] =
{
	CFG_GPIO_0,
	CFG_GPIO_1,
	CFG_GPIO_2,
	CFG_GPIO_3,
	CFG_GPIO_4,
	CFG_GPIO_5,
	CFG_GPIO_6,
	CFG_GPIO_7,
	CFG_GPIO_8,
	CFG_GPIO_9,
	CFG_GPIO_10,
	CFG_GPIO_11,
	CFG_GPIO_12,
	CFG_GPIO_13,
	CFG_GPIO_14,
	CFG_GPIO_15,
	CFG_GPIO_16,
	CFG_GPIO_17,
	CFG_GPIO_18,
	CFG_GPIO_19,
	CFG_GPIO_20,
	CFG_GPIO_21,
	CFG_GPIO_22,
	CFG_GPIO_23,
	CFG_GPIO_24,
	CFG_GPIO_25,
	CFG_GPIO_26,
	CFG_GPIO_27,
	CFG_GPIO_28,
	CFG_GPIO_29,
	CFG_GPIO_30,
	CFG_GPIO_31,
	CFG_GPIO_32,
	CFG_GPIO_33,
	CFG_GPIO_34,
	CFG_GPIO_35,
	CFG_GPIO_36,
	CFG_GPIO_37,
	CFG_GPIO_38,
	CFG_GPIO_39,
	CFG_GPIO_40,
	CFG_GPIO_41,
	CFG_GPIO_42,
	CFG_GPIO_43,
	CFG_GPIO_44,
	CFG_GPIO_45,
	CFG_GPIO_46,
	CFG_GPIO_47,
	CFG_GPIO_48,
	CFG_GPIO_49,
	CFG_GPIO_50,
	CFG_GPIO_51,
	CFG_GPIO_52,
	CFG_GPIO_53,
	CFG_GPIO_54,
	CFG_GPIO_55,
	CFG_GPIO_56,
	CFG_GPIO_57,
	CFG_GPIO_58,
	CFG_GPIO_59,
	CFG_GPIO_60,
	CFG_GPIO_61,
	CFG_GPIO_62,
	CFG_GPIO_63,
	CFG_GPIO_64,
	CFG_GPIO_65,
	CFG_GPIO_66,
	CFG_GPIO_67,
	CFG_GPIO_68,
	CFG_GPIO_69,
	CFG_GPIO_70,
	CFG_GPIO_71,
	CFG_GPIO_72,
	CFG_GPIO_73,
	CFG_GPIO_74,
	CFG_GPIO_75,
	CFG_GPIO_76,
	CFG_GPIO_77,
	CFG_GPIO_78,
	CFG_GPIO_79,
	CFG_GPIO_80,
	CFG_GPIO_81,
	CFG_GPIO_82,
	CFG_GPIO_83,
	CFG_GPIO_84,
	CFG_GPIO_85,
	CFG_GPIO_86,
	CFG_GPIO_87
};
typedef struct
{
	int gpioIndex;
	GPIO_DIRECTION direction;
}CFG_GPIO_HDL_TBL_MAP;

const CFG_GPIO_HDL_TBL_MAP CFG_GPIO_INFO[] =
{
 {3, GPIO_OUTPUT},
 {3, GPIO_OUTPUT},
 {3, GPIO_OUTPUT},
 {3, GPIO_OUTPUT},
 {3, GPIO_OUTPUT},
 {3, GPIO_OUTPUT},
 {3, GPIO_OUTPUT},
 {3, GPIO_OUTPUT},
 {3, GPIO_OUTPUT},
 {3, GPIO_OUTPUT},
 {3, GPIO_OUTPUT}
};

void Init_GPIO_CFG(CFG_GPIO_HDL_TBL_MAP* cfgTblMap, CFG_GPIO_HDL_TBL* CfgGPIOHdlTbl)
{
	int i = 0;
	EALLOW;
	for(i = 0; i < sizeof(cfgTblMap)/sizeof(cfgTblMap[0]); ++i)
	{
	    CfgGPIOHdlTbl[cfgTblMap[i].gpioIndex](cfgTblMap[i].direction);
	}
	EDIS;
}
/////////////////////////////////////////////////////////////////////////////lry
void CFG_SCI_A(int rxNum, int txNum)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up for GPIO28 (SCIRXDA)
    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;    // Enable pull-up for GPIO29 (SCITXDA)

    GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (SCIRXDA)

    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1;   // Configure GPIO28 for SCIRXDA operation
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1;   // Configure GPIO29 for SCITXDA operation
    EDIS;
}
void CFG_SCI_B(int rxNum, int txNum)
{
    EALLOW;
    switch(rxNum)
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

    switch(txNum)
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
void CFG_SCI_C(int rxNum, int txNum)
{
    EALLOW;
    GpioCtrlRegs.GPBPUD.bit.GPIO62 = 0;    // Enable pull-up for GPIO62 (SCIRXDC)
    GpioCtrlRegs.GPBPUD.bit.GPIO63 = 0;    // Enable pull-up for GPIO63 (SCITXDC)

    GpioCtrlRegs.GPBQSEL2.bit.GPIO62 = 3;  // Asynch input GPIO62 (SCIRXDC)

    GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 1;   // Configure GPIO62 for SCIRXDC operation
    GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 1;   // Configure GPIO63 for SCITXDC operation

    EDIS;
}
typedef void (*CFG_SCI_HDL_TBL)(int rxNum, int txNum);
#define TOTAL_SCI 3
const CFG_SCI_HDL_TBL CfgSCIHdlTbl[TOTAL_SCI] =
{
     CFG_SCI_A,
     CFG_SCI_B,
     CFG_SCI_C
};


typedef enum
{
    SCIA,
    SCIB,
    SCIC
}SCI_ENABLE;

typedef struct
{
    SCI_ENABLE sciModule;
    int rxNum;
    int txNum;
}CFG_SCI_HDL_TBL_MAP;

const CFG_SCI_HDL_TBL_MAP CFG_SCI_INFO[] =
{
 {SCIA, 28,29},
 {SCIB, 11,9},
 {SCIC, 62,63},
};

void Init_SCI_CFG(CFG_SCI_HDL_TBL_MAP* cfgSciTblMap, CFG_SCI_HDL_TBL* CfgSCIHdlTbl)
{
    int i = 0;
    EALLOW;
    for(i = 0; i < sizeof(cfgSciTblMap)/sizeof(cfgSciTblMap[0]); ++i)
    {
        CfgSCIHdlTbl[cfgSciTblMap[i].sciModule](cfgSciTblMap[i].rxNum, cfgSciTblMap[i].txNum);
    }
    EDIS;
}
/////////////////////////////////////////////////////////////////////////lry
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
typedef void (*CFG_PWM_HDL_TBL)(void);
#define TOTAL_PWM 12
const CFG_PWM_HDL_TBL CfgPwmHdlTbl[TOTAL_PWM] =
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
typedef enum
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
}PWM_ENABLE;

typedef struct
{
    PWM_ENABLE pwmModule;
}CFG_PWM_HDL_TBL_MAP;


const CFG_PWM_HDL_TBL_MAP CFG_PWM_INFO[] =
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
void Init_PWM_CFG(CFG_PWM_HDL_TBL_MAP* cfgPwmTblMap, CFG_PWM_HDL_TBL* CfgPwmHdlTbl)
{
    int i = 0;
    EALLOW;
    for(i = 0; i < sizeof(cfgPwmTblMap)/sizeof(cfgPwmTblMap[0]); ++i)
    {
        CfgPwmHdlTbl[cfgPwmTblMap[i].pwmModule]();
    }
    EDIS;
}



//===========================================================================
// End of file.
//===========================================================================
