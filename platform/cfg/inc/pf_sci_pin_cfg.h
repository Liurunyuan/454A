#ifndef PF_SCI_PIN_CFG_H_
#define PF_SCI_PIN_CFG_H_

// #include "DSP2833x_Gpio.h"
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define TOTAL_SCI 3

typedef enum
{
    SCIA,
    SCIB,
    SCIC
}SCI_ENABLE;

typedef struct
{
    SCI_ENABLE sciModule;
    int rxNum;
    int txNum;
}CFG_SCI_TBL;

typedef void (*CFG_SCI_HDL_TBL)(int rxNum, int txNum);

void Init_SCI_CFG(CFG_SCI_TBL* cfgSciTbl);

#endif
