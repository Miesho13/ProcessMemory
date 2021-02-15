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
  typedef bool OffsetEgsistFlag;
  typedef bool StartAddresEgsistFlag;

  template<typename T>
  class ReadWrite
  {
    private:
    // Variable: 
      Process & prc; // It's ref to Process obj

      Offsetvec offSetVector; // It's vectors' offsets to address we wanted 

      OffsetEgsistFlag offFlag;

      DWORD startAddres; // Where start to go for interesing value

      StartAddresEgsistFlag strAddrFlag;

      DWORD pointAddress; // Point to interesing addres
      

    public:
    
    // Constructors

      ReadWrite(Process & p); 

      ReadWrite(Process & p, Offsetvec & off);

      ReadWrite(Process & p, DWORD startAddres, Offsetvec & off);
    

    // Method:

      // Some static: 
        static T readFrom(Process & p, DWORD from);

        static void writeTo(Process & p, DWORD where, T val);

      // Sets:
        void setPointAddres(Offsetvec & off);

        void setPointAddres(DWORD addres);
        
        void setStartAddres(DWORD stra);
      
      // Read Write to current pointing addres   
        void wirteToPointAddres(T val);

        T readPointAddres();

      // For debug ifno
        Offsetvec getOffSetVector() const;

        DWORD getStartAddres() const;

        DWORD getPointAddress() const;

        void showDebugInfo() const;
  };  
}

#endif