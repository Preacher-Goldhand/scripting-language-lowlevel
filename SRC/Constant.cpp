#include "HEADERS/Constant.h"
#include "HEADERS/Memory.h"

Constant::Constant(int valueParam) : value(valueParam) {}

virtual int Constant::Evaluate(Memory& memoryParam)  override
{ 
    return value; 
}
