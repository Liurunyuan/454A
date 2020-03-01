#include "sci_protocal.h"

char rs422rxPack[100] = {0};
const functionMsgCodeUnpack SDB_MsgFuncTbl[] = 
{
};
int CalCrc(int crc, const char *buf, int len){
	int x;
	int i;

	for(i = 0; i < len; ++i){
		x = ((crc >> 8) ^ buf[i]) & 0xff;
		x ^= x >> 4;
		crc = (crc << 8) ^ (x  << 12) ^ (x << 5) ^ x;
		crc &= 0xffff;
	}
	return crc;
}

int FindRxPacketHead(SCIRXQUE *RS422RxQue){

	char head1;
	char head2;

	while(1){

		head1 = RS422RxQue->rxBuff[RS422RxQue->front];
		head2 = RS422RxQue->rxBuff[(RS422RxQue->front + 1) % SCI_RX_QUEUE_LEN];

		if(head1 == HEAD1 && head2 == HEAD2){
			return SUCCESS;
		}

		if(SciRxDeQueue(RS422RxQue) == 0){
			return FAIL;
		}
	}
}

int FindRxPacketTail(int len, SCIRXQUE *RS422RxQue){
	char tail1;
	char tail2;

	tail1 = RS422RxQue->rxBuff[(RS422RxQue->front + len - 1) % SCI_RX_QUEUE_LEN];
	tail2 = RS422RxQue->rxBuff[(RS422RxQue->front + len - 2) % SCI_RX_QUEUE_LEN];

	if(tail1 == TAIL1 && tail2 == TAIL2){
		return SUCCESS;
	}
	else{
		return FAIL;
	}
}

int CheckRxPacketLength(SCIRXQUE *RS422RxQue){

	if((RS422RxQue->rxBuff[(RS422RxQue->front + 2) % SCI_RX_QUEUE_LEN] * UNIT_LEN + EXTRA_LEN) <= SciRxQueLength(RS422RxQue)){
		return SUCCESS;
	}
	else{
		return FAIL;
	}
}

void SaveRxPacketProfile(int len, SCIRXQUE *RS422RxQue){
	int i;

	for(i = 0; i < len; ++i){
		rs422rxPack[i] = RS422RxQue->rxBuff[(RS422RxQue->front + i) % SCI_RX_QUEUE_LEN];
	}
}

void UnpackRxProfile(int len){
	int i;
	int msgCode;
	VAR16 var16;

	for(i = 0; i < len; ++i){

		msgCode = rs422rxPack[OFFSET + UNIT_LEN * i];
		var16.datahl.h = rs422rxPack[OFFSET + UNIT_LEN*i + 1];
		var16.datahl.l = rs422rxPack[OFFSET + UNIT_LEN*i + 2];
		//var16.value = var16.datahl.l + (var16.datahl.h << 8);

		if(msgCode < (sizeof(SDB_MsgFuncTbl) / sizeof(SDB_MsgFuncTbl[0]))){
			//printf("msgCode = %d\r\n",msgCode);
			if(SDB_MsgFuncTbl[msgCode]){
				SDB_MsgFuncTbl[msgCode](var16, 0, 0);
			}
		}
		else{
			//printf("unpack msg code is out of range\r\n");
		}
	}
}

void UpdateRxQueueHeadPos(int len, SCIRXQUE *RS422RxQue){
	RS422RxQue->front = (RS422RxQue->front + len) % SCI_RX_QUEUE_LEN;
}

void ProcessSciRxPacket(SCIRXQUE *RS422RxQue){
	int length;
	while(SciRxQueLength(RS422RxQue) > EXTRA_LEN){
		if(FindRxPacketHead(RS422RxQue) == FAIL){
			//printf("find head failed\r\n");
			return;
		}
		else{
			//printf("find head succeed\r\n");
		}

		if(CheckRxPacketLength(RS422RxQue) == FAIL){
			return;
		}
		else{
			//printf("Check data length succeed, begin to check tail\r\n");
		}

		length = RS422RxQue->rxBuff[(RS422RxQue->front + 2) % SCI_RX_QUEUE_LEN] * UNIT_LEN + EXTRA_LEN;

		if(FindRxPacketTail(length,RS422RxQue) == FAIL){
			//printf("find tail failed\r\n");
			if(SciRxDeQueue(RS422RxQue) == 0){
				//printf("RS422 rx queue is empty\r\n");
			}
			return;
		}
		else{
			//printf("find tail succeed\r\n");
		}

		SaveRxPacketProfile(length,RS422RxQue);

		if(CalCrc(0, rs422rxPack + OFFSET, length - EXTRA_LEN + 2) != 0){
			if(SciRxDeQueue(RS422RxQue) == 0){
				//printf("RS422 rx queue is empty\r\n");
			}
			//printf("CRC check failed\r\n");
			return;
		}
		else{
			//printf("CRC check succeed\r\n");
		}

		UnpackRxProfile(RS422RxQue->rxBuff[(RS422RxQue->front + 2) % SCI_RX_QUEUE_LEN]);

		UpdateRxQueueHeadPos(length, RS422RxQue);
	}
}
