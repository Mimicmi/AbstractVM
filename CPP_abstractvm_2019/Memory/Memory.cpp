#include "Memory.h"

Memory::Memory(/* args */)
{
}

Memory::~Memory()
{
}

const std::stack<IOperand *> &Memory::getStack() const
{
    return stack;
}

const std::stack<IOperand *> &Memory::getRegisters() const
{
    return registers;
}

void Memory::setStack(const std::stack<IOperand *> &stack)
{
    this->stack = stack;
}

void Memory::setRegisters(const std::stack<IOperand *> &registers)
{
    this->registers = registers;
}