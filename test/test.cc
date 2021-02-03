#include <iostream>
#include "../include/ProcessMemory.hpp"

int main()
{
  
  ProcessMemory::Process prc(6320, L"a.exe");
  prc.showDebudInfo();
  
  

  return 0;
}