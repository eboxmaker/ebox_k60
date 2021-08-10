/*----------------------------------------------------------------------------
 *      RL-ARM - RTX
 *----------------------------------------------------------------------------
 *      Name:    BLINKY.C
 *      Purpose: RTX example program
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2006-2013 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/
#include "MK60D10.h"                    // Device header
#include "../ebox/ebox.h"

uint32_t count;
/*----------------------------------------------------------------------------
 *      Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/
    int i;

Exti ex(&PE26,PORT_IT_FallingEdge);


int now = millis();
   
void hook()
{
    PB22.toggle();
}

void setup()
{
    ebox_init();
    
    //sim_enable_porta_clock();
    //sim_enable_portb_clock();

    //PA6.set_clock_enable(ENABLE);
    //PC3.set_clock_enable(ENABLE);
   // pa6.set_mux();
    
    
    PB21.mode(OUTPUT_PP);
    PB22.mode(OUTPUT_PP);

    uart0.begin(115200);
    uart3.begin(115200);

    
    //set_systick_user_event_per_sec(2);
    //attach_systick_user_event(hook);
    
    //trace_clk_init();
    //fb_clk_init();
    
}
void event(uint32_t para)
{
    if(para & (1 << 26)) /*对应的按键中断 翻转对应的LED电平 */
    {
        PB22.toggle();
    }

}
int main (void) 
{
    setup();
    ex.attach_interrupt(event);
ex.begin();
  while(1)
  {     
      uart0.put_string("test\r\n");
      PB21.toggle();
      delay_ms(500);




  }
}

