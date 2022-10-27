//******************
// CLASS: LED
//
// DESCRIPTION:
// LED Class
//
// CREATED: 5/13/2022, by Carlos Estay
//
// FILE: led.cpp
//


#include "led.h"

void LED::Init(GPIO_TypeDef* _port, uint16_t _pin, Logic _logic)
{
  InitOutput(_port, _pin);
  m_Logic = _logic;
}
//------------------------------------------------------------------------------
void LED::On()
{
  if(m_Logic)
  {
    Set();
  }
  else
  {
    Clear();
  }
}
//------------------------------------------------------------------------------
void LED::Off()
{
  if(m_Logic)
  {
    Clear();
  }
  else
  {
    Set();
  }
}
//------------------------------------------------------------------------------
void LED::Toggle()
{
  GPIO::Toggle();
}