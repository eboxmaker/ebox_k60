#ifndef __EBOX_UART_H
#define __EBOX_UART_H
#include "../ebox/ebox_common.h"
class Uart
{
public:
    Uart(UART_Type *uart,Port *tx,Port *rx);
    void    begin(uint32_t baud_rate);
    
    void    attach_rx_interrupt(void (*callback_fun)(void));
    void    attach_tx_interrupt(void (*callback_fun)(void));
    
    int 	put_char(uint16_t ch);
    void 	put_string(const char *str);
    void    printf_length(const char *str, uint16_t length);
    void    printf(const char *fmt, ...); //
    void    wait_busy(); 
private:
    UART_Type *uart;
    Port *tx;
    Port *rx;
    void port_init(void);
};
#endif
