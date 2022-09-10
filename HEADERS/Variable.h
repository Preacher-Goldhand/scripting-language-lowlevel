#ifndef VARIABLE_H
#define VARIABLE_H
#include <string_view>
#include "Expression.h"
#include "Memory.h"

class Variable : public Expression 
{
    private:
        std::string name;

    public:
        Variable(std::string_view nameParam);
        virtual int Evaluate(Memory& memoryParam);    
};
#endif // VARIABLE_H