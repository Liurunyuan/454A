#ifndef PF_SPI_PIN_CFG_H_
#define PF_SPI_PIN_CFG_H_

// #include "DSP2833x_Gpio.h"
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define TOTAL_SPI 1

typedef struct
{
    int spiSIMOAPin;
    int spiSOMIAPin;
    int spiCLKAPin;
    int spiSTEAPin;
}CFG_SPI_TBL;

typedef void (*CFG_SPI_HDL_TBL)(int p1, int p2, int p3, int p4);

void Init_SPI_CFG(CFG_SPI_TBL* cfgSpiTbl);

#endif