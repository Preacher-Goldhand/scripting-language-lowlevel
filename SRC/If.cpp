#include <memory>
#include "HEADERS/Program.h"
#include "HEADERS/Expression.h"
#include "HEADERS/Memory.h"
#include "HEADERS/If.h"

If::If(std::shared_ptr<Expression> conditionParam, std::shared_ptr<Program> branchThenParam, std::shared_ptr<Program> branchElseParam) : condition(conditionParam), branchThen(branchThenParam), branchElse(branchElseParam) {}

virtual void If::Evaluate(Memory& memoryParam) override
{
    // Trying to evaluate a vaule of an expression and jumping to a proper branch
     if (condition->Evaluate(memoryParam) != 0)
            branchThen->Evaluate(memoryParam);
     else
             branchElse->Evaluate(memoryParam);
}