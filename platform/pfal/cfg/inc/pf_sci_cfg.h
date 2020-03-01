#ifndef PF_SCI_CFG_H_
#define PF_SCI_CFG_H_

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

typedef enum
{
    BAUD_RATE_9600,
    BAUD_RATE_115200
}SCI_BAUD_RATE;

typedef struct
{
    SCI_ENABLE sciModule;
    int rxNum;
    int txNum;
}CFG_SCI_GPIO;

typedef struct
{
    SCI_BAUD_RATE sciBaudRate;

}CFG_SCI_PARAM;

typedef struct
{
    CFG_SCI_GPIO cfgSciGpio;
    CFG_SCI_PARAM cfgSciParam;
}CFG_SCI_TBL;


typedef void (*CFG_SCI_HDL_TBL)(CFG_SCI_TBL cfgSciTblElement);

void PFAL_SCI_CFG(CFG_SCI_TBL* cfgSciTbl, int len);

#endif
