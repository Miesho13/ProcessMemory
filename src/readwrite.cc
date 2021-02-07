#include "../include/ReadWrite.hpp"

template<typename T>
ProcessMemory::ReadWrite<T>::ReadWrite(Process & p) :
  prc(p), offsetvector(0), startAddres(0), currentAddres(0), isReady(false) { }


template<typename T>
ProcessMemory::ReadWrite<T>::ReadWrite(Process & p, Offsetvec & off) :
  prc(p), offsetvector(off), startAddres(0), currentAddres(0), isReady(false) { }


template<typename T>
ProcessMemory::ReadWrite<T>::ReadWrite(Process & p, DWORD offstartAddres, Offsetvec & off) :
  prc(p), offsetvector(off), currentAddres(0), isReady(false) 
{

  ReadProcessMemory
  (
    prc.getProcHan(), 
    (LPCVOID)(prc.getProcBaseAddr() + offstartAddres),
    &startAddres,
    sizeof(startAddres),
    NULL
  );
  
  isReady = true;
}


template<typename T>
DWORD ProcessMemory::ReadWrite<T>::getStartAddres() const
{
  return startAddres;
}


template<typename T>
DWORD ProcessMemory::ReadWrite<T>::getCurrentAddres() const
{
  return currentAddres;
}


template<typename T>
void ProcessMemory::ReadWrite<T>::showDebugInfo() const
{
  std::wcout << std::hex; 
  std::wcout << "DEBUGINFO: " << "Start Addres:: " << getStartAddres() <<  '\n';
  std::wcout << "DEBUGINFO: " << "Current addres:: " << getCurrentAddres() <<  '\n';
  std::wcout << "DEBUGINFO: Offset Vector = ";

  std::for_each
  (
    std::begin(offsetvector),
    std::end(offsetvector),
    [](DWORD x)
    {
      std::wcout << "[0x" << x << "], ";
    }
  );
  std::wcout << '\n';

  std::wcout << std::dec;
}


template class ProcessMemory::ReadWrite<int>;

template class ProcessMemory::ReadWrite<double>;

template class ProcessMemory::ReadWrite<float>;

template class ProcessMemory::ReadWrite<std::string>;




