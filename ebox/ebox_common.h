#ifndef __EBOX_COMMON_H
#define __EBOX_COMMON_H

#include "MK60D10.h"                    // Device header

#define EBOX_VERSION "16.6.14"

#define EOK         0
#define EWAIT       1
#define EBUSY       2
#define ETIMEOUT    3
#define EPARA       4
#define E2LONG      5
#define EOTHER      128

#define true 0x1
#define false 0x0

#define HIGH 0x1
#define LOW  0x0


#define LSB_FIRST 0
#define MSB_FIRST 1

#define PI 3.1415926535898
    void       random_seed(uint16_t seed);
    uint16_t    random();
    uint16_t    random(uint16_t max);
    uint16_t    random(uint16_t min, uint16_t max);
    
#define interrupts()    __enable_irq
#define no_interrupt()  __disable_irq
    
/*
 * 定义运行到RAM的函数
 */
#if defined(__ICCARM__)
//IAR 用 __ramfunc 来声明
#define     __RAMFUNC __ramfunc
#else
#define     __RAMFUN
#endif
#endif
