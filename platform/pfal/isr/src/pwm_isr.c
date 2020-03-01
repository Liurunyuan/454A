#include "pwm_isr.h"

int gpwmisr = 0;
void PFAL_PWM_ISR(void)
{
    gpwmisr++;
}

