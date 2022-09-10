#ifndef CONSTANT_H
#define CONSTANT_H
#include "Expression.h"
#include "Memory.h"

// A class representing a constant data (numbers)
class Constant : public Expression
{
    private:
        int value;

    public:
        Constant(int valueParam);
        virtual int Evaluate(Memory& memoryParam);
};
#endif // CONSTANT_H