#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include "Memory.h"

// An abstract class for implementing operation on constants and variables
class Expression 
{
    public:
        // A method to evaluate the expression 
        virtual int Evaluate(Memory& memoryParam) = 0;
};
#endif // EXPRESSION_H