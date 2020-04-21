#include "commands.h"
#include "Factory.h"
#include "../IOperand/IOperand.h"
#include "../Exception/Exception.h"
#include "../Memory/Memory.h"

void Commands::call(const std::string &function, const std::string &type, const std::string &value, int line)
{
    this->line = line;
    // this->memory = memory;
    if (function == "push"){ push(value); }
    if (function == "pop") { pop(); }
    if (function == "dump") { dump(); }
    if (function == "clear") { clear(); }
    if (function == "dup") { dup(); }
    if (function == "swap") { swap(); }
    if (function == "assert") { assert(value); }
    if (function == "add") { add(); }
    if (function == "sub") { sub(); }
    if (function == "mul") { mul(); }
    if (function == "div") { div(); }
    if (function == "mod") { mod(); }
}

void Commands::push(std::string const &value)
{
    // std::stack<IOperand *> mystack = memory.getStack();
    mystack.push(value);
}

//delete element on top of the stack
void Commands::pop()
{

    if (!mystack.empty()){
        mystack.pop();
    }
    else if (mystack.size() == 0)
        throw Exception("pop on empty stack", this->line);
}

void Commands::dump()
{
    std::stack<std::string> mydump = mystack;

    if (mystack.size() == 0)
        throw Exception("empty stack");
    for(int i = mystack.size(); i > 0; i--) {
        std::cout << mydump.top() << std::endl;
        mydump.pop();
    }
}

void Commands::clear()
{
    while (!mystack.empty()){
        mystack.pop();
    }
}

//dupplicate the value on top of the stack, create a copy of it on top
void Commands::dup()
{
    mystack.push(mystack.top());
}

void Commands::swap()
{
    if (mystack.size() < 2)
        throw Exception("empty stack or missing value");

    std::string tmp1 = mystack.top();
    mystack.pop();
    std::string tmp2 = mystack.top();
    mystack.pop();
    mystack.push(tmp1);
    mystack.push(tmp2);
}

//verify the value on top is equal to the one passed as a parameter, if not throw error
void Commands::assert(std::string const &value)
{
    if (value != mystack.top())
        throw Exception("Error");
}


//Unstack first 2 values on top of the stack, add them, stack the result
void Commands::add()
{
   
    int firstValue;
    int secondValue;
    int result;

    if (!mystack.empty()) {
        firstValue = stoi(mystack.top());
        mystack.pop();
        secondValue = stoi(mystack.top());
        mystack.pop();

        result = firstValue + secondValue;
        mystack.push(std::to_string(result));
    }
    else {
        throw Exception("no value to add", this->line);
    }
}

void Commands::sub()
{
    int firstValue;
    int secondValue;
    int result;

    if (!mystack.empty()){
        firstValue = stod(mystack.top());
        mystack.pop();
        secondValue = stod(mystack.top());
        mystack.pop();

        result = firstValue - secondValue;
        mystack.push(std::to_string(result));
    }
    else {
        throw Exception("Error");
    }
}

void Commands::mul()
{
    int firstValue;
    int secondValue;
    int result;

    if (!mystack.empty()){
        firstValue = stod(mystack.top());
        mystack.pop();
        secondValue = stod(mystack.top());
        mystack.pop();

        result = firstValue * secondValue;
        mystack.push(std::to_string(result));
    }
    else {
        throw Exception("Error");
    }
}

void Commands::div()
{
    int firstValue;
    int secondValue;
    int result;

    if (!mystack.empty()){
        firstValue = stod(mystack.top());
        mystack.pop();
        secondValue = stod(mystack.top());
        mystack.pop();

        result = firstValue / secondValue;
        mystack.push(std::to_string(result));
    }
    // else if (){
    //     //div by 0 should return error;
    // }
    else {
        throw Exception("Error");
    }
}

void Commands::mod()
{
    int firstValue;
    int secondValue;
    int result;

    if (!mystack.empty()){
        firstValue = stod(mystack.top());
        mystack.pop();
        secondValue = stod(mystack.top());
        mystack.pop();

        result = firstValue % secondValue;
        mystack.push(std::to_string(result));
    }
    // else if {
    //     //modulo by 0 should return error;
    // }
    else {
        throw Exception("Error");
    }
}

// //copy value from register v & stack it at the top. if register v does not contain a value the program execution must stop
// void Commands::load(eOperandType type, std::string const & value)
// {

// }

// //unstack the first value and store it to the register v
// void Commands::store(eOperandType type, std::string const & value)
// {

// }

// //make sure that the value at the top of the stack is an 8-bit ineger, intepret it like an ascii value & display the corresponding character on standard output
// void Commands::print(eOperandType type, std::string const & value)
// {

// }

//quit the program execution that is underway
// void Commands::exit()
// {
//     // fprintf("exit");
//     std::cout << ";;" << std::endl;
//     exit();
// }