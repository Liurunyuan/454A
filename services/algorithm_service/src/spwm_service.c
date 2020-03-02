#include "spwm_service.h"

static void FindSinTbl(int16 ct,int16 *psinvalue)
{
	if(ct < 1024)
	{
		*psinvalue=SDC_Sin_Tbl[ct]; 		/* 0--90*/
	}
	else if(ct < 2048)
	{
		*psinvalue=SDC_Sin_Tbl[2047-ct]; 	/* 90--180*/
	}
	else if(ct < 3072)
	{
		*psinvalue=-SDC_Sin_Tbl[ct-2048];	/* 180--270*/
	}
	else if(ct < 4096)
	{
		*psinvalue=-SDC_Sin_Tbl[4095-ct]; 	/* 270--360*/
	}
	else
	{

    }
}

void Cal_Three_Phase_Duty(SPWM_PARA* spwmPara)
{
	   long ful;/*å� ç©ºæ¯”ç �å€¼ä¸Žæ—‹å�˜å€¼ä¹˜ç§¯ï¼Œå�ˆæ³•èŒƒå›´0~4095ï¼Œåˆ�å§‹å€¼ä¸º0ï¼Œå¼•ç”¨å‡½æ•°SPWMï¼Œæ”¹å�˜å‡½æ•°SPWM*/
       int16 ct = spwmPara->Rvdt_Pos;
	   int16 pa,pb;/*è¯»å�–çš„æ­£å¼¦å€¼ï¼Œå�ˆæ³•èŒƒå›´0~32000ï¼Œåˆ�å§‹å€¼æ— ï¼Œå¼•ç”¨å‡½æ•°SPWMï¼Œæ”¹å�˜å‡½æ•°SPWM*/

	   FindSinTbl(ct,&pa);  /*Aç›¸æŸ¥æ­£å¼¦è¡¨*/
	   ct += 1365;  /* 4096/3=>1365ï¼ŒAç›¸ä¸ŽBç›¸ç›¸ä½�å·®120åº¦*/
	   if(ct > 4095) ct -= 4096;
	   FindSinTbl(ct,&pb);	/*Bç›¸æŸ¥æ­£å¼¦è¡¨*/
	   ful=(long)pa*(long)spwmPara->Amplitude;
	   spwmPara->Phase_Duty_U = (int16)(ful/32000);/*è®¡ç®—Aç›¸å� ç©ºæ¯”å€¼*/
	   ful=(long)pb*(long)spwmPara->Amplitude;
	   spwmPara->Phase_Duty_V = (int16)(ful/32000);/*è®¡ç®—Bç›¸å� ç©ºæ¯”å€¼*/
	   spwmPara->Phase_Duty_W = -(spwmPara->Phase_Duty_U + spwmPara->Phase_Duty_V);	/*Aï¼ŒBï¼ŒCä¸‰ç›¸å� ç©ºæ¯”å’Œä¸º0*/
}


void SPWM_outA(void)
{
	static int16 cta=0;/*ç”¨äºŽæŸ¥æ­£å¼¦è¡¨çš„æ—‹å�˜ç �å€¼ï¼Œå�ˆæ³•èŒƒå›´0~4095ï¼Œåˆ�å§‹å€¼ä¸º0ï¼Œå¼•ç”¨å‡½æ•°SPWM_outAï¼Œæ”¹å�˜å‡½æ•°SPWM_outA*/
	static int16 rvdt_zero=953;/*æ—‹å�˜ä½�ç½®ç›¸å¯¹ç”µæœºå��ç”µåŠ¿çš„é›¶ä½�å€¼ï¼Œå�ˆæ³•èŒƒå›´0~4095ï¼Œåˆ�å§‹å€¼ä¸º0ï¼Œå¼•ç”¨å‡½æ•°SPWM_outA*/
	// cta=rvdt_result-rvdt_zero;/*è°ƒæ•´é©±åŠ¨ç”µåŠ¿é›¶ä½�*/
	if(cta<0)
	{
		cta+=4096;
	}
	else if(cta>4095)
	{
		cta-=4096;
	}
	else
	{;}
	// SPWM(cta,Duty);
	// EPwm1Regs.CMPA.half.CMPA = EPWM1_TIMER_HALF_TBPRD+w_pwm;/*Aç›¸å� ç©ºæ¯”è¾“å‡º*/
	// EPwm2Regs.CMPA.half.CMPA = EPWM1_TIMER_HALF_TBPRD+v_pwm;/*Bç›¸å� ç©ºæ¯”è¾“å‡º*/
	// EPwm3Regs.CMPA.half.CMPA = EPWM1_TIMER_HALF_TBPRD+u_pwm;/*Cç›¸å� ç©ºæ¯”è¾“å‡º*/
}

