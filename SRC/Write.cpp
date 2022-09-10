#include <iostream>
#include <string_view>
#include <iterator>
#include "HEADERS/Write.h"
#include "HEADERS/Memory.h"
#include "HEADERS/VariableNotFound.h"

Write::Write(std::string_view varParam) : var(varParam) {}

void Write::Evaluate(Memory& memoryParam) override
{
    Memory::iterator it = memoryParam.find(var);
    if (it == memoryParam.end())   
        throw VariableNotFound(); 
    std::cout << memoryParam[var] << std::endl;
}