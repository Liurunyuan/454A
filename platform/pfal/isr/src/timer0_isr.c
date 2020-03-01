#include "timer0_isr.h"

int gtimertest = 0;
void PFAL_Timer0_ISR(void)
{
    gtimertest++;
}
