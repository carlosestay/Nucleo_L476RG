//******************
// CLASS: Buttom
//
// DESCRIPTION:
// GPIO Class
//
// CREATED: 5/13/2022, by Carlos Estay
//
// FILE: led.h
//

#ifndef BUTTON_H
#define BUTTON_H

#include "gpio.h"
#include "stopwatch.h"

using namespace GpioConfig;

class Button: public GPIO
{
public:
  void Init(GPIO_TypeDef*, uint16_t, Logic);
  bool IsActive(void);
  SwState GetState(void);
  void Blink(uint32_t);

private:
  Logic m_Logic;
  SwState m_State;
  Stopwatch m_Timer;
};

#endif /* BUTTON_H */