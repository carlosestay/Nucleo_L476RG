//******************
// CLASS: EventManager
//
// DESCRIPTION:
//  Class for handling events
//
// CREATED: 7/14/2020, by Carlos Estay
// MODIFIED: 5/20/2022, by CarlosEstay
//
// FILE: eventManager.h
//

#include "event.h"

#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H


class EventManager
{
public:
  EventManager();
  static EventManager* getInstance();
  
  
  //Test event with parameters
  EventArgs<uint16_t> testEventArgs;
  Event<EventArgs<uint16_t>> testEvent = Event(&testEventArgs);  
  
  //LEDs event - no paramater
  Event<void> ledEvent;
  
 
private:

};

#endif /* EVENTMANAGER_H */