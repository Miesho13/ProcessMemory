/*
  It's declaration of ReadWrite class. The class is used to read and write
  the value of a process caught with Process method.
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
    // Variable: 
      Process & prc; // It's ref to Process obj

      Offsetvec offSetVector; // It's vectors' offsets to address we wanted 

      DWORD startAddres; // Where start to go for interesing value

      DWORD pointAddress; // Point to interesing addres
      
      ReadyToUse isReady; // This flag says us everythink is ok to R/W to adress

      T value; // 

    public:
    
    // Constructors

      ReadWrite(Process & p); 

      ReadWrite(Process & p, Offsetvec & off);

      ReadWrite(Process & p, DWORD startAddres, Offsetvec & off);
    //

    // method
      static T readFrom(Process & p, DWORD from);

      static void writeTo(Process & p, DWORD where, T val);

      void setPointAddres();
      
      void wirteTo(T val);

      T returnValue();

      void setOffset(Offsetvec & off);

      void setStartAddres(DWORD stra);

      Offsetvec getOffSetVector() const;

      DWORD getStartAddres() const;

      DWORD getPointAddress() const;

      void showDebugInfo() const;
    //
  };  


}

#endif