#ifndef __EBOX_GPIO_H
#define __EBOX_GPIO_H

#include "ebox_port.h"
#include "MK60D10.h"

class Gpio :public Port   
{
public:
    Gpio(GPIO_Type *gpio_bass,PORT_Type *base,uint32_t pin):Port(base,pin)
    {
        this->gpio_base = gpio_bass;
    };
    void set_dir_in();
    void set_dir_out();
    
    void set();
    void reset();
    
    void write(uint32_t val);
    void toggle();
    
    bool read();
    bool read_input();
    bool read_output();
     
    Gpio &operator= (int value)
    {
        write(value);
        return *this;
    }
    operator int()
    {
        return read();
    }
private:
    GPIO_Type *gpio_base;
};

void        shift_out(Gpio *data_pin, Gpio *clock_pin, uint8_t bit_order, uint8_t val);
uint8_t		shift_in(Gpio *data_pin, Gpio *clock_pin, uint8_t bit_order);

#endif