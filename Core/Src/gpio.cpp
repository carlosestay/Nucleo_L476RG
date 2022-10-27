//******************
// CLASS: GPIO
//
// DESCRIPTION:
// GPIO Class
//
// CREATED: 5/13/2022, by Carlos Estay
//
// FILE: gpio.cpp
//


#include "gpio.h"

/*
  16-pin port
  MODER REGISTER (32-bits, 2 per pin)
  -00: Input mode
  -01: General purpose output mode
  -10: Alternate function mode
  -11: Analog mode (reset state)

  OTYPER REGISTER 16-LSBits, 1 per pin)
  The output type will be configured to push-pull by default.
  If open drain is desired, change OTYPER register
  
  PUPDR REGISTER (32-bits, 2 per pin)
  -00: No pull-up, pull-down
  -01: Pull-up
  -10: Pull-down
  -11: Reserved

*/

//------------------------------------------------------------------------------
void GPIO::InitInput(GPIO_TypeDef* _port, uint16_t _pin)
{
  m_Port = _port;
  m_Pin = _pin;
  m_Port->MODER &= ~(0b11 << (2*m_Pin)); //Clear moder, configure as input 
}
//------------------------------------------------------------------------------
void GPIO::InitOutput(GPIO_TypeDef* _port, uint16_t _pin)
{
  m_Port = _port;
  m_Pin = _pin;
  m_Port->MODER &= ~(0b11 <<(2*m_Pin)); //Clear moder
  m_Port->MODER |= (0b01 << (2*m_Pin)); //Configure as output
}
//------------------------------------------------------------------------------
void GPIO::Set(void)
{
  m_Port->ODR |= (1 << m_Pin);
}
//------------------------------------------------------------------------------
void GPIO::Clear(void)
{
  m_Port->ODR &= ~(1 << m_Pin);
}
//------------------------------------------------------------------------------
void GPIO::Toggle(void)
{
  m_Port->ODR ^= (1 << m_Pin);
}
//------------------------------------------------------------------------------
bool GPIO::Read(void)
{
  return(m_Port->IDR & (1 << m_Pin));
}