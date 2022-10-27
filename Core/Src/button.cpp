//******************
// CLASS: Button
//
// DESCRIPTION:
// Button Class
//
// CREATED: 5/13/2022, by Carlos Estay
//
// FILE:button.cpp
//


#include "button.h"

//------------------------------------------------------------------------------
void Button::Init(GPIO_TypeDef* _port, uint16_t _pin, Logic _logic)
{
  InitInput(_port, _pin);
  m_Logic = _logic;
  m_Timer.Init();
  
}
//------------------------------------------------------------------------------
bool Button::IsActive()
{
  bool active = Read();
  
  if(m_Logic)
  {
    return active;
  }
  else
  {
    return !active;
  }
}
//------------------------------------------------------------------------------
SwState Button::GetState()
{
  if(IsActive())
  {
    if(m_State == Idle)
    {
      m_State = Pressed;
    }
    else
    {
      m_State = Held;
    }
  }
  else
  {
    if(m_State == Pressed)
    {
      m_State = Released;
    }
    else
    {
      m_State = Idle;
    }    
  }
  return m_State;
}
//------------------------------------------------------------------------------
void Button::Blink(uint32_t _ms)
{
  
}

