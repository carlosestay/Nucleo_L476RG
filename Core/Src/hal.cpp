//******************
// CLASS: HAL
//
// DESCRIPTION:
//  HAL source file
//
// CREATED: 5/9/2022, by CarlosEstay
//
// FILE: hal.cpp
//

#include "includes.h"

System* sysPtr;
volatile uint32_t masterCount;

HAL::HAL()
{
  
}
//------------------------------------------------------------------------------
HAL::~HAL()
{
  
}
//------------------------------------------------------------------------------
void HAL::Init(System* _sys)
{
  sysPtr = _sys;
  ClockSInit();
  SysTick_Config(80000);  //Set Systick interrupt to 1KHz
  GpioInit();
  UartInit();
}
//------------------------------------------------------------------------------
void HAL::ClockSInit()
{
  /*
  After a system reset, the backup domain (RTC registers and backup registers) is protected
  against possible unwanted write accesses.
  */
  //Enable power interface clock (6.4.19)
  RCC->APB1ENR1 |= RCC_APB1ENR1_PWREN;  
  
  /*
  To limit the time lost due to jumps, it is possible to retain 32 lines of 4*64 bits in an instruction
  cache memory
  */
  //Enable instruction prefetch, instruction and data cache enable
  FLASH->ACR |= FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN;
  
  /*
  These bits represent the number of HCLK (AHB clock) period to the Flash
  access time. 
  */
  
//Prewetch buffer enable, One wait state, for 24MHz , SYSCLK <= 48 MHZ  (3.5.1)
  //Slowdown FLASH
  FLASH->ACR &= ~FLASH_ACR_LATENCY;
  FLASH->ACR |= FLASH_ACR_LATENCY_1WS;  
  
  Clock::InitPll(Pll_80MHZ);
}
//------------------------------------------------------------------------------
void HAL::GpioInit()
{
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;  //Enable Port A
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;  //Enable Port B

}
//------------------------------------------------------------------------------
void HAL::UartInit()  
{

  
  
  //USART 2 is connected to the ouside world
  
  //Enable USART2 CLOCK
  RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;  
  
  //PA2 -> USART2_TX  
  GPIOA->MODER &= ~GPIO_MODER_MODER2;           //Clear moder for PA2
  GPIOA->MODER |= GPIO_MODER_MODER2_1;         //Set Moder to Alternate (10b)
  GPIOA->AFR[0] |= 7 << (2 * 4);                //Set PA2 to AF7 (USART2_TX)
    
  //PA3 -> USART2_RX 
  GPIOA->MODER &= ~GPIO_MODER_MODER3;           //Clear moder for PA3
  GPIOA->MODER |= GPIO_MODER_MODER3_1;         //Set Moder to Alternate (10b)
  GPIOA->AFR[0] |= 7 << (3 * 4);                //Set PA3 to AF7 (USART2_RX)
  
  NVIC_EnableIRQ(USART2_IRQn);                  // CM4 Intrinsic
  //NVIC_SetPriority(USART2_IRQn, 4);
  USART2->CR1 |= USART_CR1_RXNEIE;              //Enable USART 2 Receiving Interrupt
  
}




uint32_t* HAL::GetCounterAddr(void)
{
  return (uint32_t*)&masterCount;
}
//------------------------------------------------------------------------------



//Native C interrupts-----------------------------------------------------------
  //Systick
extern "C"
{
  void SysTick_Handler(void)
  {
    ++masterCount;
  }  
}
