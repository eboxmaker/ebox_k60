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


int now = millis();
   
void hook()
{
    //PB22.toggle();
}

void setup()
{
    ebox_init();
    
    sim_enable_porta_clock();
    sim_enable_portb_clock();

    PA6.set_clock_cmd(1);
    PC3.set_clock_cmd(1);
   // pa6.set_mux();
    
    
    PB21.set_mux(PORT_MUX_AS_GPIO);
    PB21.set_dir_out();

    PB22.set_mux(PORT_MUX_AS_GPIO);
    PB22.set_dir_out();
    
    set_systick_user_event_per_sec(2);
    attach_systick_user_event(hook);
    
    trace_clk_init();
    fb_clk_init();
}

int main (void) 
{
    setup();

  while(1)
  {     
      PB21.toggle();
      delay_ms(1000);

      PB21.toggle();
      delay_ms(1000);

      PB21.toggle();
      delay_ms(1000);

      PB21.toggle();
      delay_ms(1000);



  }
}

