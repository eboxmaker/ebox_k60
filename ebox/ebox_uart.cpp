
#include "../ebox/ebox_uart.h"
#include "../ebox/ebox.h"

Uart::Uart(UART_Type *uart,Port *tx,Port *rx)
{
this->uart = uart;
this->tx    = tx;
this->rx    = rx;
}
void Uart::begin(uint32_t baud_rate)
{
  port_init();
}
void Uart::port_init(void)
{
    tx->set_clock_cmd(1);
    rx->set_clock_cmd(1);
    switch((uint32_t)uart)
    {
    case (uint32_t)UART0:
        if(rx == &PA1)
            rx->set_mux(PORT_MUX_ALT2);
        else if(rx == &PA15 || rx == &PB16 || rx == &PD6)
            rx->set_mux(PORT_MUX_ALT3);
        
        if(tx == &PA2)
            tx->set_mux(PORT_MUX_ALT2);
        else if(tx == &PA14 || tx == &PB17 || tx == &PD7)
            tx->set_mux(PORT_MUX_ALT3);
      break;
    case (uint32_t)UART1:
      if(rx == &PC3 || rx == &PE1)
          rx->set_mux(PORT_MUX_ALT3); 
      
      if(tx == &PC4 || tx == &PE0)
          tx->set_mux(PORT_MUX_ALT3);
      break;
    }
        

}