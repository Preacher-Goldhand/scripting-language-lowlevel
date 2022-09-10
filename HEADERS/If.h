#ifndef IF_H
#define IF_H
#include <memory>
#include "HEADERS/Program.h"
#include "HEADERS/Expression.h"
#include "HEADERS/Memory.h"

// A class representing if statement 
class If : public Program
{
    private:
        std::shared_ptr<Program> branchThen;
        std::shared_ptr<Program> branchElse;
        std::shared_ptr<Expression> condition;
    
    public:
        If(std::shared_ptr<Expression> conditionParam, std::shared_ptr<Program> branchThenParam, std::shared_ptr<Program> branchElseParam);
        virtual void Evaluate(Memory& memoryParam);  
};
#endif // IF_H