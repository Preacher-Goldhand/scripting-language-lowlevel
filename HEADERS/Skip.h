#ifndef SKIP_H
#define SKIP_H
#include "HEADERS/Program.h"
#include "HEADERS/Memory.h"

// A class representing a skiping of doing something (nothing doing)
class Skip : public Program
{
    public:
        virtual void Evaluate(Memory& memoryParam) {}
};
#endif // SKIP_H