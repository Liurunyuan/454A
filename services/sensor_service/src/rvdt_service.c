#include "rvdt_service.h"


int16 Get_RVDT_Position(Uint16 *Resolver_read)
{
	int16 rvdt_result_tem1=0;/*ç¬¬ä¸€æ¬¡æ—‹å�˜ä½�ç½®ä¿¡å�·å€¼ï¼Œå�ˆæ³•èŒƒå›´0~4095ï¼Œåˆ�å§‹å€¼ä¸º0ï¼Œå¼•ç”¨å‡½æ•°Rvdt_readï¼Œæ”¹å�˜å‡½æ•°Rvdt_read*/
	int16 rvdt_result_tem2=0;/*ç¬¬äºŒæ¬¡æ—‹å�˜ä½�ç½®ä¿¡å�·å€¼ï¼Œå�ˆæ³•èŒƒå›´0~4095ï¼Œåˆ�å§‹å€¼ä¸º0ï¼Œå¼•ç”¨å‡½æ•°Rvdt_readï¼Œæ”¹å�˜å‡½æ•°Rvdt_read*/
 	int16 rvdt_result_tem3=0;/*ç¬¬ä¸‰æ¬¡æ—‹å�˜ä½�ç½®ä¿¡å�·å€¼ï¼Œå�ˆæ³•èŒƒå›´0~4095ï¼Œåˆ�å§‹å€¼ä¸º0ï¼Œå¼•ç”¨å‡½æ•°Rvdt_readï¼Œæ”¹å�˜å‡½æ•°Rvdt_read*/
    int16 rvdt_result;
	rvdt_result_tem1 =*Resolver_read>>4;/*è¿žç»­è¯»ä¸‰æ¬¡æ—‹å�˜ä½�ç½®ä¿¡å�·*/
	rvdt_result_tem2 =*Resolver_read>>4;
	rvdt_result_tem3 =*Resolver_read>>4;
	if(rvdt_result_tem1==rvdt_result_tem2)/*å�–ä¸¤æ¬¡ç›¸å�Œçš„å€¼*/
	{
		rvdt_result = rvdt_result_tem1;
	}
	else if(rvdt_result_tem1==rvdt_result_tem3)
	{
		rvdt_result = rvdt_result_tem1;
	}
	else
	{
		rvdt_result = rvdt_result_tem2;
	}
	if(rvdt_result<0||rvdt_result>4095)
	{
		//TODO generate warining
	}
	else
	{
    }
    return rvdt_result;
}
