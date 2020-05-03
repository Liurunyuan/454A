#include "arinc429_service.h"

int arinc429[11] = {0,0,0,0,0,0,0,0,0,0,0};
void Arinc429_SetCtlReg(ARINC429_CTL_REG ctlRegVal)
{
    Uint16 opcode = 0x10;

    Assert_CS_Pin();

    SpiaRegs.SPITXBUF = (opcode) << 8;
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[0] = SpiaRegs.SPIRXBUF;

    SpiaRegs.SPITXBUF = (ctlRegVal.HighLowByte.HighByte << 8);

    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[1] = SpiaRegs.SPIRXBUF;

    SpiaRegs.SPITXBUF = (ctlRegVal.HighLowByte.LowByte << 8);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[2] = SpiaRegs.SPIRXBUF;

    Deassert_CS_Pin();
}

Uint16 Arinc429_ReadStatusReg(void)
{
    int ret;
    Uint16 opcode = 0x0A;
    Uint16 dummy = 0;

    Assert_CS_Pin();

    SpiaRegs.SPITXBUF = (opcode << 8);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[3] = SpiaRegs.SPIRXBUF;

    SpiaRegs.SPITXBUF = (0x0000 << 8);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[4] = SpiaRegs.SPIRXBUF;
    
    ret = arinc429[4];

    Deassert_CS_Pin();

    return ret;
}

Uint16 Arinc429_ReadCtlReg(void)
{
    Uint16 opcode = 0x0B;
    Uint16 ret;
    Uint16 dummy = 0;

    Assert_CS_Pin();
  
    SpiaRegs.SPITXBUF = (opcode << 8);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[5] = SpiaRegs.SPIRXBUF;

    SpiaRegs.SPITXBUF = (0x0000 << 8);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[6] = SpiaRegs.SPIRXBUF;

    SpiaRegs.SPITXBUF = (0x0000 << 8);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[7] = SpiaRegs.SPIRXBUF;


    ret = arinc429[6];
    ret = ret << 8;
    ret = ret | arinc429[7];

    Deassert_CS_Pin();

    return ret;
}

Uint32 Arinc429_ReadRxFIFO_ONE_WORD(void)
{
    Uint16 opcode = 0x08;
    Uint32 tmp;
    Uint32 ret;

    Assert_CS_Pin();

    SpiaRegs.SPITXBUF = (opcode << 8);
    SpiaRegs.SPITXBUF = (0x0000 << 8);
    SpiaRegs.SPITXBUF = (0x0000 << 8);
    SpiaRegs.SPITXBUF = (0x0000 << 8);
    SpiaRegs.SPITXBUF = (0x0000 << 8);

    while(SpiaRegs.SPIFFRX.bit.RXFFST < 4);
    
    tmp = SpiaRegs.SPIRXBUF;
    ret = (tmp << 24);
    tmp = SpiaRegs.SPIRXBUF;
    ret |= (tmp << 16);
    tmp = SpiaRegs.SPIRXBUF;
    ret |= (tmp << 8);
    tmp = SpiaRegs.SPIRXBUF;
    ret |= (tmp);

    Deassert_CS_Pin();

    return ret;
}



