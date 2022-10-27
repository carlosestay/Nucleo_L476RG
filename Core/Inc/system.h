//******************
// CLASS: System
//
// DESCRIPTION:
// GPIO Class
//
// CREATED: 5/13/2022, by Carlos Estay
//
// FILE: system.h
//

#ifndef SYSTEM_H
#define SYSTEM_H

#include "led.h"
#include "button.h"
#include "Stopwatch.h"
#include "eventcallback.h"
#include "event.h"
#include "uart.h"
#include "eventManager.h"


class System
{
public:
  System(){}
  ~System(){}
  void Init(void);
  void Run(void);
  
  LED led1;
  LED led2;
  LED led3;
  LED led4;
  Button sw1;
  Button sw2;
  Button sw3;
  Stopwatch pacer;
  Stopwatch eventPacer;
  uint16_t time;
  UART uart2;
  
  EventManager eventManager;
  
  //Event CallBacks
  EventCallback<Stopwatch, EventArgs<uint16_t> > testCallBack = EventCallback(&eventPacer, &Stopwatch::EventTest);
  

  EventCallback<LED> ToggleLed1 = EventCallback(&led1, &LED::Toggle);
  EventCallback<LED> ToggleLed2 = EventCallback(&led2, &LED::Toggle);
  EventCallback<LED> ToggleLed3 = EventCallback(&led3, &LED::Toggle);
  
 
private:

};

#endif /* SYSTEM_H */