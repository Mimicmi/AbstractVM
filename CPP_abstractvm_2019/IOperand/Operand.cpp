/*
** EPITECH PROJECT, 2020
** AbstractVM
** File description:
** .cpp file for Operand class, this class contain all operation for vm 
** By:
** Simon Frezard, Li Wang-Faure, Julien Barriere
*/

#include "IOperand.h"
#include "Operand.h"

Operand::Operand(const std::string value, eOperandType type): IOperand() {

    switch (type)
    {
        case Int8:
            int8 = stoi(value);
        case Int16:
            int16 = stoi(value);
        case Int32:
            int32 = stoi(value);
        case Float:
            flt = stof(value);
        case Double:
            dbl = stod(value);
    }
}