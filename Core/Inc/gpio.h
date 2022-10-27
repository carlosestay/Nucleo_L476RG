//******************
// CLASS: GPIO
//
// DESCRIPTION:
// GPIO Class
//
// CREATED: 5/13/2022, by Carlos Estay
//
// FILE: gpio.h
//
#ifndef GPIO_H
#define GPIO_H

#include "stm32l4xx.h"

namespace GpioConfig
{
  enum Logic
  {
    ActiveHigh = 1,
    ActiveLow = 0
  };
  
  enum SwState
  {
    Idle,
    Pressed,
    Held,
    Released
  };
};

class GPIO
{
public:
  GPIO(){}
  ~GPIO(){}
  void InitInput(GPIO_TypeDef*, uint16_t);
  void InitOutput(GPIO_TypeDef*, uint16_t);
  void Set(void);
  void Clear(void);
  virtual void Toggle(void);
  bool Read(void);
  
private:
  GPIO_TypeDef* m_Port;
  uint16_t m_Pin;
};

#endif /* GPIO_H */