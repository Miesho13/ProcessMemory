#include <iostream>
#include "../include/ProcessMemory.hpp"
#include <functional>

template<typename T>
class X 
{
  public:
    static T do_somethink(T a, T b){
      return a + b;
    }
};

int main()
{
  
  ProcessMemory::Process prc(13096, L"a.exe");
  prc.showDebudInfo();
  
  puts("");

  std::vector<DWORD> v = {0x20, 0x10, 0x05};

  DWORD offstar = 0;

  ProcessMemory::ReadWrite<int> a(prc, offstar, v);
  
  a.showDebugInfo();

 // auto c = X<int>::do_somethink(5,5);

  //std::cout << c << '\n';

  // ProcessMemory::ReadWrite<int>::writeTo(prc, 0x0061FEBC, 100);

  //WriteProcessMemory(prc.getProcHan(), (LPVOID)0x0061FEBC, &value, sizeof(value), NULL);

  // auto d = ProcessMemory::ReadWrite<int>::readFrom(prc, 0x0061FEBC);

  // std::cout << d << '\n';


  
  

  return 0;
}