#ifndef __EBOX_SIM_H
#define __EBOX_SIM_H
#include "../ebox/ebox_common.h"
#include "fsl_device_registers.h"

#define sim_enable_uart4_clock()    SIM_BWR_SCGC1_UART4(SIM,1);
#define sim_enable_uart5_clock()    SIM_BWR_SCGC1_UART5(SIM,1);
#define sim_enable_osc1_clock()     SIM_BWR_SCGC1_OSC1(SIM,1);//

#define sim_enable_dac0_clock()    SIM_BWR_SCGC2_DAC0(SIM,1);
#define sim_enable_dac1_clock()    SIM_BWR_SCGC2_DAC1(SIM,1);

#define sim_enable_rnga_clock()         SIM_BWR_SCGC3_RNGA(SIM,1);
#define sim_enable_flexcan1_clock()     SIM_BWR_SCGC3_FLEXCAN1(SIM,1);
#define sim_enable_nfc_clock()          SIM_BWR_SCGC3_NFC(SIM,1);//
#define sim_enable_spi2_clock()         SIM_BWR_SCGC3_SPI2(SIM,1);
#define sim_enable_sai1_clock()         SIM_BWR_SCGC3_SAI1(SIM,1);//
#define sim_enable_sdhc_clock()         SIM_BWR_SCGC3_SDHC(SIM,1);
#define sim_enable_ftm2_clock()         SIM_BWR_SCGC3_FTM2(SIM,1);
#define sim_enable_ftm3_clock()         SIM_BWR_SCGC3_FTM1(SIM,1);//
#define sim_enable_adc1_clock()         SIM_BWR_SCGC3_ADC1(SIM,1);
#define sim_enable_adc3_clock()         SIM_BWR_SCGC3_ADC3(SIM,1);//

#define sim_enable_ewm_clock()          SIM_BWR_SCGC4_EWM(SIM,1);
#define sim_enable_cmt_clock()          SIM_BWR_SCGC4_CMT(SIM,1);
#define sim_enable_iic0_clock()         SIM_BWR_SCGC4_I2C0(SIM,1);
#define sim_enable_iic1_clock()         SIM_BWR_SCGC4_I2C1(SIM,1);
#define sim_enable_uart0_clock()        SIM_BWR_SCGC4_UART0(SIM,1);
#define sim_enable_uart1_clock()        SIM_BWR_SCGC4_UART1(SIM,1);
#define sim_enable_uart2_clock()        SIM_BWR_SCGC4_UART2(SIM,1);
#define sim_enable_uart3_clock()        SIM_BWR_SCGC4_UART3(SIM,1);
#define sim_enable_usbfs_clock()        SIM_BWR_SCGC4_USBFS(SIM,1);//
#define sim_enable_cmp_clock()          SIM_BWR_SCGC4_CMP(SIM,1);
#define sim_enable_vref_clock()         SIM_BWR_SCGC4_VREF(SIM,1);
#define sim_enable_llwu_clock()         SIM_BWR_SCGC4_LLWU(SIM,1);


#define sim_enable_lptimer_clock()      SIM_BWR_SCGC5_LPTIMER(SIM,1);
#define sim_enable_regfile_clock()      SIM_BWR_SCGC5_REGFILE(SIM,1);//
#define sim_enable_tsi_clock()          SIM_BWR_SCGC5_TSI(SIM,1);
#define sim_enable_porta_clock()        SIM_BWR_SCGC5_PORTA(SIM,1);
#define sim_enable_portb_clock()        SIM_BWR_SCGC5_PORTB(SIM,1);
#define sim_enable_portc_clock()         SIM_BWR_SCGC5_PORTC(SIM,1);
#define sim_enable_portd_clock()        SIM_BWR_SCGC5_PORTD(SIM,1);
#define sim_enable_porte_clock()        SIM_BWR_SCGC5_PORTE(SIM,1);


#endif
