#ifndef PROGRAM_H
#define PROGRAM_H
#include "HEADERS/Memory.h"

// A class representing our program structure 
class Program 
{
    public:
        virtual void Evaluate(Memory& memoryParam) = 0;
};
#endif // PROGRAM_H