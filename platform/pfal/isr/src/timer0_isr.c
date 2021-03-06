#include "timer0_isr.h"
#include "prod.h"

#if(SYS_DEBUG == INCLUDE_FEATURE)
int gtimertest = 0;
#endif
int gtimertest = 0;

Uint32 gSSIDATA = 0;
Uint32 gSSIDATABAK = 0;
Uint32 gGPIO62DATA = 0;
Uint16 gGPIO62Array[30] = {0};
void SimulateSSI(void)
{
    static int count = 0;
    static int subWait = 0;
    Uint32 tmp = 0;

    if(count == 0)
    {
        GpioDataRegs.GPBCLEAR.bit.GPIO63 = 1;
        count++;
        gSSIDATA = 0;
        return;
    }

    if(count == 1)
    {
        GpioDataRegs.GPBSET.bit.GPIO63 = 1;
        count++;
        return;
    }

    if(count == 33)
    {
        GpioDataRegs.GPBSET.bit.GPIO63 = 1;

        if(subWait++ > 60)
        {
            gSSIDATABAK = gSSIDATA >> 1;
            subWait = 0;
            count = 0;
        }
        return;
    }

    if((count % 2) == 0)
    {
//        gGPIO62DATA = GpioDataRegs.GPBDAT.bit.GPIO62;
        tmp = GpioDataRegs.GPBDAT.bit.GPIO62;
        gSSIDATA |= (tmp << (17 - (count/2)));
        gGPIO62Array[17 - count/2] = GpioDataRegs.GPBDAT.bit.GPIO62;
        GpioDataRegs.GPBCLEAR.bit.GPIO63 = 1;
        count++;
        return;
    }

    if((count % 2) == 1)
    {
        GpioDataRegs.GPBSET.bit.GPIO63 = 1;
        count++;
        return;
    }
}


void PFAL_Timer0_ISR(void)
{
#if(SYS_DEBUG == INCLUDE_FEATURE)
    gtimertest++;
#endif
    static Uint64 count = 0;
    if(count < 200000)
    {
        ++count;
        return;
    }
    gtimertest++;
    SimulateSSI();
}
