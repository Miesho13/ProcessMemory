/*

*/


#ifndef READWRITE_H_
#define READWRITE_H_

#include "Process.hpp"
#include <vector>
#include <algorithm>

namespace ProcessMemory
{

  typedef std::vector<DWORD> Offsetvec;
  typedef bool ReadyToUse;

  template<typename T>
  class ReadWrite
  {
    private:
      Process & prc;

      Offsetvec offsetvector;

      DWORD startAddres;

      DWORD currentAddres;
      
      ReadyToUse isReady;

      T value;

    public:
    
    // Constructors

      ReadWrite(Process & p);

      ReadWrite(Process & p, Offsetvec & off);

      ReadWrite(Process & p, DWORD startAddres, Offsetvec & off);
    
    // method
      void setOffset(Offsetvec off);

      void setStartAddres(DWORD stra);

      T readWith();

      T readCurrentAddres();
      
      void wirteTo(T val);

      void writeTo(DWORD where, T val);

      Offsetvec getOffsetvector() const;

      DWORD getStartAddres() const;

      DWORD getCurrentAddres() const;

      void showDebugInfo() const;
  };  


}

#endif