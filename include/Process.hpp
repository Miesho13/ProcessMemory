#ifndef PROCESS_H_
#define PROCESS_H_

#include <windows.h>
#include <iostream>
#include <vector>
#include <tlhelp32.h>
#include <tchar.h>


namespace ProcessMemory
{
  class Process
  {
    private:

      enum class ERR
      {
        DOESNT_FINDE_WINDOW = 1,
        OPEN_PROCESS_FAILED = 2
      };

      std::vector<ERR> errorVector;
    
    // Value is handle to the window that has
    // the specified class name and window name.
      HWND handlerProcessWin;
    
    // Value is the identifier of the
    // thread that created the window
      DWORD pID;

    // Value is open handle to the
    // specified process
      HANDLE procHan;
    
    // Process name
      std::wstring procName;

    // Address where started
    // process's memory
      DWORD procBaseAddr;

    // is true when constructor and
    // coretly
      bool isGood;
    
    public:
    // Constructor

      Process(LPCWSTR hPW, const wchar_t *PM);

      Process(DWORD pd, const wchar_t *PM);

    // Methods:

      HWND getHandlerProcessWin() const;

      DWORD getpID() const;

      HANDLE getProcHan() const;

      std::wstring getProcName() const;

      DWORD getProcBaseAddr() const;

      void showDebudInfo() const;


  };
  
}

#endif