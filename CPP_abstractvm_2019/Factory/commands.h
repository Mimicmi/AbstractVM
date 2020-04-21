#ifndef COMMANDS
#define COMMANDS

#include <stack>
#include <iostream>
#include "../IOperand/IOperand.h"
#include "../Memory/Memory.h"

class Commands {
private:
    int line;
    // Memory &memory;
    std::stack<std::string> mystack;
public:

    // Commands(const std::string &function, const std::string &type, const std::string &value, int line);
    void push(const std::string &value);
    void pop();
    void dump();
    void clear();
    void dup();
    void swap();
    void assert(std::string const & value);
    void add();
    void sub();
    void mul();
    void div();
    void mod();
    void call(const std::string &function, const std::string &type, const std::string &value, int line);
    // void load(eOperandType type, const std::string& value);
    // void store(eOperandType type, const std::string& value);
    // void print(eOperandType type, const std::string& value);
    // void exit();

    static IOperand* createOperand(eOperandType type, const std::string& value);
};

#endif