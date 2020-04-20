#include "rvdt_service.h"
#include "prod.h"

Uint16 *SDB_RVDT_Read_Addr = (Uint16 *)0x100000;
Uint16 Get_RVDT_Position(Uint16 *Resolver_read)
{
#if(SYS_DEBUG == INCLUDE_FEATURE)
	static int i = 0;

	++i;
	if(i > 4095)
	{
		i = 0;
	}
	return i;
#else
	Uint16 rvdt_result_tem1=0;
	Uint16 rvdt_result_tem2=0;
 	Uint16 rvdt_result_tem3=0;
    Uint16 rvdt_result;
	rvdt_result_tem1 = (*Resolver_read);
	rvdt_result_tem2 = (*Resolver_read);
	rvdt_result_tem3 = (*Resolver_read);
	if(rvdt_result_tem1 == rvdt_result_tem2)
	{
		rvdt_result = rvdt_result_tem1;
	}
	else if(rvdt_result_tem1 == rvdt_result_tem3)
	{
		rvdt_result = rvdt_result_tem1;
	}
	else
	{
		rvdt_result = rvdt_result_tem2;
	}
	
	if(rvdt_result < 0|| rvdt_result > 4095)
	{
		//TODO generate warining
	}
	else
	{
    }
	rvdt_result = rvdt_result;
    return rvdt_result;
#endif
}
