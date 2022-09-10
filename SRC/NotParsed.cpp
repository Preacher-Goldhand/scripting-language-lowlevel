#include "HEADERS/NotParsed.h"
#include <string_view>

NotParsed::NotParsed(std::string_view stringParam) : reason(stringParam) {}