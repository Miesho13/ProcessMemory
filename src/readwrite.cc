#include "../include/ReadWrite.hpp"

template<typename T>
ProcessMemory::ReadWrite<T>::ReadWrite(Process & p) :
  prc(p), offSetVector(0), startAddres(0), pointAddress(0), offFlag(false), 
  strFlag(false) { }



template<typename T>
ProcessMemory::ReadWrite<T>::ReadWrite(Process & p, Offsetvec & off) :
  prc(p), offSetVector(off), startAddres(0), pointAddress(0) 
{
  // Checking if vector is no empty
  if ( offSetVector.size() != 0 )
  {
    offFlag = true;
  }
  else 
  {
    offFlag = false;
  }
}



template<typename T>
ProcessMemory::ReadWrite<T>::ReadWrite
(
  Process & p, 
  DWORD offstartAddres, 
  Offsetvec & off
  ) :
  prc(p), offSetVector(off) 
{
  // Checking if vector is no empty
  if ( offSetVector.size() != 0 )
  {
    offFlag = true;
  }
  else 
  {
    offFlag = false;
  }

  // Checking if offstartAddres is not equal 0
  if ( offstartAddres >= 0 )
  {
    strAddrFlag = true;
  }
  else
  {
    strAddrFlag = false;
  }

  // Where we want start reading/writing
  startAddres = 0;
  if (strAddrFlag == true)
  {
    ReadProcessMemory
    (
      prc.getProcHan(), 
      (LPCVOID)(prc.getProcBaseAddr() + offstartAddres),
      &startAddres,
      sizeof(startAddres),
      NULL
    );
  }
  
  pointAddress = 0;

  // Go to address following offsets
  if (offFlag == true)
  {
    pointAddress = startAddres;
    for (int i = 0; i < offSetVector.size() - 1; i++)
    {
      ReadProcessMemory
      (
        prc.getProcHan(),
        (LPCVOID)(pointAddress + offSetVector.at(i)),
        &pointAddress,
        sizeof(pointAddress),
        NULL
      );
    }
    pointAddress += offSetVector.at(offSetVector.size() - 1);
  }
}



template<typename T>
T ProcessMemory::ReadWrite<T>::readFrom(Process & p, DWORD from)
{
  T retval;
  ReadProcessMemory
  (
    p.getProcHan(),
    (LPCVOID)from,
    &retval,
    sizeof(retval),
    NULL
  );

  return retval;
}



template<typename T>
void ProcessMemory::ReadWrite<T>::writeTo(Process & p, DWORD where, T val)
{
  T value = val;
  WriteProcessMemory
  (
    p.getProcHan(),
    (LPVOID)where,
    &value,
    sizeof(value),
    NULL
  );
}



template<typename T>
void ProcessMemory::ReadWrite<T>::setPointAddres(Offsetvec & off)
{
  // Clear current vector
  offSetVector.clear();
  offSetVector = off;

  // Checking if vector is no empty
  if (offSetVector.size() != 0)
  {
    offFlag = true;
  }
  else
  {
    offFlag = false;
  }
  
  if (offFlag = true)
  {

    pointAddress = startAddres;
    for (int i = 0; i < offSetVector.size() - 1; i++)
    {
      ReadProcessMemory
      (
        prc.getProcHan(),
        (LPCVOID)(pointAddress + offSetVector.at(i)),
        &pointAddress,
        sizeof(pointAddress),
        NULL
      );
    }
    pointAddress += offSetVector.at(offSetVector.size() - 1);
  }
}



template<typename T>
void ProcessMemory::ReadWrite<T>::setPointAddres(DWORD addr)
{
  pointAddress = addr;
}



template<typename T>
void ProcessMemory::ReadWrite<T>::setStartAddres(DWORD offsetToBaseAddres)
{
  // Where we want start reading/writing
  startAddres = 0;

  // Checking if offstartAddres is lower then 0
  if ( offstartAddres >= 0 )
  {
    strAddrFlag = true;
  }
  else
  {
    strAddrFlag = false;
  }
  
  if (strAddrFlag == true)
  {
    ReadProcessMemory
    (
      prc.getProcHan(), 
      (LPCVOID)(prc.getProcBaseAddr() + offsetToBaseAddres),
      &startAddres,
      sizeof(startAddres),
      NULL
    );
  }
} 



template<typename T>
void ProcessMemory::ReadWrite<T>::wirteToPointAddres(T val)
{
  if ( offFlag == true && strAddrFlag == true )
  {
    WriteProcessMemory
    (
      prc.getProcHan(),
      (LPVOID)pointAddress,
      &val,
      sizeof(val),
      NULL
    );
  }
}



template<typename T>
T ProcessMemory::ReadWrite<T>::readPointAddres()
{
  T retval = 0;

  if ( offFlag == true && strAddrFlag == true )
  ReadProcessMemory
  (
    prc.getProcHan(),
    (LPCVOID)pointAddress,
    &retval,
    sizeof(retval),
    NULL
  );

  return retval;
}



template<typename T>
DWORD ProcessMemory::ReadWrite<T>::getStartAddres() const
{
  return startAddres;
}



template<typename T>
DWORD ProcessMemory::ReadWrite<T>::getPointAddress() const
{
  return pointAddress;
}



template<typename T>
ProcessMemory::Offsetvec ProcessMemory::ReadWrite<T>::getOffSetVector() const
{
  return offSetVector;
}



template<typename T>
void ProcessMemory::ReadWrite<T>::showDebugInfo() const
{
  std::wcout << std::hex; 
  std::wcout << "DEBUGINFO: " << "Start Addres:: 0x" << getStartAddres() <<  '\n';
  std::wcout << "DEBUGINFO: " << "Current addres:: 0x" << getPointAddress() <<  '\n';
  std::wcout << "DEBUGINFO:  Offset Vector = ";

  std::for_each
  (
    std::begin(offSetVector),
    std::end(offSetVector),
    [](DWORD x)
    {
      std::wcout << "[0x" << x << "], ";
    }
  );
  std::wcout << "\n";

  std::wcout << std::dec;
}



template class ProcessMemory::ReadWrite<int>;

template class ProcessMemory::ReadWrite<double>;

template class ProcessMemory::ReadWrite<float>;

template class ProcessMemory::ReadWrite<long>;

template class ProcessMemory::ReadWrite<short>;

template class ProcessMemory::ReadWrite<std::string>;




