#ifndef COMPOSITION_H
#define COMPOSITION_H
#include <memory>
#include "HEADERS/Program.h"
#include "HEADERS/Memory.h"

// A class representing a compposition of instructions in a scope
class Composition : public Program
{
    private:
        std::shared_ptr<Program> left;
        std::shared_ptr<Program> right;
    
    public: 
        Composition(std::shared_ptr<Program> leftParam, std::shared_ptr<Program> rightParam);
        virtual void Evaluate(Memory& memoryParam) {}   
};
#endif // COMPOSITION_H