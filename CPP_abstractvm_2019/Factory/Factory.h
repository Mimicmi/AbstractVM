/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** .h file for Factory class, this class read and execute assembler language
** By:
** Simon Frezard, Li Wang-Faure, Julien Barriere
*/

#ifndef FACTORY
#define FACTORY

#include <iostream>
#include <list>
#include "../IOperand/IOperand.h"

class Factory {
    private:

        
        // IOperand* createBigDecimal(const std::string& value);

    public:
        IOperand* createInt8(const std::string& value);
        IOperand* createInt16(const std::string& value);
        IOperand* createInt32(const std::string& value);
        IOperand* createFloat(const std::string& value);
        IOperand* createDouble(const std::string& value);
        static IOperand* createOperand(eOperandType type, const std::string& value);
        // Factory();
        // ~Factory();
};

#endif