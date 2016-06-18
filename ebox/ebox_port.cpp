#include "../ebox/ebox_common.h"


Port::Port(PORT_Type *port,uint32_t pin)
{
    uint16_t temp1;
    this->port = port;
    this->pin = pin;
    
    switch((uint32_t)this->port)
    {
    case PORTA_BASE:
        temp1 = 0x0000;
        irq = PORTA_IRQn;
        break;
    case PORTB_BASE:
        temp1 = 0x0100;
        irq = PORTB_IRQn;
        break;
    case PORTC_BASE:
        temp1 = 0x0200;
        irq = PORTC_IRQn;
        break;
    case PORTD_BASE:
        temp1 = 0x0300;
        irq = PORTD_IRQn;
        break;
    case PORTE_BASE:
        temp1 = 0x0400;
        irq = PORTE_IRQn;
        break;
    //case PORTF_BASE:
     //   temp1 = 0x05;
     //   break;
    }
    this->id = (PIN_ID_t)(temp1 + this->pin);
}
void Port::set_pull_down()
{
    PORT_BWR_PCR_PS(port, pin, 0);
}

void Port::set_pull_up()
{
    PORT_BWR_PCR_PS(port, pin, 1);
}




void Port::set_slew_rate_fast()
{
    PORT_BWR_PCR_SRE(port, pin, 0);
}
void Port::set_slew_rate_slow()
{
    PORT_BWR_PCR_SRE(port, pin, 1);
}

void Port::set_drive_strength_low()
{
    PORT_BWR_PCR_DSE(port, pin, 0);
}
void Port::set_drive_strength_high()
{
    PORT_BWR_PCR_DSE(port, pin, 1);
}

void Port::set_pull_enable(FunctionalState state)
{
	PORT_BWR_PCR_PE(port, pin, state);
}
void Port::set_clock_enable(FunctionalState state)
{
    uint32_t temp = (uint32_t)port;
        temp = ((temp<<16)>>28);
    if(state)
        SIM->SCGC5    |= 1U << temp;
    else
        SIM->SCGC5    &= ~(1U << temp);
        
}
void Port::set_passive_filter_enable(FunctionalState state)
{
    PORT_BWR_PCR_PFE(port, pin, state);
}
void Port::set_push_pull_enable(FunctionalState state)
{
    PORT_BWR_PCR_PE(port, pin, state);
}
void Port::set_open_drain_enable(FunctionalState state)
{
    PORT_BWR_PCR_ODE(port, pin, state);
}

void Port::set_mux(uint8_t mux)
{
    PORT_BWR_PCR_MUX(port, pin, mux);
}



void Port::it_dma_config(PORT_IT_DMA_CONFIG_t config,FunctionalState state)
{
    set_clock_enable(ENABLE);
    port->PCR[pin] &= ~PORT_PCR_IRQC_MASK;
    if(state != ENABLE)
    {
        NVIC_DisableIRQ(irq);
        return;
    }
    switch(config)    
    {
    case PORT_DMA_RisingEdge:
        port->PCR[pin] |= PORT_PCR_IRQC(1);
        break;
    case PORT_DMA_FallingEdge:
        port->PCR[pin] |= PORT_PCR_IRQC(2);
        break;
    case PORT_DMA_RisingFallingEdge:
        port->PCR[pin] |= PORT_PCR_IRQC(3);
        break;

        
    case PORT_IT_Low:
        port->PCR[pin] |= PORT_PCR_IRQC(8);
        NVIC_EnableIRQ(irq);
        break;
    case PORT_IT_RisingEdge:
        port->PCR[pin] |= PORT_PCR_IRQC(9);
        NVIC_EnableIRQ(irq);
        break;
    case PORT_IT_FallingEdge:
        port->PCR[pin] |= PORT_PCR_IRQC(10);
        NVIC_EnableIRQ(irq);
        break;
    case PORT_IT_RisingFallingEdge:
        port->PCR[pin] |= PORT_PCR_IRQC(11);
        NVIC_EnableIRQ(irq);
        break;
    case PORT_IT_High:
        port->PCR[pin] |= PORT_PCR_IRQC(12);
        NVIC_EnableIRQ(irq);
        break;        
    default:            
        break;    
    }
}
void Port::interrupt(FunctionalState state)
{
    if(state != ENABLE)
    {
        NVIC_DisableIRQ(irq);
    }
    else
        NVIC_EnableIRQ(irq);
}

