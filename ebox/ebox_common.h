#ifndef __EBOX_COMMON_H
#define __EBOX_COMMON_H

#include "MK60D10.h"                    // Device header
#include "MK60D10_extension.h"
#include "../ebox/ebox_core.h"
#include "../ebox/ebox_sim.h"



#define EBOX_VERSION "16.6.18"

#define EOK         0
#define EWAIT       1
#define EBUSY       2
#define ETIMEOUT    3
#define EPARA       4
#define E2LONG      5
#define EOTHER      128

typedef unsigned char   boolean;      /* 8-bit*/

#define true 0x1
#define false 0x0

#define HIGH 0x1
#define LOW  0x0


#define LSB_FIRST 0
#define MSB_FIRST 1

#define PI 3.1415926535898
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;

typedef enum
{
    OUTPUT_PP    = 0x0,    
    OUTPUT_PP_PU    ,    
    OUTPUT_PP_PD    ,
    
    OUTPUT_OD       ,
    OUTPUT_OD_PU    ,
    OUTPUT_OD_PD    ,
    
    AIN             ,
    
    INPUT           ,
    INPUT_PD        ,
    INPUT_PU        ,
    
    AF_OD           ,
    AF_OD_PU        ,   
    AF_OD_PD        ,
    
    AF_PP           ,      
    AF_PP_PU        ,
    AF_PP_PD        ,
} PIN_MODE;
typedef enum
{
    PA0_ID = 0x0000,PA1_ID,     PA2_ID,     PA3_ID,     PA4_ID,     PA5_ID,     PA6_ID,     PA7_ID,
    PA8_ID,         PA9_ID,     PA10_ID,    PA11_ID,    PA12_ID,    PA13_ID,    PA14_ID,    PA15_ID,   
    PA16_ID,        PA17_ID,    PA18_ID,    PA19_ID,    PA20_ID,    PA21_ID,    PA22_ID,    PA23_ID,
    PA24_ID,        PA25_ID,    PA26_ID,    PA27_ID,    PA28_ID,    PA29_ID,    PA30_ID,    PA31_ID,
    
    PB0_ID = 0x0100,PB1_ID,     PB2_ID,     PB3_ID,     PB4_ID,     PB5_ID,     PB6_ID,     PB7_ID,
    PB8_ID,         PB9_ID,     PB10_ID,    PB11_ID,    PB12_ID,    PB13_ID,    PB14_ID,    PB15_ID,
    PB16_ID,        PB17_ID,    PB18_ID,    PB19_ID,    PB20_ID,    PB21_ID,    PB22_ID,    PB23_ID,
    PB24_ID,        PB25_ID,    PB26_ID,    PB27_ID,    PB28_ID,    PB29_ID,    PB30_ID,    PB31_ID,
            
    PC0_ID = 0x0200,PC1_ID,     PC2_ID,     PC3_ID,     PC4_ID,     PC5_ID,     PC6_ID,     PC7_ID,
    PC8_ID,         PC9_ID,     PC10_ID,    PC11_ID,    PC12_ID,    PC13_ID,    PC14_ID,    PC15_ID,
    PC16_ID,        PC17_ID,    PC18_ID,    PC19_ID,    PC20_ID,    PC21_ID,    PC22_ID,    PC23_ID,
    PC24_ID,        PC25_ID,    PC26_ID,    PC27_ID,    PC28_ID,    PC29_ID,    PC30_ID,    PC31_ID,
            
    PD0_ID = 0x0300,PD1_ID,     PD2_ID,     PD3_ID,     PD4_ID,     PD5_ID,     PD6_ID,     PD7_ID,
    PD8_ID,         PD9_ID,     PD10_ID,    PD11_ID,    PD12_ID,    PD13_ID,    PD14_ID,    PD15_ID,
    PD16_ID,        PD17_ID,    PD18_ID,    PD19_ID,    PD20_ID,    PD21_ID,    PD22_ID,    PD23_ID,
    PD24_ID,        PD25_ID,    PD26_ID,    PD27_ID,    PD28_ID,    PD29_ID,    PD30_ID,    PD31_ID,
    
    PE0_ID = 0x0400,PE1_ID,     PE2_ID,     PE3_ID,     PE4_ID,     PE5_ID,     PE6_ID,     PE7_ID,
    PE8_ID,         PE9_ID,     PE10_ID,    PE11_ID,    PE12_ID,    PE13_ID,    PE14_ID,    PE15_ID,
    PE16_ID,        PE17_ID,    PE18_ID,    PE19_ID,    PE20_ID,    PE21_ID,    PE22_ID,    PE23_ID,
    PE24_ID,        PE25_ID,    PE26_ID,    PE27_ID,    PE28_ID,    PE29_ID,    PE30_ID,    PE31_ID,
    
    PF0_ID = 0x0500,PF1_ID,     PF2_ID,     PF3_ID,     PF4_ID,     PF5_ID,     PF6_ID,     PF7_ID,
    PF8_ID,         PF9_ID,     PF10_ID,    PF11_ID,    PF12_ID,    PF13_ID,    PF14_ID,    PF15_ID,
    PF16_ID,        PF17_ID,    PF18_ID,    PF19_ID,    PF20_ID,    PF21_ID,    PF22_ID,    PF23_ID,
    PF24_ID,        PF25_ID,    PF26_ID,    PF27_ID,    PF28_ID,    PF29_ID,    PF30_ID,    PF31_ID,
    
}PIN_ID_t;


//端口引脚枚举定义
typedef enum PortPinsEnum
{
  //PortA
  PTA0=0,    PTA1=1,    PTA2=2,    PTA3=3,    
  PTA4=4,    PTA5=5,    PTA6=6,    PTA7=7,    
  PTA8=8,    PTA9=9,    PTA10=10,  PTA11=11,
  PTA12=12,  PTA13=13,  PTA14=14,  PTA15=15,
  PTA16=16,  PTA17=17,  PTA18=18,  PTA19=19,
  /********* MK60DZ10无PTA20~23 ************/
  PTA24=24,  PTA25=25,  PTA26=26,  PTA27=27,
  PTA28=28,  PTA29=29,
  /********* MK60DZ10无PTA30~31 ************/
  
  //PortB
  PTB0=32,   PTB1=33,   PTB2=34,   PTB3=35,
  PTB4=36,   PTB5=37,   PTB6=38,   PTB7=39,
  PTB8=40,   PTB9=41,   PTB10=42,  PTB11=43,
  /********* MK60DZ10无PTB12~15 ************/
  PTB16=48,  PTB17=49,  PTB18=50,  PTB19=51,
  PTB20=52,  PTB21=53,  PTB22=54,  PTB23=55,
  /********* MK60DZ10无PTB24~27 ************/
  /********* MK60DZ10无PTB28~31 ************/
  
  //PortC
  PTC0=60,   PTC1=61,   PTC2=62,   PTC3=63,
  PTC4=64,   PTC5=65,   PTC6=66,   PTC7=67,
  PTC8=68,   PTC9=69,   PTC10=70,  PTC11=71,
  PTC12=72,  PTC13=73,  PTC14=74,  PTC15=75,
  PTC16=76,  PTC17=77,  PTC18=78,  PTC19=79,
  /********* MK60DZ10无PTC20~23 ************/
  /********* MK60DZ10无PTC24~27 ************/
  /********* MK60DZ10无PTC28~31 ************/
  
  //PortD
  PTD0=92,   PTD1=93,   PTD2=94,   PTD3=95,
  PTD4=96,   PTD5=97,   PTD6=98,   PTD7=99,
  PTD8=100,  PTD9=101,  PTD10=102, PTD11=103,
  PTD12=104, PTD13=105, PTD14=106, PTD15=107,
  /********* MK60DZ10无PTD16~19 ************/
  /********* MK60DZ10无PTD20~23 ************/
  /********* MK60DZ10无PTD24~27 ************/
  /********* MK60DZ10无PTD28~31 ************/
  
  //PortE
  PTE0=124,  PTE1=125,  PTE2=126,  PTE3=127,
  PTE4=128,  PTE5=129,  PTE6=130,  PTE7=131,
  PTE8=132,  PTE9=133,  PTE10=134, PTE11=135,
#if defined(CPU_MK60F12) || defined(CPU_MK60F15)
  PTE12=136,
#endif
  /********* MK60DZ10无PTE12~15 ************/
  /********* MK60DZ10无PTE16~19 ************/
  /********* MK60DZ10无PTE20~23 ************/
  PTE24=148, PTE25=149, PTE26=150, PTE27=151,
  PTE28=152
  /********* MK60DZ10无PTE29~31 ************/
} PortPinsEnum_Type;


/*! @brief Pin mux selection*/
#define     PORT_PIN_DISABLED   0U   /*!< corresponding pin is disabled, but is used as an analog pin.*/
#define     PORT_MUX_AS_GPIO    1U   /*!< corresponding pin is disabled, but is used as an analog pin.*/
#define     PORT_MUX_ALT2     2U   /*!< chip-specific*/
#define     PORT_MUX_ALT3     3U   /*!< chip-specific*/
#define     PORT_MUX_ALT4     4U   /*!< chip-specific*/
#define     PORT_MUX_ALT5     5U   /*!< chip-specific*/
#define     PORT_MUX_ALT6     6U   /*!< chip-specific*/
#define     PORT_MUX_ALT7     7U    /*!< chip-specific*/

typedef enum{    
	PORT_DMA_RisingEdge,	          
	PORT_DMA_FallingEdge,          
    PORT_DMA_RisingFallingEdge,  
	PORT_IT_Low,                 
	PORT_IT_RisingEdge,          
	PORT_IT_FallingEdge,         
	PORT_IT_RisingFallingEdge,   
	PORT_IT_High,                
}PORT_IT_DMA_CONFIG_t;

class Port
{
public:
    Port(PORT_Type *port,uint32_t pin);
    void set_pull_down();
    void set_pull_up();
    
    void set_slew_rate_fast();
    void set_slew_rate_slow();
    
    void set_drive_strength_low();
    void set_drive_strength_high();

    void set_pull_enable(FunctionalState state);
	void set_clock_enable(FunctionalState state);
    void set_passive_filter_enable(FunctionalState state);
    void set_push_pull_enable(FunctionalState state);
    void set_open_drain_enable(FunctionalState state);
    void set_mux(uint8_t mux);
	void it_dma_config(PORT_IT_DMA_CONFIG_t config,FunctionalState state);
	void interrupt(FunctionalState state);
public:
    PIN_ID_t id;
    PORT_Type *port;
    uint32_t pin;
    IRQn_Type irq;
};

class Gpio :public Port   
{
public:
    Gpio(GPIO_Type *gpio_bass,PORT_Type *base,uint32_t pin):Port(base,pin)
    {
        this->gpio_base = gpio_bass;
    };
    void mode(PIN_MODE mode);
    void set_dir_in();
    void set_dir_out();
    
    void set();
    void reset();
    
    void write(uint32_t val);
    void toggle();
    
    bool read();
    bool read_input();
    bool read_output();
     
    Gpio &operator= (int value)
    {
        write(value);
        return *this;
    }
    operator int()
    {
        return read();
    }
private:
    GPIO_Type *gpio_base;
};

void        shift_out(Gpio *data_pin, Gpio *clock_pin, uint8_t bit_order, uint8_t val);
uint8_t	    shift_in(Gpio *data_pin, Gpio *clock_pin, uint8_t bit_order);

void        random_seed(uint16_t seed);
uint16_t    random();
uint16_t    random(uint16_t max);
uint16_t    random(uint16_t min, uint16_t max);
    
#define interrupts()    __enable_irq
#define no_interrupt()  __disable_irq
    
/*
 * 定义运行到RAM的函数
 */
#if defined(__ICCARM__)
//IAR 用 __ramfunc 来声明
#define     __RAMFUNC __ramfunc
#else
#define     __RAMFUN
#endif
    
    


#endif
