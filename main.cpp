#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <memory>
#include "HEADERS/Expression.h"
#include "HEADERS/BinaryOperator.h"
#include "HEADERS/Variable.h"
#include "HEADERS/Constant.h"
#include "HEADERS/Memory.h"
#include "HEADERS/Parser.h"
#include "HEADERS/NotParsed.h"
#include "HEADERS/VariableNotFound.h"
#include "HEADERS/Program.h"
#include "HEADERS/If.h"
#include "HEADERS/Assign.h"
#include "HEADERS/Composition.h"
#include "HEADERS/Skip.h"
#include "HEADERS/While.h"
#include "HEADERS/Write.h"
#include "HEADERS/Read.h"

int main()
{

/*
    Memory m;

    // Preparing the first expression to evaluate later
    std::unique_ptr<Expression> ex {new BinaryOperator('+', new Constant(2),
        new BinaryOperator('*',
         new BinaryOperator('+', new Constant(1), new Constant(7)),
          new BinaryOperator('*', new Constant(4), new Constant(5))))};

    std::cout << "2 + (1 + 7) * (4 * 5) = " << ex->Evaluate(m) << std::endl;

    // Preparing the second  expression to evaluate later
    std::unique_ptr<Expression> ex2{new BinaryOperator('+',
    new BinaryOperator('*', new Constant(2), new Variable("x")),
    new Variable("y"))};

    // Updating memory of data types
    m["x"] = 10;
    m["y"] = 5;
  
    // The finald evaluation of the expressions
    std::cout << "2 * x + y = " << ex2->Evaluate(m) << std::endl;
*/

/*
    std::cout << "Input an expression: ";

    std::string input;
    std::getline(std::cin, input);
  
    try
    {
        Parser parser(input);
        std::shared_ptr<Expression> ex3{parser.ParseExpression()};

        Memory m2;
        std::cout << "Result: " << ex3->eval(m2) << std::endl;
    }
    catch (NotParsed)
    {
      std::cout << "Error! The gived expression is not parsed" << std::endl;
    }
    catch (VariableNotFound)
    {
        std::cout << "Error! There is no used variables" << std::endl;
    }
*/

/*
  std::shared_ptr<Program> prog{new Composition(
    new Assign("i", new Constant(0)),
    new While(new BinaryOperator('-', new Constant(10), new Variable("i")),
      new Composition(
        new Write("i"),
        new Assign("i", new BinaryOoperator('+', new Variable("i"), new Constant(1)))};
*/

    ifstream file;

    file.open("code.txt");
    if (!file)
    {
      std::cout << "ERROR: Unable to open file";
      return 1;
    }
    std::string s;
    std::getline(file, s, static_cast<char>(EEG));
    file.close();

    try
    { 
      Parser::Parser parser(s);
      std::shared_pointer<Program> prog2{parser.ParseProgram()};
      Memory::Memory m;
      prog2->Evaluate(m);
      std::cout << std::endl;
    }
    catch (NotParsed::NotParsed& exc)
    {
      std::cout << "ERROR: " << std::endl << exc.reason << std::endl;
    }
    return 0;
}
