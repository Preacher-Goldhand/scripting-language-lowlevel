#include <iterator> 
#include <string_view>
#include "HEADERS/Variable.h"
#include "HEADERS/VariableNotFound.h"
#include "HEADERS/Memory.h"

Variable::Variable(std::string_view nameParam) : name(nameParam) {}

virtual int Variable::Evaluate(Memory& memoryParam) override
{
    Memory::iterator it = memoryParam.find(name);   // searching in Memory to find a proper data by its name saved in our map
    if (it == memoryParam.end())
        throw VariableNotFound();
    return it->second;                              // if found, return the next one data in the map
}