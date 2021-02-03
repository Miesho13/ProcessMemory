/*

*/


#ifndef READWRITE_H_
#define READWRITE_H_

#include "Process.hpp"
#include <vector>

namespace ProcessMemory
{
  template<typename T>
  class ReadWrite
  {
    private:
      Process prc;

      std::vector<int> offsetvector;

      unsigned long startAddres;

      unsigned long currentAddres;
      
    public:
    
    // Constructors

      ReadWrite(Process & p);

      ReadWrite(Process & p, std::vector<unsigned long> off);

      ReadWrite(Process & p,unsigned long startAddr, std::vector<unsigned long> off);
    
    // method
      void setOffset(std::vector<unsigned int> off);

      void setStartAddres(unsigned long stra);

      T read() const;

      void wirteTo(T value);
  };  


}

#endif