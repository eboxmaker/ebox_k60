#include "ebox_common.h"

#ifdef __cplusplus
extern "C" {
#endif
    
#include "ebox_core.h"

#define _CPU_XTAL_CLK_HZ        (50*1000000UL)      /* Value of the external crystal or oscillator clock frequency of the system oscillator (OSC) in Hz */
#define _CPU_XTAL32k_CLK_HZ     32768U              /* Value of the external 32k crystal or oscillator clock frequency of the RTC in Hz */
#define _CPU_INT_SLOW_CLK_HZ    32768U              /* Value of the slow internal oscillator clock frequency in Hz */
#define _CPU_INT_FAST_CLK_HZ    4000000U            /* Value of the fast internal oscillator clock frequency in Hz */


#define MAX_PLL_CLOCK           (200*1000000UL)
    
#define MAX_CORE_CLOCK          MAX_PLL_CLOCK
#define MAX_BUS_CLOCK           (50*1000000UL)
#define MAX_FLEX_CLOCK          (100*1000000UL)
#define MAX_FLASH_CLOCK         (25*1000000UL)
        
    static uint8_t system_clock_init(void);
    
    static uint64_t millis_seconds;
    SystemClockConfig_t system_clock_config = 
    {
        {(100*1000000UL),(50*1000000UL),(0*1000000UL),(0*1000000UL)},
        {0,0,0,0},
        {0,0}
    };
  void trace_clk_init(void)
  {
      /* Set the trace clock to the core clock frequency */
      SIM_SOPT2 |= SIM_SOPT2_TRACECLKSEL_MASK;

      /* Enable the TRACE_CLKOUT pin function on PTA6 (alt7 function) */
      PORTA_PCR6 = ( PORT_PCR_MUX(0x7));
  }
  
/*!
 *  @brief      fb 时钟输出 初始化
 *  @since      v5.0
 *  @note       可用来校验时钟输出是否正确
 *  @author     飞思卡尔公司
 */
void fb_clk_init(void)
{
    /* Enable the clock to the FlexBus module */
    SIM_SCGC7 |= SIM_SCGC7_FLEXBUS_MASK;

    /* Enable the FB_CLKOUT function on PTC3 (alt5 function) */
    PORTC_PCR3 = ( PORT_PCR_MUX(0x5));
}

    static void assert_system_clock_config(SystemClockConfig_t *config)
    {

        if(config->clock.core > MAX_CORE_CLOCK || config->clock.core == 0)
            config->clock.core = MAX_CORE_CLOCK;
        
        if(config->clock.bus > MAX_BUS_CLOCK || config->clock.bus == 0)
            config->clock.bus = MAX_BUS_CLOCK;
        
        if(config->clock.flex > MAX_FLEX_CLOCK || config->clock.flex == 0)
            config->clock.flex = MAX_FLEX_CLOCK;
        
        if(config->clock.flash > MAX_FLASH_CLOCK || config->clock.flash == 0)
            config->clock.flash = MAX_FLASH_CLOCK;
        
 
        int flag = 0;
        for(int i = 25; i >= 0; i--)//config->pll.prdiv最大值为25
        {
          for(int j = 0; j <= 31; j++)//config->pll.vdiv最大值55
          {
            if((2*1000000 <= _CPU_XTAL_CLK_HZ / (i + 1)) && (_CPU_XTAL_CLK_HZ / (i + 1) <= 4*1000000))//满足2M~4M条件
            {
              config->pll.clock = _CPU_XTAL_CLK_HZ * (j + 24) / (i + 1)  ;
              if(config->pll.clock == MAX_PLL_CLOCK)//达到最高PLL限定值，优先分配相等的配置
              {
                config->pll.prdiv = i ;
                config->pll.vdiv = j;
                flag = 1;
                break;
               }
              else if(config->pll.clock > MAX_PLL_CLOCK)//取其上一个最接近的PLL限定值；
              {
                config->pll.prdiv = i ;
                config->pll.vdiv = j - 1;
                flag = 1;
                break;
              }
            
            }
          }
          if(flag == 1)
          {
            break;
          }
        }
        if(flag == 1)//分配成功
        {          
          config->pll.clock = _CPU_XTAL_CLK_HZ * (config->pll.vdiv + 24) / (config->pll.prdiv + 1) ;
        }
        else//分配失败，加载默认配置
        {
          config->pll.prdiv = 24;
          config->pll.vdiv  = 26;
          config->pll.clock = _CPU_XTAL_CLK_HZ * (config->pll.vdiv + 24) / (config->pll.prdiv + 1) ;
        }
        
    
        
        for(int i = 1; i < 16 ; i++)
        {
            if(config->pll.clock / i <= (config->clock.core))
            {
                config->sim.core_div = i-1;
                break;
            }
        }
        for(int i = 1; i < 16 ; i++)
        {
            if(config->pll.clock / i <= config->clock.bus)
            {
                config->sim.bus_div = i-1;
                break;
            }
        }
        for(int i = 1; i < 16 ; i++)
        {
            if(config->pll.clock / i <= config->clock.flex)
            {
                config->sim.flex_div = i-1;
                break;
            }
            else
            {
                config->sim.flex_div = 15;
            }
        }
        for(int i = 1; i < 16 ; i++)
        {
            if(config->pll.clock / i <= config->clock.flash)
            {
                config->sim.flash_div = i-1;
                break;
            }
        }               
        config->clock.core = config->pll.clock/(config->sim.core_div + 1);
        config->clock.bus  = config->pll.clock/(config->sim.bus_div + 1);
        config->clock.flex = config->pll.clock/(config->sim.flex_div + 1);
        config->clock.flash= config->pll.clock/(config->sim.flash_div + 1);
    }
    
    
    __RAMFUNC void set_sys_dividers(uint32_t outdiv1, uint32_t outdiv2, uint32_t outdiv3, uint32_t outdiv4)
    {
        /*
        * This routine must be placed in RAM. It is a workaround for errata e2448.
        * Flash prefetch must be disabled when the flash clock divider is changed.
        * This cannot be performed while executing out of flash.
        * There must be a short delay after the clock dividers are changed before prefetch
        * can be re-enabled.
        */
        uint32_t temp_reg;
        uint8_t i;

        temp_reg = FMC_PFAPR; // store present value of FMC_PFAPR

        // set M0PFD through M7PFD to 1 to disable prefetch
        FMC_PFAPR |= FMC_PFAPR_M7PFD_MASK | FMC_PFAPR_M6PFD_MASK | FMC_PFAPR_M5PFD_MASK
                     | FMC_PFAPR_M4PFD_MASK | FMC_PFAPR_M3PFD_MASK | FMC_PFAPR_M2PFD_MASK
                     | FMC_PFAPR_M1PFD_MASK | FMC_PFAPR_M0PFD_MASK;

        // set clock dividers to desired value
        SIM_CLKDIV1 = SIM_CLKDIV1_OUTDIV1(outdiv1) | SIM_CLKDIV1_OUTDIV2(outdiv2)
                      | SIM_CLKDIV1_OUTDIV3(outdiv3) | SIM_CLKDIV1_OUTDIV4(outdiv4);

        // wait for dividers to change
        for (i = 0 ; i < outdiv4 ; i++)
            {}

        FMC_PFAPR = temp_reg; // re-store original value of FMC_PFAPR

        return;
    } // set_sys_dividers
    
    static uint8_t system_clock_init(void)
    {

        assert_system_clock_config(&system_clock_config);
        //上电复位后，单片机会自动进入 FEI 模式，使用 内部参考时钟

        //FEI -> FBE
        MCG_C2 &= ~MCG_C2_LP_MASK;
        MCG_C2 |= MCG_C2_RANGE(1);

        MCG_C1 = MCG_C1_CLKS(2) | MCG_C1_FRDIV(7);

        while (MCG_S & MCG_S_IREFST_MASK) {};                       //等待FLL参考时钟 为 外部参考时钟（S[IREFST]=0，表示使用外部参考时钟，）

        while (((MCG_S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) != 0x2) {}; //等待选择外部参考时钟

        //现在已经进入了 FBE模式

        //FBE -> PBE
        set_sys_dividers(system_clock_config.sim.core_div, system_clock_config.sim.bus_div, system_clock_config.sim.flex_div, system_clock_config.sim.flash_div); //设置系统分频因子选项

        MCG_C5 = MCG_C5_PRDIV0(system_clock_config.pll.prdiv);                      //分频， EXTAL_IN_MHz/( PRDIV+1)
        MCG_C6 = MCG_C6_PLLS_MASK | MCG_C6_VDIV0(system_clock_config.pll.vdiv) ;    //倍频， EXTAL_IN_MHz/( PRDIV+1)  * (VDIV+24)

        while (!(MCG_S & MCG_S_PLLST_MASK)) {};                         //等待时钟源选择PLL

        while (!(MCG_S & MCG_S_LOCK0_MASK)) {};                          //等待 PLL锁了（锁相环）

        // 现在已经进入了 PBE 模式

        // PBE -> PEE
        MCG_C1 &= ~MCG_C1_CLKS_MASK;

        while (((MCG_S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) != 0x3) {};//等待选择输出PLL

        // 现在已经进入了 PEE 模式

        return 0;
    } //pll_init     
  


    void ebox_init(void)
    {
        system_clock_init();
        millis_seconds = 0;
        SysTick_Config(system_clock_config.clock.core/1000);

    }
    uint64_t micros(void)
    {
        uint16_t val;
        val = SysTick->VAL;
        return  millis_seconds * 1000 + ((1000 - val/(system_clock_config.clock.core/1000000) ));
    }
    uint64_t millis(void)
    {

        return millis_seconds;
    }

    void delay_ms(uint64_t ms)
    {
        uint64_t end ;
        end = micros() + ms * 1000 ;//3us的叠加
        while(micros() < end);
    }
    void delay_us(uint64_t us)
    {
        uint64_t end = micros() + us ;//3us的叠加
        while(micros() < end);
    }

    
    callback_fun_type systick_cb_table[1] = {0};
    __IO uint16_t systick_user_event_per_sec;//
    __IO uint16_t _systick_user_event_per_sec;//

    void set_systick_user_event_per_sec(uint16_t frq)
    {
        _systick_user_event_per_sec = 1000 / frq;
        systick_user_event_per_sec = frq;
    }

    void attach_systick_user_event(void (*callback_fun)(void))
    {
        systick_cb_table[0] = callback_fun;
    }    
    void SysTick_Handler(void)
    {
        millis_seconds ++;
        if((millis_seconds % _systick_user_event_per_sec) == 0)
        {
            if(systick_cb_table[0] != 0)
            {
                systick_cb_table[0]();
            }
        }
    }
    
    
    

#ifdef __cplusplus
}
#endif