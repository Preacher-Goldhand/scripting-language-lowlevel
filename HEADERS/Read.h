#ifndef READ_H
#define READ_H
#include <string_view>
#include "HEADERS/Program.h"
#include "HEADERS/Memory.h"

// A class representing reading an input from an user
class Read : public Program
{
    private:
        std::string var;
    
    public:
        Read(std::string_view varParam);
        virtual void Evaluate(Memory& memoryParam);
};
#endif // READ_H