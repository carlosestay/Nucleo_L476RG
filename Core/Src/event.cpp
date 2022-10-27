//******************
// CLASS: Event
//
// DESCRIPTION:
//  --
//
// CREATED: 5/17/2022, by Carlos Estay
//
// FILE: event.cpp
//

#include "event.h"

//------------------------------------------------------------------------------
//void Event::AddListener(IEventCallback* _action)
//{
//  CallbackArray::iterator position = find(m_Actions.begin(), m_Actions.end(), _action);
//  if (position != m_Actions.end())
//  {
//          //Debug::LogWarning("Action existed in delegate list.");
//          return;
//  }
//  m_Actions.push_back(_action);
//}
//------------------------------------------------------------------------------
//void Event::RemoveListener(IEventCallback* _action)
//{
//	CallbackArray::iterator position = find(m_Actions.begin(), m_Actions.end(), _action);
//	if (position == m_Actions.end())
//	{
//		return;
//	}
//	m_Actions.erase(position);
//}
//------------------------------------------------------------------------------
//void Event::Trigger()
//{
//	for (IEventCallback* _action : m_Actions)
//	{
//		(*_action)();
//	}
//}