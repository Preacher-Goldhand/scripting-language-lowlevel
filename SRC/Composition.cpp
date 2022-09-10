#include "HEADERS/Program.h"
#include "HEADERS/Composition.h"
#include "HEADERS/Memory.h"

Composition::Composition(std::shared_ptr<Program> leftParam, std::shared_ptr<Program> rightParam) : left(leftParam), right(rightParam) {}

virtual void Composition::Evaluate(Memory& memoryParam) override
{
    // Interpreting in order values of an expression in a block scope of the composition
    left->Evaluate(memoryParam);
    right->Evaluate(memoryParam);    
}