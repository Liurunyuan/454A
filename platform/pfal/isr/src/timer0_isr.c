#include "timer0_isr.h"
#include "prod.h"

#if(SYS_DEBUG == INCLUDE_FEATURE)
int gtimertest = 0;
#endif

void PFAL_Timer0_ISR(void)
{
#if(SYS_DEBUG == INCLUDE_FEATURE)
    gtimertest++;
#endif
}
