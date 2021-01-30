#include "../include/Process.hpp"

/*** Process class process ***/

ProcessMemory::Process::Process(LPCWSTR hPW, const wchar_t *PM)
{
  this->isGood = false;
  
  // It will be assigned to is Good at the end of the constructor
  bool goodSate = true;

  //
  // Finde window with WINAPI
  this->handlerProcessWin = FindWindowW(NULL, hPW); 
  if ( this->handlerProcessWin == NULL )
  {
    errorVector.push_back(ERR::DOESNT_FINDE_WINDOW);
    goodSate = false;
  }

  // 
  // Get process ID
  this->pID = 0;
  GetWindowThreadProcessId(this->handlerProcessWin, &pID);

  // 
  // Open precess
  this->procHan = NULL;
  this->procHan = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->pID);
  if ( this->procHan == INVALID_HANDLE_VALUE || this->procHan == NULL )
  {
    errorVector.push_back(ERR::OPEN_PROCESS_FAILED);
    goodSate = false;
  }
  
  //
  // Alghoritm to finde where process memory started
  DWORD procBaseAddr = 0;

  if ( goodSate == true )
  {
    // Use tlhelp32 API
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, this->pID);
    MODULEENTRY32W modEntry32W = { 0 };
    modEntry32W.dwSize = sizeof(MODULEENTRY32W);

    if ( Module32FirstW(snapshot, &modEntry32W) )
    {
      // List search and hunks of the process
      do 
      {
        if ( wcscmp(modEntry32W.szModule, PM) == 0)
        {
          
          this->procBaseAddr = (DWORD)modEntry32W.modBaseAddr;
          this->procName = modEntry32W.szModule;
          
          break;
        }
      }while ( Module32NextW(snapshot, &modEntry32W) );
      CloseHandle(snapshot);
    }

  }

  this->isGood = goodSate;
}

ProcessMemory::Process::Process(DWORD pd, const wchar_t *PM) :
  handlerProcessWin(0), pID(pd)
{
  // It will be assigned to is Good at the end of the constructor
  bool goodSate = true;
  this->isGood = false;

  this->procHan = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->pID);
  if ( this->procHan == INVALID_HANDLE_VALUE || this->procHan == NULL )
  {
    errorVector.push_back(ERR::OPEN_PROCESS_FAILED);
    goodSate = false;
  }

  //
  // Alghoritm to finde where process memory started
  DWORD procBaseAddr = 0;

  if ( goodSate == true )
  {
    // Use tlhelp32 API
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, this->pID);
    MODULEENTRY32W modEntry32W = { 0 };
    modEntry32W.dwSize = sizeof(MODULEENTRY32W);

    if ( Module32FirstW(snapshot, &modEntry32W) )
    {
      // List search and hunks of the process
      do 
      {
        if ( wcscmp(modEntry32W.szModule, PM) == 0)
        {
          
          this->procBaseAddr = (DWORD)modEntry32W.modBaseAddr;
          this->procName = modEntry32W.szModule;
          
          break;
        }
      }while ( Module32NextW(snapshot, &modEntry32W) );
      CloseHandle(snapshot);
    }

  }
  this->isGood = goodSate;
}

// -------------------------------------------------------------------------------------

DWORD ProcessMemory::Process::getpID() const
{
  if (this->isGood == true)
  {
    return this->pID;
  }
  else 
  {
    return 0;
  }
}

HANDLE ProcessMemory::Process::getProcHan() const
{
  if (this->isGood == true)
  {
    return this->procHan;
  }
  else 
  {
    return 0;
  }
}

std::wstring ProcessMemory::Process::getProcName() const
{
  if (this->isGood == true)
  {
    return this->procName;
  }
  else 
  {
    return 0;
  }
}

HWND ProcessMemory::Process::getHandlerProcessWin() const
{
  if (this->isGood == true)
  {
    return this->handlerProcessWin;
  }
  else 
  {
    return 0;
  }
}

DWORD ProcessMemory::Process::getProcBaseAddr() const
{
  if (this->isGood == true)
  {
    return this->procBaseAddr;
  }
  else 
  {
    return 0;
  }
}

void ProcessMemory::Process::showDebudInfo() const
{
  if (isGood == true)
  {
    std::wcout << "PROCESS IFNO: " << '\n';
    std::wcout << "Proc Name: " << getProcName() << '\n';
    std::wcout << "Handler: " << getHandlerProcessWin() << '\n';
    std::wcout << "Proc Han: " << getProcHan() << '\n';
    std::wcout << "process ID: " << getpID() << '\n';
    std::wcout << "proc base addres: " << getProcBaseAddr() << '\n';
  }
  else 
  {
    std::wcout << "Number of ERROR: " << '\n';
    for (auto i : this->errorVector)
    {
      std::cout << (int)i << '\n';
    }
  }
}