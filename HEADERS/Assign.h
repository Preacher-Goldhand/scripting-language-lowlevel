#ifndef ASSIGN_H
#define ASSIGN_H
#include <memory>
#include <string_view>
#include "HEADERS/Program.h"
#include "HEADERS/Expression.h"
#include "HEADERS/Memory.h"

// A class representing an assignment operator (it assigns an expression (value) to a variable )
class Assign : public Program
{
    private:
        std::string var;
        std::shared_ptr<Expression> expr;

    public:
        Assign(std::string_view varParam, std::shared_ptr<Expression> exprParam);
        virtual void Evaluate(Memory& memoryParam);
};
#endif // ASSIGN_H