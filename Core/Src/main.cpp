#include "includes.h"

System sys;

void main()
{
  
  HAL::Init(&sys);
  sys.Init();

  sys.Run();
}
