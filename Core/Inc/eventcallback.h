//******************
// CLASS: EventCallback
//
// DESCRIPTION:
//  --
//
// CREATED: 5/17/2022, by Carlos Estay
//
// FILE: eventcallback.h
//

#ifndef EVENTCALLBACK_H
#define EVENTCALLBACK_H

#include <cstring>

class BaseArgs
{
public:
  virtual ~BaseArgs(){}
private:
  
};

template <typename T>
class EventArgs : public BaseArgs
{
  public:
  EventArgs(){}
  EventArgs(T args)
  {
    m_Args = args;
  }
  void ClearArgs(void)
  {
    std::memset(&m_Args, 0, sizeof(T));
  }
  T m_Args;
  private:
  
};

class IEventCallback
{
public:
  IEventCallback(){}
  virtual ~IEventCallback(){}; //virtual destructor to avoid undefined vehabiour
  virtual void operator() (BaseArgs* pArgs) = 0;
  virtual void operator() () = 0;
};

template <typename T, typename ArgType = void>
class EventCallback : public IEventCallback
{    
public: 
        //EventAction Type is a pointer to a function in Object of Type T, that takes an argument of type P*
        typedef void (T::*EventAction)(ArgType*);  
        typedef void (T::*EventFunction)();
          
        //Constructors
        
        //Default Contructor
        EventCallback()
        {
          std::memset(m_pInstance, 0, sizeof(T));
        };        
        
        //Non argument event callback constructor
	EventCallback(T* instance, EventFunction function)
		: m_pInstance(instance), m_pFunction(function) {};    
        
        //Argumented event callback constructor
	EventCallback(T* instance, EventAction action)
		: m_pInstance(instance), m_pAction(action) {};                  
                
        //Overrides
	virtual void operator () (BaseArgs* pArgs) override 
        { 
          (m_pInstance->*m_pAction)(static_cast <ArgType*>(pArgs));
        } 
        
        virtual void operator () () override 
        { 
           (m_pInstance->*m_pFunction)();
        } 
               
private:
	EventAction m_pAction;
        EventFunction m_pFunction;
	T* m_pInstance;
};

#endif /* EVENTCALLBACK_H */