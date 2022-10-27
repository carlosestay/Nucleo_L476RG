//******************
// CLASS: Stopwatch
//
// DESCRIPTION:
// Stopwatch Class
//
// CREATED: 5/13/2022, by Carlos Estay
//
// FILE: stopwatch.h
//

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include "stm32l4xx.h"
#include "eventcallback.h"

class Stopwatch
{
public:
  void Init(void);
  void Start(void);
  uint32_t Read(void);
  void Reset(void);
  void Stop(void);
  void Delay(uint16_t);
  void EventTest(EventArgs<uint16_t>*);
  bool IsRunning(void);
  
private:
  uint32_t m_Start;
  uint32_t m_Count;
  uint32_t* m_pMasterCount;
  bool m_Running;
};

#endif /* STOPWATCH_H */