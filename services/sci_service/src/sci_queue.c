#include "sci_queue.h"


int SciRxEnQueue(int e, SCIRXQUE *RS422RxQue){

	if((RS422RxQue->rear + 1) % SCI_RX_QUEUE_LEN == RS422RxQue->front){
		RS422RxQue->front = (RS422RxQue->front + 1) % SCI_RX_QUEUE_LEN;
	}

	RS422RxQue->rxBuff[RS422RxQue->rear] = e;
	RS422RxQue->rear = (RS422RxQue->rear + 1) % SCI_RX_QUEUE_LEN;
	return 1;
}

int SciRxDeQueue(SCIRXQUE *RS422RxQue){
	if(RS422RxQue->front == RS422RxQue->rear){
		return 0;
	}

	RS422RxQue->front = (RS422RxQue->front + 1) % SCI_RX_QUEUE_LEN;
	return 1;
}

int IsQueueEmpty(SCIRXQUE *RS422RxQue){
	if(RS422RxQue->front == RS422RxQue->rear){
		return 0;
	}
	else{
		return 1;
	}
}

int GetQueLength(SCIRXQUE *RS422RxQue){
	int length;
	length = (RS422RxQue->rear - RS422RxQue->front + SCI_RX_QUEUE_LEN) % SCI_RX_QUEUE_LEN;
	return length;
}
