#include "timer0_isr.h"
#if(SYS_DEBUG == INCLUDE_FEATUER)
int gtimertest = 0;
#endif

void PFAL_Timer0_ISR(void)
{
#if(SYS_DEBUG == INCLUDE_FEATUER)
    gtimertest++;
#endif
}
