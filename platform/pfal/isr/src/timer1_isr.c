#include "timer1_isr.h"



int gtimer1test = 0;
void PFAL_Timer1_ISR(void)
{
    gtimer1test++;
}
