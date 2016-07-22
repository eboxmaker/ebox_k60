#ifndef __EBOX_SIM_H
#define __EBOX_SIM_H
#include "../ebox/ebox_common.h"
#include "fsl_device_registers.h"

#define sim_set_enable_uart4_clock(val)         SIM_BWR_SCGC1_UART4(SIM,val);
#define sim_set_enable_uart5_clock(val)         SIM_BWR_SCGC1_UART5(SIM,val);
#define sim_set_enable_osc1_clock(val)          SIM_BWR_SCGC1_OSC1(SIM,val);//

#define sim_set_enable_dac0_clock(val)          SIM_BWR_SCGC2_DAC0(SIM,val);
#define sim_set_enable_dac1_clock(val)          SIM_BWR_SCGC2_DAC1(SIM,val);

#define sim_set_enable_rnga_clock(val)          SIM_BWR_SCGC3_RNGA(SIM,val);
#define sim_set_enable_flexcan1_clock(val)      SIM_BWR_SCGC3_FLEXCAN1(SIM,val);
#define sim_set_enable_nfc_clock(val)           SIM_BWR_SCGC3_NFC(SIM,val);//
#define sim_set_enable_spi2_clock(val)          SIM_BWR_SCGC3_SPI2(SIM,val);
#define sim_set_enable_sai1_clock(val)          SIM_BWR_SCGC3_SAI1(SIM,val);//
#define sim_set_enable_sdhc_clock(val)          SIM_BWR_SCGC3_SDHC(SIM,val);
#define sim_set_enable_ftm2_clock(val)          SIM_BWR_SCGC3_FTM2(SIM,val);
#define sim_set_enable_ftm3_clock(val)          SIM_BWR_SCGC3_FTM1(SIM,val);//
#define sim_set_enable_adc1_clock(val)          SIM_BWR_SCGC3_ADC1(SIM,val);
#define sim_set_enable_adc3_clock(val)          SIM_BWR_SCGC3_ADC3(SIM,val);//

#define sim_set_enable_ewm_clock(val)           SIM_BWR_SCGC4_EWM(SIM,val);
#define sim_set_enable_cmt_clock(val)           SIM_BWR_SCGC4_CMT(SIM,val);
#define sim_set_enable_iic0_clock(val)          SIM_BWR_SCGC4_I2C0(SIM,val);
#define sim_set_enable_iic1_clock(val)          SIM_BWR_SCGC4_I2C1(SIM,val);
#define sim_set_enable_uart0_clock(val)         SIM_BWR_SCGC4_UART0(SIM,val);
#define sim_set_enable_uart1_clock(val)         SIM_BWR_SCGC4_UART1(SIM,val);
#define sim_set_enable_uart2_clock(val)         SIM_BWR_SCGC4_UART2(SIM,val);
#define sim_set_enable_uart3_clock(val)         SIM_BWR_SCGC4_UART3(SIM,val);
#define sim_set_enable_usbfs_clock(val)         SIM_BWR_SCGC4_USBFS(SIM,val);//
#define sim_set_enable_cmp_clock(val)           SIM_BWR_SCGC4_CMP(SIM,val);
#define sim_set_enable_vref_clock(val)          SIM_BWR_SCGC4_VREF(SIM,val);
#define sim_set_enable_llwu_clock(val)          SIM_BWR_SCGC4_LLWU(SIM,val);


#define sim_set_enable_lptimer_clock(val)      SIM_BWR_SCGC5_LPTIMER(SIM,val);
#define sim_set_enable_regfile_clock(val)      SIM_BWR_SCGC5_REGFILE(SIM,val);//
#define sim_set_enable_tsi_clock(val)          SIM_BWR_SCGC5_TSI(SIM,val);
#define sim_set_enable_porta_clock(val)        SIM_BWR_SCGC5_PORTA(SIM,val);
#define sim_set_enable_portb_clock(val)        SIM_BWR_SCGC5_PORTB(SIM,val);
#define sim_set_enable_portc_clock(val)        SIM_BWR_SCGC5_PORTC(SIM,val);
#define sim_set_enable_portd_clock(val)        SIM_BWR_SCGC5_PORTD(SIM,val);
#define sim_set_enable_porte_clock(val)        SIM_BWR_SCGC5_PORTE(SIM,val);


#endif
