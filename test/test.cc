#include <iostream>
#include "../include/Process.hpp"

int main()
{
  
  ProcessMemory::Process prc(15668, L"steam.exe");
  prc.showDebudInfo();

  return 0;
}