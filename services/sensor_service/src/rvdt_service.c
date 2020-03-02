#include "rvdt_service.h"

Uint16 *SDB_RVDT_Read_Addr = (Uint16 *)0x100000;
int16 Get_RVDT_Position(Uint16 *Resolver_read)
{
	int16 rvdt_result_tem1=0;
	int16 rvdt_result_tem2=0;
 	int16 rvdt_result_tem3=0;
    int16 rvdt_result;
	rvdt_result_tem1 =*Resolver_read>>4;
	rvdt_result_tem2 =*Resolver_read>>4;
	rvdt_result_tem3 =*Resolver_read>>4;
	if(rvdt_result_tem1==rvdt_result_tem2)
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
