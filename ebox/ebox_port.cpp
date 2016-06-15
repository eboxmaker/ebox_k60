#include "../ebox/ebox_port.h"
#include "MK60D10_extension.h"


Port::Port(PORT_Type *base,uint32_t pin)
{
    this->base = base;
    this->pin = pin;
}
void Port::set_pull_down()
{
    PORT_BWR_PCR_PS(base, pin, 0);
}

void Port::set_pull_up()
{
    PORT_BWR_PCR_PS(base, pin, 1);
}

void Port::set_slew_rate_fast()
{
    PORT_BWR_PCR_SRE(base, pin, 0);
}
void Port::set_slew_rate_slow()
{
    PORT_BWR_PCR_SRE(base, pin, 1);
}

void Port::set_drive_strength_low()
{
    PORT_BWR_PCR_DSE(base, pin, 0);
}
void Port::set_drive_strength_high()
{
    PORT_BWR_PCR_DSE(base, pin, 1);
}

void Port::set_clock_cmd(bool cmd)
{
    uint32_t temp = (uint32_t)base;
        temp = ((temp<<16)>>28);
    if(cmd)
        SIM->SCGC5    |= 1U << temp;
    else
        SIM->SCGC5    &= ~(1U << temp);
        
}
void Port::set_pull_cmd(bool cmd)
{
    PORT_BWR_PCR_PE(base, pin, cmd);
}

void Port::set_passive_filter_enable(bool cmd)
{
    PORT_BWR_PCR_PFE(base, pin, cmd);
}

void Port::set_open_drain_enable(bool cmd)
{
    PORT_BWR_PCR_ODE(base, pin, cmd);
}

void Port::set_mux(uint8_t mux)
{
    PORT_BWR_PCR_MUX(base, pin, mux);
}