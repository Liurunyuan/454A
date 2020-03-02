#ifndef SPWM_SERVICE_H_
#define SPWM_SERVICE_H_

// #include "DSP2833x_Gpio.h"
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "prod.h"
#include "sin_table.h"
#include "rvdt_service.h"


typedef struct _SPWM_PARA
{
    int16 Phase_Duty_U;
    int16 Phase_Duty_V;
    int16 Phase_Duty_W;
    int16 Duty;
    int16 Rvdt_Pos;
    int16 Rvdt_Current_Pos;
    int16 Rvdt_Zero;
    /* data */
}SPWM_PARA;

#endif
