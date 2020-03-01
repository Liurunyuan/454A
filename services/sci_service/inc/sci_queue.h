#ifndef SCI_QUEUE_H_
#define SCI_QUEUE_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#define SCI_RX_QUEUE_LEN 800

typedef struct _RS422RXQUE{
	char rxBuff[SCI_RX_QUEUE_LEN];
	int front;
	int rear;
}SCIRXQUE;


int SciRxEnQueue(int e, SCIRXQUE *RS422RxQue);
int SciRxDeQueue(SCIRXQUE *RS422RxQue);
int IsQueueEmpty(SCIRXQUE *RS422RxQue);
int SciRxQueLength(SCIRXQUE *RS422RxQue);
#endif
