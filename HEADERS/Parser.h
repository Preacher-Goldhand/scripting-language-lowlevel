#ifndef PARSER_H
#define PARSER_H
#include <string_view>
#include <string>
#include <memory>
#include "HEADERS/Expression.h"
#include "HEADERS/Program.h"

// A class representing an arithmetic expression parser
class Parser 
{
    private:
        std::string input;   // a text to analyze
        size_t position; // an input's current char position 

    public: 
        Parser(std::string_view inputParam);  
        void SkipWhitespaces();                             // skips whitespaces and carries a pointer on the first non-whitespace char
        char LookAhead();                                   // skips whitespaces and informs which a char is at giving position

        std::shared_ptr<Expression> ParseExpression();      // parses the expression
        std::shared_ptr<Expression> ParseSum();             // parses a sum in the expression
        std::shared_ptr<Expression> ParseMultiplication();  // parses an element of the expression
        std::shared_ptr<Expression> ParseFactor();          // parses a factor in the expression
        std::shared_ptr<Expression> ParseConstant();        // parses a number
        std::shared_ptr<Expression> ParseVariable();        // parses a name of a variable
        std::shared_ptr<Expression> ParseSumParenthesis();  // parses the sum in parenthesis

        std::string ParseIdentifier();                      // parses an identifier or a keyword in the expression

        std::shared_ptr<Program> ParseProgram();            // parses whole structure of a program
        std::shared_ptr<Program> ParseBlock();              // parses a block of composition 
        std::shared_ptr<Program> ParseInstruction();        // parses a single instruction
        std::shared_ptr<Program> ParseRead();               // parses reading an input
        std::shared_ptr<Program> ParseWrite();              // parses writing output
        std::shared_ptr<Program> ParseIf();                 // parses if stament
        std::shared_ptr<Program> ParseWhile();              // parses while loop
        std::shared_ptr<Program> ParseAssign(std::string_view valParam); // parses the assignment operator 
};  
#endif // PARSER_H