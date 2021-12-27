# ProcessMemory

## About
It is a simple API for reading and writing the values of listening processes on windows.

## Specification

The API is divided into two classes. The first one called `Process` stores information about the listened process, such as process ID, prcess name ect. The second one `ReadWrite` is used to set the reading and changing values in the process.

# Main feature:
  - Get metadata about process.
  - Reading value from another process's address space.
  - Changing a value from another process's address space.
  


## How to use

In order to work, the API needs a header's path in the project and complicated files with kals definitions.

After including the `ProcessMemory.hpp` header to your project, it should look like this:

```c++
#include "ProcessMemory.hpp"
```

Now you need to create an object that will store the necessary information about the process you will be working on. For this, using the `Process` class. Constructor should get window's name and process's name.

```c++
ProcessMemory::Process calculatorP(nameOfWindow, nameOfProcess);
```

Now we can use Process's object to construct ReadWrite object.

```c++
ProcessMemory::ReadWrite calcRW(calculatorP);
ProcessMemory::ReadWrite calcRW(calculatorP, offSetVector);
ProcessMemory::ReadWrite calcRW(calculatorP, startedAddress, offSetVector);
```

Like above is a three way to create Read Write object.








