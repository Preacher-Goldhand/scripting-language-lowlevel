#ifndef WHILE_H
#define WHILE_H
#include <memory>
#include "HEADERS/Program.h"
#include "HEADERS/Expression.h"
#include "HEADERS/Memory.h"

// A class representing while loop statement 
class While : public Program
{
    private:
        std::shared_ptr<Program> body;
        std::shared_ptr<Expression> condition;
    
    public:
        While(std::shared_ptr<Expression> conditionParam, std::shared_ptr<Program> bodyParam);
        virtual void Evaluate(Memory& memoryParam);
};
#endif // WHILE_H


