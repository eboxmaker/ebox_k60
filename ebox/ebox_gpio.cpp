#include "../ebox/ebox_gpio.h"
#include "../ebox/ebox_common.h"
#include "MK60D10_extension.h"

void Gpio::set_dir_in()
{
    GPIO_CLR_PDDR(gpio_base, 1U << pin);
}
void Gpio::set_dir_out()
{
    GPIO_SET_PDDR(gpio_base, 1U << pin);
}
void Gpio::set()
{
    GPIO_WR_PSOR(gpio_base, 1U << pin); /* Set pin output to high level.*/
}
void Gpio::reset()
{
    GPIO_WR_PCOR(gpio_base, 1U << pin); /* Set pin output to low level.*/
}
void Gpio::write(uint32_t val)
{
    if (val != 0U)
    {
        GPIO_WR_PSOR(gpio_base, 1U << pin); /* Set pin output to high level.*/
    }
    else
    {
        GPIO_WR_PCOR(gpio_base, 1U << pin); /* Set pin output to low level.*/
    }
}
void Gpio::toggle()
{
    GPIO_WR_PTOR(gpio_base, 1U << pin);
}

bool Gpio::read()
{
    return ((GPIO_RD_PDIR(gpio_base) >> pin) & 0x01U);
}

bool Gpio::read_input()
{
    return ((GPIO_RD_PDIR(gpio_base) >> pin) & 0x01U);
}

bool Gpio::read_output()
{
    return ((GPIO_RD_PDOR(gpio_base) >> pin) & 0x1U);
}
/**
 *@name     uint8_t shift_in(GPIO *data_pin, GPIO *clock_pin, uint8_t bit_order)
 *@brief    GPIO按照时钟连续输出一个u8类型的数据，用于串行通信。
 *@param    data_pin：  数据输入引脚
            clock_pin:  时钟信号的引脚
            bit_order:  数据大小端控制LSB_FIRST：低位先发送；MSB_FIRST高位先发送
 *@retval   接收到的数据
*/
uint8_t shift_in(Gpio *data_pin, Gpio *clock_pin, uint8_t bit_order)
{
    uint8_t value = 0;
    uint8_t i;

    for (i = 0; i < 8; ++i)
    {
        clock_pin->write(HIGH);
        if (bit_order == LSB_FIRST)
            value |= data_pin->read() << i;
        else
            value |= data_pin->read() << (7 - i);
        clock_pin->write(LOW);
    }
    return value;
}

/**
 *@name     uint8_t shift_in(GPIO *data_pin, GPIO *clock_pin, uint8_t bit_order)
 *@brief    GPIO按照时钟连续输出一个u8类型的数据，用于串行通信。
 *@param    data_pin：  数据输出引脚
            clock_pin:  时钟信号的引脚
            bit_order:  数据大小端控制LSB_FIRST：低位先发送；MSB_FIRST高位先发送
            val：       要发送的数据
 *@retval   NONE
*/
void shift_out(Gpio *data_pin, Gpio *clock_pin, uint8_t bit_order, uint8_t val)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        if (bit_order == LSB_FIRST)
            data_pin->write(!!(val & (1 << i)));
        else
            data_pin->write(!!(val & (1 << (7 - i))));

        clock_pin->write(HIGH);
        clock_pin->write(LOW);

    }
}