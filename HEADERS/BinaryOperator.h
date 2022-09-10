#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H
#include <memory>
#include "Expression.h"
#include "Memory.h"

// A class representing binary operators such as '*', '+', '-', '/', '%'
class BinaryOperator : public Expression
{
    private:
        char symbol;
        std::shared_ptr<Expression> left;
        std::shared_ptr<Expression> right;
    
    public:
        BinaryOperator(char symbolParam,  std::shared_ptr<Expression> leftParam,  std::shared_ptr<Expression> rightParam);
        virtual int Evaluate(Memory& memoryParam);       
};
#endif // BINARY_OPERATOR_H