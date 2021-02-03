#include <iostream>
#include "../include/ProcessMemory.hpp"

int main()
{
  
  ProcessMemory::Process prc(3892, L"steam.exe");
  prc.showDebudInfo();

  return 0;
}