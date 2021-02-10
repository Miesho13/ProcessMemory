#include <iostream>
#include "../include/ProcessMemory.hpp"

int main()
{
  
  ProcessMemory::Process prc(2980, L"a.exe");
  prc.showDebudInfo();
  
  puts("");

  std::vector<DWORD> v = {0x20, 0x10, 0x05};

  DWORD offstar = 0;

  ProcessMemory::ReadWrite<int> a(prc, offstar, v);
  
  a.showDebugInfo();


  
  

  return 0;
}