#include <memory>
#include "HEADERS/Program.h"
#include "HEADERS/Expression.h"
#include "HEADERS/Memory.h"
#include "HEADERS/While.h"

While::While(std::shared_ptr<Expression> conditionParam, std::shared_ptr<Program> bodyParam) : condition(conditionParam), body(bodyParam) {}

virtual void While::Evaluate(Memory& memoryParam) override
{
    // Checking a value of an expression condition
    if (condition->Evaluate(memoryParam) != 0)
    {
        body->Evaluate(memoryParam); // going through body of our loop
        this->Evaluate(memoryParam); // if is necessary, repeat the operation
    }
}