#include "sci_service.h"

void Sci_A_Receive(SCIRXQUE* RS422RxQue){
	int16 data;

	while(SciaRegs.SCIFFRX.bit.RXFFST != 0){// rs422 rx fifo is not empty
		data = SciaRegs.SCIRXBUF.all;
		if(SciRxEnQueue(data, RS422RxQue) == 0){
			// gSysState.alarm.bit.rs422RxQFull = 1;
		}
	}
}

void Sci_B_Receive(SCIRXQUE* RS422RxQue){
	int16 data;

	while(ScibRegs.SCIFFRX.bit.RXFFST != 0){// rs422 rx fifo is not empty
		data = ScibRegs.SCIRXBUF.all;
		if(SciRxEnQueue(data, RS422RxQue) == 0){
			// gSysState.alarm.bit.rs422RxQFull = 1;
		}
	}
}

void Sci_C_Receive(SCIRXQUE* RS422RxQue){
	int16 data;

	while(ScicRegs.SCIFFRX.bit.RXFFST != 0){// rs422 rx fifo is not empty
		data = ScicRegs.SCIRXBUF.all;
		if(SciRxEnQueue(data, RS422RxQue) == 0){
			// gSysState.alarm.bit.rs422RxQFull = 1;
		}
	}
}




