#ifndef PF_CFG_H_
#define PF_CFG_H_

// #include "DSP2833x_Gpio.h"
#include "pf_adc_cfg.h"
#include "pf_gpio_cfg.h"
#include "pf_pwm_cfg.h"
#include "pf_sci_cfg.h"
#include "pf_spi_cfg.h"
#include "pf_xintf_cfg.h"

CFG_GPIO_TBL CfgGpioTbl_User[] =
{
    {3, GPIO_OUTPUT},			//{gpio number, gpio direction}
    {3, GPIO_OUTPUT},
    {3, GPIO_OUTPUT},
    {3, GPIO_OUTPUT},
    {3, GPIO_OUTPUT},
    {3, GPIO_OUTPUT},
    {3, GPIO_OUTPUT},
    {3, GPIO_OUTPUT},
    {3, GPIO_OUTPUT},
    {3, GPIO_OUTPUT},
    {3, GPIO_OUTPUT}
};

CFG_PWM_TBL CfgPwmTbl_User[] =
{
   {
       {
           PWM1A
       },
       {
           40
       }
   },
   {
       {
           PWM1B
       },
       {
           40
       }
   },
   {
       {
           PWM2A
       },
       {
           40
       }
   },
   {
       {
           PWM2B
       },
       {
           40
       }
   },
   {
       {
           PWM3A
       },
       {
           40
       }
   },
   {
       {
           PWM3B
       },
       {
           40
       }
   },
   {
       {
           PWM4A
       },
       {
           40
       }
   },
   {
       {
           PWM4B
       },
       {
           40
       }
   },
   {
       {
           PWM5A
       },
       {
           40
       }
   },
   {
       {
           PWM5B
       },
       {
           40
       }
   },
   {
       {
           PWM6A
       },
       {
           40
       }
   },
   {
       {
           PWM6B
       },
       {
           40
       }
   }
};

CFG_SCI_TBL CfgSciTbl_User[] =
{
    {
        {
            SCIA,       //sci moudule, A, B, C
            28,         //sci rx gpio index
            29          //sci tx gpio index
        },
        {
            BAUD_RATE_115200    //sci baud rate
        }
    },
    {
        {
            SCIB, 
            11,
            9
        },
        {
            BAUD_RATE_115200
        }
    },
    {
        {
            SCIC, 
            62,
            63
        },
        {
            BAUD_RATE_115200
        }
    }
};


CFG_SPI_TBL CfgSpiTbl_User[] =
{
    {54, 55, 56, 57}
};

CFG_XINTF_TBL CfgXintfTbl_User[] =
{
    {
        DATA_MODE_16BIT,        //DATA_MODE_16BIT   DATA_MODE_32BIT          select data bus width
        ADDR_DISABLE,           //ADDR_DISABLE  ADDR_ENAABLE                 address bus enable or not
        ZONE0_DISABLE,          //ZONE0_DISABLE  ZONE0_ENABLE                zone0 enable or not
        ZONE6_ENABLE,           //ZONE6_DISABLE  ZONE6_ENABLE                zone6 enable or not
        ZONE7_DISABLE           //ZONE7_DISABLE  ZONE7_ENABLE                zone7 enable or not
    }
};
#endif /* MAIN_H_ */
