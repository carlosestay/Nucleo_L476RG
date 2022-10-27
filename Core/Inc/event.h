//******************
// CLASS: Event
//
// DESCRIPTION:
//  --
//
// CREATED: 5/17/2022, by Carlos Estay
//
// FILE: event.h
//

#ifndef EVENT_H
#define EVENT_H

#include "eventcallback.h"
#include <vector> //to have a dynamic list for event callbacks


template <typename T = void>
class Event
{
public:
  
  ~Event(){}
  
  Event(){}
  Event(T* eventArgs)
  {
    m_EventArgs = eventArgs;
  }
  
  
  void AddListener(IEventCallback* _action)
  {
    CallbackArray::iterator position = find(m_Actions.begin(), m_Actions.end(), _action);
    if (position != m_Actions.end())
    {
            //Debug::LogWarning("Action existed in delegate list.");
            return;
    }
    m_Actions.push_back(_action);
  }
  
  void RemoveListener(IEventCallback* _action)
  {
          CallbackArray::iterator position = find(m_Actions.begin(), m_Actions.end(), _action);
          if (position == m_Actions.end())
          {
                  return;
          }
          m_Actions.erase(position);
  }
  
  void Trigger(BaseArgs* eventArgs)
  {
    for (IEventCallback* _action : m_Actions)
    {
            (*_action)(static_cast<T*>(eventArgs));
    }
  }
  
  void TriggerArgs()
  {
    for (IEventCallback* _action : m_Actions)
    {
            (*_action)(static_cast<T*>(m_EventArgs));
    }    
  }
  
  
  void Trigger()
  {
    for (IEventCallback* _action : m_Actions)
    {
            (*_action)();
    }
  }
 
private:
	typedef std::vector<IEventCallback*> CallbackArray;
	CallbackArray m_Actions;
        T* m_EventArgs;
};

#endif /* EVENT_H */