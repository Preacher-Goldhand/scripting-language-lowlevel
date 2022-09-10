#include <iostream>
#include <string_view>
#include "HEADERS/Read.h"
#include "HEADERS/Memory.h"

Read::Read(std::string_view varParam) : var(varParam) {}

void Read::Evaluate(Memory& memoryParam) override
{
        int numberToRead;
        std::cin >> numberToRead;               // gets an input from an user
        memoryParam[var] = numberToRead;        // stores the input in our memory
}