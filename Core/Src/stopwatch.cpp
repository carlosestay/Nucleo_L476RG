//******************
// CLASS: Stopwatch
//
// DESCRIPTION:
// Stopwatch Class
//
// CREATED: 5/13/2022, by Carlos Estay
//
// FILE:stopwatch.cpp
//


#include "stopwatch.h"
#include "hal.h"

//------------------------------------------------------------------------------
void Stopwatch::Init()
{
  m_pMasterCount = HAL::GetCounterAddr();
}
//------------------------------------------------------------------------------
void Stopwatch::Start()
{
  m_Start = *m_pMasterCount;
  m_Running = true;
}
//------------------------------------------------------------------------------
uint32_t Stopwatch::Read()
{
  m_Count = *m_pMasterCount - m_Start;
  return m_Count;
}
//------------------------------------------------------------------------------
void Stopwatch::Reset()
{
  m_Start = *m_pMasterCount;
  m_Count = 0;
}
//------------------------------------------------------------------------------
void Stopwatch::Stop()
{
  m_Start = 0;
  m_Count = 0;
  m_Running = false;
}
//------------------------------------------------------------------------------
void Stopwatch::Delay(uint16_t _time)
{
  m_Count = 0;
  Start();
  while(Read() < _time);
}
//------------------------------------------------------------------------------
void Stopwatch::EventTest(EventArgs<uint16_t> *args)
{
  args->m_Args += 10;
}
//------------------------------------------------------------------------------
bool Stopwatch::IsRunning()
{
  return m_Running;
}
//------------------------------------------------------------------------------

