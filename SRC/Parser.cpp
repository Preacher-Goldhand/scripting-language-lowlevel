#include <string_view>
#include <memory>
#include "HEADERS/Parser.h"
#include "HEADERS/ExpressionEndGuard.h"
#include "HEADERS/Constant.h"
#include "HEADERS/Variable.h"
#include "HEADERS/NotParsed.h"
#include "HEADERS/BinaryOperator.h"


Parser::Parser(std::string_view inputParam) : input(inputParam), position(0) 
{
    input.push_back(EEG);  // put a guard on the end of a gived string 
}

void Parser::SkipWhitespaces()
{
    while (isspace(input[position])) // searches for whitespaces
        ++position;
}

char Parser::LookAhead()
{
    SkipWhitespaces();      // call checking for whitespaces
    return input[position]; // return a current char's possition
}

std::shared_ptr<Expression> Parser::ParseExpression()
{
    std::shared_ptr<Expression> ex{Parser::ParseSum()}; // calls a function for parsing sums in an expression
    if (Parser::LookAhead() == EEG)     // checks if a current char has the guard of a string
        return ex;
    else
        throw NotParsed();
}

 std::shared_ptr<Expression> Parser::ParseSum() 
 {
    std::shared_ptr<Expression> ex{Parser::ParseMultiplication()}; // calls a function for parsing elements of multiplication in the whole sum
    char toCheck{Parser::LookAhead()};

    while (toCheck == '+' || toCheck == '-')    // the sum is seperated by '+' or '-'
    {
        ++position;
        ex{new BinaryOperator(toCheck, ex, Parser::ParseMultiplication())};  // multiplies elements in an expression
        toCheck{Parser::LookAhead()};      // goes to the next one 
    }
    return ex;
 }

std::shared_ptr<Expression> Parser::ParseMultiplication()
{
    std::shared_ptr<Expression> ex{Parser::ParseFactor()};
    char toCheck{Parser::LookAhead()};

     while (toCheck == '*' || toCheck == '/' || toCheck == '%')    // factors are seperated by '*', '/' or '%'
    {
        ++position;
        ex{new BinaryOperator(toCheck, ex, Parser::ParseFactor())};  // parses factors in an expression
        toCheck{Parser::LookAhead()};      // goes to the next one 
    }
    return ex;
}

std::shared_ptr<Expression> Parser::ParseFactor()
{
    // Cheking factors used in an expression
    char toCheck{Parser::LookAhead()};

    if (isdigit(toCheck))
        return Parser::ParseConstant();
    else if (isalpha(toCheck))
        return Parser::ParseVariable();
    else if (toCheck == '(')
        return Parser::ParseSumParenthesis();
    else
        throw NotParsed();
}

std::shared_ptr<Expression> Parser::ParseConstant()
{
    // Parsing a number of digits in a constant
    int numberOfDigits{0};

    while (isdigit(input[position]))
    {
        numberOfDigits *= 10;
        numberOfDigits += input[position] - '0';
        ++position;
    }
    return new Constant(numberOfDigits);
}

std::shared_ptr<Expression> Parser::ParseVariable()
{
    // Parsing a name of a variable
    std::string varName;

    while (isalpha(input[position]))
    {
        varName.push_back(input[position]);
        ++position;
    }
    return new Variable(varName);
}

std::shared_ptr<Expression> Parser::ParseSumParenthesis()
{
    // Parse the sum in parenthesis 
    ++position;     // ensures that a pointer is at an opening '('
    std::shared_ptr<Expression> ex{Parser::ParseSum()};

    if (Parser::LookAhead() == ')')
    {
        ++position;
        return ex;
    } 
    else 
    {
        throw NotParsed();
    }
}

std::string Parser::ParseIdentifier()
{
    // Parsing a keyword in the expression
    std::string toCheck;

    while (isalnum(input[position]))
    {
        toCheck.push_back(input[position]);
        ++position;
    }
    return toCheck;
}

std::shared_ptr<Program> Parser::ParseProgam()
{
    // Parsing whole structure of a program
    std::shared_ptr<Program> prog{Parser::ParseBlock()};
    if(Parser::LookAhead() == EEG)
        return prog;
    else
        throw NotParsed("end of stream expected");
 }

 std::shared_ptr<Program> Parser::ParseBlock()
 {
    // Parsing a single instruction in the expression
    std::shared_ptr<Program> prog{Parser::ParseInstruction()};
   char toCheck{Parser::LookAhead()};

    while (toCheck != '}' && c != EEG) 
    {
        // Checking a composition of the block of instructions
        std::shared_ptr<Program> prog2{Parser::ParseInstruction()};
        prog{new Composition(prog, prog2)};
        toCheck{Parser::LookAhead()};
    }
    return prog;
 }

 std::shared_ptr<Program> Parser::ParseInstruction()
 {
    char toCheck{Parser::LookAhead()};

    if (toCheck == '{')
    {
        ++position;
        std::shared_ptr<Program> prog{Parser::ParseBlock()};   // Verifying the block of instructions

        if (Parser::LookAhead() == '}')                         // Stops parsing, if there is an ending of the block
        {
            ++position;
            return prog;
        }
        else 
            throw NotParsed("'}' expected");
    }
    else if (isalpha(toCheck))
    {
        // Switch case for keywords used in the block
        std::string stringChoice{Parser::ParseInstruction()};

        switch (stringChoice)
        {
            case "read":
                return Parser::ParseRead();
                break;
            case "write":
                return Parser::ParseWrite();
                break;
            case "if":
                return Parser::ParseIf();
                break;
            case "while":
                return Parser::ParseWhile();
                break;
            case "skip":
                return new Skip();
                break;
            default:
                return Parser::ParseAssign(stringChoice);
                break;
        }
    }
    else 
        throw NotParsed("identifier or a keyword expected")
 }

 std::shared_ptr<Program> Parser::ParseRead()
 {
    // Parsing an input as a keyword in the expression
    char toCheck{Parser::LookAhead()};

    if (isalpha(toCheck))
    {
        std::string stringParser{Parser::ParseIdentifier()};
        return new Read(stringParser);
    }
    else 
        throw NotParsed();
 }

 std::shared_ptr<Program> Parser::ParseWrite()
 {
    // Parsing a written input as a keyword in the expression
    char toCheck{Parser::LookAhead()};

    if (isalpha(toCheck))
    {
        std::string stringParser{Parser::ParseIdentifier()};
        return new Write(stringParser);
    }
    else 
        throw NotParsed("variable expected");
 }

std::shared_ptr<Program> Parser::ParseIf()
{
    // Parsing if-else stament 
    std::shared_ptr<Expression> expr{Parser::ParseSum()};
    std::shared_ptr<Program> prog{Parser::ParseInstruction()};

    if(isalpha(Parser::LookAhead()));
    {
        if (Parser::ParseIdentifier() == "else")
        {
             std::shared_ptr<Program> prog2{Parser::ParseInstruction()};
             return new If(expr, prog, prog2);
        }
        else 
             throw NotParsed("'else' expected");     
    }
    else 
         throw NotParsed(); 
}

std::shared_ptr<Program> Parser::ParseWhile()
{
    // Parsing while loop used in the program
    std::shared_ptr<Expression> expr{Parser::ParseSum()};
    std::shared_ptr<Program> prog{Parser::ParseInstruction()};
    return new While(expr, prog);
}

std::shared_ptr<Program> Parser:ParseAssign(std::string_view valParam);
{
    // Parsing the assignment operator and a value of its expression
    char toCheck{Parser::LookAhead()};

    if (toCheck == '=')
    {
        ++position;
        std::shared_ptr<Expression> expr{Parser::ParseSum()};
        return new Assign(valParam, expr);
    }
    else 
        throw NotParsed("'=' expected");
}