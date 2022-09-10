#include <string_view>
#include <memory>
#include "HEADERS/Expression.h"
#include "HEADERS/Assign.h"
#include "HEADERS/Memory.h"

Assign::Assign(std::string_view varParam, std::shared_ptr<Expression> exprParam) : var(varParam), expr(exprParam) {}

 virtual void Assign::Evaluate(Memory& memoryParam) override
 {
    memoryParam[var] = expr->Evaluate(memoryParam); // under a variable's name stores a value of an assigned expression
 }