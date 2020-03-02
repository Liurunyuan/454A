#ifndef RVDT_SERVICE_H_
#define RVDT_SERVICE_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

Uint16 *SDB_Resolver_read=(Uint16 *)0x100000;

int16 Get_RVDT_Position(Uint16 *Resolver_read);

#endif
