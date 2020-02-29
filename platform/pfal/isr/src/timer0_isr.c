#include "timer0_isr.h"

int gtimertest = 0;
void Timer0_ISR(void)
{
    gtimertest++;
}
