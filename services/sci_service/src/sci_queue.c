#include "sci_queue.h"


int SciRxEnQueue(int e, SCIRXQUE *RS422RxQue)
{
	if((RS422RxQue->rear + 1) % SCI_RX_QUEUE_LEN == RS422RxQue->front)
	{
		RS422RxQue->front = (RS422RxQue->front + 1) % SCI_RX_QUEUE_LEN;
	}

	RS422RxQue->rxBuff[RS422RxQue->rear] = e;
	RS422RxQue->rear = (RS422RxQue->rear + 1) % SCI_RX_QUEUE_LEN;
	return 1;
}

int SciRxDeQueue(SCIRXQUE *RS422RxQue)
{
	if(RS422RxQue->front == RS422RxQue->rear)
	{
		return 0;
	}

	RS422RxQue->front = (RS422RxQue->front + 1) % SCI_RX_QUEUE_LEN;
	return 1;
}

int IsSciRxQueueEmpty(SCIRXQUE *RS422RxQue)
{
	if(RS422RxQue->front == RS422RxQue->rear)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int GetSciRxQueLength(SCIRXQUE *RS422RxQue)
{
	int length;
	length = (RS422RxQue->rear - RS422RxQue->front + SCI_RX_QUEUE_LEN) % SCI_RX_QUEUE_LEN;
	return length;
}

int SciTxEnQueue(char e, SCITXQUE *RS422TxQue)
{
	if((RS422TxQue->rear + 1) % SCI_TX_QUEUE_LEN == RS422TxQue->front)
	{
		return 0;
	}
	RS422TxQue->txBuf[RS422TxQue->rear] = e;
	RS422TxQue->rear = (RS422TxQue->rear + 1) % SCI_TX_QUEUE_LEN;
	return 1;
}
int SciTxDeQueue(SCITXQUE *RS422TxQue)
{
	if(RS422TxQue->front == RS422TxQue->rear)
	{
		return 0;
	}

	RS422TxQue->front = (RS422TxQue->front + 1) % SCI_TX_QUEUE_LEN;
	return 1;
}

int GetSciTxQueLength(SCITXQUE *RS422TxQue)
{
	int length;
	length = (RS422TxQue->rear - RS422TxQue->front + SCI_TX_QUEUE_LEN) % SCI_TX_QUEUE_LEN;
	return length;
}
