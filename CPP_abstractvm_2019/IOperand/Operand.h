/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** .h file for Operand 
** By:
** Simon Frezard, Li Wang-Faure, Julien Barriere
*/

#ifndef OPERAND
#define OPERAND

#include <iostream>
#include <list>
#include "../IOperand/IOperand.h"

class Operand : public IOperand {
    private:
        int8_t int8;
        int16_t int16;
        int32_t int32;
        float flt;
        double dbl;

    public:
        Operand(const std::string value, eOperandType type);
        ~Operand();
};

#endif