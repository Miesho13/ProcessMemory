/*
  This header it's part of simple API to read and write process's
  memory. Here is the class declaration. 

*/


#ifndef PROCESS_H_
#define PROCESS_H_

#include <windows.h>
#include <iostream>
#include <tlhelp32.h>
#include <vector>


namespace ProcessMemory
{

  typedef std::wstring ProcessName;

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
    
    // Process's name
      ProcessName procName;

    // Address where process's
    // memory is start
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

      ProcessName getProcName() const;

      DWORD getProcBaseAddr() const;

      bool getGoodState() const;

      void showDebudInfo() const;


  };
  
}

#endif