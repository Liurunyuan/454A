#include "spwm_service.h"
SPWM_PARA gSpwmPara = {0};
static void FindSinTbl(int16 ct,int16 *psinvalue)
{
	if(ct < 1024)
	{
		*psinvalue = SDC_Sin_Tbl[ct]; 		/* 0--90*/
	}
	else if(ct < 2048)
	{
		*psinvalue = SDC_Sin_Tbl[2047-ct]; 	/* 90--180*/
	}
	else if(ct < 3072)
	{
		*psinvalue = -SDC_Sin_Tbl[ct-2048];	/* 180--270*/
	}
	else if(ct < 4096)
	{
		*psinvalue =- SDC_Sin_Tbl[4095-ct]; 	/* 270--360*/
	}
	else
	{

    }
}

void Calculate_Three_Phase_Duty(SPWM_PARA* spwmPara)
{
	   long ful;
	   int16 pa,pb;
       int16 ct = spwmPara->Rvdt_Pos;

	   FindSinTbl(ct,&pa);

	   ct += 1365;
	   if(ct > 4095) ct -= 4096;

	   FindSinTbl(ct,&pb);

	   ful = (long)pa * (long)spwmPara->Duty;
	   spwmPara->Phase_Duty_U = (int16)(ful/32000);
	   ful = (long)pb * (long)spwmPara->Duty;
	   spwmPara->Phase_Duty_V = (int16)(ful/32000);
	   spwmPara->Phase_Duty_W = -(spwmPara->Phase_Duty_U + spwmPara->Phase_Duty_V);
}


void Spwm_Output(SPWM_PARA* spwmPara)
{
#if(SPWM_DUTY_GRADUAL_CHANGE == INCLUDE_FEATURE)
	++spwmPara->DutyAddIntervalCnt;
	if(spwmPara->DutyAddIntervalCnt < spwmPara->DutyAddInterval){
       return;
   	}
	spwmPara->DutyAddIntervalCnt = 0;

	if(spwmPara->Duty_Gradual > spwmPara->TargetDuty){
       	spwmPara->Duty_Gradual = (spwmPara->Duty_Gradual - spwmPara->Ddtmax) < spwmPara->TargetDuty ? spwmPara->TargetDuty : (spwmPara->Duty_Gradual -spwmPara->Ddtmax);
    }
    else if(spwmPara->Duty_Gradual < spwmPara->TargetDuty){
    	spwmPara->Duty_Gradual = (spwmPara->Duty_Gradual + spwmPara->Ddtmax) > spwmPara->TargetDuty ? spwmPara->TargetDuty : (spwmPara->Duty_Gradual + spwmPara->Ddtmax);
    }
    else{
           //nothing need change
    }

   	if(spwmPara->Duty_Gradual > spwmPara->ThresholdDutyP)
	{
    	spwmPara->Duty_Gradual = spwmPara->ThresholdDutyP;
   	}
   	else if(spwmPara->Duty_Gradual < spwmPara->ThresholdDutyN)
	{
       	spwmPara->Duty_Gradual = spwmPara->ThresholdDutyN;
   	}

	spwmPara->Duty = spwmPara->Duty_Gradual;
#endif

#if(SPWM_DUTY_GRADUAL_CHANGE == EXCLUDE_FEATURE)
    spwmPara->Duty = spwmPara->TargetDuty;
#endif

    spwmPara->Rvdt_Current_Pos = Get_RVDT_Position(SDB_RVDT_Read_Addr);

    spwmPara->Rvdt_Pos = spwmPara->Rvdt_Current_Pos - spwmPara->Rvdt_Zero;

	if(spwmPara->Rvdt_Pos < 0)
	{
		spwmPara->Rvdt_Pos += 4096;
	}
	else if(spwmPara->Rvdt_Pos > 4095)
	{
		spwmPara->Rvdt_Pos -= 4096;
	}
	else
	{
        //TODO generate alarm
    }

    Calculate_Three_Phase_Duty(spwmPara);

    EPMW1_OUTPUT_DUAL_PLOARITY(750, spwmPara->Phase_Duty_W);
    EPMW2_OUTPUT_DUAL_PLOARITY(750, spwmPara->Phase_Duty_V);
    EPMW3_OUTPUT_DUAL_PLOARITY(750, spwmPara->Phase_Duty_U);
}

void Init_Spwm_Service(void)
{
	gSpwmPara.Duty = 0;
	gSpwmPara.Phase_Duty_U = 0;
	gSpwmPara.Phase_Duty_V = 0;
	gSpwmPara.Phase_Duty_W = 0;
	gSpwmPara.Rvdt_Current_Pos = 0;
	gSpwmPara.Rvdt_Pos = 0;
	gSpwmPara.Rvdt_Zero = 0;
	gSpwmPara.Duty_Gradual = 0;
	gSpwmPara.DutyAddInterval = 0;
	gSpwmPara.DutyAddIntervalCnt = 0;
	gSpwmPara.Ddtmax = 0;
	gSpwmPara.ThresholdDutyP = 0;
	gSpwmPara.ThresholdDutyN = 0;
}
