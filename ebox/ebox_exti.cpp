#include "../ebox/ebox_exti.h"



static exti_callback_fun_type exti_cb_table[6] = {NULL};


Exti::Exti(Gpio *pin,PORT_IT_DMA_CONFIG_t trigger)
{
    this->pin = pin;
    this->trigger = trigger;


};
void Exti::begin()
{
    pin->mode(INPUT_PU);
    pin->it_dma_config(trigger,ENABLE);
}
void Exti::attach_interrupt(exti_callback_fun_type callback)
{
    switch((uint32_t)(this->pin->port))
    {
    case (uint32_t)PORTA_BASE:
        exti_cb_table[0] = callback;
        break;
    case (uint32_t)PORTB_BASE:
        exti_cb_table[1] = callback;
        break;
    case (uint32_t)PORTC_BASE:
        exti_cb_table[2] = callback;
        break;
    case (uint32_t)PORTD_BASE:
        exti_cb_table[3] = callback;
        break;
    case (uint32_t)PORTE_BASE:
        exti_cb_table[4] = callback;
        break;
    //case (uint32_t)PORTF_BASE:
    //    exti_cb_table[5] = callback;
    //    break;
    
    }
}
void Exti::interrupt(FunctionalState enable)
{
    pin->interrupt(enable);
}

extern "C"
{



    void PORTA_IRQHandler(void)
    {
         uint32_t ISFR;
        ISFR = PORTA->ISFR;
        PORTA->ISFR = 0xFFFFFFFF;
        if(exti_cb_table[0] != NULL)
        exti_cb_table[0](ISFR);
    }

    void PORTB_IRQHandler(void)
    {
         uint32_t ISFR;
        ISFR = PORTB->ISFR;
        PORTB->ISFR = 0xFFFFFFFF;
        if(exti_cb_table[1] != NULL)
        exti_cb_table[1](ISFR);
    }

    void PORTC_IRQHandler(void)
    {
         uint32_t ISFR;
        ISFR = PORTC->ISFR;
        PORTC->ISFR = 0xFFFFFFFF;
        if(exti_cb_table[2] != NULL)
        exti_cb_table[2](ISFR);
    }

    void PORTD_IRQHandler(void)
    {
         uint32_t ISFR;
        ISFR = PORTD->ISFR;
        PORTD->ISFR = 0xFFFFFFFF;
        if(exti_cb_table[3] != NULL)
        exti_cb_table[3](ISFR);
    }

    void PORTE_IRQHandler(void)
    {
         uint32_t ISFR;
        ISFR = PORTE->ISFR;
        PORTE->ISFR = 0xFFFFFFFF;
        if(exti_cb_table[4] != NULL)
        exti_cb_table[4](ISFR);
    }
    void PORTF_IRQHandler(void)
    {

    }
    
}