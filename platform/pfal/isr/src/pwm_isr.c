#include "pwm_isr.h"
#include "prod.h"
#include "sci_protocal.h"
#include "sci_service.h"

#if(SYS_DEBUG == INCLUDE_FEATURE)

#endif
int gpwmisr = 0;
void PFAL_PWM_ISR(void)
{
#if(SYS_DEBUG == INCLUDE_FEATURE)

#endif
    gpwmisr++;
    Spwm_Output(&gSpwmPara);
    CheckEnableScibTx(gScibTxQue);
}

