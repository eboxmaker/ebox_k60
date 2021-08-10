#ifndef __EBOX_UART_H
#define __EBOX_UART_H
#include "../ebox/ebox_common.h"
typedef enum
{
    UART_Parity_No,
    UART_Parity_Even,
    UART_Parity_Odd,
}UART_Parity_t;

typedef enum
{
    UART_StopBits_0_5,
    UART_StopBits_1,
    UART_StopBits_1_5,
    UART_StopBits_2,
}UART_STOPBITS_t;

typedef enum
{
    UART_WordLength_8b,
    UART_WordLength_9b,
}UART_WORD_LENGTH_t;


class Uart
{
public:
    Uart(UART_Type *uart,Port *tx,Port *rx);
    void    begin(uint32_t baud_rate);
    
    void    attach_rx_interrupt(void (*callback_fun)(void));
    void    attach_tx_interrupt(void (*callback_fun)(void));
    
    void 	put_char(uint16_t ch);
    void 	put_string(const char *str);
    void    printf_length(const char *str, uint16_t length);
    void    printf(const char *fmt, ...); //
    void    wait_busy(); 
private:
    UART_Type *uart;
    Port *tx;
    Port *rx;
    void port_init(void);
    void init(uint32_t baud_rate, UART_WORD_LENGTH_t data_bit, UART_Parity_t parity, UART_STOPBITS_t stop_bit);
    uint32_t clock;
};
#endif
