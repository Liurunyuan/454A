#ifndef PF_PWM_PIN_CFG_H_
#define PF_PWM_PIN_CFG_H_

// #include "DSP2833x_Gpio.h"
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define TOTAL_PWM 12

typedef enum
{
    PWM1A,
    PWM1B,
    PWM2A,
    PWM2B,
    PWM3A,
    PWM3B,
    PWM4A,
    PWM4B,
    PWM5A,
    PWM5B,
    PWM6A,
    PWM6B
}PWM_ENABLE;

typedef struct
{
    PWM_ENABLE pwmModule;
}CFG_PWM_TBL;

typedef void (*CFG_PWM_HDL_TBL)(void);

void Init_PWM_CFG(CFG_PWM_TBL* cfgPwmTbl);

#endif /* MAIN_H_ */

