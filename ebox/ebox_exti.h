#ifndef __EBOX_EXTI_H
#define __EBOX_EXTI_H

#include "../ebox/ebox_common.h"
typedef void (*exti_callback_fun_type)(uint32_t para);

class Exti
{
public:		
	Exti(Gpio *pin,PORT_IT_DMA_CONFIG_t trigger);
    void begin();
	void attach_interrupt(exti_callback_fun_type callback);
    void interrupt(FunctionalState enable);

private:
    Gpio *pin;
    PORT_IT_DMA_CONFIG_t trigger;

};

#endif
