//******************
// CLASS: EventManager
//
// DESCRIPTION:
//  Event Manager source dile for handling events
//
// CREATED: 7/14/2020, by Carlos Estay
//
// MODIFIED: 5/20/2022, by CarlosEstay
//
// FILE: eventManager.cpp
//
//#include "includes.h"

#include "eventManager.h"

static EventManager* Instance;

//-------------------------------------------------------------------Constructor
EventManager::EventManager()
{
  Instance = this;
}
//------------------------------------------------------------------------------
EventManager* EventManager::getInstance()
{
  return Instance;
}
//------------------------------------------------------------------------------------------