#ifndef __EBOX_PORT_H
#define __EBOX_PORT_H
#include "MK60D10.h"

/*! @brief Pin mux selection*/
#define PORT_PIN_DISABLED   0U   /*!< corresponding pin is disabled, but is used as an analog pin.*/
#define PORT_MUX_AS_GPIO    1U   /*!< corresponding pin is disabled, but is used as an analog pin.*/
#define    kPortMuxAlt2     2U   /*!< chip-specific*/
#define    kPortMuxAlt3     3U   /*!< chip-specific*/
#define    kPortMuxAlt4     4U   /*!< chip-specific*/
#define    kPortMuxAlt5     5U   /*!< chip-specific*/
#define    kPortMuxAlt6     6U   /*!< chip-specific*/
#define    kPortMuxAlt7     7U    /*!< chip-specific*/
class Port
{
public:
    Port(PORT_Type *base,uint32_t pin);
    void set_pull_down();
    void set_pull_up();
    
    void set_slew_rate_fast();
    void set_slew_rate_slow();
    
    void set_drive_strength_low();
    void set_drive_strength_high();

    void set_clock_cmd(bool cmd);
    void set_pull_cmd(bool cmd);
    void set_passive_filter_enable(bool cmd);
    void set_open_drain_enable(bool cmd);
    void set_mux(uint8_t mux);
    
protected:
    PORT_Type *base;
    uint32_t pin;
};
#endif

