//******************
// CLASS: LED
//
// DESCRIPTION:
// GPIO Class
//
// CREATED: 5/13/2022, by Carlos Estay
//
// FILE: led.h
//

#ifndef LED_H
#define LED_H

#include "gpio.h"


using namespace GpioConfig;

class LED: public GPIO
{
public:
  void Init(GPIO_TypeDef*, uint16_t, Logic);
  void On(void);
  void Off(void);
  virtual void Toggle(void) override;

private:
  Logic m_Logic;
};

#endif /* LED_H */