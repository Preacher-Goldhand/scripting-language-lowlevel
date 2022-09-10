#include <memory>
#include "HEADERS/Expression.h"
#include "HEADERS/BinaryOperator.h"
#include "HEADERS/UnknownOperator.h"
#include "HEADERS/Memory.h"

BinaryOperator::BinaryOperator(char symbolParam,  std::shared_ptr<Expression> leftParam,  std::shared_ptr<Expression> rightParam) 
                                : symbol(symbolParam), left(leftParam), right(rightParam) {}
                                
virtual int BinaryOperator::Evaluate(Memory& memoryParam) override
 {
    switch (symbol)
    {
        case '*': return left->Evaluate(memoryParam) * right->Evaluate(memoryParam);    // multiplies the first element on the left by the next element on the right
        case '+': return left->Evaluate(memoryParam) + right->Evaluate(memoryParam);    // adds the first element on the left by the next element on the right
        case '-': return left->Evaluate(memoryParam) - right->Evaluate(memoryParam);    // substracts the first element on the left by the next element on the right
        case '/': return left->Evaluate(memoryParam) / right->Evaluate(memoryParam);    // divides the first element on the left by the next element on the right
        case '%': return left->Evaluate(memoryParam) % right->Evaluate(memoryParam);    // modulo on the first element on the left by the next element on the right
        default : throw UnkownOperator();
    }
 }                               