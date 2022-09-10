#ifndef WRITE_H
#define WRITE_H
#include <string_view>
#include "HEADERS/Program.h"
#include "HEADERS/Memory.h"

// A class representing writing an output from an user
class Write : public Program
{
    private:
        std::string var;
    
    public:
        Write(std::string_view varParam);
        virtual void Evaluate(Memory& memoryParam);
};
#endif // WRITE_H