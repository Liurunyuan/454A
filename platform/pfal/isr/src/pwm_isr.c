#include "pwm_isr.h"

#if(SYS_DEBUG == INCLUDE_FEATUER)
int gpwmisr = 0;
#endif
void PFAL_PWM_ISR(void)
{
#if(SYS_DEBUG == INCLUDE_FEATUER)
    gpwmisr++;
#endif
    Spwm_Output(&gSpwmPara);
}

