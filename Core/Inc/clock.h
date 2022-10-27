//******************
// CLASS: CLOCK
//
// DESCRIPTION:
// Clock System Class
//
// CREATED: 5/9/2022, by Carlos Estay
//
// FILE: clock.h
//
#ifndef CLOCK_H
#define CLOCK_H

#include "stm32l4xx.h"

namespace ClockSystem
{
  enum MsiRange
  {
    Msi8MHZ = 7 << 4,
    Msi16MHZ = 8 << 4,
    Msi24MHZ = 9 << 4,
    Msi32MHZ = 10 << 4,
    Msi48MHZ = 11 << 4
  };
  
  enum PllRange
  {//PllM is defaulted to 0(/1)
    Pll_12MHZ = 3<<25 | 24<<8 | RCC_PLLCFGR_PLLSRC_MSI,          //PllR = 8(11b << 25), PllN = 24 << 8
    Pll_16MHZ = 3<<25 | 32<<8 | RCC_PLLCFGR_PLLSRC_MSI,          //PllR = 8(11b << 25), PllN = 32 << 8      
    Pll_20MHZ = 3<<25 | 40<<8 | RCC_PLLCFGR_PLLSRC_MSI,          //PllR = 8(11b << 25), PllN = 40 << 8
    Pll_24MHZ = 1<<25 | 24<<8 | RCC_PLLCFGR_PLLSRC_MSI,          //PllR = 4(01b << 25), PllN = 24 << 8
    Pll_32MHZ = 1<<25 | 32<<8 | RCC_PLLCFGR_PLLSRC_MSI,          //PllR = 4(01b << 25), PllN = 32 << 8
    Pll_40MHZ = 1<<25 | 40<<8 | RCC_PLLCFGR_PLLSRC_MSI,          //PllR = 4(01b << 25), PllN = 40 << 8
    Pll_48MHZ = 0<<25 | 24<<8 | RCC_PLLCFGR_PLLSRC_MSI,          //PllR = 4(00b << 25), PllN = 24 << 8
    Pll_64MHZ = 0<<25 | 32<<8 | RCC_PLLCFGR_PLLSRC_MSI,          //PllR = 2(00b << 25), PllN = 32 << 8
    Pll_80MHZ = 0<<25 | 40<<8 | RCC_PLLCFGR_PLLSRC_MSI           //PllR = 2(00b << 25), PllN = 40 << 8
  };  
};

using namespace ClockSystem;

class Clock
{
public:
  Clock(){}
  ~Clock(){}
  static void InitMsi(MsiRange);
  static void InitPll(PllRange);
  
private:
  
  
};

#endif /* CLOCK_H */