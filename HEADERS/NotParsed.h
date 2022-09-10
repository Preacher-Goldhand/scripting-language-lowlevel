#ifndef NOT_PARSED_H
#define NOT_PARSED_H
#include <string>
#include <string_view>

// A class representing an expception of a given unparsed expression
class NotParsed
{
    public:
        std::string reason;

        NotParsed() {};
        NotParsed(std::string_view stringParam);
};
#endif // NOT_PARSED_H