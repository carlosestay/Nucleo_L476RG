//******************
// CLASS: IEventcallback
//
// DESCRIPTION:
//  --
//
// CREATED: 5/17/2022, by Carlos Estay
//
// FILE: iEventCallback.h
//


class IEventcallback
{
public:
  IEventcallback();
  ~IEventcallback();
  
  virtual void operator() () = 0;
  
};

template<typename T>
class EventCallback : public IEventCallback
{    
public: 
        //Constructor
	EventCallback(T* instance, void (T::*function)())
		: m_pInstance(instance), m_pFunction(function) {}    
	virtual void operator () () override { (m_pInstance->*m_pFunction)(); }    
private:
	void (T::*m_pFunction)();
	T* m_pInstance;
        
};