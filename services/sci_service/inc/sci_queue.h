#ifndef SCI_QUEUE_H_
#define SCI_QUEUE_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#define SCI_RX_QUEUE_LEN 800
#define SCI_TX_QUEUE_LEN 900

typedef struct _RS422RXQUE{
	char rxBuff[SCI_RX_QUEUE_LEN];
	int front;
	int rear;
}SCIRXQUE;


typedef struct _RS422TXQUE{
	char txBuf[SCI_TX_QUEUE_LEN];
	int front;
	int rear;
}SCITXQUE;


int SciRxEnQueue(int e, SCIRXQUE *RS422RxQue);
int SciTxEnQueue(char e, SCITXQUE *RS422TxQue);
int SciRxDeQueue(SCIRXQUE *RS422RxQue);
int SciTxDeQueue(SCITXQUE *RS422TxQue);
int IsSciRxQueueEmpty(SCIRXQUE *RS422RxQue);
int GetSciRxQueLength(SCIRXQUE *RS422RxQue);
int GetSciTxQueLength(SCITXQUE *RS422TxQue);
#endif
