#include "arinc429_service.h"

int arinc429[11] = {0,0,0,0,0,0,0,0,0,0,0};
Uint16 gtArincCtlH = 0xE8;
Uint16 gtArincCtlL = 0x04;
Uint32 testbyte[4] = {0,0,0,0};
void Arinc429_SetCtlReg(ARINC429_CTL_REG ctlRegVal)
{
    Uint16 opcode = 0x10;

    Assert_CS_Pin();

    SpiaRegs.SPITXBUF = (opcode) << 8;
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[0] = (SpiaRegs.SPIRXBUF);

   SpiaRegs.SPITXBUF = (ctlRegVal.HighLowByte.HighByte << 8);
    // SpiaRegs.SPITXBUF = (gtArincCtlH << 8);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[1] = (SpiaRegs.SPIRXBUF);

   SpiaRegs.SPITXBUF = (ctlRegVal.HighLowByte.LowByte << 8);
    // SpiaRegs.SPITXBUF = (gtArincCtlL << 8);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[2] = (SpiaRegs.SPIRXBUF);

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
    arinc429[3] = (SpiaRegs.SPIRXBUF);

    SpiaRegs.SPITXBUF = (0x0000);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[4] = (SpiaRegs.SPIRXBUF);
    
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
    arinc429[5] = (SpiaRegs.SPIRXBUF);

    SpiaRegs.SPITXBUF = (0x0000);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[6] = (SpiaRegs.SPIRXBUF);

    SpiaRegs.SPITXBUF = (0x0000);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    arinc429[7] = (SpiaRegs.SPIRXBUF);


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
    Uint32 dummy;

    Assert_CS_Pin();

    SpiaRegs.SPITXBUF = (opcode << 8);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    dummy = (SpiaRegs.SPIRXBUF);

    SpiaRegs.SPITXBUF = (0x0000);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    tmp = SpiaRegs.SPIRXBUF;
    testbyte[0] = tmp;
    ret = tmp << 24;

    SpiaRegs.SPITXBUF = (0x0000);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    tmp = SpiaRegs.SPIRXBUF;
    testbyte[1] = tmp;
    ret |= (tmp << 16);

    SpiaRegs.SPITXBUF = (0x0000);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    tmp = SpiaRegs.SPIRXBUF;
    testbyte[2] = tmp;
    ret |= (tmp << 8);

    SpiaRegs.SPITXBUF = (0x0000);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    tmp = SpiaRegs.SPIRXBUF;
    testbyte[3] = tmp;
    ret |= (tmp);

    Deassert_CS_Pin();

    return ret;
}

void Arinc429_WriteTxFIFO_ONE_WORD(Uint32 data)
{
    Uint16 opcode = 0x0E;
    Uint32 dummy;

    Uint16 high;
    Uint32 low;

    low = (Uint16)data;
    high = (Uint16)(data >> 16);

    Assert_CS_Pin();

    SpiaRegs.SPITXBUF = (opcode << 8);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    dummy = (SpiaRegs.SPIRXBUF);

    SpiaRegs.SPITXBUF = (high);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    dummy = (SpiaRegs.SPIRXBUF);

    SpiaRegs.SPITXBUF = (high << 8);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    dummy = (SpiaRegs.SPIRXBUF);

    SpiaRegs.SPITXBUF = (low);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    dummy = (SpiaRegs.SPIRXBUF);

    SpiaRegs.SPITXBUF = (low << 8);
    while(SpiaRegs.SPISTS.bit.INT_FLAG != 1);
    dummy = (SpiaRegs.SPIRXBUF);

    Deassert_CS_Pin();
}

