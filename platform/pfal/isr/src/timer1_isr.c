#include "timer1_isr.h"


#if(SYS_DEBUG == INCLUDE_FEATUER)
int gtimer1test = 0;
#endif

void PFAL_Timer1_ISR(void)
{
#if(SYS_DEBUG == INCLUDE_FEATUER)
    gtimer1test++;
#endif
}
