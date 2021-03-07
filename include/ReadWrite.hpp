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
      Process & prc; 

      Offsetvec offSetVector; 

      OffsetEgsistFlag offFlag;

      DWORD startAddres; 
      StartAddresEgsistFlag strAddrFlag;

      DWORD pointAddress; 
      

    public:
    
    // Constructors

    ReadWrite(Process & p); 

    ReadWrite(Process & p, Offsetvec & off);

    ReadWrite(Process & p, DWORD startAddres, Offsetvec & off);
    

    // Method:

      
    static T readFrom(Process & p, DWORD from);

    static void writeTo(Process & p, DWORD where, T val);

      
    void setPointAddres(Offsetvec & off);

    void setPointAddres(DWORD addres);
        
    void setStartAddres(DWORD stra);
      
       
    void wirteToPointAddres(T val);

    T readPointAddres();


    Offsetvec getOffSetVector() const;

    DWORD getStartAddres() const;

    DWORD getPointAddress() const;

    void showDebugInfo() const;
  };  
}

#endif