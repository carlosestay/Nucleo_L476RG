//******************
// CLASS: System
//
// DESCRIPTION:
// GPIO Class
//
// CREATED: 5/13/2022, by Carlos Estay
//
// FILE: system.cpp
//


#include "includes.h"


/*


*/



//------------------------------------------------------------------------------
void System::Init(void)
{
  led1.Init(GPIOA, 5, ActiveLow);
  led2.Init(GPIOA, 6, ActiveLow);
  led3.Init(GPIOA, 7, ActiveLow);
  led4.Init(GPIOB, 6, ActiveLow);
  led1.Off();
  led2.Off();
  led3.Off();
  led4.Off();  
  sw1.Init(GPIOA, 1, ActiveLow);
  sw2.Init(GPIOA, 4, ActiveLow);
  sw3.Init(GPIOB, 0, ActiveLow);
  pacer.Init();
  pacer.Start();


  uart2.Init(USART_2,B_115200);
  
  EventManager::getInstance()->testEvent.AddListener(&testCallBack);
  EventManager::getInstance()->ledEvent.AddListener(&ToggleLed1);
  EventManager::getInstance()->ledEvent.AddListener(&ToggleLed2);
  EventManager::getInstance()->ledEvent.AddListener(&ToggleLed3);
  
}
//------------------------------------------------------------------------------
void System::Run(void)
{
  EventManager::getInstance()->testEventArgs.m_Args = 250;
  for(;;)
  {
    if(pacer.Read() > EventManager::getInstance()->testEventArgs.m_Args)
    {
      pacer.Reset();
      //testEvent.TriggerArgs();
      EventManager::getInstance()->testEvent.TriggerArgs();
      led4.Toggle();  
      uart2.WriteString("Helo Carlos\r\n");
    }
    
    if(sw3.GetState() == Pressed)
    {
      //led3.Toggle();
//      EventManager::getInstance()->ledEvent.Trigger();
//      EventManager::getInstance()->testEvent.Trigger(&EventManager::getInstance()->testEventArgs);
      //testEvent.TriggerArgs();
    }  
    
  }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
