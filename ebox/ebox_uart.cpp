
#include "../ebox/ebox_uart.h"
Uart::Uart(UART_Type *uart,Port *tx,Port *rx)
{
this->uart = uart;
this->tx    = tx;
this->rx    = rx;
}
void Uart::begin(uint32_t baud_rate)
{
  port_init();
  init(baud_rate,UART_WordLength_8b,UART_Parity_No,UART_StopBits_1);
}
void Uart::port_init(void)
{
    tx->set_clock_enable(ENABLE);
    rx->set_clock_enable(ENABLE);
    switch((uint32_t)uart)
    {
    case (uint32_t)UART0_BASE:
        if(rx->id == PA1_ID)
            rx->set_mux(PORT_MUX_ALT2);
        else if(rx->id == PA15_ID || rx->id == PB16_ID || rx->id == PD6_ID)
            rx->set_mux(PORT_MUX_ALT3);
        
        if(tx->id == PA2_ID)
            tx->set_mux(PORT_MUX_ALT2);
        else if(tx->id == PA14_ID || tx->id == PB17_ID || tx->id == PD7_ID)
            tx->set_mux(PORT_MUX_ALT3);
      break;

      
    case (uint32_t)UART1_BASE:
      if(rx->id == PC3_ID || rx->id == PE1_ID)
          rx->set_mux(PORT_MUX_ALT3); 
      
      if(tx->id == PC4_ID || tx->id == PE0_ID)
          tx->set_mux(PORT_MUX_ALT3);
      break;

      
   case (uint32_t)UART2_BASE:
      if(rx->id == PD2_ID)
          rx->set_mux(PORT_MUX_ALT3); 
      
      if(tx->id == PD3_ID)
          tx->set_mux(PORT_MUX_ALT3);
      break;

      
   case (uint32_t)UART3_BASE:
      if(rx->id == PB10_ID || rx->id == PC16_ID || rx->id == PE5_ID)
          rx->set_mux(PORT_MUX_ALT3); 
      
      if(tx->id == PB11_ID || tx->id == PC17_ID || tx->id == PE4_ID)
          tx->set_mux(PORT_MUX_ALT3);
      break;
        
   case (uint32_t)UART4_BASE:
      if(rx->id == PC14_ID || rx->id == PE25_ID)
          rx->set_mux(PORT_MUX_ALT3); 
      
      if(tx->id == PC15_ID || tx->id == PE24_ID)
          tx->set_mux(PORT_MUX_ALT3);
      break;
        
   case (uint32_t)UART5_BASE:
      if(rx->id == PD8_ID || rx->id == PE9_ID)
          rx->set_mux(PORT_MUX_ALT3); 
      
      if(tx->id == PD9_ID || tx->id == PE8_ID)
          tx->set_mux(PORT_MUX_ALT3);
      break;
    }
}
void Uart::init(uint32_t baud_rate, UART_WORD_LENGTH_t data_bit, UART_Parity_t parity, UART_STOPBITS_t stop_bit)
{
    uint16_t sbr;
    uint8_t brfa;
    if((uint32_t)this->uart == UART0_BASE || (uint32_t)this->uart == UART1_BASE)
    {
        this->clock = system_clock_config.clock.core;
    }
    else
        this->clock = system_clock_config.clock.bus;
    
    /*  enable uartx clock    */
    switch((uint32_t)uart)
    {
        case (UART0_BASE):
            sim_set_enable_uart0_clock(ENABLE);
            break;
        case (UART1_BASE):
            sim_set_enable_uart1_clock(ENABLE);
            break;
        case (UART2_BASE):
            sim_set_enable_uart2_clock(ENABLE);
            break;
        case (UART3_BASE):
            sim_set_enable_uart3_clock(ENABLE);
            break;
        case (UART4_BASE):
            sim_set_enable_uart4_clock(ENABLE);
            break;
        case (UART5_BASE):
            sim_set_enable_uart5_clock(ENABLE);
            break;
        default :
            break;
    
    }
    
    /* disable Tx Rx first */
    uart->C2 &= ~((UART_C2_TE_MASK)|(UART_C2_RE_MASK));
    
    /* baud rate generation */
    sbr = (uint16_t)((this->clock)/((baud_rate)*16));
    if(sbr > 0x1FFF)sbr = 0x1FFF;
    
    brfa = ((32*this->clock)/((baud_rate)*16)) - 32*sbr;
    
    /* config baudrate */
    uart->BDH &= ~UART_BDH_SBR_MASK;
    uart->BDL &= ~UART_BDL_SBR_MASK;
    uart->C4 &= ~UART_C4_BRFA_MASK;
    
    uart->BDH |= UART_BDH_SBR(sbr>>8); 
    uart->BDL = UART_BDL_SBR(sbr); 
    uart->C4 |= UART_C4_BRFA(brfa);
    /* parity */
    switch(parity)
    {
        case UART_Parity_No: /* standard N 8 N 1*/
            uart->C1 &= ~UART_C1_PE_MASK;
            uart->C1 &= ~UART_C1_M_MASK;
            break;
        case UART_Parity_Even:/* 8 bit data + 1bit parity */
            uart->C1 |= UART_C1_PE_MASK;
            uart->C1 &= ~UART_C1_PT_MASK;
            break;
        case UART_Parity_Odd:
            uart->C1 |= UART_C1_PE_MASK;
            uart->C1 |= UART_C1_PT_MASK;
            break;
        default:
            break;
    }
        /* bit per char */
    /* note: Freescale's bit size config in register are including parity bit! */
    switch(data_bit)
    {
        case UART_WordLength_8b:
            if(uart->C1 & UART_C1_PE_MASK)
            {
                /* parity is enabled it's actually 9bit*/
                uart->C1 |= UART_C1_M_MASK;
                uart->C4 &= ~UART_C4_M10_MASK;    
            }
            else
            {
                uart->C1 &= ~UART_C1_M_MASK;
                uart->C4 &= ~UART_C4_M10_MASK;    
            }
            break;
        case UART_WordLength_9b:
            if(uart->C1 & UART_C1_PE_MASK)
            {
                /* parity is enabled it's actually 10 bit*/
                uart->C1 |= UART_C1_M_MASK;
                uart->C4 |= UART_C4_M10_MASK;  
            } 
            else
            {
                uart->C1 |= UART_C1_M_MASK;
                uart->C4 &= ~UART_C4_M10_MASK;      
            }
            break;
        default:
            break;
    }
    uart->S2 &= ~UART_S2_MSBF_MASK; /* LSB */
    
    /* enable Tx Rx */
    uart->C2 |= ((UART_C2_TE_MASK)|(UART_C2_RE_MASK));
    
    /* link debug instance */
    /* if it's first initalized ,link getc and putc to it */
    /*if(is_fitst_init)
    {
        UART_DebugInstance = Init->instance;
    }
    is_fitst_init = false;
    */
    
}

void Uart::put_char(uint16_t ch)
{


   /* no buffer is used */
   while(!(uart->S1 & UART_S1_TDRE_MASK));
 
    
    uart->D = (uint8_t)(ch & 0xFF);
    
}

void Uart::put_string(const char *str)
{
    while(*str != '\0')
    {
       /* no buffer is used */
       while(!(uart->S1 & UART_S1_TDRE_MASK));         
       uart->D = (uint8_t)(*str++ & 0xFF);
    }
}












