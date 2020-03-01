#ifndef SCI_PROTOCAL_H_
#define ASCI_PROTOCAL_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "sci_queue.h"

/*0x5a  0x5a    0x01    */
#define HEAD1 0x5a
#define HEAD2 0x5a
#define TAIL1 0xa5
#define TAIL2 0xa5
#define SUCCESS     (1)
#define FAIL        (0)
#define UNIT_LEN    (3)
#define EXTRA_LEN   (9)
#define OFFSET      (5)

typedef struct _DATA{
	Uint16 l : 8;
	Uint16 h : 8;
}DATA;

typedef union _VAR16{
	DATA datahl;
	int16 value;
}VAR16;

typedef void (*functionMsgCodeUnpack)(VAR16 a, int b,int c);
#endif



