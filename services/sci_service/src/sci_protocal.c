#include "sci_protocal.h"

char rs422rxPack[100] = {0};
const functionMsgCodeUnpack SDB_MsgFuncTbl[] = 
{
    0,
    0,
    0,
    0
};
int SciRxCalCrc(int crc, const char *buf, int len){
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

	if((RS422RxQue->rxBuff[(RS422RxQue->front + 2) % SCI_RX_QUEUE_LEN] * UNIT_LEN + EXTRA_LEN) <= GetSciRxQueLength(RS422RxQue)){
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
	while(GetSciRxQueLength(RS422RxQue) > EXTRA_LEN){
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

		if(SciRxCalCrc(0, rs422rxPack + OFFSET, length - EXTRA_LEN + 2) != 0){
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

//////////////////////////////////////////////SCI RX END, SCI TX BEGIN

int SciTxCalCrc(int crc, const char *buf, int len) {
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
#define TOTAL_TX_VAR (8)
#define S 0
Uint16 gRx422TxEnableFlag[TOTAL_TX_VAR] = {0};
void UpdateSciTxEnableFlag(SCITXVAR* sciTxVar, int len) {
	int i;
	for (i = 0; i < len; ++i) {
		sciTxVar[i].isTx = gRx422TxEnableFlag[i];
	}
}


 void PackSciTxPacket(SCITXQUE *RS422TxQue, SCITXVAR* sciTxVar)
 {
 	int i;
 	char crcl;
 	char crch;
 	static unsigned char count = 0;
 	static int crc = 0;
 	char tmp[3] = {0};
 	int lenPosition = 0;
 	Uint16 total =0;


 	if(count == 0){
 		if(SciTxEnQueue(0x5a,RS422TxQue) == 0){
 			return;
 		}
 		if(SciTxEnQueue(0x5a,RS422TxQue) == 0){
 			return;
 		}
 		lenPosition = RS422TxQue->rear;
 		if(SciTxEnQueue(0x05,RS422TxQue) == 0){
 			return;
 		}
 		if(SciTxEnQueue(0xff,RS422TxQue) == 0){
 			return;
 		}
 		if(SciTxEnQueue(0xff,RS422TxQue) == 0){
 			return;
 		}
 		UpdateSciTxEnableFlag(sciTxVar,TOTAL_TX_VAR);
 	}

 	for(i = 0; i < TOTAL_TX_VAR; ++i){
 		if(sciTxVar[i].isTx){
 			++total;

 			sciTxVar[i].updateValue(0,0,0);
 			tmp[0] = sciTxVar[i].index;
 			tmp[1] = sciTxVar[i].value >> 8;
 			tmp[2] = sciTxVar[i].value;
 			if(SciTxEnQueue(sciTxVar[i].index, RS422TxQue) == 0){
 				return;
 			}
 			if(SciTxEnQueue((sciTxVar[i].value >> 8), RS422TxQue) == 0){
 				return;
 			}
 			if(SciTxEnQueue(sciTxVar[i].value, RS422TxQue) == 0){
 				return;
 			}
 			crc = SciTxCalCrc(crc, tmp, 3);
 		}
 	}

 	if(count == 0){
 		RS422TxQue->txBuf[lenPosition] = total * (S + 1);//timer0 interrupt isr can not be interrupted by TX, so we can set length value here
 	}

 	++count;

 	if(count > S){

 		crcl = (char)crc;
 		crch = (char)(crc >> 8);
 		crc = 0;
 		count = 0;
 		if(SciTxEnQueue(crch, RS422TxQue) == 0){
 			return;
 		}
 		if(SciTxEnQueue(crcl, RS422TxQue) == 0){
 			return;
 		}
 		if(SciTxEnQueue(0xa5, RS422TxQue) == 0){
 			return;
 		}
 		if(SciTxEnQueue(0xa5, RS422TxQue) == 0){
 			return;
 		}
 	}
 }
