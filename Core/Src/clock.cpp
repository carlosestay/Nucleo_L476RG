//******************
// CLASS: CLOCK
//
// DESCRIPTION:
// Clock System Source File
//
// CREATED: 5/9/2022, by Carlos Estay
//
// FILE: clock.cpp
//
#include "clock.h"


//------------------------------------------------------------------------------
void Clock::InitMsi(MsiRange _range)
{//Check (6.2.3) in the Reference Manual
  RCC->CR &= ~RCC_CR_MSIRANGE_Msk;      //Clear MSI range
  //Set range, select range from CR register, Set MSI ON
  RCC->CR |= _range | RCC_CR_MSIRGSEL | RCC_CR_MSION;
}
//------------------------------------------------------------------------------
void Clock::InitPll(PllRange _range)
{
  RCC->CR &= ~RCC_CR_PLLON;             //Disable Pll
  while(RCC->CR  & RCC_CR_PLLRDY);     //Wait until Pll is fully stopped
  
  /*
  For Pll Configuration check (6.4.4) in the Reference Manual
  Also, the Clock COnfiguration tab in STMCubeMx 

  - PllSRC = 01b (MSI Clock)
  - Pll Clock = Pll Input (MSI) x PllN / PllM / PllR
  - PllM = 0 always (/1)

  Range 1:
  - PllN = 32
    - PllR = 8 for 16MHz
    - PllR = 4 for 32MHz
    - PllR = 2 for 64MHz

  Range 2:
  - PllN = 24
    - PllR = 8 for 12MHz
    - PllR = 4 for 24MHz
    - PllR = 2 for 48MHz

  Range 3:
  - PllN = 40
    - PllR = 8 for 20MHz
    - PllR = 4 for 40MHz
    - PllR = 2 for 80MHz
  */
  RCC->PLLCFGR = _range;                //Set range Defined in PllRange enum
  RCC->CR |= RCC_CR_PLLON;              //Enable Pll again
  while(!(RCC->CR & RCC_CR_PLLRDY));    //Wait until PLL is locked
  RCC->PLLCFGR |= RCC_PLLCFGR_PLLREN;   //Enable PLL Output  
  RCC->CFGR |= RCC_CFGR_SW_PLL;         //Set Pll as System Clock
}