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

Gpio pb21(GPIOB,PORTB,21);
Gpio pb22(GPIOB,PORTB,22);
Gpio pa6(GPIOA,PORTA,6);
Gpio pc3(GPIOC,PORTC,3);
int now = millis();

   
void hook()
{
    pb22.toggle();
}
int main (void) 
{
    ebox_init();
    pa6.set_clock_cmd(1);
    pc3.set_clock_cmd(1);
   // pa6.set_mux();
    
    pb21.set_clock_cmd(1);
    pb21.set_mux(PORT_MUX_AS_GPIO);
    pb21.set_dir_out();

    pb21.set_clock_cmd(1);
    pb21.set_mux(PORT_MUX_AS_GPIO);
    pb21.set_dir_out();

    pb22.set_mux(PORT_MUX_AS_GPIO);
    pb22.set_dir_out();
    set_systick_user_event_per_sec(2);
    attach_systick_user_event(hook);
    trace_clk_init();
    fb_clk_init();
  while(1)
  {     
      pb21.toggle();
      
      //for(int i =0 ; i < 0x;i++)   
      //for(int i =0 ; i < 0x4fffff;i++);   
      delay_ms(1);
  }
}

