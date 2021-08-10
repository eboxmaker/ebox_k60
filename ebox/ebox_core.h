#ifndef __EBOX_CORE_H
#define __EBOX_CORE_H




#ifdef __cplusplus
extern "C" {
#endif

    typedef struct{
        uint32_t core;
        uint32_t bus;
        uint32_t flex;
        uint32_t flash;
    }SystemClock_t;
    
    typedef struct{
        uint32_t core_div;
        uint32_t bus_div;
        uint32_t flex_div;
        uint32_t flash_div;
    }SimDiv_t;
    
    typedef struct{
        uint32_t clock;
        uint8_t prdiv;
        uint8_t vdiv;
    }PllDiv_t;
    
    typedef struct{
        SystemClock_t   clock;
        SimDiv_t        sim;
        PllDiv_t        pll;    
    }SystemClockConfig_t;
    
    
    typedef void (*callback_fun_type)(void);
    extern  callback_fun_type systick_cb_table[1];
    extern  SystemClockConfig_t system_clock_config;

    void ebox_init(void);
    uint64_t micros(void);
    uint64_t millis(void);
    void delay_ms(uint64_t ms);
    void delay_us(uint64_t us);
    void set_systick_user_event_per_sec(uint16_t frq);
    void attach_systick_user_event(void (*callback_fun)(void));
    void trace_clk_init(void);
    void fb_clk_init(void);
#ifdef __cplusplus
}
#endif
#endif
