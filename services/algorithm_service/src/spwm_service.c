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

void Calculate_Three_Phase_Duty(SPWM_PARA* spwmPara)
{
	   long ful;
       int16 ct = spwmPara->Rvdt_Pos;
	   int16 pa,pb;

	   FindSinTbl(ct,&pa);
	   ct += 1365;
	   if(ct > 4095) ct -= 4096;
	   FindSinTbl(ct,&pb);
	   ful=(long)pa*(long)spwmPara->Amplitude;
	   spwmPara->Phase_Duty_U = (int16)(ful/32000);
	   ful=(long)pb*(long)spwmPara->Amplitude;
	   spwmPara->Phase_Duty_V = (int16)(ful/32000);
	   spwmPara->Phase_Duty_W = -(spwmPara->Phase_Duty_U + spwmPara->Phase_Duty_V);
}


void SPWM_outA(void)
{
	static int16 cta=0;
	static int16 rvdt_zero=953;

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

