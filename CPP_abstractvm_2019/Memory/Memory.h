#ifndef MEMORY_H_
# define MEMORY_H_

#include <stack>
#include "../IOperand/IOperand.h"

class Memory
{
private:
    std::stack<IOperand *> stack;
    std::stack<IOperand *> registers;
public:
    Memory(/* args */);
    ~Memory();
    const std::stack<IOperand *>& getStack() const;
    const std::stack<IOperand *>& getRegisters() const;
    void setStack(const std::stack<IOperand *>& stack);
    void setRegisters(const std::stack<IOperand *>& registers);
};

#endif /* !MEMORY_H_ */
