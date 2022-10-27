//******************
// CLASS: HAL
//
// DESCRIPTION:
//  Hardware Abstraction Layer
//
// CREATED: 5/9/2022, by Carlos Estay
//
// FILE: hal.h
//
#ifndef HAL_H
#define HAL_H

#define SYSTEM_CLOCK 80000000


#include "stm32l4xx.h"
#include "system.h"

class HAL
{
public:
  HAL();
  ~HAL();
  static void Init(System*);
  static void ClockSInit(void);
  static void GpioInit(void);
  static void UartInit(void);
  static uint32_t* GetCounterAddr(void);
private:
  
  
};

#endif /* HAL_H */