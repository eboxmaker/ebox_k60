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
